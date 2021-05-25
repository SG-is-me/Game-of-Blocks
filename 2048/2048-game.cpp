#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<fstream>
#include<cstring>
#include<ctime>

using namespace std;
int m=0,t=0,z=0;

class scorecard
{
	char name[30];
	int matrix[4][4];
	int last[4][4];
	float score;
	
	public:
		scorecard()
		{
			score=0;
			srand(time(NULL));
			
			for(int i=0;i<=3;i++)
				for(int j=0;j<=3;j++)
				{
					matrix[i][j]=0;
					last[i][j]=matrix[i][j];
				}
				
			matrix[rand()%4][rand()%4]=2;
			matrix[rand()%4][rand()%4]=2;
			
		}
		
		int check(scorecard t)
		{
			if(strcmpi(name,t.name)==0)
				return 0;
				
			else
				return 1;
		}
		
		void input()
		{
			cout<<"Enter Name :"<<endl;
			cin.ignore();
			gets(name);
		}
		
		void disp(int i)
		{
			cout<<i<<'\t'<<name<<'\t'<<'\t'<<score<<endl<<endl;
		}
		
		void display()
		{
			for(int i=0; i<=16 ; i++)
			{
				if(i%4==0)
					for(int j=0; j<=16 ; j++)
						if(j==16)
							cout<<"+";
						else
						if((j%4==0)&&(j!=16))
							cout<<"+-";
						else
							cout<<"--";
		
				else
					for(int k=0; k<=16 ; k++)
					{
						if(k%4==0)
							cout<<"|";
							
						else
						if(((k%2==0)&&(k%4!=0))&&((i%2==0)&&(i%4!=0)))
							cout<<matrix[(i-2)/4][(k-2)/4];
					
						else
							cout<<" ";
							
						cout<<" ";
					}
			
				cout<<endl;	
			}
			
			cout<<endl<<"Score : "<<score;
			cout<<endl<<endl;
		}
		
		void move(char p);
		void check_move(int &n, int &b);
		
		void convert1()
		{
			for(int i=0;i<=3;i++)
				for(int j=0;j<=3;j++)
					matrix[i][j]=last[i][j];
		}
		
		void convert2()
		{
			for(int i=0;i<=3;i++)
				for(int j=0;j<=3;j++)
					last[i][j]=matrix[i][j];	
		}
		
		void extract(scorecard &t)
		{
			for(int i=0;i<=3;i++)
				for(int j=0;j<=3;j++)
					t.matrix[i][j]=matrix[i][j];
					
			t.score=score;
		}
		
};

void scorecard :: check_move(int &n,int &b)
{
		
		for(int i=1;i<=3;i++)
		{
			for(int j=0;j<=3;j++)
			{
				if(matrix[i-1][j]==matrix[i][j])
				{
					b++;
					break;
				}
			}
			
			if(b!=0)
				break;	
		}

		for(int i=0;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(matrix[i][j-1]==matrix[i][j])
				{
					b++;
					break;
				}
			}
			
			if(b!=0)
				break;
		}
		
		for(int i=0;i<=3;i++)
		{
			for(int j=0;j<=3;j++)
			{
				if(matrix[i][j]==2048)
					n++;
			}
		}			
}

void scorecard :: move(char p)
{
	srand(time(NULL));
	
	if(p=='w')
	{
	
	  for(int k=0;k<=3;k++)
	  {
		for(int i=1;i<=3;i++)
		{
			for(int j=0;j<=3;j++)
			{
				if(matrix[i-1][j]==0)
				{
						matrix[i-1][j]=matrix[i][j];
						matrix[i][j]=0;	
				}
				
				else
				if(matrix[i-1][j]==matrix[i][j])
				{
					matrix[i-1][j]=matrix[i-1][j] + matrix[i][j];
					matrix[i][j]=0;
					score+=10;					
				}				
			}
		}
      }

		for(int a=0;;a++)
		{	
			int i=rand()%4 , j=rand()%4;
			
			if(matrix[i][j]==0)
				{
					matrix[i][j]=pow(2,rand()%3);
					
					if(matrix[i][j]==1)
						matrix[i][j]=2;
			
					break;
				}	
		}
	
	}
	
	else
	if(p=='s')
	{
	
	  for(int k=0;k<=3;k++)
	  {	
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<=3;j++)
			{
				if(matrix[i+1][j]==0)
				{
						matrix[i+1][j]=matrix[i][j];
						matrix[i][j]=0;	
				}
						
				else
				if(matrix[i+1][j]==matrix[i][j])
				{
					matrix[i+1][j]=matrix[i+1][j] + matrix[i][j];
					matrix[i][j]=0;
					score+=10;					
				}	
						
			}
		}
      }
      
			for(int a=0;;a++)
			{		
				int i=rand()%4 , j=rand()%4;
				
				if(matrix[i][j]==0)
					{
						matrix[i][j]=pow(2,rand()%3);
						if(matrix[i][j]==1)
							matrix[i][j]=2;
					
						break;
					}	
			}
			
	}
		
    else
	if(p=='d')
	{
		
	  for(int k=0;k<=3;k++)
	  {
		for(int i=0;i<=3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(matrix[i][j+1]==0)
				{
						matrix[i][j+1]=matrix[i][j];
						matrix[i][j]=0;
						
						
				}
				else
				if(matrix[i][j+1]==matrix[i][j])
				{
					matrix[i][j+1]=matrix[i][j+1] + matrix[i][j];
					matrix[i][j]=0;
					score+=10;									
				}	
			
			}
		}
      }


			for(int a=0;;a++)
			{	
				int i=rand()%4 , j=rand()%4;
			
				if(matrix[i][j]==0)
					{
						matrix[i][j]=pow(2,rand()%3);
						if(matrix[i][j]==1)
							matrix[i][j]=2;
				
						break;
					}	
			}
	}
	
    else
	if(p=='a')
	{
		
		
	  for(int k=0;k<=3;k++)
	  {
		for(int i=0;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(matrix[i][j-1]==0)
				{
						matrix[i][j-1]=matrix[i][j];
						matrix[i][j]=0;
						
						
				}
				
				else
				if(matrix[i][j-1]==matrix[i][j])
				{
					matrix[i][j-1]=matrix[i][j-1] + matrix[i][j];
					matrix[i][j]=0;
					score+=10;									
				}	
			}
		}
      }

			for(int a=0;;a++)
			{	
				int i=rand()%4 , j=rand()%4;
			
				if(matrix[i][j]==0)
					{
						matrix[i][j]=pow(2,rand()%3);
						if(matrix[i][j]==1)
							matrix[i][j]=2;
				
						break;
					}	
			}
		
	}
	
}
	
int search(scorecard &t)
{
	ifstream fin("info.dat", ios::binary);
	scorecard s;
	int flag=0;
	fin.read((char*)&s, sizeof(s));
	while(fin)
	{
		if(s.check(t)==0)
		{
			flag++;
			s.extract(t);
			t.display();
			return 0;
			break;
		}
		
		else
			fin.read((char*)&s, sizeof(s));			
	}
	
	if(flag==0)
		return 1;

	else 
		return 0;
		
	fin.close();
}

void save1(scorecard t)
{
	ofstream file("info.dat", ios::binary|ios::app);
	
	file.write((char*)&t, sizeof(t));
	file.close();
}

void save2(scorecard t)
{
	fstream file("info.dat", ios::binary | ios::in | ios::out);
	scorecard s;
	long ptr = sizeof(s);
	file.read((char*)&s, sizeof(s));
	while(file)
	{
		if(s.check(t)==0)
		{
			file.seekp(-ptr, ios::cur);
			file.write((char*)&t, sizeof(t));
		}
		
		else
			file.read((char*)&s, sizeof(s));
	}
	
	file.close();
}

void remove()
{
	scorecard t;
	t.input();
	ofstream fout("new.dat",ios::out|ios::binary);
	ifstream fin("info.dat",ios::in| ios::binary);
	scorecard s;
	
	if(!fin)
	{
		cout<<"File not Found";
		exit(0);
	}
	
	else
	{
		fin.read((char*)&s, sizeof(s));
		while(fin)
		{
			if(s.check(t)!=0)
				fout.write((char*)&s, sizeof(s));
			
			fin.read((char*)&s, sizeof(s));
		}
	}
	
	fout.close();
	fin.close();
	remove("info.dat");
	rename("new.dat", "info.dat");
	exit(0);
}

int main()
{
	scorecard player;
	int choice,pls;
	char ch;
	
	do
	{
		
		cout<<'\t'<<'\t'<<'\t'<<'\t'<<"   2048"<<endl<<endl;
		
		for(int i=0; i<=12 ; i++)
		{
			cout<<'\t'<<'\t'<<'\t';
			
			if(i%3==0)
				for(int j=0; j<=12 ; j++)
					cout<<"*"<<" ";
		
			else
				for(int k=0; k<=12 ; k++)
				{
					if(k%3==0)
						cout<<"*";
						
					else
						cout<<" ";
					
					cout<<" ";
				}
				
			cout<<endl;	
		}
		
		cout<<endl<<'\t'<<'\t'<<'\t'<<"  For New Game, press 1"<<endl<<endl;
		cout<<'\t'<<'\t'<<'\t'<<"  For Load Game, press 2"<<endl<<endl;
		cout<<'\t'<<'\t'<<"      For Deleting a Record, press 3"<<endl<<endl;
		cout<<'\t'<<'\t'<<"       For Displaying Score, press 4"<<endl<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<"   ";
		cin>>choice;
		if(choice==1)
		{
			system("cls");		
			player.input();
			while(1)
			{
				if(search(player)==1)
					break;
					
				if(search(player)==0)
				{
					system("cls");
					cout<<"Name already taken. Please enter new name :"<<endl<<endl;
					player.input();
				}
			}
			
			system("cls");
			player.display();
		}
		
		else
		if(choice==2)
		{	
			system("cls");		
			player.input();
			while(1)
			{
				if(search(player)==0)
					break;
					
				if(search(player)==1)
				{
					system("cls");
					cout<<"Name not found. Enter Agian :"<<endl<<endl;
					player.input();
				}
			}	
			
			system("cls");
			player.display();
		}
		
		else
		if(choice==3)
		{
			system("cls");
			remove();
		}
		
		else
		if(choice==4)
		{
			system("cls");
			int i=1;
			ifstream fin("info.dat", ios::binary);
			scorecard d;
			fin.read((char*)&d, sizeof(d));
			while(fin)
			{
				d.disp(i);
				fin.read((char*)&d, sizeof(d));
				i++;	
			}
			fin.close();
			exit(0);
		}
		
		else
		{
			system("cls");
			cout<<"Please Enter Correct Choice";
		}
			
	do
	{
		cout<<"Enter move :"<<endl<<endl<<"w for up"<<endl<<"s for down"<<endl<<"a for left"<<endl<<"d for right"<<endl<<"Press u to undo last move"<<endl<<"Press e to exit"<<endl<<endl<<"To save game, press m"<<endl;
		cin>>ch;
		
		if(ch=='m')
		{
			if(choice==1)
				save1(player);
				
			else
			if(choice==2)
			{
				save2(player);				
			}

			system("cls");
			player.display();
			cout<<"Progress Saved"<<endl<<endl;	
		}
		
		else
		if(ch=='e')
			exit(0);
		
		else
		if((ch=='u')&&(t==0))
		{
			player.convert1();
			system("cls");
			player.display();
			t++;
		}
		
		else
		if((ch=='w')||(ch=='s')||(ch=='a')||(ch=='d'))
		{
			system("cls");
			player.convert2();				
			player.move(ch);
			player.display();
			player.check_move(::t,::z);
			
			if(t!=0)
				t--;
		}
		
		else
		{
			system("cls");
			player.display();
			cout<<"Invalid Input"<<endl<<endl;
			player.check_move(::t,::z);
		}			
				
	}
	while(::z!=0);

	if(::t==1)
		cout<<"CONGRATULATIONS!!";
				
	else
	if(::z==0)
		cout<<"Game Over :("<<endl<<endl;
	
	cout<<"To go back to home page, press 1"<<endl<<"To exit, press 2"<<endl;
	cin>>pls;		
		
	if(pls==2)
		exit(0);
	}
	while(pls==1);

	return 0;
}
