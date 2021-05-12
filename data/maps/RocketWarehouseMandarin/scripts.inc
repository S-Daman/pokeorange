RocketWarehouseMandarin_MapScripts::
	.byte 0


MandarinWarehouse1F_Warp::
	lock
	warpteleport MAP_ROCKET_WAREHOUSE_MANDARIN, 255, 1, 13
	waitstate
	release
	end


MandarinWarehouse1F_Carr::
	lock
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 21
	goto_if_eq MandarinWarehouse1F_Carr_2
MandarinWarehouse1F_Carr_1:
	compare VAR_TEMP_0, 20
	goto_if_eq MandarinWarehouse1F_Carr_5
MandarinWarehouse1F_Carr_4:
	compare VAR_TEMP_0, 19
	goto_if_eq MandarinWarehouse1F_Carr_8
MandarinWarehouse1F_Carr_7:
	fadedefaultbgm
	fadescreen 1
	removeobject 1
	removeobject 2
	setflag FLAG_HIDE_CARR_1F
	setflag FLAG_HIDE_SCIENTIST_1F
	setvar VAR_ROUTE105_STATE, 8
	fadescreen 0
	release
	end

MandarinWarehouse1F_Carr_2:
	applymovement EVENT_OBJ_ID_PLAYER, CarrScriptPlayerMove1
	applymovement 1, CarrMove1
	waitmovement 1
	playbgm MUS_MGM0, 1
	msgbox MandarinWarehouse1F_CarrIntro, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_TABITHA_1, MandarinWarehouse1F_CarrDefeat
	msgbox MandarinWarehouse1F_CarrPost, MSGBOX_AUTOCLOSE
	goto MandarinWarehouse1F_Carr_1

MandarinWarehouse1F_Carr_5:
	applymovement EVENT_OBJ_ID_PLAYER, CarrScriptPlayerMove2
	applymovement 1, CarrMove2
	waitmovement 1
	playbgm MUS_MGM0, 1
	msgbox MandarinWarehouse1F_CarrIntro, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_TABITHA_1, MandarinWarehouse1F_CarrDefeat
	msgbox MandarinWarehouse1F_CarrPost, MSGBOX_AUTOCLOSE
	goto MandarinWarehouse1F_Carr_4

MandarinWarehouse1F_Carr_8:
	applymovement EVENT_OBJ_ID_PLAYER, CarrScriptPlayerMove3
	applymovement 1, CarrMove3
	waitmovement 1
	playbgm MUS_MGM0, 1
	msgbox MandarinWarehouse1F_CarrIntro, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_TABITHA_1, MandarinWarehouse1F_CarrDefeat
	msgbox MandarinWarehouse1F_CarrPost, MSGBOX_AUTOCLOSE
	goto MandarinWarehouse1F_Carr_7


CarrMove1:
	delay_4
	delay_4
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

CarrScriptPlayerMove1:
	walk_left
	walk_left
	step_end

CarrMove2:
	delay_4
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

CarrScriptPlayerMove2:
	walk_left
	walk_up
	face_left
	step_end

CarrMove3:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

CarrScriptPlayerMove3:
	walk_up
	face_left
	step_end

MandarinWarehouse1F_Grunt::
	trainerbattle_single TRAINER_GRUNT_PETALBURG_WOODS, MandarinWarehouse1F_GruntIntro, MandarinWarehouse1F_GruntDefeat
	msgbox MandarinWarehouse1F_GruntPost, MSGBOX_DEFAULT
	release
	end


MandarinWarehouse1F_Elevator::
	lock
	msgbox MandarinWarehouse1F_Elevator_Text_0, MSGBOX_AUTOCLOSE
	release
	end


MandarinWarehouse1F_Spin1::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera
	playse SE_W081
	waitmovement 0
	release
	end


lodamera:
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	step_end

MandarinWarehouse1F_Spin2::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera2
	playse SE_W081
	waitmovement 0
	release
	end


lodamera2:
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_down
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin3::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera3
	playse SE_W081
	waitmovement 0
	release
	end


lodamera3:
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin4::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera4
	playse SE_W081
	waitmovement 0
	release
	end


lodamera4:
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin5::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera5
	playse SE_W081
	waitmovement 0
	release
	end


lodamera5:
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin6::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera6
	playse SE_W081
	waitmovement 0
	release
	end


lodamera6:
	walk_fastest_down
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin7::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera7
	playse SE_W081
	waitmovement 0
	release
	end


lodamera7:
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin8::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera8
	playse SE_W081
	waitmovement 0
	release
	end


lodamera8:
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin9::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera9
	playse SE_W081
	waitmovement 0
	release
	end


lodamera9:
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin10::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera10
	playse SE_W081
	waitmovement 0
	warpteleport MAP_ROCKET_WAREHOUSE_MANDARIN, 255, 1, 13
	waitstate
	release
	end


lodamera10:
	walk_fastest_left
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	step_end

MandarinWarehouse1F_Spin11::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera11
	playse SE_W081
	waitmovement 0
	warpteleport MAP_ROCKET_WAREHOUSE_MANDARIN, 255, 1, 13
	waitstate
	release
	end


lodamera11:
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	step_end

MandarinWarehouse1F_Spin12::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera12
	playse SE_W081
	waitmovement 0
	release
	end


lodamera12:
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin13::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera13
	playse SE_W081
	waitmovement 0
	release
	end


lodamera13:
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin14::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera14
	playse SE_W081
	waitmovement 0
	release
	end


lodamera14:
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin15::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera15
	playse SE_W081
	waitmovement 0
	release
	end


lodamera15:
	walk_fastest_right
	walk_fastest_right
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin16::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera16
	playse SE_W081
	waitmovement 0
	release
	end


lodamera16:
	walk_fastest_right
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Spin17::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, lodamera17
	playse SE_W081
	waitmovement 0
	release
	end


lodamera17:
	walk_fastest_up
	walk_fastest_up
	step_end

MandarinWarehouse1F_Elevator_Text_0:
	.string "No!\nIt needs a CARD KEY!$"

MandarinWarehouse1F_CarrIntro::
	.string "Oh, hey, so you made it.\n"
	.string "Didn't you read the sign outside?\p"
	.string "Sorry, but I'm gonna have to get rid\n"
	.string "of you, brat.\p"
	.string "We can't have us, NEO TEAM ROCKET,\n"
	.string "meddled by a kid, too!$"

MandarinWarehouse1F_CarrDefeat::
	.string "No way!\n"
	.string "What is wrong with kids these days?!$"

MandarinWarehouse1F_CarrPost::
	.string "You may have won this time, but\n"
	.string "next time won't be so easy, kid.\p"
	.string "TEAM ROCKET's reign is back, and you\n"
	.string "haven't seen the last of us!$"

MandarinWarehouse1F_GruntIntro::
	.string "Hey, this is a private facility!\n"
	.string "You can't be around here!$"

MandarinWarehouse1F_GruntDefeat::
	.string "Please just scram already!$"

MandarinWarehouse1F_GruntPost::
	.string "It took me a while to design those\n"
	.string "ramp panels, but looks like they work\l"
	.string "flawlessly now.$"
