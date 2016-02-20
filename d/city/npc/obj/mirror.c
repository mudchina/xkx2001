//Cracked by Roath
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIY"铜镜"NOR, ({"tong jing", "mirror", "jing" }) );
        set_weight(2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
"一面白铜磨成的镜子，照出你的仪容；\n");
                set("unit", "面");
                set("value", 500);
        }
        init_blade(10);
        setup();
}        
        
void init()
{
           add_action("do_look","look");
        
}

int do_look(string arg)
{
        object me = this_player();
        object ob = this_object();
        int qper = me->query_per();
        string qname = me->query("name");

        if (!id(arg)) return 0;

        message_vision("$N拿起一面铜镜仔细端详着\n\n", me);
        if (this_player()->query("gender") == "女性") {
        if (qper<15) 
        {
        write(this_object()->query("long") +"镜中之人貌似无盐，你吓地一失手把镜子打得粉碎！！\n\n");
        destruct(ob);   
        return 1;
}
        if (qper<20)
        {
write(this_object()->query("long") +"你看了看镜子，觉得多少也还算是中人之姿了，嫣然一笑，却也风态款款！\n\n");
        return 1;
}
 
if (qper<25)
        {
write(this_object()->query("long") +"镜中之人虽是荆钗布裙，但然清秀之色溢然而现，却有一番风韵！\n\n");
        return 1;
}          
if (qper<35)
        {
write(this_object()->query("long") +"你向镜中望去，端的是闭月羞花之容，沉鱼落雁之色！芙蓉妖艳，明媚回春！！\n\n");
        return 1;
}

if (qper>34)        
{
write(this_object()->query("long") +"镜中之人满面脂粉，看不清本来面目！\n\n");
        return 1;
}

}

        else
{
if (qper<15)
        {
write(this_object()->query("long") +"镜中人面带菜色，一副病慵慵的模样！\n\n");
        return 1;
}       
        
if (qper<21)
        {
write(this_object()->query("long") +"你对着铜镜打量了半晌，自觉到也还五官端正！\n\n");
        return 1;
}        

if (qper<28)
        {
write(this_object()->query("long") +"镜中公子气宇轩昂，端的是人中龙凤！\n\n");
        return 1;
}
        
if (qper<34)
        {
write(this_object()->query("long") +"你只见自己润润如玉，谦然君子耳！\n\n");
        return 1;
}
        
if (qper>33)
        {
write(this_object()->query("long") +"镜中之人颇为纤柔，婉若妇人一般！\n\n");
        return 1;
}

}

}
