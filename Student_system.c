#include<stdio.h>
#include<string.h>  
int g = 1;
struct Student
    {
     char name[20];
     int number;
     float score;
    };
struct Student stus[1000];
int num = 0;
int main()
{
    
    void getData();
    void makeChoice();
    //读取数据，显示
    getData();
    //选择要执行的操作
    while(g)
    {
        makeChoice();
    }
    return 0;
}
    
    
    void makeChoice()
    {
        void saveData();
        void insertData();
        void seletorAll();
        void seletor();
        void changeData();
        int s;
        
        printf("1、查询所有数据 \n");
        printf("2、查询单个数据 \n");
        printf("3、插入数据 \n");
        printf("4、修改数据 \n");
        printf("5、exit!! \n\n");
        printf("please make a choose:\n");
        scanf("%d",&s);
        switch(s)
        {
            case 1: 
            seletorAll();
            break;
            case 2:
            seletor();
            break;
            case 3: 
            insertData();
            break;
            case 4: 
            changeData();
            break;
            case 5: 
            printf("exit !\n");
            g = 0;
            //4、保存数据
            saveData();
            break;
        }
    }
    /*
    *获取数据
    */
    void getData()
    {   
        FILE *fp;
        int i;
        if((fp=fopen("info.txt","rb"))==NULL)
        {
            printf("不能打开文件！\n");
            return;
        }
        if(fread(&num,sizeof(int),1,fp)!=1)
        {
            num = -1;
        }
        else
        {
            for(i=0; i<num; i++)
            {
                fread(&stus[i],sizeof(struct Student),1,fp);
            }
        }
        fclose(fp);
    }
    /*
    *保存数据
    */
    void saveData()
    {
        FILE *fp;
        int i;
        if((fp=fopen("info.txt","wb"))==NULL)
        {
            printf("不能打开文件！\n");
            return;
            
        }
        if(fwrite(&num,sizeof(int),1,fp)!=1)
        {
            printf("写入文件错误！\n");
        }
         for (i=0;i<num;i++)  
        {  
             if (fwrite(&stus[i],sizeof(struct Student),1,fp)!=1)  
             {  
                  printf("写入文件错误!\n");  
             }  
        }      
  
        fclose(fp); 
        printf("保存成功！\n");
    }
    /*
    *查询所有学生数据
    */
    void seletorAll()
    {
        int i;
        for(i=0; i<num; i++)
        {
            printf("%10s,%10d,%10.2f\n",stus[i].name,stus[i].number,stus[i].score);
        }
        if(num == 0)
        {
            printf("还未保存学生信息！\n");
        }
        printf("\n");
    }
    /*
    *查询单个学生数据
    */
    void seletor()
    {
        char name[20];
        int i,index = -1;
        printf("请输入需要查询的姓名：");
        scanf("%s",name);
        for(i=0; i<num; i++)
        {       
            if(strcmp(stus[i].name,name) == 0 )
            {
                index = i;
                break;
            }
            
        }
        if(index != -1)
        {
            printf("%10s,%10d,%10.2f\n",stus[index].name,stus[index].number,stus[index].score);
        }
        else
        {
            printf("未查到该学生信息。\n");
        }
        
    }
    /*
    *修改学生信息
    */
    
    void changeData()
    {
        char name[20];
        int i,index = -1;
        int choice;
        printf("请输入需要修改的学生的姓名：");
        scanf("%s",name);
        for(i=0; i<num; i++)
        {
            if(strcmp(name,stus[i].name) == 0  )
            {
                index = i;
                break;
            }
        }
        if(index != -1)
        {
            printf("请输入需要修改的信息：\n");
            printf("1、修改学号\n");
            printf("2、修改成绩\n");
            scanf("%d",&choice);
            if(choice == 1)
            {
                printf("请输入修改后的学号：\n");
                scanf("%d",&stus[index].number);
            }
            else
            {
                printf("请输入修改后的成绩：\n");
                scanf("%f",&stus[index].score);
            }
            printf("修改后的信息为：\n");
            printf("%10s,%10d,%10.2f\n",stus[index].name,stus[index].number,stus[index].score);
        }
        else
        {
            printf("未查到该学生信息。\n");
        }
        
        
    }
    /*
    *插入学生数据
    */
    void insertData()
    {
        char g;
        do
        {
           printf("请输入姓名：");
           scanf("%s",stus[num].name);
           printf("请输入学号：");
           scanf("%d",&stus[num].number);
           printf("请输入成绩：");
           scanf("%f",&stus[num].score);
            num ++;
            
            printf("是否继续：（y/n）：");
            scanf("%s",&g);
            
            if(g=='n')
            {
                break;
            }
            printf("\n");
        }while(1);
        
    }
    
    
    

