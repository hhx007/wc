#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])             
{
	int c=0;
	int w=0;
	int l=0;
	char * file;
    FILE * fp;
    char a;
    if((fp=fopen(argv[2],"r"))==NULL)
    {
        printf("read file failed��\n");
        exit(-1);
    }
    while(!feof(fp))
    {
        a=fgetc(fp);
        if(a!=' '&&a!='\n'&&a!='\t'&&a!=','&&a!='.'&&a!='!'&&a!=';'&&a!='=')//ͳ���ַ��� 
            c++;
        if(a==' '||a=='\n'||a=='\t'||a==','||a=='.'||a=='!'||a=='='||a==';')//ͳ�ƴ��� 
            w++;
        if(a=='\n'||a=='\t')//ͳ������ 
            l++;
    }
    l++;
    c--;         
    fclose(fp);
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        {  
        printf("���ļ�\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        continue;
        }
        else if(!strcmp(argv[1],"-c"))                 
            printf("�ַ���Ϊ:%d\n",c);//ʵ��ͳ���ַ������ܣ�����ַ��� 
        else if(!strcmp(argv[1],"-w"))                  
            printf("�ʵ���ĿΪ:%d\n",w);//ʵ��ͳ�ƴ������ܣ��������  
        else if(!strcmp(argv[1],"-l"))                
            printf("����Ϊ:%d\n",l);//ʵ��ͳ���������ܣ��������  

        else
            printf("�����\n");
        break;
        
    }
    return 0;
     
}
