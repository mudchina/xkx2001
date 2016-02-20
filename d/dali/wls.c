//Cracked by Kafei
// Room: /dali/wls.c
// AceP

inherit ROOM;

void create()
{
	set("short", "无量山");
	set("long", @LONG
西面这一群大山就是无量山了，山上有无量剑派的剑湖宫。这里是山脚下。
此山并不算太高，但十分险峻。几名无量剑的弟子正守在上山的路口，身佩长
剑，神情严肃。路旁有块牌子(paizi)。
LONG );

	set("item_desc", ([
		"paizi" :"日下正值本派斗剑比武之际，应邀前来观礼之江湖朋友请上山，闲杂人等请回！\n",
		]));

	set("exits", ([
		"westup" : __DIR__"jhg1",
		"north"  : __DIR__"wls1",
		"south"  : __DIR__"wls1",
		"east"   : __DIR__"wls17",
	]));
	set("cost", 3);
        set("outdoors", "dali");
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	int i;
	me=this_player();

	if (dir == "westup")
	{
		if (!present("bai tie", me) || query("visited")) 
			return notify_fail("无量剑弟子说道: “本派正在斗剑比武，闲杂人等不得打扰！”\n"); 
		else {
			inv=all_inventory(me);
			for(i=0; i<sizeof(inv); i++) 
				if (inv[i]->is_character())
					return notify_fail("无量剑弟子说道: “本派正在斗剑比武，闲杂人等不得打扰！”\n"); 
			if (objectp(ob=present("corpse", me)))
				return notify_fail("无量剑弟子喝道: “滚开！带具尸体来干什么！”\n"); 
			message_vision("无量剑弟子对$N躬身作了个揖，道: “欢迎阁下前来观礼。”\n",me);
			set("visited",1);
			return ::valid_leave(me, dir);
		}
	}
	return ::valid_leave(me, dir);
}
