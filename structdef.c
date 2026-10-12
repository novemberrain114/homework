typedef enum {
    MALE = 'M',
    FEMALE = 'F',
} Sex;
typedef struct {
    char name[10];
    Sex sex;
    int age;
    double height;
}PerInfo;
int main(){
    PerInfo t={.name="hhh",.sex=MALE,.age=19,.height=1.80};
    printf("%s %c %d %.1f\n",t.name,(char)t.sex,t.height);
    return 0;
}