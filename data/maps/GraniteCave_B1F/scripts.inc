GraniteCave_B1F_MapScripts::
	.byte 0


CrystalOnixRoar::
	lockall
	waitse
	playmoncry SPECIES_ORANGE_ONIX, 0
	waitmoncry
	applymovement EVENT_OBJ_ID_PLAYER, CrystalOnixRoarPlayerExclamation
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, CrystalOnixCamera1
	waitmovement 0
	waitse
	playmoncry SPECIES_ORANGE_ONIX, 0
	waitmoncry
	delay 10
	applymovement EVENT_OBJ_ID_CAMERA, CrystalOnixCamera2
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_ROUTE105_STATE, 10
	releaseall
	end


CrystalOnixCamera1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

CrystalOnixCamera2:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CrystalOnixRoarPlayerExclamation:
	emote_exclamation_mark
	face_right
	step_end

CrystalCaveBrockB1F::
	lockall
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 26
	goto_if_eq CrystalCaveBrockB1F_2
CrystalCaveBrockB1F_1:
	compare VAR_TEMP_1, 27
	goto_if_eq CrystalCaveBrockB1F_5
CrystalCaveBrockB1F_4:
	end

CrystalCaveBrockB1F_2:
	applymovement EVENT_OBJ_ID_PLAYER, WalkToBrock1
	waitmovement 0
	delay 25
	applymovement 2, BrockLookLeft
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	msgbox CrystalCaveBrockIntro, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_FREDRICK, CrystalCaveBrockDefeat
	msgbox CrystalCaveBrockPost, MSGBOX_AUTOCLOSE
	turnobject 2, 2
	setvar VAR_ROUTE105_STATE, 11
	releaseall
	goto CrystalCaveBrockB1F_1

CrystalCaveBrockB1F_5:
	applymovement EVENT_OBJ_ID_PLAYER, WalkToBrock2
	waitmovement 0
	delay 25
	applymovement 2, BrockLookLeft
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	msgbox CrystalCaveBrockIntro, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_FREDRICK, CrystalCaveBrockDefeat
	msgbox CrystalCaveBrockPost, MSGBOX_AUTOCLOSE
	turnobject 2, 2
	setvar VAR_ROUTE105_STATE, 11
	releaseall
	goto CrystalCaveBrockB1F_4


WalkToBrock1:
	walk_right
	walk_right
	walk_up
	face_right
	step_end

WalkToBrock2:
	walk_up
	walk_up
	walk_right
	step_end

BrockLookLeft:
	emote_exclamation_mark
	face_left
	step_end

CrystalOnixBattle::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ORANGE_ONIX, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_ORANGE_ONIX, 20, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CrystalOnixBattle_2
CrystalOnixBattle_1:
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq CrystalOnixBattle_5
CrystalOnixBattle_4:
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq CrystalOnixBattle_8
CrystalOnixBattle_7:
	fadescreenswapbuffers 1
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers 0
	setflag FLAG_DEFEATED_REGICE
	release
	end

CrystalOnixBattle_2:
	goto IslandCave_EventScript_DefeatedRegice
	goto CrystalOnixBattle_1

CrystalOnixBattle_5:
	goto IslandCave_EventScript_RanFromRegice
	goto CrystalOnixBattle_4

CrystalOnixBattle_8:
	goto IslandCave_EventScript_RanFromRegice
	goto CrystalOnixBattle_7


BrockSalty::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x030, BrockSalty_2
	goto_if_set FLAG_DEFEATED_REGICE, BrockSalty_5
	msgbox BrockSalty_Text_3, MSGBOX_AUTOCLOSE
	turnobject 2, 2
	release
	end

BrockSalty_2:
	msgbox BrockSalty_Text_0, MSGBOX_AUTOCLOSE
	release
	end

BrockSalty_5:
	switch VAR_FACING
	case DIR_NORTH, BrockSalty_9
	case DIR_WEST, BrockSalty_10
	case DIR_EAST, BrockSalty_11
BrockSalty_7:
	release
	end

BrockSalty_9:
	msgbox BrockSalty_Text_1, MSGBOX_AUTOCLOSE
	turnobject 2, 2
	delay 70
	turnobject 2, 1
	msgbox BrockSalty_Text_2, MSGBOX_AUTOCLOSE
	setflag FLAG_UNUSED_0x030
	goto BrockSalty_7

BrockSalty_10:
	msgbox BrockSalty_Text_1, MSGBOX_AUTOCLOSE
	turnobject 2, 2
	delay 70
	turnobject 2, 4
	msgbox BrockSalty_Text_2, MSGBOX_AUTOCLOSE
	setflag FLAG_UNUSED_0x030
	goto BrockSalty_7

BrockSalty_11:
	msgbox BrockSalty_Text_1, MSGBOX_AUTOCLOSE
	turnobject 2, 2
	delay 70
	turnobject 2, 3
	msgbox BrockSalty_Text_2, MSGBOX_AUTOCLOSE
	setflag FLAG_UNUSED_0x030
	goto BrockSalty_7


BrockSalty_Text_0:
	.string "I'm staying here for a little while\nto research this cave, {PLAYER}.\pI hope our paths will cross\nagain someday.$"

BrockSalty_Text_1:
	.string "{PLAYER}, after just witnessing your\nbattle, I've realized that you must've\lbeen chosen by the CRYSTAL ONIX.\pHad you not come, it might've\nnot even revealed itself in the\lfirst place.\pI should've understood this sooner…$"

BrockSalty_Text_2:
	.string "I really appreciate you coming down\nhere, {PLAYER}.\pI'm going to hang around here for a\nlittle while to research this place.\pWho knows what secrets lie here?$"

BrockSalty_Text_3:
	.string "{PLAYER}, please go ahead and\nface the CRYSTAL ONIX!$"

CrystalCaveBrockIntro::
	.string "{PLAYER}, you made it!\p"
	.string "Well, then, as we promised, let's\n"
	.string "battle for the right to take on the\l"
	.string "CRYSTAL ONIX!$"

CrystalCaveBrockDefeat::
	.string "Seems like it's your turn this time…$"

CrystalCaveBrockPost::
	.string "{PLAYER}, that was amazing!\p"
	.string "You displayed skill that I have\n"
	.string "only seen from two other TRAINERS.\p"
	.string "You are truly worthy of facing the\n"
	.string "CRYSTAL ONIX.\p"
	.string "Please go ahead!$"
