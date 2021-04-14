RustboroCity_House1_MapScripts:: @ 821593E
	.byte 0

RustboroCity_House1_EventScript_Trader:: @ 821593F
	lockall
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade:: @ 82159BD
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon:: @ 82159C7
	lockall
	bufferspeciesname 0, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_House1_EventScript_TradeCompleted:: @ 82159D5
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker:: @ 82159DF
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant: @ 82159E8
	.string "SHROOMISH is cute, but I don't have one.\n"
	.string "Do you have a SHROOMISH?\p"
	.string "Want to trade it for my CHINCHOU?$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon: @ 8215A77
	.string "Wow! Thank you!\n"
	.string "I always wanted a SHROOMISH!$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe: @ 8215A9D
	.string "That's not a SHROOMISH.\n"
	.string "Please trade with me if you get one.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay: @ 8215ACE
	.string "You don't want to trade?\n"
	.string "Oh, darn…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute: @ 8215B17
	.string "How is that CHINCHOU I traded you?\n"
	.string "Your SHROOMISH is so lovely!$"

RustboroCity_House1_Text_AllSortsOfPlaces: @ 8215B57
	.string "In all sorts of places, there are all\n"
	.string "sorts of POKéMON and people.\p"
	.string "I find that fascinating, so I go to all\n"
	.string "sorts of places.$"


RustboroCity_CuttersHouse_EventScript_OldDudeBitchingAboutKinnow:: @ 8215C0A
	msgbox RustboroCity_CuttersHouse_Text_OldDudeBitchingAboutKinnow, MSGBOX_NPC
	end
	
RustboroCity_CuttersHouse_Text_OldDudeBitchingAboutKinnow: @ 8215C13
	.string "They should really expand the\n"
	.string "ferry service to make it easier\l"
	.string "navigating to KINNOW ISLAND.\p"
	.string "There's no way someone my age\n"
	.string "can do so much surfing in that\l"
	.string "scorching heat…$"
	
RustboroCity_MeraBetaMarGya:: @ 8215C0A
	msgbox RustboroCity_CuttersHouse_Text_MeraBetaMarGya, MSGBOX_NPC
	end
	
RustboroCity_CuttersHouse_Text_MeraBetaMarGya: @ 8215C13
	.string "I wish my son didn't just give up\n"
	.string "like that.\p"
	.string "We wanted to explore CRYSTAL CAVE's\n"
	.string "mysteries together, but he had already\l"
	.string "left by the time I got home…$"
