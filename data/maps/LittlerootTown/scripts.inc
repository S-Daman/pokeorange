LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_LOAD:
	removeobject 3
	setflag FLAG_HIDEMOM
	goto_if_set FLAG_SYS_POKEDEX_GET, LittlerootTown_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	clearflag FLAG_HIDEMOM
	goto_if_set FLAG_SYS_B_DASH, LittlerootTown_MapScripts_MAP_SCRIPT_ON_LOAD_4
LittlerootTown_MapScripts_MAP_SCRIPT_ON_LOAD_3:
	setobjectxyperm 1, 13, 16
	setobjectmovementtype 1, MOVEMENT_TYPE_WANDER_AROUND
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_LOAD_4:
	setflag FLAG_HIDEMOM
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_LOAD_3

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROUTE106_STATE, 0, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	goto_if_set FLAG_SYS_POKEDEX_GET, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	setvar VAR_ROUTE106_STATE, 1
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	applymovement 3, MomApproachesPlayer
	applymovement EVENT_OBJ_ID_PLAYER, SurprisedToSeeMom
	waitmovement EVENT_OBJ_ID_PLAYER
	waitse
	playse SE_PIN
	waitse
	waitmovement 3
	delay 10
	msgbox LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message SwitchedToRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	msgbox LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1, MSGBOX_DEFAULT
	msgbox LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2, MSGBOX_DEFAULT
	closemessage
	delay 4
	applymovement 3, MomLeavesPlayer
	waitmovement 0
	setvar VAR_ROUTE106_STATE, 1
	removeobject 3
	setflag FLAG_HIDEMOM
	return


SurprisedToSeeMom:
	delay_16
	face_left
	emote_exclamation_mark
	step_end

MomApproachesPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MomLeavesPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

FatassHentaiPedoItaru::
	lock
	faceplayer
	msgbox FatassHentaiPedoItaru_Text_0, MSGBOX_AUTOCLOSE
	release
	return


Pedo2::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, Pedo2_2
	msgbox Pedo2_Text_1, MSGBOX_AUTOCLOSE
Pedo2_1:
	release
	return

Pedo2_2:
	msgbox Pedo2_Text_0, MSGBOX_AUTOCLOSE
	goto Pedo2_1


Vaughn::
	lock
	faceplayer
	msgbox Vaughn_Text_0, MSGBOX_DEFAULT
	giveitem_std ITEM_RARE_CANDY, 99, 0
	giveitem_std ITEM_RARE_CANDY, 99, 0
	giveitem_std ITEM_SUN_STONE, 1, 0
	giveitem_std ITEM_FIRE_STONE, 1, 0
	giveitem_std ITEM_THUNDER_STONE, 1, 0
	givemon SPECIES_MAGIKARP, 19, ITEM_NONE
	release
	return


ValenciaIslandSign::
	lock
	msgbox ValenciaIslandSign_Text_0, MSGBOX_SIGN
	release
	return


ApnaGhar::
	lock
	msgbox ApnaGhar_Text_0, MSGBOX_SIGN
	release
	return


IvyLab::
	lock
	msgbox IvyLab_Text_0, MSGBOX_SIGN
	release
	return


PedoStopsYou::
	lockall
	applymovement 1, Pedo_Move_1
	playse SE_PIN
	delay 64
	playbgm MUS_TSURETEK, 0
	msgbox PedoStopsYou_Text_0, MSGBOX_AUTOCLOSE
	applymovement 1, Pedo_Move_2
	turnobject EVENT_OBJ_ID_PLAYER, 4
	waitmovement 0
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 17
	goto_if_eq PedoStopsYou_2
PedoStopsYou_1:
	compare VAR_TEMP_1, 15
	goto_if_eq PedoStopsYou_5
PedoStopsYou_4:
	applymovement 1, Pedo_Move_9
	applymovement EVENT_OBJ_ID_PLAYER, Pedo_Move_9
	waitmovement 0
	turnobject 1, 3
	msgbox PedoStopsYou_Text_2, MSGBOX_AUTOCLOSE
	fadedefaultbgm
	goto_if_set FLAG_SYS_POKEDEX_GET, PedoStopsYou_8
PedoStopsYou_7:
	releaseall
	return

PedoStopsYou_2:
	applymovement 1, Pedo_Move_3
	waitmovement 0
	turnobject EVENT_OBJ_ID_PLAYER, 2
	msgbox PedoStopsYou_Text_1, MSGBOX_AUTOCLOSE
	applymovement EVENT_OBJ_ID_PLAYER, Pedo_Move_4
	applymovement 1, Pedo_Move_5
	waitmovement 0
	goto PedoStopsYou_1

PedoStopsYou_5:
	applymovement 1, Pedo_Move_6
	waitmovement 0
	turnobject EVENT_OBJ_ID_PLAYER, 1
	msgbox PedoStopsYou_Text_1, MSGBOX_AUTOCLOSE
	applymovement EVENT_OBJ_ID_PLAYER, Pedo_Move_7
	applymovement 1, Pedo_Move_8
	waitmovement 0
	goto PedoStopsYou_4

PedoStopsYou_8:
	setvar VAR_ROUTE105_STATE, 4
	goto PedoStopsYou_7


Pedo_Move_1:
	emote_exclamation_mark
	face_left
	step_end

Pedo_Move_2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Pedo_Move_3:
	walk_left
	face_down
	step_end

Pedo_Move_4:
	walk_up
	face_right
	step_end

Pedo_Move_5:
	walk_right
	step_end

Pedo_Move_6:
	walk_left
	face_up
	step_end

Pedo_Move_7:
	walk_down
	face_right
	step_end

Pedo_Move_8:
	walk_right
	step_end

Pedo_Move_9:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "MOM: Well done. You seem to have\npicked a strong POKéMON, {PLAYER}.\pNow that you are going on an adventure,\nI want you to have this.$"

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "MOM: Those shoes came with\ninstructions.\p“Press the B Button while wearing these\nRUNNING SHOES to run extra-fast!”\p“Slip on these RUNNING SHOES and race\nin the great outdoors!”$"

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
	.string "… … … … … … … …\n… … … … … … … …\pPlease be careful out there, {PLAYER}.\pI can tell you will be just fine.$"

FatassHentaiPedoItaru_Text_0:
	.string "The power of technology is amazing!\pIt is now possible to store\nPOKéMON and items as data via PC.$"

Pedo2_Text_0:
	.string "{PLAYER}!\pPROF. IVY is waiting for you!$"

Pedo2_Text_1:
	.string "Oh, nice POKéMON!\nIt looks so cool! I wish I had one.$"

Vaughn_Text_0:
	.string "Pokemon Master cheater saala.\nVaughn Max randwa loda chodu bhagat\pAb hilane de mereko$"

ValenciaIslandSign_Text_0:
	.string "VALENCIA ISLAND\nSweet Taste of a New Beginning$"

ApnaGhar_Text_0:
	.string "{PLAYER}'s House$"

IvyLab_Text_0:
	.string "IVY RESEARCH LAB$"

PedoStopsYou_Text_0:
	.string "Wait, {PLAYER}!$"

PedoStopsYou_Text_1:
	.string "What do you think you're doing?$"

PedoStopsYou_Text_2:
	.string "It's dangerous to go out without a\nPOKéMON!\pIsn't PROF. IVY giving you a\nPOKéMON today?$"

SwitchedToRunningShoes::
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"
