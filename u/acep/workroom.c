//Cracked by Kafei
// acep's workroom ^_^
inherit ROOM;

void create()
{
	set("short", "飞行的家");
	set("long", @LONG
这里是飞行的工作室，大书橱里整整齐齐地摆满了主人爱看的各
种书籍。屋子正中是张大桌子 (table)，旁边有几张沙发和一个茶几
外加一座冰箱。
LONG);

	set("item_desc", ([
		"table"   : "除了一台电脑外，没做完的模型和程序胡乱地堆着，还有几本最新的杂志。\n",
		]));

	set("exits", ([
		"kd"  : "/d/city/kedian",
		"down"   : "/d/wizard/wizard_room",
		"sl" : "/d/shaolin/guangchang1",
		"wn" : "/d/wudang/sanqingdian",
		"xx" : "/d/xingxiu/xxh2",
		"gb" : "/d/gaibang/undertre",
		"gb2" : "/d/gaibang/gbxiaowu",
		"kd" : "/d/city/kedian",
		"qz" : "/d/quanzhou/zhongxin",
        "hs" : "/d/huashan/buwei1",
        "bt" : "/d/xingxiu/btyard",
        "dl" : "/d/dali/wangfu1", 
        "em" : "/d/emei/baoguomen",
        "em1" : "/d/emei/hz_guangchang",
        "xs" : "/d/xueshan/guangchang",
		"qfy" : "/u/qfy/workroom",
		"lyu" : "/u/lyu/workroom",
		"xbc" : "/u/xbc/workroom",
		"cls" : "/u/cleansword/workroom",
		"rover" : "/u/rover/workroom",
		"marz" : "/u/marz/workroom",
		"mgl" : "/u/mongol/workroom",
        "ryu" : "/u/ryu/workroom",
		]));

	set("valid_startroom", 1);

    setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && dir != "kd")
		return notify_fail("你往前一走，却发现有无形的力场锁着你，出不去！:(\n");
	return ::valid_leave(me, dir);
}
