#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

//【未対応要件】
//・外部メモリアロケータ対応
//・ShiftJISコードとUTF8の対応　※プリント時に変換する
//・プリント処理のスレッド化対応
//・ノーティファイ処理（画面表示処理）対応
//・アサーション対応

#define WINDOWS

#define DEBUG_MODE_ENABLED

#ifdef WINDOWS

#include <windows.h>
#include <process.h>

#define ___FILE __FILE__
#define ___LINE __LINE__
#define ___TIMESTAMP __TIMESTAMP__
#define ___FUNC __FUNCTION__

class CCriticalSection
{
private:
	CRITICAL_SECTION m_obj;
private:
//	explicit CCriticalSection(){}
	explicit CCriticalSection(CCriticalSection&){}
	explicit CCriticalSection(CCriticalSection*){}
public:
	explicit CCriticalSection()
	{
		InitializeCriticalSection(&this->m_obj);
	}
	~CCriticalSection()
	{
		DeleteCriticalSection(&this->m_obj);
	}
public:
	void Lock()
	{
		EnterCriticalSection(&this->m_obj);
	}
	void Release()
	{
		LeaveCriticalSection(&this->m_obj);
	}
};
class CAutoCriticalSection
{
private:
	CCriticalSection* m_obj;
private:
	explicit CAutoCriticalSection(){}
	explicit CAutoCriticalSection(CAutoCriticalSection&){}
	explicit CAutoCriticalSection(CAutoCriticalSection*){}
public:
	explicit CAutoCriticalSection(CCriticalSection& obj) :
		m_obj(&obj)
	{
		this->m_obj->Lock();
	}
	explicit CAutoCriticalSection(CCriticalSection* obj) :
		m_obj(obj)
	{
		if (this->m_obj)
			this->m_obj->Lock();
	}
	~CAutoCriticalSection()
	{
		if (this->m_obj)
			this->m_obj->Release();
	}
};
class CInterlockedInteger
{
private:
	LONG m_value;
private:
	explicit CInterlockedInteger(){}
	explicit CInterlockedInteger(CInterlockedInteger&){}
	explicit CInterlockedInteger(CInterlockedInteger*){}
public:
	CInterlockedInteger(const int init_value) :
		m_value(init_value)
	{
	}
public:
	int get() const { return this->m_value; }
	int add(const int plus) { InterlockedExchangeAdd(&this->m_value, plus); return this->m_value; }
	int increment() { return InterlockedIncrement(&this->m_value); }
	int decrement() { return InterlockedIncrement(&this->m_value); }
};
class CInterlockedIntegerEx
{
private:
	CCriticalSection m_cs_obj;
	int m_value;
	const int m_value_mask;
	const int m_value_min;
	const int m_value_max;
private:
//	explicit CInterlockedIntegerEx() :m_mask(0), m_rotation_min(0), m_rotation_max(0){}
	explicit CInterlockedIntegerEx(CInterlockedIntegerEx&) :m_value_mask(0), m_value_min(0), m_value_max(0){}
	explicit CInterlockedIntegerEx(CInterlockedIntegerEx*) :m_value_mask(0), m_value_min(0), m_value_max(0){}
public:
	CInterlockedIntegerEx() :
		m_value(0),
		m_value_mask(~0),
		m_value_min(-9999),
		m_value_max(9999)
	{
	}
	CInterlockedIntegerEx(const int init_value) :
		m_value(init_value),
		m_value_mask(~0),
		m_value_min(-9999),
		m_value_max(9999)
	{
	}
	CInterlockedIntegerEx(const int init_value, const int value_mask) :
		m_value(init_value),
		m_value_mask(value_mask),
		m_value_min(-9999),
		m_value_max(9999)
	{
	}
	CInterlockedIntegerEx(const int init_value, const int value_min, const int value_max) :
		m_value(init_value),
		m_value_mask(~0),
		m_value_min(value_min),
		m_value_max(value_max)
	{
	}
public:
	int get() const { return this->m_value; }
	int add(const int plus)
	{
		CAutoCriticalSection cs(this->m_cs_obj);
		this->m_value = (this->m_value + plus) & this->m_value_mask;
		return this->m_value;
	}
	int addLimit(const int plus)
	{
		CAutoCriticalSection cs(this->m_cs_obj);
		this->m_value = this->m_value + plus;
		if (this->m_value < this->m_value_min)
			this->m_value = this->m_value_min;
		else if (this->m_value > this->m_value_max)
			this->m_value = this->m_value_max;
		return this->m_value;
	}
	int addRotation(const int plus)
	{
		CAutoCriticalSection cs(this->m_cs_obj);
		this->m_value = this->m_value + plus;
		if (this->m_value < this->m_value_min)
			this->m_value = this->m_value_max - (this->m_value_min - this->m_value - 1);
		else if (this->m_value > this->m_value_max)
			this->m_value = this->m_value_min + (this->m_value - this->m_value_max - 1);
		return this->m_value;
	}
	int increment()
	{
		CAutoCriticalSection cs(this->m_cs_obj);
		this->m_value = (++this->m_value) & this->m_value_mask;
		return this->m_value;
	}
	int incrementLimit()
	{
		CAutoCriticalSection cs(this->m_cs_obj);
		++this->m_value;
		if (this->m_value > this->m_value_max)
			this->m_value = this->m_value_max;
		return this->m_value;
	}
	int incrementRotation()
	{
		CAutoCriticalSection cs(this->m_cs_obj);
		++this->m_value;
		if (this->m_value > this->m_value_max)
			this->m_value = this->m_value_min;
		return this->m_value;
	}
	int decrement()
	{
		CAutoCriticalSection cs(this->m_cs_obj);
		this->m_value = (--this->m_value) & this->m_value_mask;
		return this->m_value;
	}
	int decrementLimit()
	{
		CAutoCriticalSection cs(this->m_cs_obj);
		--this->m_value;
		if (this->m_value < this->m_value_min)
			this->m_value = this->m_value_min;
		return this->m_value;
	}
	int decrementRotation()
	{
		CAutoCriticalSection cs(this->m_cs_obj);
		--this->m_value;
		if (this->m_value < this->m_value_min)
			this->m_value = this->m_value_max;
		return this->m_value;
	}
};

typedef DWORD THREAD_ID;
THREAD_ID getCurrentThreadId()
{
	return GetCurrentThreadId();
}

#endif//WINDOWS

#ifdef DEBUG_MODE_ENABLED

namespace debug
{
	typedef unsigned int CALL_POINT_ID;
	typedef unsigned char CALL_POINT_TYPE;
	typedef unsigned int MESSAGE_BLOCK_ID;
	typedef unsigned int MESSAGE_ID;
	typedef unsigned char MESSAGE_RANK;
	typedef unsigned char MESSAGE_STATE;
	typedef unsigned short MESSAGE_MASK;
	typedef char* const TEXT;
	typedef int LINE;
	struct T_THREAD_INFO;
	struct T_CALL_POINT_INFO;
	struct T_MESSAGE_BLOCK_INFO;
	struct T_MESSAGE_INFO;

	enum E_CALL_POINT_TYPE
	{
		TYPE_NONE = 0,
		TYPE_SYSTEM = 1,
		TYPE_CHARA = 2,
		TYPE_MAP = 3,
		TYPE_EFFECT = 4,
		TYPE_MENU = 5,
		TYPE_EVENT = 6,
		TYPE_SOUND = 7,
		TYPE_PLANNER = 8,
		TYPE_RESERVE_01 = 9,
		TYPE_RESERVE_02 = 10,
		TYPE_RESERVE_03 = 11,
		TYPE_RESERVE_04 = 12,
		TYPE_RESERVE_05 = 13,
		TYPE_RESERVE_06 = 14,
		TYPE_RESERVE_07 = 15,
		TYPE_USER_01 = 16,
		TYPE_USER_02 = 17,
		TYPE_USER_03 = 18,
		TYPE_USER_04 = 19,
		TYPE_USER_05 = 20,
		TYPE_USER_06 = 21,
		TYPE_USER_07 = 22,
		TYPE_USER_08 = 23,
		TYPE_USER_09 = 24,
		TYPE_USER_10 = 25,
		TYPE_USER_11 = 26,
		TYPE_USER_12 = 27,
		TYPE_USER_13 = 28,
		TYPE_USER_14 = 29,
		TYPE_USER_15 = 30,
		TYPE_USER_16 = 31,
		TYPE_NUM = 32,
	};
	enum E_MESSAGE_RANK
	{
		RANK_NORMAL = 0,
		RANK_DETAIL = 1,
		RANK_DETAIL_LV1 = 1,
		RANK_DETAIL_LV2 = 2,
		RANK_DETAIL_LV3 = 3,
		RANK_CRITICAL = 4,
		RANK_CRITICAL_LV1 = 4,
		RANK_CRITICAL_LV2 = 5,
		RANK_CRITICAL_LV3 = 6,
		RANK_RESERVE_01 = 7,
		RANK_RESERVE_02 = 8,
		RANK_RESERVE_03 = 9,
		RANK_RESERVE_04 = 10,
		RANK_RESERVE_05 = 11,
		RANK_RESERVE_06 = 12,
		RANK_RESERVE_07 = 13,
		RANK_RESERVE_08 = 14,
		RANK_RESERVE_09 = 15,
		RANK_NUM = 16,
	};
	enum E_MESSAGE_STATE
	{
		STATE_NONE = 0,
		STATE_PRINTED = 1,
	//	STATE_NOTIFIED = 3,
	//	STATE_COMPLETED = 4,
	};
	static const char* s_call_info_type_name[TYPE_NUM] =
	{
		"NONE",
		"SYSTEM",
		"CHARA",
		"MAP",
		"EFFECT",
		"MENU",
		"EVENT",
		"SOUND",
		"PLANNER",
		"RESERVE_01",
		"RESERVE_02",
		"RESERVE_03",
		"RESERVE_04",
		"RESERVE_05",
		"RESERVE_06",
		"RESERVE_07",
		"USER_01",
		"USER_02",
		"USER_03",
		"USER_04",
		"USER_05",
		"USER_06",
		"USER_07",
		"USER_08",
		"USER_09",
		"USER_10",
		"USER_11",
		"USER_12",
		"USER_13",
		"USER_14",
		"USER_15",
		"USER_16",
	};
	static const char* s_message_rank_name[RANK_NUM] =
	{
		"NORMAL",
		"DETAIL_LV1",
		"DETAIL_LV2",
		"DETAIL_LV3",
		"CRITICAL_LV1",
		"CRITICAL_LV2",
		"CRITICAL_LV3",
		"RESERVE_01",
		"RESERVE_02",
		"RESERVE_03",
		"RESERVE_04",
		"RESERVE_05",
		"RESERVE_06",
		"RESERVE_07",
		"RESERVE_08",
		"RESERVE_09",
	};
	inline MESSAGE_MASK calcRankMaskBit(const E_MESSAGE_RANK rank){ return static_cast<MESSAGE_MASK>(1) << static_cast<MESSAGE_MASK>(rank); }
	inline const char* const getTypeName(const E_CALL_POINT_TYPE type){ return s_call_info_type_name[type]; }
	inline const char* const getRankName(const E_MESSAGE_RANK rank){ return s_message_rank_name[rank]; }

	struct T_FUNC_INFO
	{
	public:
		const TEXT m_file_path;
		const TEXT m_timestamp;
		const TEXT m_func_name;
		const LINE m_file_line;
	public:
		T_FUNC_INFO(const TEXT file_path, const TEXT timestamp, const TEXT func_name, const LINE file_line):
			m_file_path(file_path),
			m_timestamp(timestamp),
			m_func_name(func_name),
			m_file_line(file_line)
		{
		}
	};
	struct T_MESSAGE_INFO
	{
	public:
		T_MESSAGE_INFO* m_next;
		CCriticalSection m_cs_obj;
		MESSAGE_ID m_id;
		MESSAGE_RANK m_rank;
		LINE m_file_line;
		bool m_with_call_info;
		const char* m_text;
		MESSAGE_STATE m_state;
	private:
		explicit T_MESSAGE_INFO(){}
		explicit T_MESSAGE_INFO(T_MESSAGE_INFO&){}
		explicit T_MESSAGE_INFO(T_MESSAGE_INFO*){}
	public:
		explicit T_MESSAGE_INFO(const MESSAGE_ID id, E_MESSAGE_RANK rank, const LINE file_line, const bool with_call_info, const char* const text) :
			m_next(nullptr),
			m_id(id),
			m_rank(rank),
			m_file_line(file_line),
			m_with_call_info(with_call_info),
			m_text(nullptr),
			m_state(STATE_NONE)
		{
			if (text)
			{
				const size_t text_len = strlen(text);
				char* text_copy = new char[text_len + 1];
				if (text_copy)
				{
					strcpy_s(text_copy, text_len + 1, text);
					this->m_text = text_copy;
				}
			}
		}
		~T_MESSAGE_INFO()
		{
			CAutoCriticalSection cs(this->m_cs_obj);
			if (this->m_text)
			{
				delete this->m_text;
				this->m_text = nullptr;
			}
		}
	};
	struct T_MESSAGE_BLOCK_INFO
	{
	public:
		T_MESSAGE_BLOCK_INFO* m_next;
		T_MESSAGE_INFO* m_message_info_top;
		CCriticalSection m_cs_obj;
		MESSAGE_BLOCK_ID m_id;
		MESSAGE_RANK m_rank_default;
		T_FUNC_INFO m_func_info;
	private:
		void deleteMessageInfo(T_MESSAGE_INFO* parent_info, T_MESSAGE_INFO* info)
		{
			if (!info) return;
			deleteMessageInfo(info, info->m_next);
			if (parent_info)
				parent_info->m_next = nullptr;
			delete info;
		}
		void deleteMessageInfo(T_MESSAGE_INFO* info)
		{
			deleteMessageInfo(nullptr, info);
		}
	private:
		explicit T_MESSAGE_BLOCK_INFO() :m_func_info(nullptr, nullptr, nullptr, 0){}
		explicit T_MESSAGE_BLOCK_INFO(T_MESSAGE_BLOCK_INFO&) :m_func_info(nullptr, nullptr, nullptr, 0){}
		explicit T_MESSAGE_BLOCK_INFO(T_MESSAGE_BLOCK_INFO*) :m_func_info(nullptr, nullptr, nullptr, 0){}
	public:
		explicit T_MESSAGE_BLOCK_INFO(const MESSAGE_BLOCK_ID id, E_MESSAGE_RANK rank_default, const TEXT file_path, const TEXT timestamp, const TEXT func_name, const LINE file_line) :
			m_next(nullptr),
			m_message_info_top(nullptr),
			m_id(id),
			m_rank_default(rank_default),
			m_func_info(file_path, timestamp, func_name, file_line)
		{
		}
		~T_MESSAGE_BLOCK_INFO()
		{
			CAutoCriticalSection cs(this->m_cs_obj);
			deleteMessageInfo(this->m_message_info_top);
			this->m_message_info_top = nullptr;
		}
	};
	struct T_CALL_POINT_INFO
	{
	public:
		T_CALL_POINT_INFO* m_next;
		T_MESSAGE_BLOCK_INFO* m_message_block_info_top;
		CCriticalSection m_cs_obj;
		CALL_POINT_ID m_id;
		CALL_POINT_TYPE m_type;
		T_FUNC_INFO m_func_info;
		const char* m_caption;
	private:
		void deleteMessageBlockInfo(T_MESSAGE_BLOCK_INFO* parent_info, T_MESSAGE_BLOCK_INFO* info)
		{
			if (!info) return;
			deleteMessageBlockInfo(info, info->m_next);
			if (parent_info)
				parent_info->m_next = nullptr;
			delete info;
		}
		void deleteMessageBlockInfo(T_MESSAGE_BLOCK_INFO* info)
		{
			deleteMessageBlockInfo(nullptr, info);
		}
	private:
		explicit T_CALL_POINT_INFO() :m_func_info(nullptr, nullptr, nullptr, 0){}
		explicit T_CALL_POINT_INFO(T_CALL_POINT_INFO&) :m_func_info(nullptr, nullptr, nullptr, 0){}
		explicit T_CALL_POINT_INFO(T_CALL_POINT_INFO*) :m_func_info(nullptr, nullptr, nullptr, 0){}
	public:
		explicit T_CALL_POINT_INFO(const CALL_POINT_ID id, E_CALL_POINT_TYPE type, const TEXT file_path, const TEXT timestamp, const TEXT func_name, const LINE file_line, const char* const caption) :
			m_next(nullptr),
			m_message_block_info_top(nullptr),
			m_id(id),
			m_type(type),
			m_func_info(file_path, timestamp, func_name, file_line),
			m_caption(nullptr)
		{
			if (caption)
			{
				const size_t caption_len = strlen(caption);
				char* caption_copy = new char[caption_len + 1];
				if (caption_copy)
				{
					strcpy_s(caption_copy, caption_len + 1, caption);
					this->m_caption = caption_copy;
				}
			}
		}
		~T_CALL_POINT_INFO()
		{
			CAutoCriticalSection cs(this->m_cs_obj);
			deleteMessageBlockInfo(this->m_message_block_info_top);
			this->m_message_block_info_top = nullptr;
			if (this->m_caption)
			{
				delete this->m_caption;
				this->m_caption = nullptr;
			}
		}
	};

	struct T_THREAD_INFO
	{
	public:
		T_THREAD_INFO* m_next;
		T_CALL_POINT_INFO* m_call_point_info_top;
		CCriticalSection m_cs_obj;
		THREAD_ID m_id;
		const char* m_name;
	private:
		void deleteCallPointInfo(T_CALL_POINT_INFO* parent_info, T_CALL_POINT_INFO* info)
		{
			if (!info) return;
			deleteCallPointInfo(info, info->m_next);
			if (parent_info)
				parent_info->m_next = nullptr;
			delete info;
		}
		void deleteCallPointInfo(T_CALL_POINT_INFO* info)
		{
			deleteCallPointInfo(nullptr, info);
		}
	private:
		explicit T_THREAD_INFO(){}
		explicit T_THREAD_INFO(T_THREAD_INFO&){}
		explicit T_THREAD_INFO(T_THREAD_INFO*){}
	public:
		explicit T_THREAD_INFO(const THREAD_ID id, const char* name) :
			m_next(nullptr),
			m_call_point_info_top(nullptr),
			m_id(id),
			m_name(nullptr)
		{
			if (name)
			{
				const size_t name_len = strlen(name);
				char* name_copy = new char[name_len + 1];
				if (name_copy)
				{
					strcpy_s(name_copy, name_len + 1, name);
					this->m_name = name_copy;
				}
			}
		}
		~T_THREAD_INFO()
		{
			CAutoCriticalSection cs(this->m_cs_obj);
			deleteCallPointInfo(this->m_call_point_info_top);
			this->m_call_point_info_top = nullptr;
			if (this->m_name)
			{
				delete this->m_name;
				this->m_name = nullptr;
			}
		}
	};

	class T_WORK_BUFF
	{
	public:
		const size_t m_buff_size_def;
		size_t m_buff_size;
		char* m_buff;
		CCriticalSection m_cs_obj;
	private:
		explicit T_WORK_BUFF() :m_buff_size_def(0){}
		explicit T_WORK_BUFF(T_WORK_BUFF&) :m_buff_size_def(0){}
		explicit T_WORK_BUFF(T_WORK_BUFF*) :m_buff_size_def(0){}
	public:
		explicit T_WORK_BUFF(const size_t buff_size) :
			m_buff_size_def(buff_size),
			m_buff_size(0),
			m_buff(nullptr)
		{
			m_buff = new char[m_buff_size_def];
			if (m_buff)
				m_buff_size = m_buff_size_def;
		}
		~T_WORK_BUFF()
		{
			if (m_buff)
			{
				delete m_buff;
				m_buff = nullptr;
			}
		}
	};
	class CWorkBuff
	{
	private:
		const int m_buff_num;
		const int m_buff_size;
		CInterlockedIntegerEx m_buff_index;
		T_WORK_BUFF** m_buff;
	private:
		explicit CWorkBuff() :m_buff_num(0), m_buff_size(0){}
		explicit CWorkBuff(CWorkBuff&) :m_buff_num(0), m_buff_size(0){}
		explicit CWorkBuff(CWorkBuff*) :m_buff_num(0), m_buff_size(0){}
	public:
		explicit CWorkBuff(const int buff_num, const int buff_size) :
			m_buff_num(buff_num),
			m_buff_size(buff_size),
			m_buff_index(0, 0, buff_num - 1),
			m_buff(nullptr)
		{
			m_buff = new T_WORK_BUFF*[this->m_buff_num];
			if (this->m_buff)
			{
				for (int index = 0; index < this->m_buff_num; ++index)
				{
					this->m_buff[index] = new T_WORK_BUFF(this->m_buff_size);
				}
			}
		}
		~CWorkBuff()
		{
			if (this->m_buff)
			{
				for (int index = 0; index < this->m_buff_num; ++index)
				{
					delete this->m_buff[index];
					this->m_buff[index] = nullptr;
				}
				delete this->m_buff;
				this->m_buff = nullptr;
			}
		}
	public:
		T_WORK_BUFF* getNext()
		{
			if (!this->m_buff)
				return nullptr;
			const int index = this->m_buff_index.incrementRotation();
			return this->m_buff[index];
		}
	};

	CCriticalSection* s_cs_obj = nullptr;
	T_THREAD_INFO* s_thread_info_top = nullptr;
	MESSAGE_MASK s_print_rank_mask[TYPE_NUM];
	MESSAGE_MASK s_notify_rank_mask[TYPE_NUM];
	CWorkBuff* s_work_buff = NULL;

	inline MESSAGE_MASK getPrintRankMask(const E_CALL_POINT_TYPE type){ return s_print_rank_mask[type]; }
	inline MESSAGE_MASK getNotifyRankMask(const E_CALL_POINT_TYPE type){ return s_notify_rank_mask[type]; }
	inline bool checkPrintRankMask(const E_CALL_POINT_TYPE type, const E_MESSAGE_RANK rank){ return (s_print_rank_mask[type] & calcRankMaskBit(rank)) != 0; }
	inline bool checkNotifyRankMask(const E_CALL_POINT_TYPE type, const E_MESSAGE_RANK rank){ return (s_notify_rank_mask[type] & calcRankMaskBit(rank)) != 0; }
	inline MESSAGE_MASK setPrintRankMaskOn(const E_CALL_POINT_TYPE type, const E_MESSAGE_RANK rank){ s_print_rank_mask[type] |= calcRankMaskBit(rank); return s_print_rank_mask[type]; }
	inline MESSAGE_MASK setNotifyRankMaskOn(const E_CALL_POINT_TYPE type, const E_MESSAGE_RANK rank){ s_notify_rank_mask[type] |= calcRankMaskBit(rank); return s_notify_rank_mask[type]; }
	inline MESSAGE_MASK setPrintRankMaskOff(const E_CALL_POINT_TYPE type, const E_MESSAGE_RANK rank){ s_print_rank_mask[type] &= ~calcRankMaskBit(rank); return s_print_rank_mask[type]; }
	inline MESSAGE_MASK setNotifyRankMaskOff(const E_CALL_POINT_TYPE type, const E_MESSAGE_RANK rank){ s_notify_rank_mask[type] &= ~calcRankMaskBit(rank); return s_notify_rank_mask[type]; }
	inline MESSAGE_MASK setPrintRankMask(const E_CALL_POINT_TYPE type, const E_MESSAGE_RANK rank, const bool on){ return on ? setPrintRankMaskOn(type, rank) : setPrintRankMaskOff(type, rank); }
	inline MESSAGE_MASK setNotifyRankMask(const E_CALL_POINT_TYPE type, const E_MESSAGE_RANK rank, const bool on){ return on ? setNotifyRankMaskOn(type, rank) : setNotifyRankMaskOff(type, rank); }

	T_WORK_BUFF* getWorkBuff()
	{
		if (!s_work_buff)
			return nullptr;
		return s_work_buff->getNext();
	}

	const char* const getFileName(const char* const path)
	{
		int len = strlen(path);
		const char* p = path + len - 1;
		for (int pos = len - 1; pos >= 0; --pos, --p)
		{
			const char c = *p;
			if (c == '/' || c == '\\')
			{
				return p + 1;
			}
		}
		return path;
	}
	
	T_THREAD_INFO* getThread(const THREAD_ID thread_id)//【注】ロック状態でオブジェクトを返すので、明示的にリリースする必要あり
	{
		CAutoCriticalSection cs(s_cs_obj);
		T_THREAD_INFO* thread_info = s_thread_info_top;
		while (thread_info && thread_info->m_id != thread_id)
		{
			thread_info = thread_info->m_next;
		}
		if (thread_info)
			thread_info->m_cs_obj.Lock();
		return thread_info;
	}
	void addThread(const THREAD_ID thread_id, const char* name, va_list args)
	{
		CAutoCriticalSection cs(s_cs_obj);
		T_THREAD_INFO* thread_info = nullptr;
		{
			T_WORK_BUFF* work_buff = getWorkBuff();
			if (work_buff)
			{
			//	const size_t name_size = _vscprintf(name, args);
			//	const size_t buff_size = buff_size;
			//	char* buff = new char[buff_size];
			//	vsprintf_s(buff, buff_size, name, args);
				CAutoCriticalSection cs(work_buff->m_cs_obj);
				size_t buff_size = work_buff->m_buff_size;
				char* buff = work_buff->m_buff;
				buff[0] = '\0';
				vsprintf_s(buff, buff_size, name, args);
				thread_info = new T_THREAD_INFO(thread_id, buff);
			}
		}
		if (!s_thread_info_top)
		{
			s_thread_info_top = thread_info;
		}
		else
		{
			T_THREAD_INFO* thread_info_parent = s_thread_info_top;
			while (thread_info_parent->m_next)
			{
				thread_info_parent = thread_info_parent->m_next;
			}
			thread_info_parent->m_next = thread_info;
		}
	}
	void removeThread(const THREAD_ID thread_id)
	{
		CAutoCriticalSection cs(s_cs_obj);
		T_THREAD_INFO* thread_info_parent = nullptr;
		T_THREAD_INFO* thread_info = s_thread_info_top;
		while (thread_info && thread_info->m_id != thread_id)
		{
			thread_info_parent = thread_info;
			thread_info = thread_info->m_next;
		}
		if (thread_info)
		{
			{
				CAutoCriticalSection cs(thread_info->m_cs_obj);
				if (thread_info_parent)
				{
					CAutoCriticalSection cs(thread_info_parent->m_cs_obj);
					thread_info_parent->m_next = thread_info->m_next;
				}
				else
				{
					s_thread_info_top = thread_info->m_next;
				}
			}
			delete thread_info;
		}
	}
	void removeThreadAll()
	{
		T_THREAD_INFO* thread_info = nullptr;
		{
			CAutoCriticalSection cs(s_cs_obj);
			thread_info = s_thread_info_top;
			s_thread_info_top = nullptr;
		}
		while (thread_info)
		{
			T_THREAD_INFO* thread_info_next = thread_info->m_next;
			{
				CAutoCriticalSection cs(thread_info->m_cs_obj);
			}
			delete thread_info;
			thread_info = thread_info_next;
		}
	}
	
	T_CALL_POINT_INFO* getCallPoint(T_THREAD_INFO* thread_info, const CALL_POINT_ID call_point_id)//【注】ロック状態でオブジェクトを返すので、明示的にリリースする必要あり
	{
		if (!thread_info)
			return nullptr;
		T_CALL_POINT_INFO* call_point_info = thread_info->m_call_point_info_top;
		while (call_point_info && call_point_info->m_id != call_point_id)
		{
			call_point_info = call_point_info->m_next;
		}
		if (call_point_info)
			call_point_info->m_cs_obj.Lock();
		return call_point_info;
	}
	T_CALL_POINT_INFO* getCallPointLast(const THREAD_ID thread_id)//【注】ロック状態でオブジェクトを返すので、明示的にリリースする必要あり
	{
		T_THREAD_INFO* thread_info = getThread(thread_id);
		if (!thread_info)
			return nullptr;
		T_CALL_POINT_INFO* call_point_info = thread_info->m_call_point_info_top;
		while (call_point_info && call_point_info->m_next)
		{
			call_point_info = call_point_info->m_next;
		}
		if (call_point_info)
			call_point_info->m_cs_obj.Lock();
		thread_info->m_cs_obj.Release();
		return call_point_info;
	}
	CALL_POINT_ID addCallPoint(const THREAD_ID thread_id, const E_CALL_POINT_TYPE type, const TEXT file_path, const TEXT timestamp, const TEXT func_name, const LINE file_line, const char* caption, va_list args)
	{
		T_THREAD_INFO* thread_info = getThread(thread_id);
		if (!thread_info)
			return 0;
		CALL_POINT_ID id = 0;
		T_CALL_POINT_INFO* call_point_info_last = thread_info->m_call_point_info_top;
		while (call_point_info_last && call_point_info_last->m_next)
		{
			call_point_info_last = call_point_info_last->m_next;
		}
		if (call_point_info_last)
			id = call_point_info_last->m_id + 1;
		else
			id = 1;
		T_CALL_POINT_INFO* call_point_info = nullptr;
		{
			T_WORK_BUFF* work_buff = getWorkBuff();
			if (work_buff)
			{
			//	const size_t caption_size = _vscprintf(caption, args);
			//	const size_t buff_size = buff_size;
			//	char* buff = new char[buff_size];
			//	vsprintf_s(buff, buff_size, caption, args);
				CAutoCriticalSection cs(work_buff->m_cs_obj);
				size_t buff_size = work_buff->m_buff_size;
				char* buff = work_buff->m_buff;
				buff[0] = '\0';
				vsprintf_s(buff, buff_size, caption, args);
				call_point_info = new T_CALL_POINT_INFO(id, type, file_path, timestamp, func_name, file_line, buff);
			}
		}
		if (call_point_info)
		{
			if (!call_point_info_last)
			{
				thread_info->m_call_point_info_top = call_point_info;
			}
			else
			{
				call_point_info_last->m_next = call_point_info;
			}
		}
		else
			id = 0;
		thread_info->m_cs_obj.Release();
		return id;
	}
	bool removeCallPoint(const THREAD_ID thread_id, const CALL_POINT_ID call_point_id)
	{
		T_THREAD_INFO* thread_info = getThread(thread_id);
		if (!thread_info)
			return false;
		bool result = false;
		T_CALL_POINT_INFO* call_point_info_parent = nullptr;
		T_CALL_POINT_INFO* call_point_info = thread_info->m_call_point_info_top;
		while (call_point_info && call_point_info->m_id != call_point_id)
		{
			call_point_info_parent = call_point_info;
			call_point_info = call_point_info->m_next;
		}
		if (call_point_info)
		{
			{
				if (call_point_info_parent)
				{
					call_point_info_parent->m_next = call_point_info->m_next;
				}
				else
				{
					thread_info->m_call_point_info_top = call_point_info->m_next;
				}
			}
			delete call_point_info;
			result = true;
		}
		thread_info->m_cs_obj.Release();
		return result;
	}
	bool removeCallPointAll(const THREAD_ID thread_id)
	{
		T_CALL_POINT_INFO* call_point_info = nullptr;
		{
			T_THREAD_INFO* thread_info = getThread(thread_id);
			if (!thread_info)
				return false;
			call_point_info = thread_info->m_call_point_info_top;
			thread_info->m_call_point_info_top = nullptr;
			thread_info->m_cs_obj.Release();
		}
		while (call_point_info)
		{
			T_CALL_POINT_INFO* call_point_info_next = call_point_info->m_next;
			delete call_point_info;
			call_point_info = call_point_info_next;
		}
		return true;
	}

	T_MESSAGE_BLOCK_INFO* getMessageBlock(T_CALL_POINT_INFO* call_point_info, const MESSAGE_BLOCK_ID message_block_id)//【注】ロック状態でオブジェクトを返すので、明示的にリリースする必要あり
	{
		if (!call_point_info)
			return nullptr;
		T_MESSAGE_BLOCK_INFO* message_block_info = call_point_info->m_message_block_info_top;
		while (message_block_info && message_block_info->m_id != message_block_id)
		{
			message_block_info = message_block_info->m_next;
		}
		if (message_block_info)
			message_block_info->m_cs_obj.Lock();
		return message_block_info;
	}
	MESSAGE_ID addMessageBlock(const THREAD_ID thread_id, const CALL_POINT_ID call_point_id, const E_MESSAGE_RANK rank_default, const TEXT file_path, const TEXT timestamp, const TEXT func_name, const LINE file_line)
	{
		T_THREAD_INFO* thread_info = getThread(thread_id);
		if (!thread_info)
			return 0;
		MESSAGE_BLOCK_ID id = 0;
		T_CALL_POINT_INFO* call_point_info = getCallPoint(thread_info, call_point_id);
		thread_info->m_cs_obj.Release();
		if (call_point_info)
		{
			T_MESSAGE_BLOCK_INFO* message_block_info_last = call_point_info->m_message_block_info_top;
			while (message_block_info_last && message_block_info_last->m_next)
			{
				message_block_info_last = message_block_info_last->m_next;
			}
			if (message_block_info_last)
				id = message_block_info_last->m_id + 1;
			else
				id = 1;
			T_MESSAGE_BLOCK_INFO* message_block_info = new T_MESSAGE_BLOCK_INFO(id, rank_default, file_path, timestamp, func_name, file_line);
			if (message_block_info)
			{
				if (!message_block_info_last)
				{
					call_point_info->m_message_block_info_top = message_block_info;
				}
				else
				{
					message_block_info_last->m_next = message_block_info;
				}
			}
			else
				id = 0;
			call_point_info->m_cs_obj.Release();
		}
		return id;
	}
	bool removeMessageBlock(const THREAD_ID thread_id, const CALL_POINT_ID call_point_id, const MESSAGE_BLOCK_ID message_block_id)
	{
		T_THREAD_INFO* thread_info = getThread(thread_id);
		if (!thread_info)
			return false;
		bool result = false;
		T_CALL_POINT_INFO* call_point_info = getCallPoint(thread_info, call_point_id);
		thread_info->m_cs_obj.Release();
		if (call_point_info)
		{
			T_MESSAGE_BLOCK_INFO* message_block_info_parent = nullptr;
			T_MESSAGE_BLOCK_INFO* message_block_info = call_point_info->m_message_block_info_top;
			while (message_block_info && message_block_info->m_id != message_block_id)
			{
				message_block_info_parent = message_block_info;
				message_block_info = message_block_info->m_next;
			}
			if (message_block_info)
			{
				{
					if (message_block_info_parent)
					{
						message_block_info_parent->m_next = message_block_info->m_next;
					}
					else
					{
						call_point_info->m_message_block_info_top = message_block_info->m_next;
					}
				}
				delete message_block_info;
				result = true;
			}
			call_point_info->m_cs_obj.Release();
		}
		return result;
	}
	bool removeMessageBlockAll(const THREAD_ID thread_id, const CALL_POINT_ID call_point_id)
	{
		T_MESSAGE_BLOCK_INFO* message_block_info = nullptr;
		{
			T_THREAD_INFO* thread_info = getThread(thread_id);
			if (!thread_info)
				return false;
			T_CALL_POINT_INFO* call_point_info = getCallPoint(thread_info, call_point_id);
			thread_info->m_cs_obj.Release();
			if (call_point_info)
			{
				message_block_info = call_point_info->m_message_block_info_top;
				call_point_info->m_message_block_info_top = nullptr;
				call_point_info->m_cs_obj.Release();
			}
		}
		while (message_block_info)
		{
			T_MESSAGE_BLOCK_INFO* message_block_info_next = message_block_info->m_next;
			delete message_block_info;
			message_block_info = message_block_info_next;
		}
		return true;
	}

	T_MESSAGE_INFO* getMessage(T_MESSAGE_BLOCK_INFO* message_block_info, const MESSAGE_ID message_id)//【注】ロック状態でオブジェクトを返すので、明示的にリリースする必要あり
	{
		if (!message_block_info)
			return nullptr;
		T_MESSAGE_INFO* message_info = message_block_info->m_message_info_top;
		while (message_info && message_info->m_id != message_id)
		{
			message_info = message_info->m_next;
		}
		if (message_info)
			message_info->m_cs_obj.Lock();
		return message_info;
	}
	MESSAGE_ID addMessage(const THREAD_ID thread_id, const CALL_POINT_ID call_point_id, const MESSAGE_BLOCK_ID message_block_id, const E_MESSAGE_RANK rank, const LINE file_line, const bool with_call_info, const char* text, va_list args)
	{
		T_THREAD_INFO* thread_info = getThread(thread_id);
		if (!thread_info)
			return 0;
		MESSAGE_ID id = 0;
		T_CALL_POINT_INFO* call_point_info = getCallPoint(thread_info, call_point_id);
		thread_info->m_cs_obj.Release();
		if (call_point_info)
		{
			T_MESSAGE_BLOCK_INFO* message_block_info = getMessageBlock(call_point_info, message_block_id);
			call_point_info->m_cs_obj.Release();
			if (message_block_info)
			{
				T_MESSAGE_INFO* message_info_last = message_block_info->m_message_info_top;
				while (message_info_last && message_info_last->m_next)
				{
					message_info_last = message_info_last->m_next;
				}
				if (message_info_last)
					id = message_info_last->m_id + 1;
				else
					id = 1;
				T_MESSAGE_INFO* message_info = nullptr;
				{
					T_WORK_BUFF* work_buff = getWorkBuff();
					if (work_buff)
					{
					//	const size_t caption_size = _vscprintf(text, args);
					//	const size_t buff_size = buff_size;
					//	char* buff = new char[buff_size];
					//	vsprintf_s(buff, buff_size, text, args);
						CAutoCriticalSection cs(work_buff->m_cs_obj);
						size_t buff_size = work_buff->m_buff_size;
						char* buff = work_buff->m_buff;
						buff[0] = '\0';
						vsprintf_s(buff, buff_size, text, args);
						message_info = new T_MESSAGE_INFO(id, rank, file_line, with_call_info, buff);
					}
				}
				if (message_info)
				{
					if (!message_info_last)
					{
						message_block_info->m_message_info_top = message_info;
					}
					else
					{
						message_info_last->m_next = message_info;
					}
				}
				else
					id = 0;
				message_block_info->m_cs_obj.Release();
			}
		}
		return id;
	}
	bool removeMessage(const THREAD_ID thread_id, const CALL_POINT_ID call_point_id, const MESSAGE_BLOCK_ID message_block_id, const MESSAGE_ID message_id)
	{
		T_THREAD_INFO* thread_info = getThread(thread_id);
		if (!thread_info)
			return false;
		bool result = false;
		T_CALL_POINT_INFO* call_point_info = getCallPoint(thread_info, call_point_id);
		thread_info->m_cs_obj.Release();
		if (call_point_info)
		{
			T_MESSAGE_BLOCK_INFO* message_block_info = getMessageBlock(call_point_info, message_block_id);
			call_point_info->m_cs_obj.Release();
			if (message_block_info)
			{
				T_MESSAGE_INFO* message_info_parent = nullptr;
				T_MESSAGE_INFO* message_info = message_block_info->m_message_info_top;
				while (message_info && message_info->m_id != message_id)
				{
					message_info_parent = message_info;
					message_info = message_info->m_next;
				}
				if (message_info)
				{
					{
						if (message_info_parent)
						{
							message_info_parent->m_next = message_info->m_next;
						}
						else
						{
							message_block_info->m_message_info_top = message_info->m_next;
						}
					}
					delete message_info;
					result = true;
				}
				message_block_info->m_cs_obj.Release();
			}
		}
		return result;
	}
	bool removeMessageAll(const THREAD_ID thread_id, const CALL_POINT_ID call_point_id, const MESSAGE_BLOCK_ID message_block_id)
	{
		T_MESSAGE_INFO* message_info = nullptr;
		{
			T_THREAD_INFO* thread_info = getThread(thread_id);
			if (!thread_info)
				return false;
			T_CALL_POINT_INFO* call_point_info = getCallPoint(thread_info, call_point_id);
			thread_info->m_cs_obj.Release();
			if (call_point_info)
			{
				T_MESSAGE_BLOCK_INFO* message_block_info = getMessageBlock(call_point_info, message_block_id);
				call_point_info->m_cs_obj.Release();
				if (message_block_info)
				{
					message_info = message_block_info->m_message_info_top;
					message_block_info->m_message_info_top = nullptr;
					message_block_info->m_cs_obj.Release();
				}
			}
		}
		while (message_info)
		{
			T_MESSAGE_INFO* message_info_next = message_info->m_next;
			delete message_info;
			message_info = message_info_next;
		}
		return true;
	}

	void printInfo(char* buff, const int buff_size, const T_THREAD_INFO* thread_info, const T_CALL_POINT_INFO*const* call_point_info_list, const int call_point_info_num, const T_MESSAGE_BLOCK_INFO* message_block_info, const T_MESSAGE_INFO* message_info, const bool with_call_info)
	{
		if (with_call_info)
		{
			if (thread_info)
			{
				const char* fmt = "---------------<<CallInfo:Thread=\"%s\">>---------------\n";
				if (buff)
					sprintf_s(buff, buff_size, fmt, thread_info->m_name);
				else
					printf(fmt, thread_info->m_name);
			}
			const T_CALL_POINT_INFO*const* call_point_info_list_pp = call_point_info_list;
			for (int index = 0; index < call_point_info_num; ++index, ++call_point_info_list_pp)
			{
				const T_CALL_POINT_INFO*const call_point_info_list_p = *call_point_info_list_pp;
				const char* fmt = "\"%s\" <T:%s> %s()[%d] \"%s\"(%s)\n";
				if (buff)
					sprintf_s(buff, buff_size, fmt, call_point_info_list_p->m_caption, getTypeName(static_cast<E_CALL_POINT_TYPE>(call_point_info_list_p->m_type)), call_point_info_list_p->m_func_info.m_func_name, call_point_info_list_p->m_func_info.m_file_line, getFileName(call_point_info_list_p->m_func_info.m_file_path), call_point_info_list_p->m_func_info.m_timestamp);
				else
					printf(fmt, call_point_info_list_p->m_caption, getTypeName(static_cast<E_CALL_POINT_TYPE>(call_point_info_list_p->m_type)), call_point_info_list_p->m_func_info.m_func_name, call_point_info_list_p->m_func_info.m_file_line, getFileName(call_point_info_list_p->m_func_info.m_file_path), call_point_info_list_p->m_func_info.m_timestamp);
			}
			if (message_info)
			{
				const char* fmt = "  <R:%s> %s()[%d] \"%s\"(%s)\n    ";
				if (buff)
					sprintf_s(buff, buff_size, fmt, getRankName(static_cast<E_MESSAGE_RANK>(message_info->m_rank)), message_block_info->m_func_info.m_func_name, message_info->m_file_line, getFileName(message_block_info->m_func_info.m_file_path), message_block_info->m_func_info.m_timestamp);
				else
					printf(fmt, getRankName(static_cast<E_MESSAGE_RANK>(message_info->m_rank)), message_block_info->m_func_info.m_func_name, message_info->m_file_line, getFileName(message_block_info->m_func_info.m_file_path), message_block_info->m_func_info.m_timestamp);
			}
		}
		if (message_info)
		{
			const char* fmt = "%s\n";
			if (buff)
				sprintf_s(buff, buff_size, fmt, message_info->m_text);
			else
				printf(fmt, message_info->m_text);
		}
	}
	void printInfo(const T_THREAD_INFO* thread_info, const T_CALL_POINT_INFO*const* call_point_info_list, const int call_point_info_num, const T_MESSAGE_BLOCK_INFO* message_block_info, const T_MESSAGE_INFO* message_info, const bool with_call_info)
	{
		printInfo(NULL, 0, thread_info, call_point_info_list, call_point_info_num, message_block_info, message_info, with_call_info);
	}
	void flushInfo(const THREAD_ID thread_id, const bool is_only_thread, const CALL_POINT_ID call_point_id, const bool is_only_call_point, const MESSAGE_BLOCK_ID message_block_id, const bool is_only_message_block)
	{
		CAutoCriticalSection cs(s_cs_obj);
		T_THREAD_INFO* thread_info = s_thread_info_top;
		while (thread_info)
		{
			thread_info->m_cs_obj.Lock();
			if (!is_only_thread || (is_only_thread && thread_info->m_id == thread_id))
			{
				const int CALL_POINT_INFO_LIST_MAX = 32;
				T_CALL_POINT_INFO* call_point_info_list[CALL_POINT_INFO_LIST_MAX];
				int call_point_info_num = 0;
				T_CALL_POINT_INFO* call_point_info = thread_info->m_call_point_info_top;
				while (call_point_info)
				{
					call_point_info->m_cs_obj.Lock();
					if (!is_only_call_point || (is_only_call_point && call_point_info->m_id == call_point_id))
					{
						const E_CALL_POINT_TYPE type = static_cast<E_CALL_POINT_TYPE>(call_point_info->m_type);
						if (call_point_info_num < CALL_POINT_INFO_LIST_MAX)
							call_point_info_list[call_point_info_num++] = call_point_info;
						T_MESSAGE_BLOCK_INFO* message_block_info = call_point_info->m_message_block_info_top;
						while (message_block_info)
						{
							message_block_info->m_cs_obj.Lock();
							if (!is_only_message_block || (is_only_message_block && message_block_info->m_id == message_block_id))
							{
								T_MESSAGE_INFO* message_info = message_block_info->m_message_info_top;
								while (message_info)
								{
									message_info->m_cs_obj.Lock();
									if (message_info->m_state == STATE_NONE)
									{
										const E_MESSAGE_RANK rank = static_cast<E_MESSAGE_RANK>(message_info->m_rank);
										bool is_print = false;
										for (int index = 0; index < call_point_info_num; ++index)
										{
											if (checkPrintRankMask(static_cast<E_CALL_POINT_TYPE>(call_point_info_list[index]->m_type), rank))
											{
												is_print = true;
												break;
											}
										}
										{
											printInfo(thread_info, call_point_info_list, call_point_info_num, message_block_info, message_info, message_info->m_with_call_info);
										}
										message_info->m_state = STATE_PRINTED;
									}
									T_MESSAGE_INFO* message_info_next = message_info->m_next;
									message_info->m_cs_obj.Release();
									message_info = message_info_next;
								}
							}
							const int curr_message_block_id = message_block_info->m_id;
							T_MESSAGE_BLOCK_INFO* message_block_info_next = message_block_info->m_next;
							message_block_info->m_cs_obj.Release();
							message_block_info = message_block_info_next;
							if (curr_message_block_id == message_block_id)
								break;
						}
					}
					const int curr_call_info_id = call_point_info->m_id;
					T_CALL_POINT_INFO* call_point_info_next = call_point_info->m_next;
					call_point_info->m_cs_obj.Release();
					call_point_info = call_point_info_next;
					if (curr_call_info_id == call_point_id)
						break;
				}
			}
			const int curr_thread_id = thread_info->m_id;
			T_THREAD_INFO* thread_info_next = thread_info->m_next;
			thread_info->m_cs_obj.Release();
			thread_info = thread_info_next;
			if (curr_thread_id == thread_id)
				break;
		}
	}
	void flushMessageBlock(const THREAD_ID thread_id, const bool is_only_thread, const CALL_POINT_ID call_point_id, const bool is_only_call_point, const MESSAGE_BLOCK_ID message_block_id, const bool is_only_message_block)
	{
		flushInfo(thread_id, is_only_thread, call_point_id, is_only_call_point, message_block_id, is_only_message_block);
	}
	void flushMessagesCallPoint(const THREAD_ID thread_id, const bool is_only_thread, const CALL_POINT_ID call_point_id, const bool is_only_call_point)
	{
		flushInfo(thread_id, is_only_thread, call_point_id, is_only_call_point, 0xffffffff, false);
	}
	void flushMessagesThread(const THREAD_ID thread_id, const bool is_only_thread)
	{
		flushInfo(thread_id, is_only_thread, 0xffffffff, false, 0xffffffff, false);
	}
	void flushMessagesAll()
	{
		flushInfo(0xffffffff, false, 0xffffffff, false, 0xffffffff, false);
	}
	
	void initialize()
	{
		s_work_buff = new CWorkBuff(8, 2048);
		s_cs_obj = new CCriticalSection();
		addThread(0, "(unknown)", nullptr);
		addCallPoint(0, TYPE_NONE, "(unknown)", "(unknown)", "(unknown)", 0, "(unknown)", nullptr);
		const MESSAGE_MASK default_print_rank_mask = calcRankMaskBit(RANK_NORMAL) | calcRankMaskBit(RANK_CRITICAL_LV1) | calcRankMaskBit(RANK_CRITICAL_LV2) | calcRankMaskBit(RANK_CRITICAL_LV3);
		const MESSAGE_MASK default_notify_rank_mask = calcRankMaskBit(RANK_CRITICAL_LV1) | calcRankMaskBit(RANK_CRITICAL_LV2) | calcRankMaskBit(RANK_CRITICAL_LV3);
		for (int i = 0; i < TYPE_NUM; ++i)
		{
			s_print_rank_mask[i] = default_print_rank_mask;
			s_notify_rank_mask[i] = default_notify_rank_mask;
		}
	}
	void finalize()
	{
		removeThread(0);
		removeThreadAll();
		delete s_cs_obj;
		delete s_work_buff;
	}

	class CThread
	{
	private:
		const THREAD_ID m_thread_id;
		const char* m_name;
	private:
		explicit CThread() :m_thread_id(0){}
		explicit CThread(CThread&) :m_thread_id(0){}
		explicit CThread(CThread*) :m_thread_id(0){}
	public:
		explicit CThread(const char* name, ...) :
			m_thread_id(getCurrentThreadId()),
			m_name(name)
		{
		//	flushMessagesAll();
			va_list args;
			va_start(args, name);
			addThread(this->m_thread_id, this->m_name, args);
			va_end(args);
		}
		~CThread()
		{
			flushMessagesThread(this->m_thread_id, true);
			removeThread(this->m_thread_id);
		}
	public:
		THREAD_ID getThreadID() const { return this->m_thread_id; }
		const char* const getName() const { return this->m_name; }
	};
	class CCallPoint
	{
	private:
		const THREAD_ID m_thread_id;
		CALL_POINT_ID m_call_point_id;
		CALL_POINT_TYPE m_type;
		const TEXT m_file_path;
		const TEXT m_timestamp;
		const TEXT m_func_name;
		const LINE m_file_line;
	private:
		explicit CCallPoint() :m_thread_id(0), m_file_path(nullptr), m_timestamp(nullptr), m_func_name(nullptr),m_file_line(0){}
		explicit CCallPoint(CCallPoint&) :m_thread_id(0), m_file_path(nullptr), m_timestamp(nullptr), m_func_name(nullptr), m_file_line(0){}
		explicit CCallPoint(CCallPoint*) :m_thread_id(0), m_file_path(nullptr), m_timestamp(nullptr), m_func_name(nullptr), m_file_line(0){}
	public:
		explicit CCallPoint(const E_CALL_POINT_TYPE type, const TEXT file_path, const TEXT timestamp, const TEXT func_name, const LINE file_line, const char* const caption, ...) :
			m_thread_id(getCurrentThreadId()),
			m_call_point_id(0),
			m_type(type),
			m_file_path(file_path),
			m_timestamp(timestamp),
			m_func_name(func_name),
			m_file_line(file_line)
		{
			flushMessagesThread(this->m_thread_id, true);
			va_list args;
			va_start(args, caption);
			this->m_call_point_id = addCallPoint(this->m_thread_id, static_cast<E_CALL_POINT_TYPE>(this->m_type), this->m_file_path, this->m_timestamp, this->m_func_name, this->m_file_line, caption, args);
			va_end(args);
		}
		~CCallPoint()
		{
			flushMessagesCallPoint(this->m_thread_id, true, this->m_call_point_id, false);
			removeCallPoint(this->m_thread_id, this->m_call_point_id);
		}
	public:
		THREAD_ID getThreadID() const { return this->m_thread_id; }
		E_CALL_POINT_TYPE getType() const { return static_cast<E_CALL_POINT_TYPE>(this->m_type); }
		const TEXT getFilePath() const { return this->m_file_path; }
		const TEXT getTimestamp() const { return this->m_timestamp; }
		const TEXT getFuncName() const { return this->m_func_name; }
		LINE getFileLine() const { return this->m_file_line; }
	};
	class CMessageBlock
	{
	private:
		const THREAD_ID m_thread_id;
		CALL_POINT_ID m_call_point_id;
		MESSAGE_BLOCK_ID m_message_block_id;
		MESSAGE_RANK m_rank_default;
		const TEXT m_file_path;
		const TEXT m_timestamp;
		const TEXT m_func_name;
		const LINE m_file_line;
		MESSAGE_RANK m_last_rank;
		LINE m_last_file_line;
		bool m_last_with_call_info;
		MESSAGE_ID m_last_message_id;
	private:
		explicit CMessageBlock() :m_thread_id(0), m_file_path(nullptr), m_timestamp(nullptr), m_func_name(nullptr), m_file_line(0){}
		explicit CMessageBlock(CMessageBlock&) :m_thread_id(0), m_file_path(nullptr), m_timestamp(nullptr), m_func_name(nullptr), m_file_line(0){}
		explicit CMessageBlock(CMessageBlock*) :m_thread_id(0), m_file_path(nullptr), m_timestamp(nullptr), m_func_name(nullptr), m_file_line(0){}
	public:
		explicit CMessageBlock(const E_MESSAGE_RANK rank_default, const TEXT file_path, const TEXT timestamp, const TEXT func_name, const LINE file_line) :
			m_thread_id(getCurrentThreadId()),
			m_call_point_id(0),
			m_message_block_id(0),
			m_rank_default(rank_default),
			m_file_path(file_path),
			m_timestamp(timestamp),
			m_func_name(func_name),
			m_file_line(file_line),
			m_last_rank(RANK_NORMAL),
			m_last_file_line(0),
			m_last_with_call_info(false),
			m_last_message_id(0)
		{
			T_CALL_POINT_INFO* call_point_info = getCallPointLast(this->m_thread_id);
			if (!call_point_info)
				return;
			this->m_call_point_id = call_point_info->m_id;
			flushMessagesCallPoint(this->m_thread_id, true, this->m_call_point_id, false);
			this->m_message_block_id = addMessageBlock(this->m_thread_id, this->m_call_point_id, static_cast<E_MESSAGE_RANK>(this->m_rank_default), this->m_file_path, this->m_timestamp, this->m_func_name, this->m_file_line);
			call_point_info->m_cs_obj.Release();
		}
		~CMessageBlock()
		{
			flushMessageBlock(this->m_thread_id, true, this->m_call_point_id, false, this->m_message_block_id, false);
			removeMessageBlock(this->m_thread_id, this->m_call_point_id, this->m_message_block_id);
		}
	public:
		THREAD_ID getThreadID() const { return this->m_thread_id; }
		CALL_POINT_ID getCallPointID() const { return this->m_call_point_id; }
		MESSAGE_BLOCK_ID getMessageBlockID() const { return this->m_message_block_id; }
		E_MESSAGE_RANK getRankDefault() const { return static_cast<E_MESSAGE_RANK>(this->m_rank_default); }
		const TEXT getFilePath() const { return this->m_file_path; }
		const TEXT getTimestamp() const { return this->m_timestamp; }
		const TEXT getFuncName() const { return this->m_func_name; }
		LINE getFileLine() const { return this->m_file_line; }
		E_MESSAGE_RANK getLastRank() const { return static_cast<E_MESSAGE_RANK>(this->m_last_rank); }
		LINE getLastFileLine() const { return this->m_last_file_line; }
		bool getLastWithCallInfo() const { return this->m_last_with_call_info; }
		MESSAGE_ID getLastMessageID() const { return this->m_last_message_id; }
	public:
		void message(const LINE file_line, const bool with_call_info, const char* const text, ...)
		{
			this->m_last_rank = this->m_rank_default;
			this->m_last_file_line = file_line;
			this->m_last_with_call_info = with_call_info;
			va_list args;
			va_start(args, text);
			this->m_last_message_id = addMessage(this->m_thread_id, this->m_call_point_id, this->m_message_block_id, static_cast<E_MESSAGE_RANK>(this->m_last_rank), this->m_last_file_line, this->m_last_with_call_info, text, args);
			va_end(args);
		}
		void messageWithRank(const E_MESSAGE_RANK rank, const LINE file_line, const bool with_call_info, const char* const text, ...)
		{
			this->m_last_rank = rank;
			this->m_last_file_line = file_line;
			this->m_last_with_call_info = with_call_info;
			va_list args;
			va_start(args, text);
			this->m_last_message_id = addMessage(this->m_thread_id, this->m_call_point_id, this->m_message_block_id, static_cast<E_MESSAGE_RANK>(this->m_last_rank), this->m_last_file_line, this->m_last_with_call_info, text, args);
			va_end(args);
		}
		void changeRankDefault(const E_MESSAGE_RANK rank_default) { this->m_rank_default = rank_default; }
	};
};

#define DEBUG_INITIALIZE() debug::initialize()
#define DEBUG_FINALIZE() debug::finalize()

#define DEBUG_THREAD(name, ...) debug::CThread __debug_thread_obj(name, __VA_ARGS__)

#define DEBUG_CALL_POINT(type, caption, ...) debug::CCallPoint __debug_call_point_obj(type, ___FILE, ___TIMESTAMP, ___FUNC, ___LINE, caption, __VA_ARGS__)

#define DEBUG_MESSAGE_BLOCK(rank) debug::CMessageBlock _debug_message_block_obj(rank, ___FILE, ___TIMESTAMP, ___FUNC, ___LINE);
#define DEBUG_MESSAGE_BLOCK_NORMAL() debug::CMessageBlock _debug_message_block_obj(debug::RANK_NORMAL, ___FILE, ___TIMESTAMP, ___FUNC, ___LINE);
#define DEBUG_MESSAGE_BLOCK_DETAIL() debug::CMessageBlock _debug_message_block_obj(debug::RANK_DETAIL, ___FILE, ___TIMESTAMP, ___FUNC, ___LINE);
#define DEBUG_MESSAGE_BLOCK_DETAIL_LV1() debug::CMessageBlock _debug_message_block_obj(debug::RANK_DETAIL_LV1, ___FILE, ___TIMESTAMP, ___FUNC, ___LINE);
#define DEBUG_MESSAGE_BLOCK_DETAIL_LV2() debug::CMessageBlock _debug_message_block_obj(debug::RANK_DETAIL_LV2, ___FILE, ___TIMESTAMP, ___FUNC, ___LINE);
#define DEBUG_MESSAGE_BLOCK_DETAIL_LV3() debug::CMessageBlock _debug_message_block_obj(debug::RANK_DETAIL_LV3, ___FILE, ___TIMESTAMP, ___FUNC, ___LINE);
#define DEBUG_MESSAGE_BLOCK_CRITICAL() debug::CMessageBlock _debug_message_block_obj(debug::RANK_CRITICAL, ___FILE, ___TIMESTAMP, ___FUNC, ___LINE);
#define DEBUG_MESSAGE_BLOCK_CRITICAL_LV1() debug::CMessageBlock _debug_message_block_obj(debug::RANK_CRITICAL_LV1, ___FILE, ___TIMESTAMP, ___FUNC, ___LINE);
#define DEBUG_MESSAGE_BLOCK_CRITICAL_LV2() debug::CMessageBlock _debug_message_block_obj(debug::RANK_CRITICAL_LV2, ___FILE, ___TIMESTAMP, ___FUNC, ___LINE);
#define DEBUG_MESSAGE_BLOCK_CRITICAL_LV3() debug::CMessageBlock _debug_message_block_obj(debug::RANK_CRITICAL_LV3, ___FILE, ___TIMESTAMP, ___FUNC, ___LINE);

#define DEBUG_MESSAGE_CHANGE_RANK(rank) _debug_message_block_obj.changeRank(rank);

#define DEBUG_MESSAGE(text, ...) _debug_message_block_obj.message(___LINE, false, text, __VA_ARGS__);
#define DEBUG_MESSAGE_WITH_RANK(rank, text, ...) _debug_message_block_obj.messageWithRank(rank, ___LINE, false, text, __VA_ARGS__);
#define DEBUG_MESSAGE_NORMAL(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_NORMAL, rank, ___LINE, false, text, __VA_ARGS__);
#define DEBUG_MESSAGE_DETAIL(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_DETAIL, rank, ___LINE, false, text, __VA_ARGS__);
#define DEBUG_MESSAGE_DETAIL_LV1(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_DETAIL_LV1, rank, ___LINE, false, text, __VA_ARGS__);
#define DEBUG_MESSAGE_DETAIL_LV2(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_DETAIL_LV2, rank, ___LINE, false, text, __VA_ARGS__);
#define DEBUG_MESSAGE_DETAIL_LV3(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_DETAIL_LV3, rank, ___LINE, false, text, __VA_ARGS__);
#define DEBUG_MESSAGE_CRITICAL(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_CRITICAL, rank, ___LINE, false, text, __VA_ARGS__);
#define DEBUG_MESSAGE_CRITICAL_LV1(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_CRITICAL_LV1, rank, ___LINE, false, text, __VA_ARGS__);
#define DEBUG_MESSAGE_CRITICAL_LV2(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_CRITICAL_LV2, rank, ___LINE, false, text, __VA_ARGS__);
#define DEBUG_MESSAGE_CRITICAL_LV3(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_CRITICAL_LV3, rank, ___LINE, false, text, __VA_ARGS__);

#define DEBUG_CALL_INFO(text, ...) _debug_message_block_obj.message(___LINE, true, text, __VA_ARGS__);
#define DEBUG_CALL_INFO_WITH_RANK(rank, text, ...) _debug_message_block_obj.messageWithRank(rank, ___LINE, true, text, __VA_ARGS__);
#define DEBUG_CALL_INFO_NORMAL(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_NORMAL, rank, ___LINE, true, text, __VA_ARGS__);
#define DEBUG_CALL_INFO_DETAIL(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_DETAIL, rank, ___LINE, true, text, __VA_ARGS__);
#define DEBUG_CALL_INFO_DETAIL_LV1(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_DETAIL_LV1, rank, ___LINE, true, text, __VA_ARGS__);
#define DEBUG_CALL_INFO_DETAIL_LV2(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_DETAIL_LV2, rank, ___LINE, true, text, __VA_ARGS__);
#define DEBUG_CALL_INFO_DETAIL_LV3(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_DETAIL_LV3, rank, ___LINE, true, text, __VA_ARGS__);
#define DEBUG_CALL_INFO_CRITICAL(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_CRITICAL, rank, ___LINE, true, text, __VA_ARGS__);
#define DEBUG_CALL_INFO_CRITICAL_LV1(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_CRITICAL_LV1, rank, ___LINE, true, text, __VA_ARGS__);
#define DEBUG_CALL_INFO_CRITICAL_LV2(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_CRITICAL_LV2, rank, ___LINE, true, text, __VA_ARGS__);
#define DEBUG_CALL_INFO_CRITICAL_LV3(text, ...) _debug_message_block_obj.messageWithRank(debug::RANK_CRITICAL_LV3, rank, ___LINE, true, text, __VA_ARGS__);

#define DEBUG_PRINT_TEST() printf("DEBUG_PRINT_TEST:__FILE__=\"%s\", __TIMESTAMP__=\"%s\", __DATE__=\"%s\", __TIME__=\"%s\", __LINE__=%d, __FUNCDNAME__=\"%s\", __FUNCSIG___=\"%s\", __FUNCTION__=\"%s\"\n", __FILE__, __TIMESTAMP__, __DATE__, __TIME__, __LINE__, __FUNCDNAME__, __FUNCSIG___, __FUNCTION__);

#else//DEBUG_MODE_ENABLED

#define DEBUG_INITIALIZE()
#define DEBUG_FINALIZE()

#define DEBUG_THREAD(name, ...)

#define DEBUG_CALL_POINT(type, caption, ...)

#define DEBUG_MESSAGE_BLOCK(rank)
#define DEBUG_MESSAGE_BLOCK_NORMAL()
#define DEBUG_MESSAGE_BLOCK_DETAIL()
#define DEBUG_MESSAGE_BLOCK_DETAIL_LV1()
#define DEBUG_MESSAGE_BLOCK_DETAIL_LV2()
#define DEBUG_MESSAGE_BLOCK_DETAIL_LV3()
#define DEBUG_MESSAGE_BLOCK_CRITICAL()
#define DEBUG_MESSAGE_BLOCK_CRITICAL_LV1()
#define DEBUG_MESSAGE_BLOCK_CRITICAL_LV2()
#define DEBUG_MESSAGE_BLOCK_CRITICAL_LV3()

#define DEBUG_MESSAGE_CHANGE_RANK(rank)

#define DEBUG_MESSAGE(message, ...)
#define DEBUG_MESSAGE_WITH_RANK(rank, message, ...)
#define DEBUG_MESSAGE_NORMAL(message, ...)
#define DEBUG_MESSAGE_DETAIL(message, ...)
#define DEBUG_MESSAGE_DETAIL_LV1(message, ...)
#define DEBUG_MESSAGE_DETAIL_LV2(message, ...)
#define DEBUG_MESSAGE_DETAIL_LV3(message, ...)
#define DEBUG_MESSAGE_CRITICAL(message, ...)
#define DEBUG_MESSAGE_CRITICAL_LV1(message, ...)
#define DEBUG_MESSAGE_CRITICAL_LV2(message, ...)
#define DEBUG_MESSAGE_CRITICAL_LV3(message, ...)

#define DEBUG_CALL_INFO(message, ...)
#define DEBUG_CALL_INFO_WITH_RANK(rank, message, ...)
#define DEBUG_CALL_INFO_NORMAL(message, ...)
#define DEBUG_CALL_INFO_DETAIL(message, ...)
#define DEBUG_CALL_INFO_DETAIL_LV1(message, ...)
#define DEBUG_CALL_INFO_DETAIL_LV2(message, ...)
#define DEBUG_CALL_INFO_DETAIL_LV3(message, ...)
#define DEBUG_CALL_INFO_CRITICAL(message, ...)
#define DEBUG_CALL_INFO_CRITICAL_LV1(message, ...)
#define DEBUG_CALL_INFO_CRITICAL_LV2(message, ...)
#define DEBUG_CALL_INFO_CRITICAL_LV3(message, ...)

#define DEBUG_PRINT_TEST()

#endif//DEBUG_MODE_ENABLED

class CTest
{
public:
	void test()
	{
		DEBUG_MESSAGE_BLOCK_NORMAL();
		DEBUG_MESSAGE("TEST");
	}
};

void common_func()
{
	DEBUG_MESSAGE_BLOCK_NORMAL();
	DEBUG_CALL_INFO("COMMON");
}

void sub()
{
	DEBUG_CALL_POINT(debug::TYPE_SYSTEM, "TEST1_1");
	DEBUG_MESSAGE_BLOCK_NORMAL();
	DEBUG_CALL_INFO("TEST1_1:START");
	common_func();
	{
		DEBUG_CALL_POINT(debug::TYPE_SYSTEM, "TEST1_2");
		DEBUG_MESSAGE_BLOCK_NORMAL();
		DEBUG_CALL_INFO("TEST1_2:START");
		common_func();
		{
			DEBUG_CALL_POINT(debug::TYPE_SYSTEM, "TEST1_3");
			DEBUG_MESSAGE_BLOCK_NORMAL();
			DEBUG_CALL_INFO("TEST1_3:START");
			common_func();
			{
				DEBUG_CALL_POINT(debug::TYPE_SYSTEM, "TEST1_4");
				DEBUG_MESSAGE_BLOCK_NORMAL();
				DEBUG_CALL_INFO("TEST1_4:START");
				common_func();
				{
					DEBUG_CALL_POINT(debug::TYPE_SYSTEM, "TEST1_5");
					DEBUG_MESSAGE_BLOCK_NORMAL();
					DEBUG_CALL_INFO("TEST1_5:START");
					common_func();
					{
						DEBUG_CALL_POINT(debug::TYPE_SYSTEM, "TEST1_6");
						DEBUG_MESSAGE_BLOCK_NORMAL();
						DEBUG_CALL_INFO("TEST1_6:START");
						common_func();
						{
							DEBUG_CALL_POINT(debug::TYPE_SYSTEM, "TEST1_7");
							DEBUG_MESSAGE_BLOCK_NORMAL();
							DEBUG_CALL_INFO("TEST1_7:START");
							common_func();
							DEBUG_CALL_INFO("TEST1_7:END");
						}
						common_func();
						DEBUG_CALL_INFO("TEST1_6:END");
					}
					common_func();
					DEBUG_CALL_INFO("TEST1_5:END");
				}
				common_func();
				DEBUG_CALL_INFO("TEST1_4:END");
			}
			common_func();
			DEBUG_CALL_INFO("TEST1_3:END");
		}
		common_func();
		DEBUG_CALL_INFO("TEST1_2:END");
	}
	common_func();
	DEBUG_CALL_INFO("TEST1_1:END");
}
void sub(const char* const message)
{
	DEBUG_CALL_POINT(debug::TYPE_SYSTEM, message);
	DEBUG_MESSAGE_BLOCK_NORMAL();
	DEBUG_MESSAGE("sub(message):START");
	common_func();
	DEBUG_MESSAGE("sub(message):END");
}

void special_sub()
{
	DEBUG_CALL_POINT(debug::TYPE_SYSTEM, "SPECIAL!");
	DEBUG_MESSAGE_BLOCK_NORMAL();
	DEBUG_MESSAGE("special_sub:START");
	common_func();
	CTest test;
	test.test();
	DEBUG_MESSAGE("special_sub:END");
}

void thread(const char* name)
{
	DEBUG_THREAD(name);
	DEBUG_CALL_POINT(debug::TYPE_SYSTEM, "TEST : \"%s\" %d %ld %d", "abc", 123, 456L, 789);
	DEBUG_MESSAGE_BLOCK_NORMAL();
	DEBUG_MESSAGE("<START>");
	common_func();
	sub();
	sub("TEST2-A");
	sub("TEST2-B");
	special_sub();
	common_func();
	DEBUG_MESSAGE("<END>");
}

int main(const int argc, const char* argv[])
{
	DEBUG_INITIALIZE();
	printf("- Test : Start -\n");
	thread("TEST1");
	printf("- Test : End -\n");
	DEBUG_FINALIZE();
	return EXIT_SUCCESS;
}

// End of file
