//Cracked by Roath
// Room: /d/village/bighouse2.c

inherit ROOM;

void create()
{
        set("short", "内室");
	set("long", @LONG
这里是一间寝室，屋子中间有一张大床，床上的被褥居然是绸缎的，在这样一
个小村庄里能有如此的手工的确很令人吃惊。看来这个土财主对自己并不是十分刻
薄。屋里摆着几只木箱子，墙角里有一只大柜子(cabinet)，古色古香的韵味让你
凑上前去看个仔细。
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" :"/d/village/bighouse1",
        ]));
	set("item_desc", ([
	"cabinet" : "这是一个别致的小柜子，镂空的花纹里没有一丝灰尘，像是有人经常打扫的样子。\n",
	]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
