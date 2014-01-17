#include <cstdlib>
#include <iostream>

using namespace std;

bool **W;
int n=0;
int m=0;
int v=0;
int e=0;
int x=0;
int y=0;
int *vcolor;

bool promising(int i)
{
	int j=0;
	while(++j<i)
	{
		if (W[i][j]&&vcolor[i]==vcolor[j])
		return false;
	}
	return true;
}

void m_coloring (int i)
{
	if(promising(i))
	{
		if(i+1==n)
		{
			for (i=1;i<n;i++)
			cout<<vcolor[i]<<" ";
			cout<<endl;
		}else
		{
			for (int color = 1;color<=m;color++)
			{
				vcolor[i+1]= color;
				m_coloring(i+1);
			}
		}
	}
}

void initArrays()
{
	for(int i=0;i<n;i++)
	{
		W[i]=new bool[n];
		vcolor[i]=0;
	}
}

void fillW()
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			W[i][j]=false;
		}
	}
}

void askForEdges()
{
	cout<<"Berapa banyak sisi? ";
	cin>>e;
	cout<<endl<<"Masukkan sisi: (titik_x(spasi)titik_y)"<<endl;
	
	for (int i=0;i<e;i++)
	{
		cin>>x>>y;
		W[x][y]=true;
		W[y][x]=true;
	}
}

void specialMatrixPrint()
{
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<W[i][j]<<" ";
		}
		cout<<endl;
	}
}

void showEdgesMatrix()
{
	int i;
	cout<<"\n ";for(i=1;i<n;i++)
	{
		cout<<"  "<<i;
	}
	cout<<"\n ";for(i=1;i<=n;i++)
	{
		cout<<"# ";
	}
	cout<<endl;
	
	for(i=1;i<n;i++)
	{
		cout<<i<<"# ";
		for(int j=1;j<n;j++)
		{
			cout<<(W[i][j]?"1 ":"0 ");
		}
		cout<<endl;
	}
}

void checkFor(int i)
{
	m=i;
	m_coloring(0);
	cout<<"======================================"<<endl;
	cout<<"Penjelasan: "<<endl;
	cout<<"Misalnya ada graph seperti diatas"<<endl<<endl;
	cout<<"jadi inputannya yang titiknya ada 6 dan sisinya ada 11"<<endl;
	cout<<"======================================"<<endl<<endl;
	cout<<"Hasil outputnya nanti berupa angka 1-4 yang mewakili warna."<<endl<<endl;
	cout<<"Misalnya output: 1 2 3 4 3 1"<<endl<<endl;
	cout<<"berarti"<<endl;
	cout<<"titik ke 1: warna 1 (merah)"<<endl;
	cout<<"titik ke 2: warna 2 (putih)"<<endl;
	cout<<"titik ke 3: warna 3 (biru)"<<endl;
	cout<<"titik ke 4: warna 4 (hijau)"<<endl;
	cout<<"titik ke 5: warna 3 (biru)"<<endl;
	cout<<"titik ke 6: warna 1 (merah)"<<endl;
	
}

int main(int argc, char *argv[])
{
	cout<<"Berapa banyak titik? ";
	cin>>n;
	
	n+=1;
	W=new bool *[n];
	vcolor=new int[n];
	
	initArrays();
	fillW();
	askForEdges();
	showEdgesMatrix();
	
	checkFor(4);//warna yang digunakan
	
	cin>>y;
	//return 0;
	
	
	system("pause");
	return 0;
}
