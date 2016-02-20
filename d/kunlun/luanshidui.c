//Cracked by Roath
// Room: /d/mingjiao/luanshidui.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;

void set_randomroom();
void out_player(object ob);
void create()
{
	
	set("short", "乱石堆");
	set("long", @LONG
此处乱石交错，再走下去恐怕会迷路。四周也没什么花草树木，一些
奇形怪状的大石头乱堆在旁。
LONG
	);
	set("no_clean_up", 0);
	set("cost", 5);
	setup();
	set_randomroom();
	
}

void init ()
{
/*	object ob;
	if (interactive(ob = this_player())) 
		remove_call_out("out_player");
		call_out("out_player", 150, ob);
	
*/
}
//出去时，消去在里面的成果
void out_player(object ob)
{
	string file_name,file_end;
	file_end=file_name(environment(ob));

	file_name = implode(explode(file_end, "/")[0..<2], "/");
	if (!ob->is_busy())
	if(file_name=="d/mingjiao/tiekuangshan"||file_end=="d/mingjiao/tiekuang")
	{
		tell_object(ob,HIW"\n\n你只觉眼前乱石堆纵横交错，根本看不清那里出口在何处，只得由原路退回。\n\n"NOR);
		ob->move("/d/mingjiao/luanshidui");
		return;
	}
	remove_call_out("out_player");
	call_out("out_player", 1, ob);
	return;

}

void out_message(object ob)
{	
	string file_name,file_end;
	file_end=file_name(environment(ob));

	file_name = implode(explode(file_end, "/")[0..<2], "/");
	if(file_name=="d/mingjiao/tiekuangshan"||file_end=="d/mingjiao/tiekuang")
		tell_object(ob,HIW"\n\n你只觉眼前乱石堆纵横交错，已经快看不清出口在何处，心知如果不赶快走出这乱石迷阵，必然大大的不妥。\n\n"NOR);

	return;

}

void set_randomroom()
{
	object room;
	delete("exits");
	set("exits", ([ 
	 "northeast" : __DIR__"shanlu23",
	 ]));

	room=new("/clone/room/randomroom");
	room->Set_Room(1,4,"/d/mingjiao/luanshidui","/d/mingjiao/tiekuangshan/","/d/mingjiao/tiekuang",0);
	call_out("set_randomroom", 300);
}

int valid_leave(object ob,string dir)
{
	int i;
	object obj, *inv;
	 if (dir != "northeast") 	
	 {
		 inv = deep_inventory(ob);
		 if(sizeof(inv))
			 for(i=0; i<sizeof(inv); i++) 
				 if(userp(inv[i])) 
					 return notify_fail("你只觉前面乱石堆纵横交错，实有说不出的危险。加上你身上背着别人，如何敢往前走。\n");

				 remove_call_out("out_player");
				 call_out("out_player", 200, ob);
				 remove_call_out("out_message");
				 call_out("out_message", 100, ob);
	 }
	 else
	 {
		  remove_call_out("out_player");
		  remove_call_out("out_message");
	 }
        return ::valid_leave(ob, dir);
}

