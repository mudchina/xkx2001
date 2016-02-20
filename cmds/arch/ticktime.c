//Cracked by Roath
// ticktime.c

int main()
{
        int t;  // time of the day in minutes
        mixed local;

        local = localtime(time()*60);
        t = local[2]*60 + local[1];

        printf("%s\n", chinese_number(t));
        return 1;
}
