#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//std::size_t�p
#include <bitset>//std::bitset�p

//#define FOR_UNIX//UNIX�łŃR���p�C������Ƃ��́A���̃}�N����L��������
#ifdef FOR_UNIX
#include "../StaticCRC32_unix/constexpr.h"
#else//FOR_UNIX
#include "../../StaticCRC32/StaticCRC32/src/constexpr/constexpr.h"
#endif//FOR_UNIX

//--------------------------------------------------------------------------------
//�y�����^�C���Łz�f���v�Z

//�y�����^�C���Łz�f������
bool isPrime(const std::size_t n)
{
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else if ((n & 0x1) == 0x0)//��������
		return false;
	for (std::size_t div = 3; div <= n / div; div += 2)
	{
		if (n % div == 0)
			return false;
	}
	return true;
}
//�y�����^�C���Łz�O�̑f���𐶐�
std::size_t makePrimePrev(const std::size_t n)
{
	if (n <= 2)
		return 0;
	else if (n == 3)
		return 2;
	for (std::size_t nn = n - ((n & 0x1) == 0x0 ? 1 : 2);; nn -= 2)//�������͔��肵�Ȃ�
	{
		if (isPrime(nn))
			return nn;
	}
	return 0;//dummy
}
//�y�����^�C���Łz���̑f���𐶐�
std::size_t makePrimeNext(const std::size_t n)
{
	if (n < 2)
		return 2;
	for (std::size_t nn = n + ((n & 0x1) == 0x0 ? 1 : 2);; nn += 2)//�������͔��肵�Ȃ�
	{
		if (isPrime(nn))
			return nn;
	}
	return 0;//dummy
}
//�y�����^�C���Łz�w��̒l�Ɠ������A�O�̑f���𐶐�
std::size_t makePrimeEqPrev(const std::size_t n)
{
	return isPrime(n) ? n : makePrimePrev(n);
}
//�y�����^�C���Łz�w��̒l�Ɠ������A���̑f���𐶐�
std::size_t makePrimeEqNext(const std::size_t n)
{
	return isPrime(n) ? n : makePrimeNext(n);
}

//--------------------------------------------------------------------------------
//�y���^�v���O���~���O�Łz�f���v�Z

//�y���Ӂz
// ���^�v���O���~���O�łł́A�R���p�C���ɉ����ăe���v���[�g�̍ċA���x���̌��E������B
// ���̂��߁A���� 100001 ���炢�܂ł̑f�����������Ȃ��_�ɒ��ӁB
// ���̃e���v���[�g���Ŏg���ƁA�����Ɛ�����󂯂�_�ɂ����ӁB
// �܂��A�R���p�C�����Ԃɉe��������_�ɂ����ӁB

//�y���^�v���O���~���O�ŁF���ʏ����z�Œ�l��Ԃ��N���X
template<typename T, T V>
struct _primeMeta_Fixed{//�Œ�l(V)�̂��߂̃N���X �����Z�N���X�̌��ʂ𓾂�Ƃ��ƈ�l�̗p�@�iclass_name::value�j���K�v�Ȃ���
	static const T value = V;
};

//�y���^�v���O���~���O�ŁF���ʏ����z�O�����Z�q����ɏ�������Ɋ�Â��Ēl��Ԃ��N���X
template <typename T, bool COND, class TRUE_VALUE, class FALSE_VALUE>
struct _primeMeta_EnalbeIf;
template <typename T, class TRUE_VALUE, class FALSE_VALUE>//�����茋�ʂ�true�̎��p�̓��ꉻ
struct _primeMeta_EnalbeIf<T, true, TRUE_VALUE, FALSE_VALUE>{
	static const T value = TRUE_VALUE::value;
};
template <typename T, class TRUE_VALUE, class FALSE_VALUE>//�����茋�ʂ�false�̎��p�̓��ꉻ
struct _primeMeta_EnalbeIf<T, false, TRUE_VALUE, FALSE_VALUE>{
	static const T value = FALSE_VALUE::value;
};

//�y���^�v���O���~���O�Łz�f������
//�������̔��������邽�߂ɊK�w������
template <std::size_t N, std::size_t DIV>//�ċA�N���X
struct _isPrimeMeta{
	static const bool value =
			_primeMeta_EnalbeIf<bool, (DIV > N / DIV),
				_primeMeta_Fixed<bool, true>,
				_primeMeta_EnalbeIf<bool, (N % DIV == 0),
					_primeMeta_Fixed<bool, false>,
					_isPrimeMeta<N, DIV + 2>
			>
		>::value;
};
template <std::size_t N>//�f������N���X
struct isPrimeMeta{
	static const bool value =
		_primeMeta_EnalbeIf<bool, (N & 0x1) == 0x0,
			_primeMeta_Fixed<bool, false>,
			_isPrimeMeta<N, 3>
		>::value;
};
template <>
struct isPrimeMeta<0>{
	static const bool value = false;
};
template <>
struct isPrimeMeta<1>{
	static const bool value = false;
};
template <>
struct isPrimeMeta<2>{
	static const bool value = true;
};

//�y���^�v���O���~���O�Łz�O�̑f���𐶐�
//�������̔��������邽�߂ɊK�w������
template<std::size_t N>//�ċA�N���X
struct _makePrimePrevMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			_makePrimePrevMeta<N - 2>
		>::value;
};
template<std::size_t N>//�O�̑f�������N���X
struct makePrimePrevMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, (N & 0x1) == 0x0,
			_makePrimePrevMeta<N - 1>,
			_makePrimePrevMeta<N - 2>
		>::value;
};
template<>
struct makePrimePrevMeta<0>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<1>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<2>{
	static const std::size_t value = 0;
};
template<>
struct makePrimePrevMeta<3>{
	static const std::size_t value = 2;
};

//�y���^�v���O���~���O�Łz���̑f���𐶐�
//�������̔��������邽�߂ɊK�w������
template<std::size_t N>//�ċA�N���X
struct _makePrimeNextMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			_makePrimeNextMeta<N + 2>
		>::value;
};
template<std::size_t N>//���̑f�������N���X
struct makePrimeNextMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, (N & 0x1) == 0x0,
			_primeMeta_Fixed<std::size_t, N + 1>,
			_makePrimeNextMeta<N + 2>
		>::value;
};
template<>
struct makePrimeNextMeta<0>{
	static const std::size_t value = 2;
};
template<>
struct makePrimeNextMeta<1>{
	static const std::size_t value = 2;
};

//�y���^�v���O���~���O�Łz�w��̒l�Ɠ������A�O�̑f���𐶐�
template<std::size_t N>
struct makePrimeEqPrevMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			makePrimePrevMeta<N>
		>::value;
};

//�y���^�v���O���~���O�Łz�w��̒l�Ɠ������A���̑f���𐶐�
template<std::size_t N>
struct makePrimeEqNextMeta{
	static const std::size_t value =
		_primeMeta_EnalbeIf<std::size_t, isPrimeMeta<N>::value,
			_primeMeta_Fixed<std::size_t, N>,
			makePrimeNextMeta<N>
		>::value;
};

//--------------------------------------------------------------------------------
//�n�b�V���e�[�u��
template <class T, typename KEY_TYPE, std::size_t N>
class hash_table
{
public:
	static const std::size_t ORIGINAL_TABLE_SIZE = N;//�e�[�u���T�C�Y�i���X�w�肳�ꂽ�T�C�Y�j
	static const std::size_t TABLE_SIZE = makePrimeEqNextMeta<N>::value;//�e�[�u���T�C�Y�i�w��T�C�Y�Ɠ������A������傫���f���j
	static const std::size_t PRIME = makePrimePrevMeta<N>::value;//�n�b�V���L�[�����p�f���i�w��T�C�Y��菬�����f���j
public:
	//�t�B�[���h
	std::size_t getOriginalTableSize() const { return ORIGINAL_TABLE_SIZE; }
	std::size_t getTableSize() const { return TABLE_SIZE; }
	std::size_t getPrime() const { return PRIME; }
public:
	//���\�b�h
	inline std::size_t calcNextHash(const std::size_t hash) const { return (hash + PRIME) % TABLE_SIZE; }//���̃n�b�V���l���v�Z
public:
	//�R���X�g���N�^
	hash_table():
		m_deleted(),
		m_used(0),
		m_maxSearch(0)
	{}
	//�f�X�g���N�^
	~hash_table()
	{}
private:
	T m_table[TABLE_SIZE];//�f�[�^�e�[�u��
	KEY_TYPE m_keyTable[TABLE_SIZE];//�L�[�e�[�u��
	std::bitset<TABLE_SIZE> m_deleted;//�폜�ς݃t���O
	std::size_t m_used;//�g�p���f�[�^��
	std::size_t m_maxSearch;//�ő匟���� ���o�^���폜���Ă�����Ȃ�
};

//--------------------------------------------------------------------------------
//�e�X�g

//�y�����^�C���Łz�f���\��
void printPrime(const std::size_t min, const std::size_t max)
{
	if (max > min)
		printPrime(min, max - 1);
	printf("%3d is %s [prev=%d(%d), next=%d(%d)]\n", max, isPrime(max) ? "PRIME.    " : "not prime.", makePrimePrev(max), makePrimeEqPrev(max), makePrimeNext(max), makePrimeEqNext(max));
}

//�y���^�v���O���~���O�Łz�f���\��
template<std::size_t N>
void _printPrimeCommon()
{
	printf("%3d is %s [prev=%d(%d), next=%d(%d)]\n", N, isPrimeMeta<N>::value ? "PRIME.    " : "not prime.", makePrimePrevMeta<N>::value, makePrimeEqPrevMeta<N>::value, makePrimeNextMeta<N>::value, makePrimeEqNextMeta<N>::value);
}
template<std::size_t MIN, std::size_t MAX>
struct printPrimeMeta{
	void operator()()
	{
		printPrimeMeta<MIN, MAX - 1>()();
		_printPrimeCommon<MAX>();
	}
};
template<std::size_t MIN>
struct printPrimeMeta<MIN, MIN>{
	void operator()()
	{
		_printPrimeCommon<MIN>();
	}
};

//----------------------------------------
//�e�X�g���C��
int main(const int argc, const char* argv[])
{
#if 0
	//�ċA���x�����E�`�F�b�N
	static const std::size_t x = 9999;
	printf("x=%d\n", x);
	printf("  isPrime=%s\n", isPrimeMeta<x>::value ? "true" : "False");
	printf("  prev=%d\n", makePrimePrevMeta<x>::value);
	printf("  next=%d\n", makePrimeNextMeta<x>::value);
	printf("  equalPrev=%d\n", makePrimeEqPrevMeta<x>::value);
	printf("  equalNext=%d\n", makePrimeEqNextMeta<x>::value);
#endif
#if 1
	static const std::size_t MIN = 9970;
	static const std::size_t MAX = 10020;
	
	printf("----- Check and Make Prime for Runtime -----\n");
	printPrime(MIN, MAX);
	
	printf("----- Check and Make Prime for Meta-Programming -----\n");
	printPrimeMeta<MIN, MAX>()();
	
	printf("----- Hash Table -----\n");
	static const size_t TABLE_SIZE = 1024;//1031;
	hash_table<int, int, TABLE_SIZE> table;
	printf("hash_table: .getOriginalTableSize()=%u, .getTableSize()=%u, .getPrime()=%u\n", table.getOriginalTableSize(), table.getTableSize(), table.getPrime());
	
	//�n�b�V���e�[�u���e�X�g
	//���S�Ẵn�b�V���l���A���m�Ƀe�[�u���T�C�Y�i�f���j��̍Čv�Z�i�n�b�V���l��ύX����j���s�����ŁA���̃n�b�V���l�ɖ߂邱�Ƃ��`�F�b�N����B
	int ng_count = 0;
	for (int hash = 0; hash < TABLE_SIZE; ++hash)
	{
		std::size_t count = 0;
		int next_hash = hash;
		do
		{
			next_hash = table.calcNextHash(next_hash);
			++count;
		} while (next_hash != hash && count < table.getTableSize());
		if (count != table.getTableSize())
		{
			printf("%d is OUT! (count=%d)\n", hash, count);
			++ng_count;
		}
	}
	printf("Chek Hash Table: NG=%d/%d\n", ng_count, TABLE_SIZE);
#endif
	return EXIT_SUCCESS;
}

// End of file
