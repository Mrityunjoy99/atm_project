#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
char* code(char *c,int n)
{
	static char arr[25];
	int a,sum=0,b,d=0;
	for(b=0;b<n;b++)
	{
		a=*(c+b);
		//printf("%d\t",a);
		while(a>10)
		{
			sum=0;
			while(a!=0)
			{
				sum+=a%10;
				a=a/10;
			}
			a=sum;
			//printf("%d\t",a);
		}
		
		arr[b]=a+48;
	}
	b--;
	
	return(arr);
}
int main()
{
	char un[7],pw[25]={0},name[25],amt[20],ch;
	char uiun[7],uipw[25]={0},uicp[25]={0};
	int k,y,zu,zs;
	char *cpw;
	char str[20],pwc1[25],pwc2[25],pwcc[25];
	int amtw,x,zpw1,zpw2,se;
	char c;
	int i=0,j,access=0,l=0;
	FILE *fp,*fp1;
	printf("\t\t1 - if you are already a registered \n\t\t2 - creat an account\n ");
	scanf("%d",&se);
	if(se==1)
	{
		printf("Enter your username:");
		scanf("%s",uiun);
		ch=0;
		getchar();
		printf("Enter your passward:");
		
		for(k=0;ch!='\r';k++)
		{
			ch=getch();
			uipw[k]=ch;
			printf("*");
			
			//ch='*';
			
		}
		uipw[k]='\0';
		printf("\n");
		zu=strlen(uipw);
		cpw=code(uipw,zu);
		for(k=0;k<zu;k++)
		{
			ch=*(cpw+k);
			uicp[k]=ch;
		}
		for(k=0;k<zu;k++)
		{
			ch=uicp[k];
			uipw[k]=ch;
		}
		//printf("%s",uicp);
		
		c=0;
		fp=fopen("atmtest1.txt","r");
		//printf("a");
		fp1=fopen("atmtest2.txt","w");
		//printf("b");
		if(fp==NULL)
		printf("The file does not exhists\n");
		else
		{
			while(c!=EOF)
			{
				c=fgetc(fp);
				fputc(c,fp1);
				if(c=='\n')
				{
					for(i=0;i<7;i++)
					{
						c=fgetc(fp);
						fputc(c,fp1);
						un[i]=c;
						
					}
					c=fgetc(fp);
					//fputc(c,fp1);
					c=fgetc(fp);
					for(i=0;c!='\t';i++)
					{
						pw[i]=c;
						c=fgetc(fp);
						//fputc(c,fp1);
						
						
					}
					pw[i]='\0';
					zs=strlen(pw);
					//c=fgetc(fp);
					fputc(c,fp1);
					i=0;
					c=fgetc(fp);
					//fputc(c,fp1);
					while(c!='\t')
					{
						name[i++]=c;
						c=fgetc(fp);
						//fputc(c,fp1);
					}
					name[i]='\0';
					y=strlen(name);
					c=fgetc(fp);
					for(i=0;i<20;i++)
					{
						amt[i]=0;
					}
					i=0;
					while(c!='\t')
					{
						amt[i++]=c;
						c=fgetc(fp);
					}
					access=atoi(amt);
					for(i=0;i<7;i++)
					{
						if(uiun[i]!=un[i])
						break;
					}
					if(i==7)
					i--;
					//printf("zu=%d zs=%d",zu,zs);
					if(uiun[i]==un[i])
					{
						if(zu==(zs+1))
						{
							for(i=0;i<zs;i++)
							{
								if(uipw[i]!=pw[i])
								{
									printf("You have input a wrong passward\n");
									fclose(fp1);
									remove("atmtest2.txt");
									exit(0);
								}
							}
							i--;
						}
						else
						{
							printf("You have input a wrong passward\n");
							fclose(fp1);
							remove("atmtest2.txt");
							exit(0);
						}
					}
					else
					{
						for(k=0;k<zs;k++)
						{
							c=pw[k];
							fputc(c,fp1);
						}
						fputc('\t',fp1);
						zs=strlen(pw);
						for(k=0;k<y;k++)
						{
							c=name[k];
							fputc(c,fp1);
						}
						fputc('\t',fp1);
						for(i=0;i<5;i++)
						{
							c=amt[i];
							fputc(c,fp1);
							
						}
						fputc('\t',fp1);
						continue;
					}
					if(uipw[i]==pw[i])
					{
						l=1;
						break;
					}
					else
					l=0;
				}
				else
				continue;
				
			}
			if(l!=1)
			{
				printf("The username is not registered \n ");
				fclose(fp1);
				remove("atmtest2.txt");
				exit(0);
			}
		}
		
	//	printf("zu=%d zs=%s\n",zu,zs);
		
		
		if(l==1)
		{
			printf("\t\tWelcome %s\n",name);
			printf("Enter 1 to deposite money \nEnter 2 to withdraw money\nEnter 3 to change passward\n");
			scanf("%d",&x);
			if(x==2)
			{
				printf("Enter your withdrawal amount:");
				scanf("%d",&amtw);
				while(amtw>access)
				{
					printf("You have not sufficient ballance\nYour ballance is %d\nEnter a valid amount :",access);
					scanf("%d",&amtw);
				}
				printf("Your amount is withdrawn successfully\n");
				access-=amtw;
				
				for(k=0;k<zs;k++)
				{
					c=pw[k];
					fputc(c,fp1);
				}
				fputc('\t',fp1);
				for(k=0;k<y;k++)
				{
					c=name[k];
					fputc(c,fp1);
				}
				fputc('\t',fp1);
			}
			else if(x==1)
		
			{
				printf("Enter your dipsite amount:");
				scanf("%d",&amtw);
				access+=amtw;
				
				for(k=0;k<zs;k++)
				{
					c=pw[k];
					fputc(c,fp1);
				}
				fputc('\t',fp1);
				for(k=0;k<y;k++)
				{
					c=name[k];
					fputc(c,fp1);
				}
				fputc('\t',fp1);
			}
			else if(x==3)
			{
				//k=0;
				printf("Enter new passward :");
				ch=getch();
				for(k=0;ch!='\r';k++)
				{
					
					pwc1[k]=ch;
					printf("*");
					ch=getch();
				}
				pwc1[k]='\0';
				zpw1=strlen(pwc1);
				
				printf("\n");
				printf("Re-enter new passward :");
				ch=getch();
				for(k=0;ch!='\r';k++)
				{
					
					pwc2[k]=ch;
					printf("*");
					ch=getch();
				}
				pwc2[k]='\0';
				zpw2=strlen(pwc2);
				printf("\n");
				if(zpw1==zpw2)
				{
					for(k=0;k<zpw1;k++)
					{
						if(pwc1[k]!=pwc2[k])
						{
							printf("Sorry your passward is not changed\n");
							fclose(fp1);
							remove("atmtest2.txt");
							exit(0);
						}
						
					}
				}
				else
				{
					printf("Sorry your passward is not changed\n");
					fclose(fp1);
					remove("atmtest2.txt");
					exit(0);
				}
				
				k--;
				if(pwc1[k]==pwc2[k])
				{
					cpw=code(pwc1,zpw1);
					for(k=0;k<zpw1;k++)
					{
						c=*(cpw+k);
						pwcc[k]=c;
					}
					for(k=0;k<zpw1;k++)
					{
						c=pwcc[k];
						pwc1[k]=c;
					}
					for(k=0;k<zpw1;k++)
					{
						c=pwc1[k];
						fputc(c,fp1);
					}
					fputc('\t',fp1);
					for(k=0;k<y;k++)
					{
						c=name[k];
						fputc(c,fp1);
					}
					fputc('\t',fp1);
				}
			}
			else
			{
				printf("There is some error in input\n");
				fclose(fp1);
				remove("atmtest2.txt");
				exit(0);
			}
			
			itoa(access,str,10);
			for(k=0;str[k]!='\0';k++)
			{
				ch=str[k];
				fputc(ch,fp1);
			}
			fputc('\t',fp1);
			//fputc('\n',fp1);
			while(c!=EOF)
			{
				c=fgetc(fp);
				fputc(c,fp1);
			}
			printf("Now your acount balance is %d\n",access);
		}
		fclose(fp);
		fclose(fp1);
	}
	else if(se==2)
	{
		fp=fopen("atmtest1.txt","r");
		fp1=fopen("atmtest2.txt","w");
		char cun[7];
		c=fgetc(fp);
		while(c!=EOF)
		{
			
			fputc(c,fp1);
			c=fgetc(fp);
		}
		//fputc('\n',fp1);
		rewind(fp);
		c=0;
		while(c!=EOF)
		{
			c=fgetc(fp);
			//fputc(c,fp1);
			if(c=='\n')
			{
				
				c=fgetc(fp);
				if(c!='J')
				break;
				
				for(i=0;i<7;i++)
				{
					
			//		fputc(c,fp1);
					cun[i]=c;
					c=fgetc(fp);
					
				}
				//printf("%s\n",cun);
			}
		}
		i--;
		while(i>1)
		{
			if(cun[i]!=57)
			{
				cun[i]+=1;
				break;
			}
			else
			{
				cun[i]=48;
				i--;
			}
		}
		for(i=0;i<7;i++)
		{
			c=cun[i];
			fputc(c,fp1);
		}
		fputc('\t',fp1);
		printf("Set your passward :");
		ch=getch();
				for(k=0;ch!='\r';k++)
				{
					
					pwc1[k]=ch;
					printf("*");
					ch=getch();
				}
				pwc1[k]='\0';
				zpw1=strlen(pwc1);
				
				printf("\n");
				printf("Re-enter new passward :");
				ch=getch();
				for(k=0;ch!='\r';k++)
				{
					
					pwc2[k]=ch;
					printf("*");
					ch=getch();
				}
				pwc2[k]='\0';
				zpw2=strlen(pwc2);
				//printf("\n");
				if(zpw1==zpw2)
				{
					for(k=0;k<zpw1;k++)
					{
						if(pwc1[k]!=pwc2[k])
						{
							printf("\nSorry your passward is not changed\n");
							fclose(fp1);
							remove("atmtest2.txt");
							exit(0);
						}
						
					}
				}
				else
				{
					printf("\nSorry your passward is not changed\n");
					fclose(fp1);
					remove("atmtest2.txt");
					exit(0);
				}
				
				k--;
				if(pwc1[k]==pwc2[k])
				{
					cpw=code(pwc1,zpw1);
					for(k=0;k<zpw1;k++)
					{
						c=*(cpw+k);
						pwcc[k]=c;
					}
					for(k=0;k<zpw1;k++)
					{
						c=pwcc[k];
						pwc1[k]=c;
					}
					for(k=0;k<zpw1;k++)
					{
						c=pwc1[k];
						fputc(c,fp1);
					}
					fputc('\t',fp1);
				}
				getchar();
		printf("\nEnter your name :");
		ch=getchar();
		while(ch!='\n')
		{
			fputc(ch,fp1);
			ch=getchar();
		}
		fputc('\t',fp1);
		//for(i=0;i<5;i++)
		fputc('0',fp1);
		fputc('\t',fp1);
		fputc('\n',fp1);
		fclose(fp);
		fclose(fp1);
		printf("Your account is formed successfully\nNow log in again and deposite some money in your account\nyour user name is %s\n",cun);
	}
	
	c=0;
	fclose(fp);
	fclose(fp1);
	
	fp=fopen("atmtest1.txt","w");
	fp1=fopen("atmtest2.txt","r");
	c=fgetc(fp1);
	while(c!=EOF)
	{
		
		fputc(c,fp);
		c=fgetc(fp1);
	}
	fclose(fp);
	fclose(fp1);
	remove("atmtest2.txt");
}
