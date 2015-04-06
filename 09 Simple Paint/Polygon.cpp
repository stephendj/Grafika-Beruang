#include "Polygon.hpp"

Polygon::Polygon() {
	n = 0;
}

Polygon::Polygon(string nama) {
	if(nama.compare("pesawat")==0) {
		e.push_back(Point(768,0));
		e.push_back(Point (735,44));
		e.push_back(Point (705,44));
		e.push_back(Point (680,65));
		e.push_back(Point (705,81));
		e.push_back(Point (735,81));
		e.push_back(Point (768,115));
		e.push_back(Point (778,115));
		e.push_back(Point (762,81));
		e.push_back(Point (782,81));
		e.push_back(Point (790,95));
		e.push_back(Point (799,95));
		e.push_back(Point (792,65));
		e.push_back(Point (799,30));
		e.push_back(Point (790,30));
		e.push_back(Point (782,44));
		e.push_back(Point (762,44));
		e.push_back(Point (778,0));
		e.push_back(Point(768,0));
	} else if (nama.compare("mouse")==0){
		e.push_back(Point (400,300));
		e.push_back(Point(400,310));
		e.push_back(Point(403,305));
		e.push_back(Point(405,308));
		e.push_back(Point (400,300));
	} else if(nama.compare("kapal")==0) {
		e.push_back(Point(5,590));
		e.push_back(Point (5,599));
		e.push_back(Point (99,599));
		e.push_back(Point (105,590));
		e.push_back(Point (79,590));
		e.push_back(Point (79,580));
		e.push_back(Point (73,580));
		e.push_back(Point (71,570));
		e.push_back(Point (67,570));
		e.push_back(Point (69,580));
		e.push_back(Point (61,580));
		e.push_back(Point (59,570));
		e.push_back(Point (55,570));
		e.push_back(Point (57,580));
		e.push_back(Point (49,580));
		e.push_back(Point (47,570));
		e.push_back(Point (43,570));
		e.push_back(Point (45,580));
		e.push_back(Point (39,580));
		e.push_back(Point (37,570));
		e.push_back(Point (33,570));
		e.push_back(Point (35,580));
		e.push_back(Point (27,580));
		e.push_back(Point (27,590));
		e.push_back(Point(5,590));
	} else if(nama.compare("ikan")==0) {
		e.push_back(Point (31,582));
		e.push_back(Point (38,586));
		e.push_back(Point (57,582));
		e.push_back(Point (64,582));
		e.push_back(Point (64,584));
		e.push_back(Point (69,588));
		e.push_back(Point (64,593));
		e.push_back(Point (54,595));
		e.push_back(Point (43,593));
		e.push_back(Point (38,592));
		e.push_back(Point (31,597));
		e.push_back(Point (33,590));
		e.push_back(Point (31,582));
	} else if(nama.compare("burung")==0) {
		e.push_back(Point (705,50));
		e.push_back(Point (714,49));
		e.push_back(Point (720,48));
		e.push_back(Point (729,51));
		e.push_back(Point (736,55));
		e.push_back(Point (746,58));
		e.push_back(Point (763,63));
		e.push_back(Point (770,65));
		e.push_back(Point (778,69));
		e.push_back(Point (782,68));
		e.push_back(Point (777,72));
		e.push_back(Point (763,75));
		e.push_back(Point (757,78));
		e.push_back(Point (749,81));
		e.push_back(Point (733,81));
		e.push_back(Point (721,77));
		e.push_back(Point (714,68));
		e.push_back(Point (714,55));
		e.push_back(Point (710,52));	
		e.push_back(Point (705,50));
	} else if(nama.compare("heli")==0){
		e.push_back(Point (666, 144));
		e.push_back(Point (669,160));
		e.push_back(Point (684,169));
		e.push_back(Point (705,171));
		e.push_back(Point (726,165));
		e.push_back(Point (742,151));
		e.push_back(Point (782,146));
		e.push_back(Point (785,152));
		e.push_back(Point (792,157));
		e.push_back(Point (794,116));
		e.push_back(Point (785,124));
		e.push_back(Point (784,136));
		e.push_back(Point (742,140));
		e.push_back(Point (729,127));
		e.push_back(Point (706,121));
		e.push_back(Point (677,130));
		e.push_back(Point (666, 144));
	} else if(nama.compare("baling1")==0){
		e.push_back(Point (705,84));
		e.push_back(Point (701,34));
		e.push_back(Point (709,34));
		e.push_back(Point (705,84));
	} else if(nama.compare("baling2")==0){
		e.push_back(Point (705,84));
		e.push_back(Point (660,104));
		e.push_back(Point (665,112));
		e.push_back(Point (705,84));
	} else if(nama.compare("baling3")==0){
		e.push_back(Point (705,84));
		e.push_back(Point (745,111));
		e.push_back(Point (750,104));
		e.push_back(Point (705,84));
	} else if(nama.compare("body-heli")==0){
		e.push_back(Point (706,121)); //b
		e.push_back(Point (677,130)); //c
		e.push_back(Point (666,144)); //d
		e.push_back(Point (669,160)); //e
		e.push_back(Point (684,169)); //f
		e.push_back(Point (705,171)); //g
		e.push_back(Point (692,135));
		e.push_back(Point (706,121)); //b
	} else if(nama.compare("tail-heli")==0){
		e.push_back(Point (706,121));//b
		e.push_back(Point (692,135));
		e.push_back(Point (705,171));//g
		e.push_back(Point (726,165));//h
		e.push_back(Point (742,151));//i
		e.push_back(Point (782,146));//j
		e.push_back(Point (785,152));//k
		e.push_back(Point (792,157));//l
		e.push_back(Point (794,116));//m
		e.push_back(Point (785,124));//n
		e.push_back(Point (784,136));//o
		e.push_back(Point (742,140));//p
		e.push_back(Point (729,127));//a
		e.push_back(Point (706,121));//b
	} else if (nama.compare("body-balloon")==0) {
		e.push_back(Point(480, 150));
		e.push_back(Point(520, 150));
		e.push_back(Point(520, 170));
		e.push_back(Point(480, 170));
		e.push_back(Point(480, 150));
	} else if (nama.compare("window")==0) {
		e.push_back(Point(0,0));
		e.push_back(Point(300,0));
		e.push_back(Point(300,160));
		e.push_back(Point(0,160));
		e.push_back(Point(0,0));
	} else if (nama.compare("square")==0) {
		e.push_back(Point(10,10));
		e.push_back(Point(50,10));
		e.push_back(Point(50,50));
		e.push_back(Point(10,50));
		e.push_back(Point(10,10));
	} else if (nama.compare("kapalkecil")==0) {
		e.push_back(Point(30,152));
		e.push_back(Point(30,156));
		e.push_back(Point(77,156));
		e.push_back(Point(80,152));
		e.push_back(Point(67,152));
		e.push_back(Point(67,147));
		e.push_back(Point(64,147));
		e.push_back(Point(63,142));
		e.push_back(Point(61,142));
		e.push_back(Point(62,147));
		e.push_back(Point(58,147));
		e.push_back(Point(57,142));
		e.push_back(Point(55,142));
		e.push_back(Point(56,147));
		e.push_back(Point(52,147));
		e.push_back(Point(51,142));
		e.push_back(Point(49,142));
		e.push_back(Point(50,147));
		e.push_back(Point(47,147));
		e.push_back(Point(46,142));
		e.push_back(Point(44,142));
		e.push_back(Point(45,147));
		e.push_back(Point(41,147));
		e.push_back(Point(41,152));
		e.push_back(Point(30,152));
	} else if(nama.compare("baling1kecil")==0){
		e.push_back(Point (710,29));
		e.push_back(Point (708,16));
		e.push_back(Point (709,16));
		e.push_back(Point (710,29));
	} else if(nama.compare("baling2kecil")==0){
		e.push_back(Point (710,29));
		e.push_back(Point (699,34));
		e.push_back(Point (701,36));
		e.push_back(Point (710,29));
	} else if(nama.compare("baling3kecil")==0){
		e.push_back(Point (710,29));
		e.push_back(Point (719,34));
		e.push_back(Point (720,32));
		e.push_back(Point (710,29));
	} else if(nama.compare("body-helikecil")==0){
		e.push_back(Point (711,37)); //b
		e.push_back(Point (702,39)); //c
		e.push_back(Point (699,44)); //d
		e.push_back(Point (700,48)); //e
		e.push_back(Point (704,51)); //f
		e.push_back(Point (711,52)); //g
		e.push_back(Point (707,41));
		e.push_back(Point (711,37)); //b
	} else if(nama.compare("tail-helikecil")==0){
		e.push_back(Point (711,37));//b
		e.push_back(Point (707,41));
		e.push_back(Point (711,52));//g
		e.push_back(Point (717,50));//h
		e.push_back(Point (722,46));//i
		e.push_back(Point (734,44));//j
		e.push_back(Point (735,46));//k
		e.push_back(Point (737,47));//l
		e.push_back(Point (738,35));//m
		e.push_back(Point (735,37));//n
		e.push_back(Point (735,41));//o
		e.push_back(Point (722,42));//p
		e.push_back(Point (718,38));//a
		e.push_back(Point (711,37));//b
	} else if (nama.compare("pickerBox")==0){
		e.push_back(Point(151,101));
		e.push_back(Point(151,139));
		e.push_back(Point(189,139));
		e.push_back(Point(189,101));
		e.push_back(Point(151,101));
	} else if (nama.compare("start")==0){
		e.push_back(Point(300,330));
		e.push_back(Point(500,330));
		e.push_back(Point(500,430));
		e.push_back(Point(300,430));
		e.push_back(Point(300,330));
	} else if (nama.compare("exit")==0){
		e.push_back(Point(300,450));
		e.push_back(Point(500,450));
		e.push_back(Point(500,550));
		e.push_back(Point(300,550));
		e.push_back(Point(300,450));
	} else if (nama.compare("pointer")==0){
		e.push_back(Point(220,340));
		e.push_back(Point(280,380));
		e.push_back(Point(220,420));
		e.push_back(Point(220,400));
		e.push_back(Point(260,380));
		e.push_back(Point(220,360));
		e.push_back(Point(220,340));
	} else if(nama.compare("hurufS")==0) { 
		e.push_back(Point(311,335)); 
		e.push_back(Point(345,335)); 
		e.push_back(Point(345,347)); 
		e.push_back(Point(323,347)); 
		e.push_back(Point(323,374)); 
		e.push_back(Point(345,374)); 
		e.push_back(Point(345,425)); 
		e.push_back(Point(311,425)); 
		e.push_back(Point(311,413)); 
		e.push_back(Point(333,413)); 
		e.push_back(Point(333,386)); 
		e.push_back(Point(311,386)); 
		e.push_back(Point(311,335)); 
	} else if(nama.compare("hurufT")==0) {
		e.push_back(Point(350,335)); 
		e.push_back(Point(385,335)); 
		e.push_back(Point(385,347)); 
		e.push_back(Point(374,347)); 
		e.push_back(Point(374,425)); 
		e.push_back(Point(362,425)); 
		e.push_back(Point(362,347)); 
		e.push_back(Point(350,347)); 
		e.push_back(Point(350,335)); 
	} else if(nama.compare("hurufA")==0) { 
		e.push_back(Point(384,425)); 
		e.push_back(Point(401,335)); 
		e.push_back(Point(418,425)); 
		e.push_back(Point(410,425)); 
		e.push_back(Point(406,400)); 
		e.push_back(Point(396,400)); 
		e.push_back(Point(392,425)); 
		e.push_back(Point(384,425)); 
	} else if(nama.compare("hurufR")==0) { 
		e.push_back(Point(420,335)); 
		e.push_back(Point(454,335)); 
		e.push_back(Point(454,380)); 
		e.push_back(Point(443,380)); 
		e.push_back(Point(454,425)); 
		e.push_back(Point(443,425)); 
		e.push_back(Point(432,380)); 
		e.push_back(Point(432,425)); 
		e.push_back(Point(420,425)); 
		e.push_back(Point(420,335)); 
	} else if (nama.compare("hurufE")==0){
		e.push_back(Point(328,455));
		e.push_back(Point(362,455));
		e.push_back(Point(362,473));
		e.push_back(Point(345,473));
		e.push_back(Point(345,491));
		e.push_back(Point(362,491));
		e.push_back(Point(362,509));
		e.push_back(Point(345,509));
		e.push_back(Point(345,527));
		e.push_back(Point(362,527));
		e.push_back(Point(362,545));
		e.push_back(Point(328,545));
		e.push_back(Point(328,455));
	} else if (nama.compare("hurufX")==0){
		e.push_back(Point(365,455));
		e.push_back(Point(375,455));
		e.push_back(Point(382,495));
		e.push_back(Point(389,455));
		e.push_back(Point(399,455));
		e.push_back(Point(389,500));
		e.push_back(Point(399,545));
		e.push_back(Point(389,545));
		e.push_back(Point(382,505));
		e.push_back(Point(375,545));
		e.push_back(Point(365,545));
		e.push_back(Point(375,500));
		e.push_back(Point(365,455));
	} else if (nama.compare("hurufI")==0){
		e.push_back(Point(402,455));
		e.push_back(Point(436,455));
		e.push_back(Point(436,470));
		e.push_back(Point(424,470));
		e.push_back(Point(424,530));
		e.push_back(Point(436,530));
		e.push_back(Point(436,545));
		e.push_back(Point(402,545));
		e.push_back(Point(402,530));
		e.push_back(Point(414,530));
		e.push_back(Point(414,470));
		e.push_back(Point(402,470));
		e.push_back(Point(402,455));
	} else if (nama.compare("garisbawah")==0){
		e.push_back(Point(660,89));
		e.push_back(Point(794,89));
	} else if (nama.compare("p")==0){
		e.push_back(Point(660,84));
		e.push_back(Point(660,67));
		e.push_back(Point(667,67));
		e.push_back(Point(669,68));
		e.push_back(Point(670,73));
		e.push_back(Point(669,74));
		e.push_back(Point(668,74));
		e.push_back(Point(666,75));
		e.push_back(Point(660,76));
	} else if (nama.compare("i")==0){
		e.push_back(Point(675,67));
		e.push_back(Point(675,84));
	} else if (nama.compare("c1")==0){
		e.push_back(Point(693,69));
		e.push_back(Point(692,67));
		e.push_back(Point(687,67));
		e.push_back(Point(684,68));
		e.push_back(Point(682,72));
		e.push_back(Point(682,78));
		e.push_back(Point(683,80));
		e.push_back(Point(687,84));
		e.push_back(Point(691,84));
		e.push_back(Point(693,81));
	} else if (nama.compare("k1")==0){
		e.push_back(Point(697,67));
		e.push_back(Point(697,84));
	}else if (nama.compare("k2")==0){
		e.push_back(Point(707,67));
		e.push_back(Point(697,75));
		e.push_back(Point(707,84));
	}else if (nama.compare("c2")==0){
		e.push_back(Point(729,69));
		e.push_back(Point(727,67));
		e.push_back(Point(723,67));
		e.push_back(Point(720,68));
		e.push_back(Point(718,72));
		e.push_back(Point(718,78));
		e.push_back(Point(719,80));
		e.push_back(Point(723,84));
		e.push_back(Point(727,84));
		e.push_back(Point(729,81));
	}else if (nama.compare("o1")==0){
		e.push_back(Point(737,67));
		e.push_back(Point(741,67));
		e.push_back(Point(744,68));
		e.push_back(Point(745,70));
		e.push_back(Point(746,74));
		e.push_back(Point(745,78));
		e.push_back(Point(744,81));
		e.push_back(Point(741,84));
		e.push_back(Point(737,84));
		e.push_back(Point(734,81));
		e.push_back(Point(732,78));
		e.push_back(Point(732,74));
		e.push_back(Point(732,72));
		e.push_back(Point(735,68));
		e.push_back(Point(737,67));
	}else if (nama.compare("l")==0){
		e.push_back(Point(753,67));
		e.push_back(Point(753,84));
		e.push_back(Point(761,84));
	}else if (nama.compare("o2")==0){
		e.push_back(Point(769,67));
		e.push_back(Point(773,67));
		e.push_back(Point(776,68));
		e.push_back(Point(777,70));
		e.push_back(Point(778,74));
		e.push_back(Point(777,78));
		e.push_back(Point(776,81));
		e.push_back(Point(773,84));
		e.push_back(Point(769,84));
		e.push_back(Point(766,81));
		e.push_back(Point(764,78));
		e.push_back(Point(764,74));
		e.push_back(Point(764,72));
		e.push_back(Point(767,68));
		e.push_back(Point(769,67));
	}else if (nama.compare("r")==0){
		e.push_back(Point(784,84));
		e.push_back(Point(784,67));
		e.push_back(Point(791,67));
		e.push_back(Point(793,68));
		e.push_back(Point(794,73));
		e.push_back(Point(793,74));
		e.push_back(Point(792,74));
		e.push_back(Point(790,75));
		e.push_back(Point(788,76));
		e.push_back(Point(791,78));
		e.push_back(Point(793,81));
		e.push_back(Point(794,84));
	}else if (nama.compare("hurufY")==0){
		e.push_back(Point(160,140));
		e.push_back(Point(195,140));
		e.push_back(Point(235,220));
		e.push_back(Point(280,140));
		e.push_back(Point(310,140));
		e.push_back(Point(250,240));
		e.push_back(Point(250,290));
		e.push_back(Point(220,290));
		e.push_back(Point(220,240));
		e.push_back(Point(160,140));
	}else if (nama.compare("hurufO")==0){
		e.push_back(Point(325,215));
		e.push_back(Point(360,140));
		e.push_back(Point(440,140));
		e.push_back(Point(475,215));
		e.push_back(Point(440,290));
		e.push_back(Point(360,290));
		e.push_back(Point(325,215));
	} else if (nama.compare("hurufU")==0){
		e.push_back(Point(490,140));
		e.push_back(Point(540,140));
		e.push_back(Point(540,240));
		e.push_back(Point(590,240));
		e.push_back(Point(590,140));
		e.push_back(Point(640,140));
		e.push_back(Point(640,290));
		e.push_back(Point(490,290));
		e.push_back(Point(490,140));
	} else if(nama.compare("hurufW")==0) {
		e.push_back(Point(160,310));
		e.push_back(Point(178,310));
		e.push_back(Point(202,445));
		e.push_back(Point(226,310));
		e.push_back(Point(244,310));
		e.push_back(Point(268,445));
		e.push_back(Point(292,310));
		e.push_back(Point(310,310));
		e.push_back(Point(277,460));
		e.push_back(Point(259,460));
		e.push_back(Point(235,325));
		e.push_back(Point(211,460));
		e.push_back(Point(193,460));
		e.push_back(Point(160,310));
	} else if (nama.compare("hurufI-win")==0){
		e.push_back(Point(325,310));
		e.push_back(Point(475,310));
		e.push_back(Point(475,340));
		e.push_back(Point(420,340));
		e.push_back(Point(420,430));
		e.push_back(Point(475,430));
		e.push_back(Point(475,460));
		e.push_back(Point(325,460));
		e.push_back(Point(325,430));
		e.push_back(Point(380,430));
		e.push_back(Point(380,340));
		e.push_back(Point(325,340));
		e.push_back(Point(325,310));
	} else if(nama.compare("hurufN")==0) {
		e.push_back(Point(490,460));
		e.push_back(Point(490,310));
		e.push_back(Point(515,310));
		e.push_back(Point(615,435));
		e.push_back(Point(615,310));
		e.push_back(Point(640,310));
		e.push_back(Point(640,460));
		e.push_back(Point(615,460));
		e.push_back(Point(515,335));
		e.push_back(Point(515,460));
		e.push_back(Point(490,460));
	}else if(nama.compare("beruangB")==0) {
		e.push_back(Point(92,200));
		e.push_back(Point(92,110));
		e.push_back(Point(140,110));
		e.push_back(Point(160,130));
		e.push_back(Point(140,150));
		e.push_back(Point(176,162));
		e.push_back(Point(178,175));
		e.push_back(Point(140,200));
		e.push_back(Point(122,200));
		e.push_back(Point(122,186));
		e.push_back(Point(140,186));
		e.push_back(Point(154,173));
		e.push_back(Point(154,166));
		e.push_back(Point(130,160));
		e.push_back(Point(130,140));
		e.push_back(Point(140,130));
		e.push_back(Point(110,130));
		e.push_back(Point(110,200));
		e.push_back(Point(92,200));
	} else if(nama.compare("beruangE")==0) {
		e.push_back(Point(182,110)); 
		e.push_back(Point(268,110)); 
		e.push_back(Point(268,130));
		e.push_back(Point(200,130)); 
		e.push_back(Point(200,140)); 
		e.push_back(Point(250,140)); 
		e.push_back(Point(250,160)); 
		e.push_back(Point(200,160)); 
		e.push_back(Point(200,174)); 
		e.push_back(Point(268,174)); 
		e.push_back(Point(268,200)); 
		e.push_back(Point(182,200)); 
		e.push_back(Point(182,110));
	} else if(nama.compare("beruangR")==0) {
		e.push_back(Point(272,200));
		e.push_back(Point(272,110));
		e.push_back(Point(330,110));
		e.push_back(Point(358,140));
		e.push_back(Point(330,163));
		e.push_back(Point(358,200));
		e.push_back(Point(330,200));
		e.push_back(Point(300,164));
		e.push_back(Point(300,150));
		e.push_back(Point(330,150));
		e.push_back(Point(330,130));
		e.push_back(Point(282,130));
		e.push_back(Point(282,200));
		e.push_back(Point(272,200));
	} else if(nama.compare("beruangU")==0) {
		e.push_back(Point(362,110));
		e.push_back(Point(362,200));
		e.push_back(Point(448,200));
		e.push_back(Point(448,120));
		e.push_back(Point(430,120));
		e.push_back(Point(430,178));
		e.push_back(Point(380,178));
		e.push_back(Point(380,110));
		e.push_back(Point(362,110));
	} else if(nama.compare("beruangA")==0) {
		e.push_back(Point(452,200));
		e.push_back(Point(452,140));
		e.push_back(Point(494,110));
		e.push_back(Point(538,140));
		e.push_back(Point(538,200));
		e.push_back(Point(515,200));
		e.push_back(Point(515,175));
		e.push_back(Point(478,175));
		e.push_back(Point(478,163));
		e.push_back(Point(516,163));
		e.push_back(Point(516,150));
		e.push_back(Point(496,138));
		e.push_back(Point(473,150));
		e.push_back(Point(473,200));
		e.push_back(Point(452,200));
	} else if(nama.compare("beruangN")==0) {
		e.push_back(Point(542,200));
		e.push_back(Point(542,110));
		e.push_back(Point(568,110));
		e.push_back(Point(610,174));
		e.push_back(Point(610,110));
		e.push_back(Point(628,110));
		e.push_back(Point(628,200));
		e.push_back(Point(606,200));
		e.push_back(Point(560,130));
		e.push_back(Point(560,200));
		e.push_back(Point(542,200));
	} else if(nama.compare("beruangG")==0) {
		e.push_back(Point(718,130));
		e.push_back(Point(650,130));
		e.push_back(Point(650,175));
		e.push_back(Point(700,175));
		e.push_back(Point(700,163));
		e.push_back(Point(662,163));
		e.push_back(Point(662,150));
		e.push_back(Point(718,150));
		e.push_back(Point(718,175));
		e.push_back(Point(700,200));
		e.push_back(Point(650,200));
		e.push_back(Point(632,175));
		e.push_back(Point(632,130));
		e.push_back(Point(652,110));
		e.push_back(Point(700,110));
		e.push_back(Point(718,130));
	} 

	n = e.size();
}

Polygon::Polygon(vector<Point> P) {
	e = P;
	e.push_back(e[0]);
	n = e.size();
}


Polygon::Polygon(const Polygon& p) {
	n = p.n;
	e = p.e;
	r = p.r;
	g = p.g;
	b = p.b;
	t = p.t;
}

Polygon& Polygon::operator=(const Polygon& p) {
	n = p.n;
	e = p.e;
	r = p.r;
	g = p.g;
	b = p.b;
	t = p.t;

	return *this;
}

Polygon& Polygon::operator<<(const vector<Point>& P) {
	n = P.size();
	e = P;
	e.push_back(e[0]);

	return *this;
}

void Polygon::setZ(int z) {
	for (int i=0; i<e.size(); ++i) {
		e[i].z=z;
	}
}

void Polygon::setRGBT(int r, int g, int b, int t) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->t = t;
}

void Polygon::insert(Point point) {
	e[n] = point;
	e.push_back(e[0]);
	++n;
}

void Polygon::mirrorTransform() {
	int x = getMidX();
	for(int i=0;i<n;i++) {
		e[i].x = x + (x-e[i].x);
	}
}

float Polygon::getMidY() {
	int i=1;
	float maxY=e[0].y;
	while(i<n) {
		if(e[i].y>maxY) {
			maxY=e[i].y;
		}
		i++;
	}

	i=1;
	float minY=e[0].y;
	while(i<n) {
		if(e[i].y<minY) {
			minY=e[i].y;
		}
		i++;
	}

	return (maxY + minY)/2;
}

float Polygon::getMidX() {
	int i=1;
	float maxX=e[0].x;
	while(i<n) {
		if(e[i].x>maxX) {
			maxX=e[i].x;
		}
		i++;
	}

	i=1;
	float minX=e[0].x;
	while(i<n) {
		if(e[i].x<minX) {
			minX=e[i].x;
		}
		i++;
	}

	return (maxX + minX)/2;
}

float Polygon::getMaxX() {
	int i=1;
	float maxX=e[0].x;
	while(i<n) {
		if(e[i].x>maxX) {
			maxX=e[i].x;
		}
		i++;
	}
	return maxX;
}

float Polygon::getMinX() {
	int i=1;
	float minX=e[0].x;
	while(i<n) {
		if(e[i].x<minX) {
			minX=e[i].x;
		}
		i++;
	}
	return minX;
}

float Polygon::getMaxY() {
	int i=1;
	float maxY=e[0].y;
	while(i<n) {
		if(e[i].y>maxY) {
			maxY=e[i].y;
		}
		i++;
	}
	return maxY;
}

float Polygon::getMinY() {
	int i=1;
	float minY=e[0].y;
	while(i<n) {
		if(e[i].y<minY) {
			minY=e[i].y;
		}
		i++;
	}
	return minY;
}

bool Polygon::isBoundary() {
	int i=0;
	bool found = false;
	while(i<n && !found) {
		if(e[i].x>799 || e[i].x<=0 || e[i].y>160 || e[i].y<=0) {
			found = true;
		}
		i++;
	}
	return found;
}

void Polygon::moveRight(float dx) {
	int i=0;
	while(i<n)
	{
		e[i].x=e[i].x+dx;
		i++;
	}
}

void Polygon::moveLeft(float dx) {
	int i=0;
	while(i<n)
	{
		e[i].x=e[i].x-dx;
		i++;
	}
}


void Polygon::moveUp(float dy) {
	int i=0;
	while(i<n)
	{
		e[i].y=e[i].y-dy;
		i++;
	}
}

void Polygon::moveDown(float dy) {
	int i=0;
	while(i<n)
	{
		e[i].y=e[i].y+dy;
		i++;
	}
}


void Polygon::rotate(double dg){
	int i=1;
	double con=1;
	double tempx,tempy;
	while(i<n){
		tempx= ((cos(dg*con)*(e[i].x - e[0].x)) - (sin(dg*con)*(e[i].y - e[0].y)) + e[0].x);
		tempy= ((sin(dg*con)*(e[i].x - e[0].x)) + (cos(dg*con)*(e[i].y - e[0].y)) + e[0].y);
		e[i].x = tempx;
		e[i].y = tempy;
		i++;
	}
}