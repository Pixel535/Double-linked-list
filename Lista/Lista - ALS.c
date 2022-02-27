#include <stdio.h>
#include <stdlib.h>

int losuj(int min, int max)
{
	return (rand()%(max-min+1)+min);
}

typedef struct Lista{
    int numer;
    struct Lista *next;
    struct Lista *prev;
    struct Lista *mostW;
    int Nmost;
};

struct Lista *head;
struct Lista *tail;
struct Lista *head2;
struct Lista *tail2;
struct Lista *most;

void push()
{
   int min = 1;
   int max = 2000;
   int z = losuj(min, max);
   struct Lista *link, *link2, *mostL;
   link = (struct Lista *) malloc(sizeof(struct Lista));
   link2 = (struct Lista *) malloc(sizeof(struct Lista));
   mostL = (struct Lista *) malloc(sizeof(struct Lista));
   if(z % 2 == 0)
   {
            link->numer=z;
            mostL->Nmost=z;
            if(head == NULL)
            {
                if(head2 == NULL)
                {
                    head = link;
                    link -> next = head;
                    link -> prev = head;
                    tail = link;
                    link -> next = tail;
                    link -> prev = tail;
                }
                else
                {
                    head = link;
                    link -> next = head;
                    link -> prev = head;

                    most = mostL;
                    mostL->next = head;
                    mostL->prev = tail2;

                    tail2->mostW=most;
                    head->mostW=most;

                    most->numer = most->next->numer;

                }
            }

            else
            {
                tail = head;
                while(tail->next !=head)
                {
                    tail = tail->next;
                }
                tail->next = link;
                link->prev = tail;
                head -> prev = link;
                link -> next = head;
                tail = link;
            }
            printf("Dodano Liczbe do listy A: %d\n", z);
    }
    else if(z % 2 != 0)
    {
            link2->numer=z;
            if(head2 == NULL)
            {
                if(head == NULL)
                {
                head2 = link2;
                link2 -> next = head2;
                link2 -> prev = head2;
                tail2 = link2;
                link2 -> next = tail2;
                link2 -> prev = tail2;
                }
                else
                {
                    head2 = link2;
                    link2 -> next = head2;
                    link2 -> prev = head2;

                    most = mostL;
                    mostL->next = head2;
                    mostL->prev = tail;

                    tail->mostW=most;
                    head2->mostW=most;

                    most->numer = most->next->numer;

                }

            }
            else
            {
                tail2 = head2;
                while(tail2->next != head2)
                {
                    tail2 = tail2->next;
                }
                tail2->next = link2;
                link2->prev = tail2;
                head2 -> prev = link2;
                link2 -> next = head2;
                tail2 = link2;
            }
            printf("Dodano Liczbe do listy B: %d\n", z);
    }
}

void printL()
{
    pokazListeA();
    printf("\n\n");
    pokazListeB();
    printf("\n\n");
    pokazMost();
}

void pokazMost()
{
    if(most == NULL)
    {
        printf("Brak mostu!\n");
    }
    else
    {
        printf("Most znajduje sie pomiedzy wartosciami %d a %d\n",most->prev->numer, most->numer);
    }

}

void pokazListeA()
{
    struct Lista *wsk, *wsk2;
    wsk = head;
    wsk2 = head;
    int x = 1;
    printf("Lista A: \n");
    if(head == NULL)
    {
        printf("Lista jest pusta\n");
    }
    else
    {
        while (wsk->next != head)
        {
            printf("%d) %d\n", x, wsk->numer);
            wsk = wsk->next;
            ++x;
        }
        printf("%d) %d\n\n", x, wsk->numer);

        printf("Polaczenie wezlami:\n\n");

        while (wsk2->next != head)
        {
            printf("Dla numeru : %d --------- Z lewej strony polaczony jest z: %d --------- Z prawej strony polaczony jest z: %d\n", wsk2->numer, wsk2->prev->numer, wsk2->next->numer);
            wsk2 = wsk2->next;
        }
        printf("Dla numeru : %d --------- Z lewej strony polaczony jest z: %d --------- Z prawej strony polaczony jest z: %d\n", wsk2->numer, wsk2->prev->numer, wsk2->next->numer);
    }

}
void pokazListeB()
{
    struct Lista *wsk3, *wsk4;
    wsk3 = head2;
    wsk4 = head2;
    int x = 1;
    printf("Lista B: \n");
    if(head2 == NULL)
    {
        printf("Lista jest pusta\n");
    }
    else
    {
        while (wsk3->next != head2)
        {
            printf("%d) %d\n", x, wsk3->numer);
            wsk3 = wsk3->next;
            ++x;
        }
        printf("%d) %d\n\n", x, wsk3->numer);

        printf("Polaczenie wezlami:\n\n");

        while (wsk4->next != head2)
        {
            printf("Dla numeru : %d --------- Z lewej strony polaczony jest z: %d --------- Z prawej strony polaczony jest z: %d\n", wsk4->numer, wsk4->prev->numer, wsk4->next->numer);
            wsk4 = wsk4->next;
        }
        printf("Dla numeru : %d --------- Z lewej strony polaczony jest z: %d --------- Z prawej strony polaczony jest z: %d\n", wsk4->numer, wsk4->prev->numer, wsk4->next->numer);
    }


}

void dellist()
{
    struct Lista *ptr, *ptr2, *ptr3;
    struct Lista *qwe, *qwe2, *qwe3;

    if(most != NULL)
    {
        if(most->next == head)
        {
            ptr = most->next;
            qwe = most->prev;

            most = NULL;

            ptr2 = ptr->next;
            qwe2 = qwe->next;

            while( qwe2 != head2)
            {
                qwe3 = qwe2;
                qwe2 = qwe2->next;
                free(qwe3);
            }
            free(qwe2);
            head2 = NULL;


            while( ptr2 != head)
            {
                ptr3 = ptr2;
                ptr2 = ptr2->next;
                free(ptr3);
            }
            free(ptr2);
            head = NULL;
        }
        else if(most->next == head2)
        {
            ptr = most->next;
            qwe = most->prev;

            most = NULL;

            ptr2 = ptr->next;
            qwe2 = qwe->next;

            while( qwe2 != head)
            {
                qwe3 = qwe2;
                qwe2 = qwe2->next;
                free(qwe3);
            }
            free(qwe2);
            head = NULL;

            while( ptr2 != head2)
            {
                ptr3 = ptr2;
                ptr2 = ptr2->next;
                free(ptr3);
            }
            free(ptr2);
            head2 = NULL;
        }
    }
    else if((most == NULL) && (head != NULL))
    {
        ptr = head->next;
        while(ptr != head)
        {
            ptr2 = ptr;
            ptr = ptr->next;
            free(ptr2);
        }
        free(ptr);
        head = NULL;

    }
    else if((most == NULL) && (head2 != NULL))
    {
        ptr = head2->next;
        while(ptr != head2)
        {
            ptr2 = ptr;
            ptr = ptr->next;
            free(ptr2);
        }
        free(ptr);
        head2 = NULL;
    }
    printf("Usunieto cala liste!\n");
}
void pCount()
{
    int a = 0;
    int b = 0;
    int c;
    printf("Podaj dir [1] lub [-1]\n");
    scanf("%d", &c);
    if(c == 1)
    {
        struct Lista *current;
        if(head != NULL)
        {
            current = head;
            a = 1;
            while(current->next != head)
            {
                current = current->next;
                a++;
            }
        }
        else if(head == NULL)
        {
            return;
        }
        if(head2 != NULL)
        {
            current = head2;
            b = 1;
            while(current->next != head2)
            {
                current = current->next;
                b++;
            }
        }
        else if(head2 == NULL)
        {
            return;
        }
        printf("Lista A ma %d elementow\n", a);
        printf("Lista B ma %d elementow\n", b);
    }
    else if(c == -1)
    {
        struct Lista *current;
        if(head != NULL)
        {
            current = head;
            a = 1;
            while(current->prev != head)
            {
                current = current->prev;
                a++;
            }
        }
        else if(head == NULL)
        {
            return;
        }
        if(head2 != NULL)
        {
            current = head2;
            b = 1;
            while(current->prev != head2)
            {
                current = current->prev;
                b++;
            }
        }
        else if(head2 == NULL)
        {
            return;
        }
        printf("Lista A ma %d elementow\n", a);
        printf("Lista B ma %d elementow\n", b);
    }

}

void del()
{
    int x;
    printf("Podaj numer ktory chcesz usunac z listy: ");
    scanf("%d", &x);
    struct Lista *xyz, *xyz2, *xyz3, *faketail;
    if(most == NULL)
    {
        if(head != NULL && x != head->numer) //
        {
            xyz = head;
            while(xyz->numer != x)
            {
                xyz = xyz->next;
            }
            xyz2 = xyz->next;
            xyz3 = xyz->prev;
            xyz3->next = xyz2;
            xyz2->prev = xyz3;
            free(xyz);
        }
        else if(head != NULL && x == head->numer) //
        {
            if(head->next == head)
            {
                free(head);
                head = NULL;
            }
            else
            {
                xyz = head;
                while(xyz->numer != x)
                {
                    xyz = xyz->next;
                }
                xyz2 = xyz->next;
                xyz3 = xyz->prev;
                xyz3->next = xyz2;
                xyz2->prev = xyz3;
                head=head->next;
                free(xyz);
            }

        }
        else if(head2 != NULL && x != head2->numer) //
        {
            xyz = head2;
            while(xyz->numer != x)
            {
                xyz = xyz->next;
            }
            xyz2 = xyz->next;
            xyz3 = xyz->prev;
            xyz3->next = xyz2;
            xyz2->prev = xyz3;
            free(xyz);
        }
        else if(head2 != NULL && x == head2->numer) //
        {
            if(head2->next == head2)
            {
                free(head2);
                head2 = NULL;
            }
            else
            {
                xyz = head2;
                while(xyz->numer != x)
                {
                    xyz = xyz->next;
                }
                xyz2 = xyz->next;
                xyz3 = xyz->prev;
                xyz3->next = xyz2;
                xyz2->prev = xyz3;
                head2=head2->next;
                free(xyz);
            }
        }
    }
    else if(most != NULL)
    {
        if(most->next == head)
        {
            if((x % 2 == 0))
            {
                if(x != head->numer) //
                {
                    xyz = head;
                    while(xyz->numer != x)
                    {
                        xyz = xyz->next;
                    }
                    xyz2 = xyz->next;
                    xyz3 = xyz->prev;
                    xyz3->next = xyz2;
                    xyz2->prev = xyz3;
                    free(xyz);
                }
                else if(x == head->numer) //
                {
                    if(head->next == head)
                    {
                        free(head);
                        head = NULL;
                        most = NULL;
                    }
                    else
                    {
                        xyz = head;
                        while(xyz->numer != x)
                        {
                            xyz = xyz->next;
                        }
                        xyz2 = xyz->next;
                        xyz3 = xyz->prev;
                        xyz3->next = xyz2;
                        xyz2->prev = xyz3;
                        head = head->next;
                        most->next = head;
                        most->numer = most->next->numer;
                        free(xyz);
                    }
                }

            }
            else if((x % 2 != 0))
            {
                if(x != most->prev->numer) //
                {
                    if (x == head2->numer)
                    {
                        xyz = head2;
                        while(xyz->numer != x)
                        {
                            xyz = xyz->next;
                        }
                        xyz2 = xyz->prev;
                        xyz3 = xyz->next;
                        xyz3->prev = xyz2;
                        xyz2->next = xyz3;
                        head2 = head2->next;
                        free(xyz);
                    }
                    else
                    {
                    xyz = most->prev;
                    while(xyz->numer != x)
                    {
                        xyz = xyz->prev;
                    }
                    xyz2 = xyz->next;
                    xyz3 = xyz->prev;
                    xyz3->next = xyz2;
                    xyz2->prev = xyz3;
                    free(xyz);
                    }

                }
                else if(x == most->prev->numer)//
                {
                    faketail = most->prev;
                    if(faketail->next == faketail)
                    {
                        free(faketail);
                        head2 = NULL;
                        most = NULL;
                    }
                    else if (faketail != head2)
                    {
                        xyz = faketail;
                        while(xyz->numer != x)
                        {
                            xyz = xyz->next;
                        }
                        xyz2 = xyz->prev;
                        xyz3 = xyz->next;
                        xyz3->prev = xyz2;
                        xyz2->next = xyz3;
                        faketail = faketail->prev;
                        most->prev = faketail;
                        free(xyz);
                    }
                    else if (faketail == head2)
                    {
                        xyz = faketail;
                        while(xyz->numer != x)
                        {
                            xyz = xyz->next;
                        }
                        xyz2 = xyz->prev;
                        xyz3 = xyz->next;
                        xyz3->prev = xyz2;
                        xyz2->next = xyz3;
                        faketail = faketail->prev;
                        most->prev = faketail;
                        head2 = head2->next;
                        free(xyz);
                    }

                }

            }

        }
        else if(most->next == head2)
        {

            if((x % 2 != 0))
            {
                if(x != head2->numer) //
                {
                    xyz = head2;
                    while(xyz->numer != x)
                    {
                        xyz = xyz->next;
                    }
                    xyz2 = xyz->next;
                    xyz3 = xyz->prev;
                    xyz3->next = xyz2;
                    xyz2->prev = xyz3;
                    free(xyz);
                }
                else if(x == head2->numer) //
                {
                    if(head2->next == head2)
                    {
                        free(head2);
                        head2 = NULL;
                        most = NULL;
                    }
                    else
                    {
                        xyz = head2;
                        while(xyz->numer != x)
                        {
                            xyz = xyz->next;
                        }
                        xyz2 = xyz->next;
                        xyz3 = xyz->prev;
                        xyz3->next = xyz2;
                        xyz2->prev = xyz3;
                        head2 = head2->next;
                        most->next = head2;
                        most->numer = most->next->numer;
                        free(xyz);
                    }
                }

            }
            else if((x % 2 == 0))
            {
                if(x != most->prev->numer) //
                {
                    if (x == head->numer)
                    {
                        xyz = head;
                        while(xyz->numer != x)
                        {
                            xyz = xyz->next;
                        }
                        xyz2 = xyz->prev;
                        xyz3 = xyz->next;
                        xyz3->prev = xyz2;
                        xyz2->next = xyz3;
                        head = head->next;
                        free(xyz);
                    }
                    else
                    {
                        xyz = most->prev;
                        while(xyz->numer != x)
                        {
                            xyz = xyz->prev;
                        }
                        xyz2 = xyz->next;
                        xyz3 = xyz->prev;
                        xyz3->next = xyz2;
                        xyz2->prev = xyz3;
                        free(xyz);
                    }

                }
                else if(x == most->prev->numer)//
                {
                    faketail = most->prev;
                    if(faketail->next == faketail)
                    {
                        free(faketail);
                        head2 = NULL;
                        most = NULL;
                    }
                    else if (faketail != head)
                    {
                        xyz = faketail;
                        while(xyz->numer != x)
                        {
                            xyz = xyz->next;
                        }
                        xyz2 = xyz->prev;
                        xyz3 = xyz->next;
                        xyz3->prev = xyz2;
                        xyz2->next = xyz3;
                        faketail = faketail->prev;
                        most->prev = faketail;
                        free(xyz);
                    }
                    else if (faketail == head)
                    {
                        xyz = faketail;
                        while(xyz->numer != x)
                        {
                            xyz = xyz->next;
                        }
                        xyz2 = xyz->prev;
                        xyz3 = xyz->next;
                        xyz3->prev = xyz2;
                        xyz2->next = xyz3;
                        faketail = faketail->prev;
                        most->prev = faketail;
                        head = head->next;
                        free(xyz);
                    }

                }

            }

        }
    }
    printf("Usunieto podany element!\n");
}

int main()
{
    srand(time(0));
    int n, komenda;
    printf("Podaj n: ");
    scanf("%d", &n);
    printf("\n\n");
    for(int i = 0; i<n; i++)
    {
        push();
    }
    printf("\n\n");
    printf("Lista\n");
	printf("----------------------------------------------\n");
	printf("[0] Wyjdz z programu\n");
	printf("[1] Print_all\n");
	printf("[2] dellist\n");
	printf("[3] pCount\n");
	printf("[4] Push\n");
	printf("[5] del\n");
	printf("[6] \n");
	printf("----------------------------------------------\n\n");

	while(1)
    {
		printf("\nWybrana komenda: ");
		scanf("%d", &komenda);
		printf("\n");
		switch (komenda)
		{
			case 0: return 0; break;
			case 1: printL(); break;
			case 2: dellist(); break;
			case 3: pCount(); break;
			case 4: push(); break;
			case 5: del(); break;
			case 6: ; break;
        }
    }


    return 0;
}
/*
  Mateusz Gajda
*/
