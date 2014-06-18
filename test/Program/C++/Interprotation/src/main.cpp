#include <stdio.h>
#include <stdlib.h>

#include <algorithm>//std::min用

//--------------------------------------------------------------------------------
//フェード処理クラス
//※線形補間
class linear_fade
{
public:
	//アクセッサ
	inline float begin() const { return m_begin; }//開始値
	inline float end() const { return m_end; }//終了値
	inline float difference() const { return m_end - m_begin; }//差
	inline float time() const { return m_time; }//時間
	inline float gradient() const { return difference() / m_time; }//傾き
	inline float t() const { return m_t; }//進行度
	inline float remain_t() const { return 1.f - m_t; }//進行度の残り
	inline float progress_time() const { return m_time * m_t; }//進行時間
	inline float remain_time() const { return m_time * (1.f - m_t); }//進行時間の残り
	inline float now() const { return m_now; }//現在値
	bool isGoal() const { return m_t == 1.f; }//ゴールに達しているか？

public:
	//メソッド

	//更新処理
	void update(const float elapsed_time)
	{
		if (!isGoal())
		{
			const float now_time = m_time * m_t + elapsed_time;//時間を進める
			m_t = std::min(now_time / m_time, 1.f);//進行度を算出
			m_now = m_begin * (1.f - m_t) + m_end * m_t;//現在の値を更新（線形補間）
		}
	}
	//フェード開始
	void start(const float time, const float begin, const float end)
	{
		m_begin = begin;
		m_end = end;
		m_time = time;
		adjust();
	}
	//現在値を強制変更
	void setNow(const float now)
	{
		m_now = now;
		adjust();
	}
private:
	//現在値に基づいて進行度を逆算・調整する
	void adjust()
	{
		if (m_begin == m_end || m_now == m_end)
		{
			m_t = 1.f;
			m_now = m_end;
		}
		else if (m_now == m_begin)
			m_t = 0.f;
		else
		{
			m_t = (m_now - m_begin) / (m_end - m_begin);//線形補間の逆算
			//計算結果の調整
			if (m_t < 0.f)
			{
				m_t = 0.f;
				m_now = m_begin;
			}
			else if (m_t > 1.f)
			{
				m_t = 1.f;
				m_now = m_end;
			}
		}
	}
public:
	//現在の状態を表示
	void debugPrint(const int flame)
	{
		//printf("%2d: now=%.3f, begin=%.3f, end=%.3f, diff=%.3f, time=%.3f, gradient=%.3f, t=%.3f, remain_t=%.3f, progress_time=%.3f, remain_time=%.3f, isGoal()=%s\n", flame, now(), begin(), end(), difference(), time(), gradient(), t(), remain_t(), progress_time(), remain_time(), isGoal() ? "true" : "false");
		printf("%2d: now=%.3f, begin=%.3f, end=%.3f, time=%.3f, t=%.3f, isGoal()=%s\n", flame, now(), begin(), end(), time(), t(), isGoal() ? "true" : "false");
	}
public:
	//コンストラクタ
	linear_fade(const float now = 0.f) :
		m_begin(0.f),
		m_end(0.f),
		m_time(0.f),
		m_t(0.f),
		m_now(now)
	{}
private:
	//フィールド
	float m_begin;//開始値
	float m_end;//終了値
	float m_time;//時間
	float m_t;//進行度（進行時間）
	float m_now;//現在の状態
};

//テスト
void test()
{
	const float fps = 30.f;//30fps想定
	const float elapsed_time = 1.f / fps;//1フレーム当たりの進行時間
	printf("frames per second = %.0f, elapsed time per frame = %.3f\n", fps, elapsed_time);
	int flame = 0;

	//フェードオブジェクトを初期化
	linear_fade fade(1.f);//初期値は1.f

	//フェード開始
	fade.start(1.5f, 1.f, 0.5f);//1.5秒かけて、最大(1.0）から半分（0.5）までフェード
	
	//20フレームだけ更新
	for (int i = 0; i < 20; ++i)
	{
		fade.debugPrint(flame++);
		fade.update(elapsed_time);//更新処理
	}

	//フェードを途中変更
	fade.start(1.5f, 0.5f, 1.f);//1.5秒かけて、半分（0.5）から最大(1.0）までフェード

	//フェード完了まで更新
	while (!fade.isGoal())
	{
		fade.debugPrint(flame++);
		fade.update(elapsed_time);//更新処理
	}
	fade.debugPrint(flame);
}

//--------------------------------------------------------------------------------
//テスト
int main(const int argc, const char* argv[])
{
	test();

	return EXIT_SUCCESS;
}

// End of file
