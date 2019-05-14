#include <iostream.h>
#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>
int array[10];
int MAX;
#define ValueOf(x) (x.value())
#define Exchange(x,y) (x.exchange(y))

class element
{
	int _value;
	int _color;
	public:
		element()
		{
		    _color = 15;    //white
	}
		void get()
		{
			scanf("%d",&_value);
		}
		int value()
		{
		    return _value;
	}
		void exchange(element &e)
		{
			element temp;
			temp = e;
			e = *this;
			*this = temp;
		}
		void setcolor(int col)
		{
	    _color = col;
	}
		void show()
		{
			textbackground(_color);
			if(_color == 15)
			{
				textcolor(0);
			}
			else
			{
				textcolor(15);
			}
			cprintf(" %2d ",_value);
			printf(" ");
		}
};

void Display ( element *A , int p , int r )
{
	printf("\n ");
	for(int i=p;i<r;i++)
	{
		A[i].show();
	}
}
int partition(element *A,int low,int high)
{
	int i,j,temp,pivot;
       //	int flag=0;
	pivot=ValueOf(A[low]);
	int l=low;
	i=low+1;
	j=high;
	while(1)
	{
			Display(A,0,MAX);
			printf("\ti: %d\t j:%d: pivot:%d",i,j,pivot);
			delay(1000);
		while(i<high && ValueOf(A[i])<=pivot)
		{
			i++;

		}
		while(ValueOf(A[j])>pivot)
		{
			j--;

		}
			Display(A,0,MAX);
			printf("\ti: %d\t j:%d:",i,j);
			delay(1000);
		if(i<j)
		{
		      //	flag=1;

			Exchange(A[i],A[j]);
			Display(A,0,MAX);
			printf("\ti: %d <swap> j:%d",i,j);

			delay(1000);

		}
		else
		{
		       /*	temp=A[low];
			A[low]=A[j];
			A[j]=temp;*/

			Exchange(A[low],A[j]);
			A[j].setcolor(RED);
			Display(A,0,MAX);
			printf("\t  swap  %d and %d, set pivot:%d ",l,j,pivot);
			delay(1000);
			return j;
		}
	}
}
/*int partition(element *A ,int p ,int r)
{
	int pivot , i = 1 , j = 1;
	pivot = ValueOf(A[r]);
	A[r].setcolor(RED);
	i = p - 1;
	for(j=p;j<r;j++)
	{
	    int flag=0;
		if( ValueOf(A[j]) <= pivot )
		{
			i = i + 1;
			Exchange(A[j],A[i]);
			if(j!=i)
		flag=1;
		}
		else
		{
			A[j].setcolor(BLUE);
		}
		Display ( A  , 0 , MAX );
		if(flag==1)
	    printf("\ti: %d   <swap>   j:%d",i,j);
	else
	    printf("\ti: %d\t\tj:%d",i,j);
		delay ( 100 );
    }
    Exchange(A[r],A[i+1]);
	A[i+1].setcolor ( GREEN );
    printf("\n");
	Display ( A  , 0 , MAX );
	printf ( " > %d at correct position. \n", ValueOf ( A[i+1] ) );
	getch();
	return i+1 ;
}*/
void QuickSort(element arr[], int low, int high)
{
    int q;
    if(low==high)
    {
	arr[low].setcolor(RED);
    }
    if (low < high)
    {
	/*q is partitioning index*/
	q = partition(arr, low, high);
	QuickSort(arr, low, q - 1);
	QuickSort(arr, q + 1, high);
    }
}

int main()
{
    int x=120,i,gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
    settextstyle(9,HORIZ_DIR,3);
    /*int co[] = {100, 50, 900, 50, 900, 260, 100, 260, 100, 50};
    drawpoly(4, co);*/
    setcolor(GREEN);
    outtextxy(x,75,"LOADING ALGO PROJECT");
    setcolor(YELLOW);
    outtextxy(x,135,"     QUICK SORT");
    setcolor(WHITE);
    outtextxy(x,230,"    PLEASE WAIT");
    setcolor(CYAN);
    for(i=0;i<400;++i)
    {
      delay(20);
	line(x,200,x,220);
	x++;
    }
    clrscr;
    closegraph();
	element array[10];
	i=1;
	textbackground(0);
	textcolor(15);
	clrscr();
	printf("enter no of elements:- > ");
	scanf("%d",&MAX);
	printf("\nEnter %d elements:- > ",MAX);
	for(i=0;i<MAX;i++)
		array[i].get();
	Display ( array , 0 , MAX );
	printf ( " > Given Array.");
    getch();
	printf("\n ");
	QuickSort(array,0,MAX-1);
	printf("\n Array Sorted:\n ");
	for(i=0;i<MAX;i++)
		array[i].show();
	printf("\n");
	getch();
	return 0;
}
