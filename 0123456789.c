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
        printf("read file failed！\n");
        exit(-1);
    }
    while(!feof(fp))
    {
        a=fgetc(fp);
        if(a!=' '&&a!='\n'&&a!='\t'&&a!=','&&a!='.'&&a!='!'&&a!=';'&&a!='=')//统计字符数 
            c++;
        if(a==' '||a=='\n'||a=='\t'||a==','||a=='.'||a=='!'||a=='='||a==';')//统计词数 
            w++;
        if(a=='\n'||a=='\t')//统计行数 
            l++;
    }
    l++;
    c--;         
    fclose(fp);
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        {  
        printf("空文件\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        continue;
        }
        else if(!strcmp(argv[1],"-c"))                 
            printf("字符数为:%d\n",c);//实现统计字符数功能，输出字符数 
        else if(!strcmp(argv[1],"-w"))                  
            printf("词的数目为:%d\n",w);//实现统计词数功能，输出词数  
        else if(!strcmp(argv[1],"-l"))                
            printf("行数为:%d\n",l);//实现统计行数功能，输出行数  

        else
            printf("输错了\n");
        break;
        
    }
    return 0;
     
}
