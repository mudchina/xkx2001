//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "紫芝峪");
        set("long", 
"顺通元谷拾阶而上，便到了紫芝峪，峪中五彩缤纷长满了
各色不知名的野花，间或有珍奇药材生长其中。据传峪中暗藏
灵芝而不显其形，因而得名“紫芝峪”。\n"
        );
        set("exits", ([
                "eastup"  : __DIR__"longquanguan",
                "southdown"  : __DIR__"tongyuangu",
]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
       // replace_program(ROOM);
}
/*void init()
{
          add_action("do_search","search");
}
int do_search(string arg)
{	
	int fuyuan;
	object ob,me;
      me = this_player();
	fuyuan = me->query("kar");
      if (arg != "grass")
        return notify_fail("你要在哪儿找? \n");
	else
	{
                if (query("searched"))
                        return notify_fail("你在草丛中找寻了一会儿，但什么都没找到。\n");
		else{ 
		if (random(fuyuan) >15)
		{
		        ob = new("/clone/drug/lingzhi");
	        	set("searched",1);              
                	message_vision("你在四周的山草中不断的找寻着，忽然在草丛之中发现了一株灵芝"。\n",me);
                	ob->move(me);
                	return 1;
        	}
	else return 0;
	}       

}*/