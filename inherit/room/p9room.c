//Cracked by Roath
// paigow room
// some of the ideas are borrowed from xiang's pigroom
// the code is VERY messy, shrug
// --ding
// modified by aln 4 / 98

inherit F_CLEAN_UP;
inherit ROOM;

int 	*tile_rank=({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}),
	*pair_rank=({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0}),
	*tile_value=({12,2,8,4,10,6,4,11,10,7,6,9,8,7,5,3,6}),
	*oldtiles=allocate(32), 
   	*newtiles=allocate(32),
     	player,totalbet, casinowin,
     	stage, //0-waiting, 1-open bank, 2-close bank
     	min=10,
     	max=100;

string *tile_cname=({"天牌","地牌","人牌","合牌","梅花","长三","板凳","虎头","屏风",
		"七点","六点","杂九","杂八","杂七","杂五","至尊"}),
	*tile_face=({
"「六六」","「一一」","「四四」","「一三」","［五五］","［三三］","［二二］",
"［五六］","［四六］","［一六］","［一五］","［三六］","［四五］","［二六］",
"［三五］","［二五］","［三四］","［一四］","［二三］","［一二］","［二四］"}),

	*cool_face=({
" -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- ",
" -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- ",
" -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- ",
" -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- ",
"| ●  ● |","| ●  ● |","|        |","|        |","| ●  ● |","| ●  ● |","|        |","|        |",
"| ●  ● |","| ●  ● |","| ●     |","| ●     |","|        |","|        |","| ●  ● |","| ●  ● |",
"| ●  ● |","| ●  ● |","|        |","|        |","|        |","|        |","| ●     |","| ●  ● |",
"|        |","| ●     |","|        |","| ●     |","|        |","|        |","|        |","|        |",
"| ●  ● |","| ●  ● |","|   ●   |","|   ●   |","|        |","|        |","|   ●   |","|   ●   |",
"|   ●   |","|   ●   |","|   ●   |","|   ●   |","| ●  ● |","| ●  ● |","|   ●   |","|   ●   |",
"|        |","|        |","|   ●   |","|   ●   |","|   ●   |","|   ●   |","|   ●   |","|        |",
"| ●  ● |","|   ●   |","| ●  ● |","|   ●   |","|   ●   |","| ●  ● |","|   ●   |","| ●  ● |",
"| ●  ● |","| ●  ● |","|        |","|        |","| ●  ● |","| ●  ● |","|        |","|        |",
"| ●  ● |","| ●  ● |","|     ● |","|     ● |","|        |","|        |","| ●  ● |","| ●  ● |",
"| ●  ● |","| ●  ● |","|        |","|        |","|        |","|        |","|     ● |","| ●  ● |",
"|        |","|     ● |","|        |","|     ● |","|        |","|        |","|        |","|        |",
"|        |","|        |","|        |","|        |","|        |","|        |","|        |","|        |",
"|        |","|        |","|        |","|        |","|        |","|        |","|        |","|        |",
"|        |","|        |","|        |","|        |","|        |","|        |","|        |","|        |",
"|        |","|        |","|        |","|        |","|        |","|        |","|        |","|        |",
"| ●  ● |","| ●  ● |","|        |","|        |","| ●  ● |","| ●  ● |","| ●     |","| ●     |",
"| ●  ● |","| ●  ● |","| ●     |","| ●     |","|        |","|        |","| ●  ● |","| ●  ● |",
"| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |",
"| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","| ●     |","|        |","| ●  ● |",
"| ●  ● |","| ●  ● |","|   ●   |","|   ●   |","|        |","|        |","|   ●   |","|   ●   |",
"|   ●   |","|   ●   |","|   ●   |","|   ●   |","| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |",
"| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","|   ●   |","|   ●   |","| ●  ● |","|   ●   |",
"| ●  ● |","|   ●   |","|   ●   |","|        |","|        |","|   ●   |","| ●  ● |","|        |",
"| ●  ● |","| ●  ● |","|        |","|        |","| ●  ● |","| ●  ● |","|     ● |","|     ● |",
"| ●  ● |","| ●  ● |","|     ● |","|     ● |","|        |","|        |","| ●  ● |","| ●  ● |",
"| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |",
"| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","| ●  ● |","|     ● |","|        |","| ●  ● |",
" -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- ",
" -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- ",
" -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- ",
" -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- "," -------- "
}),

	wtype="silver",
	cwtype="白银",
	*winner=({}),
	*loser=({}),
	*hand_cname=allocate(4);


mapping	tiles=allocate_mapping(2),
	cchar=([
	"left" : "上门",
	"middle" : "中门",
	"right" : "下门", ]);


void tile_init();
void shuffle(int *ol, int *nl,int t);
int check_status(int *hand);
int is_pair(int *hand);
int is_high(int *hand);
void add_winner(int i); //1-left, 2-middle, 3-right
void add_loser(int i);
string get_hname(int *hand);

void init()
{
	if (wizardp(this_player())) {
	add_action("do_test", "test");
	add_action("do_xxx", "xxx");
	}
	add_action("do_bet", "bet");
	add_action("do_none", "practice");
        add_action("do_none", "lian");
        add_action("do_none", "exercise");
        add_action("do_none", "dazuo");
        add_action("do_none", "study");
        add_action("do_none", "du");
        add_action("do_none", "respirate");
        add_action("do_none", "tuna");

	if (this_player()->query_temp("p9/player"))
		this_player()->delete_temp("p9/");
}

int do_xxx()
{
write("so far accepted "+player+" bets worth "+totalbet+" , and casino net winning is "+casinowin+".\n");
return 1;
}

int do_none(string arg)
{
	tell_object(this_player(), "赌场里喧嚷吵闹，你根本静不下心来。\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("p9/player"))
		return notify_fail("你正赌着钱呢，等这一把开了再走吧。\n");
        return ::valid_leave(me, dir);
}


int do_test()
{
	int i,j,k,n,t;
	string str;

	k=30;
	for (i=0; i<9; i++) {
		str=cool_face[k]+"  "+cool_face[k+1];
		message_vision("		    	  "+str+"\n",this_player());
		k+=32;
	}

	for (i=0; i<5; i++) {
		n=0;
		for (j=0;j<9; j++) {
			str="";
			for (k=0; k<6; k++) 
				str+=cool_face[k+n+t]+" ";
			message_vision("     "+str+"\n", this_player());
			n+=32;
		}
		t+=6;
	}
	return 1;
}
	
int do_bet(string arg)
{
	int wager, tile_played;
	string type,area;
	object mtype, me;

	me=this_player();

	if (!arg || sscanf(arg, "%d %s %s", wager, type, area) !=3) 
		return notify_fail("bet <amount> <area>, area is left|middle|right, eg. bet 10 silver left.\n");

        if (type != wtype)
                return notify_fail("这里只接受"+cwtype+"!\n");
        mtype = present(wtype + "_money", me);
        if( !mtype)          return notify_fail("你身上没有这种货币。\n");
        if( wager < 1 )        return notify_fail("你要压多少啊?\n");
        if( (int)mtype->query_amount() < wager)
        return notify_fail("你身上没有那么多" + mtype->query("name") + "。\n");
        if( wager < min || wager > max )
                return notify_fail("你的赌注不在限额之内!\n"
+ "这里的限额是" + chinese_number(min) + "至" + chinese_number(max) + "两"+cwtype+"。\n");

        if (area != "left" && area != "middle" && area != "right")
                return notify_fail("你要赌哪一门?\n");

        if (stage >1) return notify_fail("已经开赌了，等下把吧。\n");

        if (me->query_temp("p9/player")) 
                return notify_fail("你不是已经下注了吗?! 等着开牌吧!\n");

        if (!stage) {
		tell_room(this_object(), "下注啊，下注啊，买的多赢的多啊～～～\n");
		stage = 1;
                call_out("start_play", 30);
	}
	if (!tile_played) {
		tile_init();
		tile_played =1;
	}

	tell_room(this_object(), me->query("name") 
+ "压了" + chinese_number(wager) + "两"+cwtype+"在"+cchar[area] +"。\n");

// all is fine, ready to play

        mtype->set_amount((int)mtype->query_amount() - wager);
        mtype->move(me);

	me->set_temp("p9/player",1);
	me->set_temp("p9/wager",wager);
	me->set_temp("p9/area", area);
	player++;
	totalbet+=wager;
	casinowin+=wager;

	return 1;
}

void start_play()
{
	int i,j,k,tile,tmp, tmp2,
        *hand_value=allocate(4),
        *hand_status=allocate(4); // 0-nothing, 1-high, 2-pair

	string str1, str2, *str=({});

        tell_room(this_object(), "\n买定离手，开牌啦!\n");
        stage=2;

	shuffle(oldtiles, newtiles,2);
// deal
        for (i=0; i<2; i++)
               for (j = 0; j < 4; j++) 
                       tiles[j][i] = newtiles[k++];

//cmp tiles
        for (i=0; i<4; i++) {
              j=0;

//put the high ranked tile of the pair in front
              if (tile_rank[tiles[i][j]/2] > tile_rank[tiles[i][j+1]/2]) {
                      tmp=tiles[i][j+1];
                      tiles[i][j+1]=tiles[i][j];
                      tiles[i][j]=tmp;
               }
                for (j = 0; j < 2; j++)
                {
                        k=tiles[i][j];
                        tile=k/2;
                        if (k >30) tile++;
                        hand_value[i] += tile_value[tile];
                }
                hand_value[i] %= 10;
                hand_status[i]=check_status(tiles[i]);
// write("i: "+i+", handvalue: "+hand_value[i]+", hand_status[i]:"+hand_status[i]+"\n");
        }

        j=0;
        for (i=1; i<4; i++) {
                if (hand_status[i] > hand_status[j]) 
                        add_winner(i);
                else if (hand_status[i] == hand_status[j]) {
                        switch (hand_status[i]){
                        case 2: {
                                if (pair_rank[tiles[i][j]/2] < pair_rank[tiles[j][j]/2])
                                        add_winner(i);
                                else add_loser(i);
                                break;
                        }
                        case 1: {
                                tmp = tiles[i][j+1]/2;
                                if (tmp >15 ) tmp++;
                                tmp = tile_value[tmp];
                                tmp %= 10;
                                tmp2 = tiles[j][j+1]/2;
                                if (tmp2 >15 ) tmp2++;
                                tmp2 = tile_value[tmp2];
                                tmp2 %= 10;
                                if (tmp > tmp2)
                                        add_winner(i);
                                else if ((tile_rank[tiles[i][j]/2] < tile_rank[tiles[j][j]/2]) &&
                                        (tmp == tmp2))
                                        add_winner(i);
                                else add_loser(i);
                                break;
                        }
                        case 0: if (hand_value[i]>hand_value[j]) 
                                        add_winner(i); 
                                else if ((hand_value[i]==hand_value[j]) &&
                                        (tile_rank[tiles[i][j]/2] < tile_rank[tiles[j][j]/2]) &&
                                        (hand_value[i] >0))
                                        add_winner(i);
                                else add_loser(i);
                                break;
                        }
                }
                else add_loser(i);
        }

// display tiles for each hand

        for (i=0; i<4; i++)
        {
            j=0;
            tmp =0;
		switch(hand_status[i]){
		case 2 : hand_cname[i]="一对"+tile_cname[tiles[i][j]/2];break;
		case 1 : hand_cname[i]="一付"+get_hname(tiles[i]); break;
		default: if (hand_value[i] == 0)
				hand_cname[i]="一付憋十";
			 else 
			hand_cname[i]="一付"+chinese_number(hand_value[i])+"点";
		}

		switch (i) {
		case 1 : str2= "上门得到了："+hand_cname[i]+"    "; break;
		case 2 : str2+= "中门得到了："+hand_cname[i]+"  "; break;
		case 3 : str2+= "  下门得到了："+hand_cname[i]; break;
		default: str1= "                        庄家得到了："+hand_cname[i]+"\n";
		}
	    for (k =0; k< 9; k++) {
		str1 += "                        ";
                for (j = 0; j < 2; j++)
                {
			tile= tiles[i][j];
			if (i==0) str1 +=cool_face[tile+tmp]+"  ";
			else str +=({cool_face[tile+tmp]});
                }
		if (i==0) str1 += "\n";
		tmp +=32;
	    } if (i == 0)
                tell_room(this_object(), str1 +"\n");
        }
		tell_room(this_object(), str2 +"\n");

	tmp2=0;
	for (k =0; k< 9; k++) {
		tmp=0;
		str1="";
		for (j=0; j<3; j++){
			for (i=0; i<2; i++) 
		      		str1 +=str[i+tmp+tmp2] +" ";
			str1 += "  ";
			tmp += 18;
		}
		tell_room(this_object(), str1 +"\n");
		tmp2+=2;
	}
	call_out("end_play",3);
	return;
}

void end_play()
{
	int i,j,k,tmp,tmp2,tile,wager;
	string area,str,str2;
	object *inv,bigcheese,mtype;

	inv=all_inventory(this_object());

// pay out
	if (sizeof(winner)<1) tell_room(this_object(), "庄家通吃!!\n");
	else if (sizeof(winner) >2) tell_room(this_object(), "庄家通赔!!\n");
	else  {
                str = "庄家吃： ";str2 ="庄家收取了 ";
	        for (i=0; i<sizeof(loser); i++) {
                        str += cchar[loser[i]]+ " ";
			str2 += cchar[loser[i]]+ " ";
		}
                str += "，庄家赔： ";str2+= "的赌注，赔出了 ";
	        for (i=0; i<sizeof(winner); i++) {
			str += cchar[winner[i]]+ " ";
			str2 += cchar[winner[i]]+ " ";
		}
		str =str + "。\n" +str2+"的赌注。\n";
		tell_room(this_object(), str);
	}

// write("no. of inv in room: "+ sizeof(inv)+"\n");
	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query_temp("p9/player") ) {
			area=inv[i]->query_temp("p9/area");
			wager=inv[i]->query_temp("p9/wager");

// write(inv[i]->query("name")+" has bet "+wager+" on "+area+"\n");

			if (member_array(area,winner)!= -1) {
				tell_room(this_object(), inv[i]->query("name")
+ "赢回"+chinese_number(wager*195/100)+"两"+cwtype+"。\n");
//takes 5% tax
		        mtype = present(wtype + "_money", inv[i]);
		        if (!mtype) {
               			mtype = new("/clone/money/" + wtype);
                		mtype->set_amount(wager*195/100);
                		mtype->move(inv[i]);
        		}
        		else
                		mtype->add_amount(wager*195/100);
			casinowin-=(wager*19/10);
			}
			inv[i]->delete_temp("p9/");
		}
	}
//cleanup


//	player=0;
//	totalbet=0;
	stage=0;
	winner=({});
	loser=({});

	return;
}


void add_winner (int i)
{
	switch (i) {
	case 1 : winner += ({"left"});break;
	case 2 : winner += ({"middle"});break;
	case 3 : winner += ({"right"});break;
	default : winner += ({"home"});
	}
	return;
}

void add_loser (int i)
{
        switch (i) {
        case 1 : loser += ({"left"});break;
        case 2 : loser += ({"middle"});break;
	case 3 : loser += ({"right"});break;
        default : loser += ({"home"});
        }
        return;
}

string get_hname(int *hand)
{
	string str="";
	if (tile_value[hand[0]/2] == 12 )
		str += "天";
	else str += "地";
	switch (tile_value[hand[1]/2]) {
	case 9 : str += "王"; break;
	case 8 : str += "杠"; break;
	default: str += "九";
	}
	return str;
}

int check_status(int *hand)
{
	if (is_pair(hand)) return 2;
	else if(is_high(hand)) return 1;
	else return 0;
}

int is_pair(int *hand)
{
	int i=0;
	if (tile_rank[hand[i]/2] == tile_rank[hand[i+1]/2])
		return 1;
	else return 0;
}

int is_high(int *hand)
{	
	int i=0;
	if ((tile_rank[hand[i]/2] <3) && 
            (tile_value[hand[i+1]/2] > 6) &&
	    (tile_value[hand[i+1]/2] <10) )
	return 1;
	else return 0;
}

void shuffle(int *ol, int *nl, int t)
{
        int i, j, k, l;
        if (sizeof(ol) < 32 || sizeof(nl) < 32) 
                for (i = 0; i < 32; i++)
                        ol[i] = nl[i] = i;
        if (t <= 0 || t >= 10) t = 1;
        for (i = 0; i < t; i++) {
                for (j = 0; j < 32; j++) {
                        k = 31 - j;
                        l = random(k);
                        nl[j] = ol[l];
                        if (k != l)
                                ol[l] = ol[k];
                }
                for (j = 0; j < 32; j++) ol[j] = nl[j];
        }
}

void tile_init()
{
	int i;
	for (i=0; i<32; i++) oldtiles[i]=i;
        for (i = 0; i < 4; i++) tiles[i]=allocate(2);
}

