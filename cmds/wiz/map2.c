// Change by Server
// map.c
// by snowman@SJ 16/02/2000
// 地图的第一行必须是 〖xx地图〗。
// 每个地名后面必须紧跟它的英文名称，如： 石阶(shijie)

#include <ansi.h>
#include <room.h>
inherit F_CLEAN_UP;

#define MAP_DIR 	HELP_DIR + "map/"
#define LINE  "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
// 特有名称，哈哈！
#define ROOM_NAME "雪人找到的房间"

string map_place(object room, mapping exits);
int help(object me);

string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                           HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                           HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                           BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                           NOR, BOLD });
                           
        if( !str || !stringp(str) ) return 0;
        i = sizeof(color);
        while( i-- ) {
                str = replace_string(str, color[i], "");
        }
        return str;
}

string n_dir = "                   
               ＼           ┃           ／
                 ＼         ┃         ／
                   ＼       ┃       ／
                     ＼     ┃     ／\n";

string s_dir = "
                     ／     ┃     ＼
                   ／       ┃       ＼
                 ／         ┃         ＼
               ／           ┃           ＼\n";
                       

int main(object me, string arg)
{
        string *place, *line, name = "";
        object room;
        mapping exits;
        int i, j = -1;
        
        if( me->is_busy() || me->is_fighting())
        	return notify_fail("你现在正忙着呢。\n");
        	
        if( !arg || arg == "?") help(me);
        
        else if( arg == "all")
                me->start_more(read_file(MAP_DIR + "map_all"));
        
        else if( arg == "here" ){
        	if( me->query("combat_exp") > 3000 || !me->query("enter_wuguan")){
        		if( me->query("balance") < 100 && ! wizardp(me) )
        			return notify_fail("你的存款不够耶，无法显示地图。\n");
        	}
        
        	if(!objectp(room = environment(me)))
        		return notify_fail("你目前所在奇特，无法显示地图，请通知巫师。\n");
        
        	place = explode(base_name(room), "/");
        	if( place[0] != "area" && place[0] != "d")
        		return notify_fail("对不起，你目前所处之地无法显示地图。\n");
        		
        	if( sizeof(place) >= 3 && place[0] == "area"){
        		if( sizeof(place) > 3 )
        			arg = MAP_DIR + place[1] + "/" + place[2];
        		else arg = MAP_DIR + place[1] + "/" + place[1];
        	}
        	
        	else 	arg = MAP_DIR + place[1];
        	
        	if(wizardp(me) && me->query("env/debug"))
			write("Arg = "+arg+"\n");  
			
        	if( file_size(arg) <= 0) 
        		return notify_fail("对不起，你目前所处之地暂时还无地图。\n");
        	
        	if(!stringp(name = remove_ansi(room->query("short"))) )
        		return notify_fail("对不起，你目前所处之地没有地名，无法在地图上显示。\n");
        		
		line = explode(read_file(arg), "\n");
		
		for (i = 0; i < sizeof(line); i++) {
			if( strsrch(line[i], name+"("+place[sizeof(place)-1]+")") < 0 )
				continue;
			else{
				// 找到房间，并用特有名称代替。
				line[i] = replace_string( line[i], name+"("+place[sizeof(place)-1]+")", ROOM_NAME , 1);
				j = i;
				break;
			}
			
		}
		
		if(wizardp(me) && me->query("env/debug"))
			write("Lines = "+sizeof(line)+"，J = "+j+"\n");  
			
		if( j < 0) return notify_fail("\n对不起，你目前所处之「"+name+"」在地图中并没包括。\n\n");
		
		i = sizeof(line);
		if( i > 26 ){
			if (j <= 10)
				line = line[0..j+10];
			else line = line[0..0]+line[j-10..j+10];
		}
		
		arg = "";
		// 替换掉所有的房间英文文件名称，保留中文。
		for (i = 0; i < sizeof(line); i++) {
			for (j = 0; j < sizeof(line[i]); j++) {
                		if( line[i][j]>=40 && line[i][j] <= 125 )
                			continue;
                		else arg += sprintf("%c",line[i][j]);
                	}
                	arg += "\n";
                }

        	// 用房间名称替换掉特有名称。
        	arg = replace_string( arg, ROOM_NAME, BLINK+HIR+remove_ansi(room->query("short"))+NOR , 1);
        	// 输出。
        	write(HIC"\n你目前所在的「"HIR+name+HIC"」，以闪耀的红色标志在下面的地图中："NOR+ LINE + arg + LINE); 
        	me->start_busy(2);     
        }
        
        else if( arg == "place"){
        	if(!objectp(room = environment(me)))
        		return notify_fail("你目前所在奇特，无法显示地图，请通知巫师。\n");
        		
        	if( !mapp(exits = room->query("exits")) ) 
        		return notify_fail("这里没有任何明显的出路。\n");
 		
                write(map_place(room, exits));
                me->start_busy(2);
        }
        
        else if( file_size(MAP_DIR + arg) > 0 ) {
        	arg = read_file(MAP_DIR + arg);
        	for (i = 0; i < sizeof(arg); i++) {
                	if( arg[i]>=40 && arg[i] <= 125 )
                		continue;
        		else name += sprintf("%c",arg[i]);
        	}
        	me->start_more( name );
        }
        
        else return notify_fail("目前还没有这个地区的地图文件。\n");
	return 1;
	
}

string map_place(object room, mapping exits)
{
	string *place, str, name, my_room;
	string n1,n2,n3,n4,n5, s1,s2,s3,s4,s5, o1, o2, o3, o4, w1,w2, w3, e1,e2,e3;
	int i;
	
	place = sort_array(keys(exits), 1);
 	my_room = HIW+remove_ansi(room->query("short"))+NOR;
        str = HIC"\n这里是"+TASK_D->get_regions(base_name(room))+my_room+HIC"，共有"+chinese_number(sizeof(place))+"个出口，分别通往："NOR+LINE;
           
        for(i=0; i<sizeof(place); i++){
                if( objectp(room = load_object(exits[place[i]])) )
                	switch(place[i]){
                		case "northwest": n1 = remove_ansi(room->query("short"))+"(Nw)"; break;
                		case "north":     n2 = remove_ansi(room->query("short"))+"(N)";  break;
                		case "northeast": n3 = remove_ansi(room->query("short"))+"(Ne)"; break;
                		case "northup":	  n4 = remove_ansi(room->query("short"))+"(Nu)"; break;
                		case "northdown": n5 = remove_ansi(room->query("short"))+"(Nd)"; break;
                		case "southwest": s1 = remove_ansi(room->query("short"))+"(Sw)"; break;
                		case "south":     s2 = remove_ansi(room->query("short"))+"(S)";  break;
                		case "southeast": s3 = remove_ansi(room->query("short"))+"(Se)"; break;
                		case "southup":	  s4 = remove_ansi(room->query("short"))+"(Su)"; break;
                		case "southdown": s5 = remove_ansi(room->query("short"))+"(Sd)"; break;
                		case "west": 	  w1 = remove_ansi(room->query("short"))+"(W)";  break;
                		case "westup":	  w2 = remove_ansi(room->query("short"))+"(Wu)"; break;
                		case "westdown":  w3 = remove_ansi(room->query("short"))+"(Wd)"; break;
                		case "east":      e1 = remove_ansi(room->query("short"))+"(E)";  break;
                		case "eastup":	  e2 = remove_ansi(room->query("short"))+"(Eu)"; break;
                		case "eastdown":  e3 = remove_ansi(room->query("short"))+"(Ed)"; break;
                		case "enter":     o1 = "里面："+remove_ansi(room->query("short"))+"(Enter)"; break;
                		case "out":       o2 = "外面："+remove_ansi(room->query("short"))+"(Out)"; break;
                		case "up":        o3 = "上面："+remove_ansi(room->query("short"))+"(Up)"; break;
                		case "down":      o4 = "下面："+remove_ansi(room->query("short"))+"(Down)"; break;
                	}
	}
                
        // drew upper pic.
        if(stringp(n1) || stringp(n2) || stringp(n3) || stringp(n4) || stringp(n5)){
        	if(stringp(n4) )
                	str += sprintf("\t\t\t  %-18s", n4 );
                
                if(stringp(n1) || stringp(n2) || stringp(n3))
                	str += sprintf("\n\t%-16s  %-16s  %-16s", n1, n2, n3);
               	if(stringp(n5) )
                	str += sprintf("\n\t     ＼   \t  %-16s ／", n5 );
                str += n_dir;        	
                str = replace_string( str, "＼", stringp(n1)?"＼":"  ");
                str = replace_string( str, "┃", stringp(n2)?"┃":stringp(n4)?"┃":stringp(n5)?"┃":"  ");
                str = replace_string( str, "／", stringp(n3)?"／":"  ");
     	}
        // end upper pic.
                
        // drew middle pic.
        name = sprintf("      %10s   \t\t\t    %-16s", w2, e2);
        name += sprintf("\n      %10s ←━━  %-10s  ━━→ %-16s\n", w1, my_room, e1);
        name += sprintf("      %10s   \t\t\t    %-16s", w3, e3);
        if(stringp(w1) || stringp(w2) || stringp(w3) )
        	name = replace_string( name, "←━━", "━━━");
        else name = replace_string( name, "←━━", "      ");
       
       	if(stringp(e1) || stringp(e2) || stringp(e3) )
        	name = replace_string( name, "━━→", "━━━");
        else name = replace_string( name, "━━→", "      ");
        // end middle pic.
                
        // drew lower pic.
        if(stringp(s1) || stringp(s2) || stringp(s3) || stringp(s4) || stringp(s5)){
                name += sprintf(s_dir);
                if(stringp(s4) )
                	name += sprintf("\t     ／   \t  %-16s ＼\n", s4 );
                	
                if(stringp(s1) || stringp(s2) || stringp(s3))
                	name += sprintf("\t%-16s  %-16s  %-16s\n", s1, s2, s3);
               	if(stringp(s5) )
                	name += sprintf("\t\t\t  %-18s\n", s5 );
                name = replace_string( name, "＼", stringp(s3)?"＼":"  ");
                name = replace_string( name, "┃", stringp(s2)?"┃":stringp(s4)?"┃":stringp(s5)?"┃":"  ");
                name = replace_string( name, "／", stringp(s1)?"／":"  ");
        }
                
        // end lower pic.
                
        // connect pics and remove unused pots.
        str += name+"\n";
        if(stringp(o1))
               	str += sprintf("\t%-16s\n", o1);
        if(stringp(o2))
                str += sprintf("\t%-16s\n", o2);
        if(stringp(o3))
                str += sprintf("\t%-16s\n", o3);
        if(stringp(o4))
                str += sprintf("\t%-16s\n", o4);
        str = replace_string( str, "0 ", "  ");
        // end.
        return str+LINE;
}

int help(object me)
{
        write(@HELP
指令格式：
          map        	  : 显示本信息。
	  map <地区|all>  : 显示此<地区|全域>的地图。
	  map place       : 显示和你目前所在相连的区域。
	  map here	  : 显示你目前所在地在地图中的位置(还不完善)。
	  
这个指令让你可以获取一个地区的相关地图。

By snowman@SJ 16/02/2000
HELP);
        return 1;
}
