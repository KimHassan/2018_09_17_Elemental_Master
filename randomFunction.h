#include "singletonBase.h"
#include <time.h>

//���� �߻��� ��ũ�� ��ü
class randomFunction : public singletonBase < randomFunction >
{
public:
	//������
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