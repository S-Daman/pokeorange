Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_TUTGUY_SCRIPT2, Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto_if_set FLAG_TUTGUY_SCRIPT, Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm 3, 57, 25
	setobjectmovementtype 3, MOVEMENT_TYPE_WANDER_AROUND
	return


TutGuyTile::
	clearflag FLAG_TUTGUY_SCRIPT
	setvar VAR_ROUTE105_STATE, 4
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 21
	goto_if_eq TutGuyTile_2
	compare VAR_TEMP_1, 22
	goto_if_eq TutGuyTile_5
	compare VAR_TEMP_1, 23
	goto_if_eq TutGuyTile_11
	compare VAR_TEMP_0, 62
	goto_if_eq TutGuyTile_17
	compare VAR_TEMP_0, 63
	goto_if_eq TutGuyTile_22
	return

TutGuyTile_2:
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 3, TutGuyTile_Move_1
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	applymovement 3, TutGuyTile_Move_2
	waitmovement 0
	turnobject EVENT_OBJ_ID_PLAYER, 3
	msgbox TutGuyTile_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq TutGuyTile_8
	release
	applymovement 3, TutGuyTile_Move_3
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	delay 5
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	special StartWallyTutorialBattle
	waitstate
	lock
	faceplayer
	applymovement 3, TutGuyTile_Move_4
	waitmovement 0
	msgbox TutGuyTile_Text_2, MSGBOX_AUTOCLOSE
	applymovement 3, TutGuyTile_Move_5
	waitmovement 0
	special LoadPlayerParty
	setflag FLAG_TUTGUY_SCRIPT
	releaseall
	end

TutGuyTile_5:
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 3, TutGuyTile_Move_1
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	applymovement 3, TutGuyTile_Move_6
	waitmovement 0
	turnobject EVENT_OBJ_ID_PLAYER, 3
	msgbox TutGuyTile_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq TutGuyTile_14
	release
	applymovement 3, TutGuyTile_Move_3
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	delay 5
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	special StartWallyTutorialBattle
	waitstate
	lock
	faceplayer
	applymovement 3, TutGuyTile_Move_4
	waitmovement 0
	msgbox TutGuyTile_Text_2, MSGBOX_AUTOCLOSE
	applymovement 3, TutGuyTile_Move_7
	waitmovement 0
	special LoadPlayerParty
	setflag FLAG_TUTGUY_SCRIPT
	releaseall
	end

TutGuyTile_8:
	msgbox TutGuyTile_Text_1, MSGBOX_AUTOCLOSE
	applymovement 3, TutGuyTile_Move_10
	waitmovement 0
	release
	end

TutGuyTile_11:
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 3, TutGuyTile_Move_1
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	applymovement 3, TutGuyTile_Move_8
	waitmovement 0
	turnobject EVENT_OBJ_ID_PLAYER, 3
	msgbox TutGuyTile_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq TutGuyTile_20
	release
	applymovement 3, TutGuyTile_Move_3
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	delay 5
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	special StartWallyTutorialBattle
	waitstate
	lock
	faceplayer
	applymovement 3, TutGuyTile_Move_4
	waitmovement 0
	msgbox TutGuyTile_Text_2, MSGBOX_AUTOCLOSE
	applymovement 3, TutGuyTile_Move_9
	waitmovement 0
	special LoadPlayerParty
	setflag FLAG_TUTGUY_SCRIPT
	releaseall
	end

TutGuyTile_14:
	msgbox TutGuyTile_Text_1, MSGBOX_AUTOCLOSE
	applymovement 3, TutGuyTile_Move_11
	waitmovement 0
	release
	end

TutGuyTile_17:
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement 3, TutGuyTile_Move_1
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	applymovement 3, TutGuyTile_Hori_Move_6
	waitmovement 0
	turnobject EVENT_OBJ_ID_PLAYER, 1
	msgbox TutGuyTile_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq TutGuyTile_25
	release
	applymovement 3, TutGuyTile_Hori_Move_3
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	delay 5
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	special StartWallyTutorialBattle
	waitstate
	lock
	faceplayer
	applymovement 3, TutGuyTile_Hori_Move_4
	waitmovement 0
	msgbox TutGuyTile_Text_2, MSGBOX_AUTOCLOSE
	applymovement 3, TutGuyTile_Hori_Move_7
	waitmovement 0
	special LoadPlayerParty
	setflag FLAG_TUTGUY_SCRIPT
	releaseall
	end

TutGuyTile_20:
	msgbox TutGuyTile_Text_1, MSGBOX_AUTOCLOSE
	applymovement 3, TutGuyTile_Move_12
	waitmovement 0
	release
	end

TutGuyTile_22:
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement 3, TutGuyTile_Move_1
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	applymovement 3, TutGuyTile_Hori_Move_8
	waitmovement 0
	turnobject EVENT_OBJ_ID_PLAYER, 1
	msgbox TutGuyTile_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq TutGuyTile_28
	release
	applymovement 3, TutGuyTile_Hori_Move_3
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	delay 5
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	special StartWallyTutorialBattle
	waitstate
	lock
	faceplayer
	applymovement 3, TutGuyTile_Hori_Move_4
	waitmovement 0
	msgbox TutGuyTile_Text_2, MSGBOX_AUTOCLOSE
	applymovement 3, TutGuyTile_Hori_Move_9
	waitmovement 0
	special LoadPlayerParty
	setflag FLAG_TUTGUY_SCRIPT
	releaseall
	end

TutGuyTile_25:
	msgbox TutGuyTile_Text_1, MSGBOX_AUTOCLOSE
	applymovement 3, TutGuyTile_Hori_Move_11
	waitmovement 0
	release
	end

TutGuyTile_28:
	msgbox TutGuyTile_Text_1, MSGBOX_AUTOCLOSE
	applymovement 3, TutGuyTile_Hori_Move_11
	waitmovement 0
	release
	end


TutGuyTile_Move_1:
	emote_exclamation_mark
	step_end

TutGuyTile_Move_2:
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

TutGuyTile_Move_3:
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	emote_exclamation_mark
	step_end

TutGuyTile_Move_4:
	face_right
	step_end

TutGuyTile_Move_5:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

TutGuyTile_Move_6:
	walk_right
	walk_right
	walk_right
	step_end

TutGuyTile_Move_7:
	walk_left
	walk_left
	walk_left
	step_end

TutGuyTile_Move_8:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

TutGuyTile_Move_9:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

TutGuyTile_Move_10:
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

TutGuyTile_Move_11:
	walk_left
	walk_left
	walk_left
	step_end

TutGuyTile_Move_12:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

TutGuyTile_Hori_Move_3:
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	emote_exclamation_mark
	step_end

TutGuyTile_Hori_Move_4:
	face_up
	step_end

TutGuyTile_Hori_Move_6:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

TutGuyTile_Hori_Move_7:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TutGuyTile_Hori_Move_8:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

TutGuyTile_Hori_Move_9:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

TutGuyTile_Hori_Move_11:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

TutGuy::
	lock
	faceplayer
	goto_if_unset FLAG_TUTGUY_SCRIPT, TutGuy_2
TutGuy_1:
	msgbox TutGuy_Text_0, MSGBOX_AUTOCLOSE
	release
	end

TutGuy_2:
	goto_if_set FLAG_TUTGUY_SCRIPT2, TutGuy_5
	compare VAR_FACING, 1
	goto_if_eq TutGuy_8
	compare VAR_FACING, 2
	goto_if_eq TutGuy_11
	compare VAR_FACING, 3
	goto_if_eq TutGuy_17
	compare VAR_FACING, 4
	goto_if_eq TutGuy_22
	goto TutGuy_1

TutGuy_5:
	faceplayer
	msgbox TutGuy_Text_0, MSGBOX_AUTOCLOSE
	release
	end

TutGuy_8:
	msgbox TutGuy_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq TutGuy_14
	release
	applymovement 3, TutGuy_Move_1
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	delay 5
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	special StartWallyTutorialBattle
	waitstate
	lock
	faceplayer
	msgbox TutGuyTile_Text_2, MSGBOX_AUTOCLOSE
	special LoadPlayerParty
	setflag FLAG_TUTGUY_SCRIPT2
	releaseall
	end

TutGuy_11:
	msgbox TutGuy_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq TutGuy_20
	release
	applymovement 3, TutGuy_Move_2
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	delay 5
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	special StartWallyTutorialBattle
	waitstate
	lock
	faceplayer
	msgbox TutGuyTile_Text_2, MSGBOX_AUTOCLOSE
	special LoadPlayerParty
	setflag FLAG_TUTGUY_SCRIPT2
	releaseall
	end

TutGuy_14:
	msgbox TutGuyTile_Text_1, MSGBOX_AUTOCLOSE
	release
	end

TutGuy_17:
	msgbox TutGuy_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq TutGuy_25
	release
	applymovement 3, TutGuy_Move_3
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	delay 5
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	special StartWallyTutorialBattle
	waitstate
	lock
	faceplayer
	msgbox TutGuyTile_Text_2, MSGBOX_AUTOCLOSE
	special LoadPlayerParty
	setflag FLAG_TUTGUY_SCRIPT2
	releaseall
	end

TutGuy_20:
	msgbox TutGuyTile_Text_1, MSGBOX_AUTOCLOSE
	release
	end

TutGuy_22:
	msgbox TutGuy_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq TutGuy_28
	release
	applymovement 3, TutGuy_Move_4
	waitmovement 0
	waitse
	playse SE_PIN
	waitse
	delay 5
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	special StartWallyTutorialBattle
	waitstate
	lock
	faceplayer
	msgbox TutGuyTile_Text_2, MSGBOX_AUTOCLOSE
	special LoadPlayerParty
	setflag FLAG_TUTGUY_SCRIPT2
	releaseall
	end

TutGuy_25:
	msgbox TutGuyTile_Text_1, MSGBOX_AUTOCLOSE
	release
	end

TutGuy_28:
	msgbox TutGuyTile_Text_1, MSGBOX_AUTOCLOSE
	release
	end


TutGuy_Move_1:
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	emote_exclamation_mark
	step_end

TutGuy_Move_2:
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	emote_exclamation_mark
	step_end

TutGuy_Move_3:
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	emote_exclamation_mark
	step_end

TutGuy_Move_4:
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	emote_exclamation_mark
	step_end

Route49::
	lock
	msgbox Route49_Text_0, MSGBOX_SIGN
	giveitem_std ITEM_MAGOST_BERRY, 1, 0
	release
	return


Route49Port::
	lock
	msgbox Route49Port_Text_0, MSGBOX_SIGN
	release
	return


HoneyTreePlaceholder::
	lock
	msgbox HoneyTreePlaceholder_Text_0, MSGBOX_SIGN
	release
	return


Route49Youngster::
	lock
	faceplayer
	msgbox Route49Youngster_Text_0, MSGBOX_AUTOCLOSE
	return


Route49Camper::
	lock
	faceplayer
	msgbox Route49Camper_Text_0, MSGBOX_AUTOCLOSE
	release
	return


Route49Girl::
	lock
	faceplayer
	msgbox Route49Girl_Text_0, MSGBOX_AUTOCLOSE
	release
	return


Route49TrainerTips::
	lock
	msgbox Route49TrainerTips_Text_0, MSGBOX_SIGN
	release
	return


TutGuyTile_Text_0:
	.string "Hey, {PLAYER}!\nThat's a cool POKéMON you've got.\pWould you like me to demonstrate\nhow a POKéMON is caught?$"

TutGuyTile_Text_1:
	.string "Ah. That's alright.\pAnyway, if you ever want to learn how\nto catch POKéMON, just let me\lknow.$"

TutGuyTile_Text_2:
	.string "That's how it's done!\pThey are easier to catch if you\nweaken them first.$"

TutGuy_Text_0:
	.string "Be careful out there, {PLAYER}.\pI hear there are some shady\ncharacters around.$"

TutGuy_Text_1:
	.string "{PLAYER}!\pWould you like me to demonstrate\nhow a POKéMON is caught?$"

Route49_Text_0:
	.string "ROUTE 49\n{RIGHT_ARROW} VALENCIA ISLAND$"

Route49Port_Text_0:
	.string "VALENCIA ISLAND PORT$"

HoneyTreePlaceholder_Text_0:
	.string "This tree looks like it can be\nslathered with HONEY! $"

Route49Youngster_Text_0:
	.string "Did you know what I saw the\nother day?\pPROF. IVY saved a RATICATE that\nwas burned by a startled VILEPLUME.\pIt was quite a scene!$"

Route49Camper_Text_0:
	.string "I am waiting for POKéMON to come\nfor the HONEY I applied on that tree.\pI wonder if I will encounter any\nrare finds!$"

Route49Girl_Text_0:
	.string "Are your POKéMON in good shape?\pIf they are low on health, you\nshould stay away from the grass.$"

Route49TrainerTips_Text_0:
	.string "TRAINER TIPS\pWhen your POKéMON are running low on\nHit Points (HP), let them rest at a\lPOKéMON CENTER to restore them.$"
