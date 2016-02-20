//Cracked by Roath

void init()
{
	add_action("do_start", "start");
	add_action("do_knock", "knock");
}

string look_book()
{
	string desc, *msg;
	
	desc = "小册子上写了一些和象棋有关的口诀或诗词，其中一页写着：\n\n";
	
	msg = ({
"【象棋十诀】：
一、开局宜正	二、中变出奇	叁、残局稳细	四、全局审势	五、车占要津
六、马路疏通	七、炮贵机动	八、兵卒猛进	九、相仕阻敌	十、将帅主攻\n\n",
"棋子全盘叁十二，半为黑色半为红，鸿沟划处分河界，九路纵横尽可通。\n\n",
"将军挂帅决雌雄，卫士相随镇九宫，象跨方田隔南北，车行直道任西东，
马经斜日防旁塞，炮越重峦利远攻，兵卒勇前无退缩，渡河一步可横通。\n\n",
"绿树为麾盖，荫下设棋局，赢者自得意，输者气呼呼。\n\n",
"当头一炮得先多，马後车前卒渡河，乘胜进攻应反顾，失机坚守切求和。\n\n",
"象棋法与用兵同，谋算全凭布局工，胜气争先终得势，贪多恋子必无功；
虚心量敌休妄应，刻意求河戒急攻，成败寻常何畏怯，熟能生巧自精通。\n\n",
	});
	desc += msg[random(sizeof(msg))];
	return desc;
}

int do_start(string arg)
{       object board, me = this_player();

	if (present("chinese chess board", environment(me) ) )
	{       
	write("这里已经有一个棋盘了。\n");
		return 1;       
	}       
	message_vision("$N摆好了象棋棋盘，准备开局。\n", me);
	board = new("/clone/misc/chess");
	board->move(environment(me));
	return 1;
}
