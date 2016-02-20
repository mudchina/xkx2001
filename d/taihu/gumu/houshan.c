//Cracked by Roath
//GU MU FROM SANTA
//houshan.C

inherit ROOM;

void create()
{
	set("short", "终南山－－后山");
	set("long", @LONG
这里是终南山的后山。前方是一片茂密的树林，里面黑乎乎的。
地上立着一块石碑（shibei)。  
LONG
	);
	set("item_desc", ([
	"shibei" : "\n
		
		不	全
		
		得	真
	重	
	阳	入	弟
	手
	喻	林	子
		        \n",
	]));


	set("exits", ([
		"enter" : __DIR__"shulin1",
		"south" : __DIR__"shan"
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}



