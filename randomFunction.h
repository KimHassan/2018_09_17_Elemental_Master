#include "singletonBase.h"
#include <time.h>

//난수 발생용 매크로 객체
class randomFunction : public singletonBase < randomFunction >
{
public:
	//생성자
	randomFunction()
	{
		//srand(time(NULL))
		srand(GetTickCount());
	}
	~randomFunction()
	{

	}

	inline int getInt(int num) { return rand() % num; }
	inline int getFromIntTo(int fromNum, int toNum) { return rand() % (toNum - fromNum + 1) + fromNum; }

};