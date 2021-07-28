#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int avoid_count_single_line_comment(char *a,int start)
{
    int i,ans=0;
    for(i=start;;i++)
    {
        if(a[i]=='\n')
        return ans;

        else
        ans++;
    }
}

int avoid_count_multi_line_comment(char *a,int start)
{
    int i,ans=0;
    for(i=start;;i++)
    {
        if(a[i]=='*' && a[i+1]=='/')
        return ans;

        else
        ans++;
    }
}


char * remove_comments(char *code)
{
    int len=strlen(code),index=0,i;
    static char ans[100000];
    bool multi_line=false,single_line=false;

    for(i=0;i<len;i++)
    {
        if(code[i]=='/' && code[i+1]=='/')
        {
            i+=avoid_count_single_line_comment(code,i+2)+1;
        }

        else if(code[i]=='/' && code[i+1]=='*')
        {
            i+=avoid_count_multi_line_comment(code,i+2)+3;
        }

        else
            ans[index++]=code[i];
    }

    return ans;
}


int main()
{
    char code[10000],c;
    int index=0;
    FILE *fp;


    fp=fopen("testing.c","r");


    while(1)
    {
        c=fgetc(fp);

        if(c==EOF)
        break;

        code[index++]=c;
    }

    printf("Here goes the original Code!!\n");
    puts(code);


    char *s=remove_comments(code);
    printf("Here goes the Final Code!!\n");
    puts(s);

    return 0;
}