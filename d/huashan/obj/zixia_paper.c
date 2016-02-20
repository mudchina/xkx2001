//Cracked by Roath
// zixia_paper.c
inherit ITEM;

void create()
{
        set_name("纸笺", ({"zixia paper", "zixia"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "页");

                set("long",
"紫霞千变，万气归宗。紫氤正气，相辅相承。聚龙虎，畅筋脉。开玄关，\n"
"过重楼。通任督，就玄功。功成者气精具增，洗骨净髓。动静由心，动者\n"
"如脱兔，静者若处子。冰心观万象，天塌亦不惊。根骨得天後，百病皆难\n"
"侵。一举一动，劲随意到，劲到力至，无坚不摧也。\n"
"行功者须在华山小筑密室内闭关，行功法则如下：\n"
"。。。。。\n"
"。。。。。。。\n"
"biguan <臂力> <悟性> <根骨> <身法>\n"
"备注：所增各项天赋值的总和为四点。\n"
"例如：biguan 2 0 1 1， 臂力加二，悟性不变。根骨身法俱增一点。\n");

		set("value", 10000000);
		set("material", "paper");
//		set("no_drop","这样东西不能离开你。\n");
        }
}