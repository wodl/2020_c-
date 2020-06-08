#include <iostream>
using namespace std;

class Gun
{
	int bullet;
public:
	Gun(int bnum) : bullet(bnum){}
	void Shot()
	{
		cout << "BBANG" << endl;
		bullet--;
	}
};

class Police
{
	int handcuffs;
	Gun * pistol;
public:
	Police(int bnum, int bcuff) : handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}

	Police(Police& ref): handcuffs(ref.handcuffs)
	{
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;
	}
	Police& operator= (const Police& ref)
	{
		handcuffs = ref.handcuffs;
		if (pistol != NULL)
			delete pistol;
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;

		return *this;

	}

	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main()
{
	Police pman1(5, 3);
	Police pman2 = pman1;
	pman2.PutHandcuff();
	pman2.Shot();

	Police pman3(2, 4);
	pman3 = pman1;
	pman3.PutHandcuff();
	pman3.Shot();
	return 0;
}