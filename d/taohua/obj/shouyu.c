//Cracked by Roath
// 
inherit ITEM;

void create()
{
        set_name("»ÆÒ©Ê¦ÊÖÚÍ", ({"shou yu", "yu", "letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "·â");
                set("long","\n
=================================
|				|
|		×Ö		|
|		ÚÍ		|
|		Áé		|
|		·ç		|
|		Îá		|
|		Í½		|
|				|
|			ÌÒ	|
|			»¨	|
|			»Æ	|
|				|
|			¼ê	|
|				|
=================================\n");
                set("material", "paper");
        }
}
