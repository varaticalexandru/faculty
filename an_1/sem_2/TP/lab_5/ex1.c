#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef enum unitate_masura{
	UMBucata,
	UMKg
} selector;

// articol/structura cu variante
typedef struct produs {
	// selector: unitate de masura ('b' - la bucata, 'k' - kilograme);
	selector um;

	// union
	union {
		int n_bucati;
		double kg;
	} c;			// cantitate
} produs;

void AfisareStruct(produs* p)
{
	switch (p->um)
	{
	case UMBucata:
		printf("Nr. bucati: %d\n", p->c.n_bucati);
	break;

	case UMKg:
		printf("Kilograme: %.2f\n", p->c.kg);
	break;

	default:
		printf("Unitate de masura invalida\n");
		break;
	}
}

void Introducere(produs* p)
{
	
	printf("Unitatea de masura ('0' - bucata sau '1' - kilogram) : ");
	scanf("%d", &p->um);

	switch (p->um)
	{
	case UMBucata:
	{
		printf("Introduceti nr. de bucati: ");
		scanf("%d", &p->c.n_bucati);
	}
	break;

	case UMKg:
	{
		printf("Introduceti nr. de kilograme: ");
		scanf("%lf", &p->c.kg);
	}
	break;

	default:
		printf("Unitate de masura invalida !\n");
		break;
	}
}

int main(int argc, char** argv)
{
	produs p;
	
	Introducere(&p);
	AfisareStruct(&p);


	_getch();
	return 0;
}