//Memory Time
//240K   32MS

#include<iostream>
#include<cstring>
using namespace std;

typedef class
{
	public:
		int row;
		char col;
}location;

int p,q;  //chess size = p*q
          //��������p����ĸ����q
bool chess['Z'+1][27];

int x,y;  //����ֵ
void path(int i,int j,int num)  //ijΪ��ʿ��ǰ�����̵�λ��
{                               //numΪ��ʿ����Ҫ������λ�����
	switch(num)
	{
     	case 1: {x=i-1; y=j-2; break;}     //ע�������������˳���ܴ�
		case 2: {x=i+1; y=j-2; break;}     //��Ϊ��ĿҪ�����ֵ���lexicographically���
		case 3: {x=i-2; y=j-1; break;}     //���˳����ˣ��ض�WA
		case 4: {x=i+2; y=j-1; break;}
		case 5: {x=i-2; y=j+1; break;}
		case 6: {x=i+2; y=j+1; break;}
		case 7: {x=i-1; y=j+2; break;}
		case 8: {x=i+1; y=j+2; break;}
	}
	return;
}

bool DFS(location* way,int i,int j,int step)
{
	chess[i][j]=true;
	way[step].row=i;
	way[step].col=j;
	if(step==way[0].row)
		return true;

	for(int k=1;k<=8;k++)   //��ʿ�ӵ�ǰλ�ó�����������λ��
	{
		path(i,j,k);
		int ii=x,jj=y;
		if(!chess[ii][jj] && ii>=1 && ii<=p && jj>='A' && jj<='A'+q-1)
			if(DFS(way,ii,jj,step+1))
				return true;
	}

	chess[i][j]=false;  //��ִ�е��ⲽ��˵��ǰ������8����������Ҫ��
	return false;       //����ǰλ���Ǵ���λ�ã�������¼������һ��
}

int main(void)
{
	int test;
	cin>>test;
	int t=1;
	while(t<=test)
	{
		/*Initial*/

		memset(chess,false,sizeof(chess));

		cin>>p>>q;
		if(p==1 && q==1)      //��Χ��խ����ҪҲ��AC
		{
			cout<<"Scenario #"<<t++<<':'<<endl;
			cout<<"A1"<<endl<<endl;
			continue;
		}
		if(p*q>26 || p>=9 || q>=9 || p<=2 || q<=2)        //��Χ��խ����ҪҲ��AC
		{
			cout<<"Scenario #"<<t++<<':'<<endl;
			cout<<"impossible"<<endl<<endl;
			continue;
		}

		location* way=new location[p*q+1];   //��¼�߹���λ������
		way[0].row=p*q;   //��¼�ܲ���(�����ܸ�����)

		/*DFS*/

		bool flag=false;
		for(int j='A';j<='A'+q-1;j++)
		{
			for(int i=1;i<=p;i++)
				if(DFS(way,i,j,1))
				{
					cout<<"Scenario #"<<t++<<':'<<endl;

					for(int k=1;k<=way[0].row;k++)
						cout<<way[k].col<<way[k].row;
					cout<<endl<<endl;
					flag=true;
					break;
				}
				if(flag)
					break;
		}

		if(!flag)
		{
			cout<<"Scenario #"<<t++<<':'<<endl;
			cout<<"impossible"<<endl<<endl;
		}
	}
	return 0;
}
