//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "琼岛白塔");
	set("long", @LONG
百塔为以琼华岛为主体组成的四面景观的中心。位于北海琼华岛之巅。白塔
上为喇嘛塔，下为高大的砖石台基，塔座为折角式须弥座，其上承托覆钵式塔身，
正面中有壶门式眼光门，门内刻有藏文咒语。塔身上部为细长的十三天，上为两
层铜质伞盖，边缘悬铜钟十四个，最上为鎏金火焰宝珠塔刹。
LONG
	);
	set("cost", 2);
	
      
	 
	set("exits", ([
                "northdown" : __DIR__"yilan",
                "southdown" : __DIR__"yongansi",
		"kedian" : "/d/city/kedian",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
