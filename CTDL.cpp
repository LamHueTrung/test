#include <stdio.h>
 // c�u 3a
typedef struct khach_hang
{
	int ma_so;
	char ho_ten[50];
	bool phai_nam; 
	float so_tien;
} KHACH_HANG;

typedef struct NODE
{
	KHACH_HANG info;
	NODE *pNext;
} NODE;

typedef struct LIST
{
	NODE *pHead;
	NODE * pTail;
} LIST;

// C�u 3b
void Cau_3b(LIST &l) 
{
	for(NODE *p = l.pHead; p != NULL; p = p->pNext)
		if(p->info.phai_nam == true)
			printf("%d", p->info.ma_so);
}

// C�u 3c
void Cau_3c(LIST &l)
{
	for(NODE *p = l.pHead; p != NULL)
	{
		NODE *k = NULL;
		
		while(p != NULL)
		{
			if (p->info.so_tien < 10000) break;
			k = p;
			p = p->pNext;
		}
	
		if(k != NULL)
		{
			if(p == l.pTail)
				l.pTail = k;
			k->pNext = p->pNext;
			delete p;
		} else
		{
			l.pHead = p->pNext;
			delete p;
			if(l.pHead == NULL)
				l.pTail = NULL;
			
		}
		p = k->pNext;
	}

}
