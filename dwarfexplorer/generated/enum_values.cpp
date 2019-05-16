#include <cstdint>
#include <tuple>
#include <DataDefs.h>
#include <Core.h>
#include <Console.h>
#include <Export.h>
#include <PluginManager.h>
#include <RemoteServer.h>
#include <RemoteClient.h>
#include <VersionInfo.h>
#include "df_all.h"
#include "DF_Types.h"
#include "node.h"


using namespace rdf;


int64_t cast(DF_Type p_base_type, uint64_t p_address)
{
	switch (p_base_type)
	{
		case DF_Type::int8_t:   return *(reinterpret_cast<int8_t*>(p_address));
		case DF_Type::int16_t:  return *(reinterpret_cast<int16_t*>(p_address));
		case DF_Type::int32_t:  return *(reinterpret_cast<int32_t*>(p_address));
		case DF_Type::int64_t:  return *(reinterpret_cast<int64_t*>(p_address));
		case DF_Type::uint8_t:  return *(reinterpret_cast<uint8_t*>(p_address));
		case DF_Type::uint16_t: return *(reinterpret_cast<uint16_t*>(p_address));
		case DF_Type::uint32_t: return *(reinterpret_cast<uint32_t*>(p_address));
		default: break;
	}
	return -1111;
}

std::tuple<int64_t, std::string, std::string> get_ui_advmode_menu_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Default"; break;
		case 1: std::get<1>(result) = "Look"; break;
		case 2: std::get<1>(result) = "ConversationAddress"; break;
		case 3: std::get<1>(result) = "ConversationSelect"; break;
		case 4: std::get<1>(result) = "ConversationSpeak"; break;
		case 5: std::get<1>(result) = "Inventory"; break;
		case 6: std::get<1>(result) = "Drop"; break;
		case 7: std::get<1>(result) = "ThrowItem"; break;
		case 8: std::get<1>(result) = "Wear"; break;
		case 9: std::get<1>(result) = "Remove"; break;
		case 10: std::get<1>(result) = "Interact"; break;
		case 11: std::get<1>(result) = "Put"; break;
		case 12: std::get<1>(result) = "PutContainer"; break;
		case 13: std::get<1>(result) = "Eat"; break;
		case 14: std::get<1>(result) = "ThrowAim"; break;
		case 15: std::get<1>(result) = "Fire"; break;
		case 16: std::get<1>(result) = "Get"; break;
		case 17: std::get<1>(result) = "Unk17"; break;
		case 18: std::get<1>(result) = "CombatPrefs"; break;
		case 19: std::get<1>(result) = "Companions"; break;
		case 20: std::get<1>(result) = "MovementPrefs"; break;
		case 21: std::get<1>(result) = "SpeedPrefs"; break;
		case 22: std::get<1>(result) = "InteractAction"; break;
		case 23: std::get<1>(result) = "MoveCarefully"; break;
		case 24: std::get<1>(result) = "Announcements"; break;
		case 25: std::get<1>(result) = "UseBuilding"; break;
		case 26: std::get<1>(result) = "Travel"; break;
		case 27: std::get<1>(result) = "Unk27"; break;
		case 28: std::get<1>(result) = "Unk28"; break;
		case 29: std::get<1>(result) = "SleepConfirm"; break;
		case 30: std::get<1>(result) = "SelectInteractionTarget"; break;
		case 31: std::get<1>(result) = "Unk31"; break;
		case 32: std::get<1>(result) = "Unk32"; break;
		case 33: std::get<1>(result) = "FallAction"; break;
		case 34: std::get<1>(result) = "ViewTracks"; break;
		case 35: std::get<1>(result) = "Jump"; break;
		case 36: std::get<1>(result) = "Unk36"; break;
		case 37: std::get<1>(result) = "AttackConfirm"; break;
		case 38: std::get<1>(result) = "AttackType"; break;
		case 39: std::get<1>(result) = "AttackBodypart"; break;
		case 40: std::get<1>(result) = "AttackStrike"; break;
		case 41: std::get<1>(result) = "Unk41"; break;
		case 42: std::get<1>(result) = "Unk42"; break;
		case 43: std::get<1>(result) = "DodgeDirection"; break;
		case 44: std::get<1>(result) = "Unk44"; break;
		case 45: std::get<1>(result) = "Unk45"; break;
		case 46: std::get<1>(result) = "Build"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_talk_choice_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Greet"; break;
		case 1: std::get<1>(result) = "Nevermind"; break;
		case 2: std::get<1>(result) = "Trade"; break;
		case 3: std::get<1>(result) = "AskJoin"; break;
		case 4: std::get<1>(result) = "AskSurroundings"; break;
		case 5: std::get<1>(result) = "SayGoodbye"; break;
		case 6: std::get<1>(result) = "AskStructure"; break;
		case 7: std::get<1>(result) = "AskFamily"; break;
		case 8: std::get<1>(result) = "AskProfession"; break;
		case 9: std::get<1>(result) = "AskPermissionSleep"; break;
		case 10: std::get<1>(result) = "AccuseNightCreature"; break;
		case 11: std::get<1>(result) = "AskTroubles"; break;
		case 12: std::get<1>(result) = "BringUpEvent"; break;
		case 13: std::get<1>(result) = "SpreadRumor"; break;
		case 14: std::get<1>(result) = "ReplyGreeting"; break;
		case 15: std::get<1>(result) = "RefuseConversation"; break;
		case 16: std::get<1>(result) = "ReplyImpersonate"; break;
		case 17: std::get<1>(result) = "BringUpIncident"; break;
		case 18: std::get<1>(result) = "TellNothingChanged"; break;
		case 19: std::get<1>(result) = "Goodbye2"; break;
		case 20: std::get<1>(result) = "ReturnTopic"; break;
		case 21: std::get<1>(result) = "ChangeSubject"; break;
		case 22: std::get<1>(result) = "AskTargetAction"; break;
		case 23: std::get<1>(result) = "RequestSuggestAction"; break;
		case 24: std::get<1>(result) = "AskJoinInsurrection"; break;
		case 25: std::get<1>(result) = "AskJoinRescue"; break;
		case 26: std::get<1>(result) = "StateOpinion"; break;
		case 27: std::get<1>(result) = "RespondJoinInsurrection"; break;
		case 28: std::get<1>(result) = "anon_1"; break;
		case 29: std::get<1>(result) = "AllowPermissionSleep"; break;
		case 30: std::get<1>(result) = "DenyPermissionSleep"; break;
		case 31: std::get<1>(result) = "anon_2"; break;
		case 32: std::get<1>(result) = "AskJoinAdventure"; break;
		case 33: std::get<1>(result) = "AskGuideLocation"; break;
		case 34: std::get<1>(result) = "RespondJoin"; break;
		case 35: std::get<1>(result) = "RespondJoin2"; break;
		case 36: std::get<1>(result) = "OfferCondolences"; break;
		case 37: std::get<1>(result) = "StateNotAcquainted"; break;
		case 38: std::get<1>(result) = "SuggestTravel"; break;
		case 39: std::get<1>(result) = "SuggestTalk"; break;
		case 40: std::get<1>(result) = "RequestSelfRescue"; break;
		case 41: std::get<1>(result) = "AskWhatHappened"; break;
		case 42: std::get<1>(result) = "AskBeRescued"; break;
		case 43: std::get<1>(result) = "SayNotRemember"; break;
		case 44: std::get<1>(result) = "anon_3"; break;
		case 45: std::get<1>(result) = "SayNoFamily"; break;
		case 46: std::get<1>(result) = "StateUnitLocation"; break;
		case 47: std::get<1>(result) = "ReferToElder"; break;
		case 48: std::get<1>(result) = "AskComeCloser"; break;
		case 49: std::get<1>(result) = "DoBusiness"; break;
		case 50: std::get<1>(result) = "AskComeStoreLater"; break;
		case 51: std::get<1>(result) = "AskComeMarketLater"; break;
		case 52: std::get<1>(result) = "TellTryShopkeeper"; break;
		case 53: std::get<1>(result) = "DescribeSurroundings"; break;
		case 54: std::get<1>(result) = "AskWaitUntilHome"; break;
		case 55: std::get<1>(result) = "DescribeFamily"; break;
		case 56: std::get<1>(result) = "StateAge"; break;
		case 57: std::get<1>(result) = "DescribeProfession"; break;
		case 58: std::get<1>(result) = "AnnounceNightCreature"; break;
		case 59: std::get<1>(result) = "StateIncredulity"; break;
		case 60: std::get<1>(result) = "BypassGreeting"; break;
		case 61: std::get<1>(result) = "AskCeaseHostilities"; break;
		case 62: std::get<1>(result) = "DemandYield"; break;
		case 63: std::get<1>(result) = "HawkWares"; break;
		case 64: std::get<1>(result) = "YieldTerror"; break;
		case 65: std::get<1>(result) = "Yield"; break;
		case 66: std::get<1>(result) = "ExpressOverwhelmingEmotion"; break;
		case 67: std::get<1>(result) = "ExpressGreatEmotion"; break;
		case 68: std::get<1>(result) = "ExpressEmotion"; break;
		case 69: std::get<1>(result) = "ExpressMinorEmotion"; break;
		case 70: std::get<1>(result) = "ExpressLackEmotion"; break;
		case 71: std::get<1>(result) = "OutburstFleeConflict"; break;
		case 72: std::get<1>(result) = "StateFleeConflict"; break;
		case 73: std::get<1>(result) = "MentionJourney"; break;
		case 74: std::get<1>(result) = "SummarizeTroubles"; break;
		case 75: std::get<1>(result) = "AskAboutIncident"; break;
		case 76: std::get<1>(result) = "AskDirectionsPerson"; break;
		case 77: std::get<1>(result) = "AskDirectionsPlace"; break;
		case 78: std::get<1>(result) = "AskWhereabouts"; break;
		case 79: std::get<1>(result) = "RequestGuide"; break;
		case 80: std::get<1>(result) = "RequestGuide2"; break;
		case 81: std::get<1>(result) = "ProvideDirections"; break;
		case 82: std::get<1>(result) = "ProvideWhereabouts"; break;
		case 83: std::get<1>(result) = "TellTargetSelf"; break;
		case 84: std::get<1>(result) = "TellTargetDead"; break;
		case 85: std::get<1>(result) = "RecommendGuide"; break;
		case 86: std::get<1>(result) = "ProfessIgnorance"; break;
		case 87: std::get<1>(result) = "TellAboutPlace"; break;
		case 88: std::get<1>(result) = "AskFavorMenu"; break;
		case 89: std::get<1>(result) = "AskWait"; break;
		case 90: std::get<1>(result) = "AskFollow"; break;
		case 91: std::get<1>(result) = "ApologizeBusy"; break;
		case 92: std::get<1>(result) = "ComplyOrder"; break;
		case 93: std::get<1>(result) = "AgreeFollow"; break;
		case 94: std::get<1>(result) = "ExchangeItems"; break;
		case 95: std::get<1>(result) = "AskComeCloser2"; break;
		case 96: std::get<1>(result) = "InitiateBarter"; break;
		case 97: std::get<1>(result) = "AgreeCeaseHostile"; break;
		case 98: std::get<1>(result) = "RefuseCeaseHostile"; break;
		case 99: std::get<1>(result) = "RefuseCeaseHostile2"; break;
		case 100: std::get<1>(result) = "RefuseYield"; break;
		case 101: std::get<1>(result) = "RefuseYield2"; break;
		case 102: std::get<1>(result) = "Brag"; break;
		case 103: std::get<1>(result) = "DescribeRelation"; break;
		case 104: std::get<1>(result) = "ClaimSite"; break;
		case 105: std::get<1>(result) = "AnnounceLairHunt"; break;
		case 106: std::get<1>(result) = "RequestDuty"; break;
		case 107: std::get<1>(result) = "AskJoinService"; break;
		case 108: std::get<1>(result) = "AcceptService"; break;
		case 109: std::get<1>(result) = "TellRemainVigilant"; break;
		case 110: std::get<1>(result) = "GiveServiceOrder"; break;
		case 111: std::get<1>(result) = "WelcomeSelfHome"; break;
		case 112: std::get<1>(result) = "anon_4"; break;
		case 113: std::get<1>(result) = "AskTravelReason"; break;
		case 114: std::get<1>(result) = "TellTravelReason"; break;
		case 115: std::get<1>(result) = "AskLocalRuler"; break;
		case 116: std::get<1>(result) = "ComplainAgreement"; break;
		case 117: std::get<1>(result) = "CancelAgreement"; break;
		case 118: std::get<1>(result) = "SummarizeConflict"; break;
		case 119: std::get<1>(result) = "SummarizeViews"; break;
		case 120: std::get<1>(result) = "AskClaimStrength"; break;
		case 121: std::get<1>(result) = "AskArmyPosition"; break;
		case 122: std::get<1>(result) = "AskOtherClaims"; break;
		case 123: std::get<1>(result) = "AskDeserters"; break;
		case 124: std::get<1>(result) = "AskSiteNeighbors"; break;
		case 125: std::get<1>(result) = "DescribeSiteNeighbors"; break;
		case 126: std::get<1>(result) = "RaiseAlarm"; break;
		case 127: std::get<1>(result) = "DemandDropWeapon"; break;
		case 128: std::get<1>(result) = "AgreeComplyDemand"; break;
		case 129: std::get<1>(result) = "RefuseComplyDemand"; break;
		case 130: std::get<1>(result) = "AskLocationObject"; break;
		case 131: std::get<1>(result) = "DemandTribute"; break;
		case 132: std::get<1>(result) = "AgreeGiveTribute"; break;
		case 133: std::get<1>(result) = "RefuseGiveTribute"; break;
		case 134: std::get<1>(result) = "OfferGiveTribute"; break;
		case 135: std::get<1>(result) = "AgreeAcceptTribute"; break;
		case 136: std::get<1>(result) = "RefuseAcceptTribute"; break;
		case 137: std::get<1>(result) = "CancelTribute"; break;
		case 138: std::get<1>(result) = "OfferPeace"; break;
		case 139: std::get<1>(result) = "AgreePeace"; break;
		case 140: std::get<1>(result) = "RefusePeace"; break;
		case 141: std::get<1>(result) = "AskTradeDepotLater"; break;
		case 142: std::get<1>(result) = "ExpressAstonishment"; break;
		case 143: std::get<1>(result) = "CommentWeather"; break;
		case 144: std::get<1>(result) = "CommentNature"; break;
		case 145: std::get<1>(result) = "SummarizeTerritory"; break;
		case 146: std::get<1>(result) = "SummarizePatrols"; break;
		case 147: std::get<1>(result) = "SummarizeOpposition"; break;
		case 148: std::get<1>(result) = "DescribeRefugees"; break;
		case 149: std::get<1>(result) = "AccuseTroublemaker"; break;
		case 150: std::get<1>(result) = "AskAdopt"; break;
		case 151: std::get<1>(result) = "AgreeAdopt"; break;
		case 152: std::get<1>(result) = "RefuseAdopt"; break;
		case 153: std::get<1>(result) = "RevokeService"; break;
		case 154: std::get<1>(result) = "InviteService"; break;
		case 155: std::get<1>(result) = "AcceptInviteService"; break;
		case 156: std::get<1>(result) = "RefuseShareInformation"; break;
		case 157: std::get<1>(result) = "RefuseInviteService"; break;
		case 158: std::get<1>(result) = "RefuseRequestService"; break;
		case 159: std::get<1>(result) = "OfferService"; break;
		case 160: std::get<1>(result) = "AcceptPositionService"; break;
		case 161: std::get<1>(result) = "RefusePositionService"; break;
		case 162: std::get<1>(result) = "InvokeNameBanish"; break;
		case 163: std::get<1>(result) = "InvokeNameService"; break;
		case 164: std::get<1>(result) = "GrovelMaster"; break;
		case 165: std::get<1>(result) = "DemandItem"; break;
		case 166: std::get<1>(result) = "GiveServiceReport"; break;
		case 167: std::get<1>(result) = "OfferEncouragement"; break;
		case 168: std::get<1>(result) = "PraiseTaskCompleter"; break;
		case 169: std::get<1>(result) = "AskAboutPersonMenu"; break;
		case 170: std::get<1>(result) = "AskAboutPerson"; break;
		case 171: std::get<1>(result) = "TellAboutPerson"; break;
		case 172: std::get<1>(result) = "AskFeelings"; break;
		case 173: std::get<1>(result) = "TellThoughts"; break;
		case 174: std::get<1>(result) = "AskServices"; break;
		case 175: std::get<1>(result) = "TellServices"; break;
		case 176: std::get<1>(result) = "OrderDrink"; break;
		case 177: std::get<1>(result) = "RentRoom"; break;
		case 178: std::get<1>(result) = "ExtendRoomRental"; break;
		case 179: std::get<1>(result) = "ConfirmServiceOrder"; break;
		case 180: std::get<1>(result) = "AskJoinEntertain"; break;
		case 181: std::get<1>(result) = "RespondJoinEntertain"; break;
		case 182: std::get<1>(result) = "AskJoinTroupe"; break;
		case 183: std::get<1>(result) = "anon_5"; break;
		case 184: std::get<1>(result) = "RefuseTroupeApplication"; break;
		case 185: std::get<1>(result) = "InviteJoinTroupe"; break;
		case 186: std::get<1>(result) = "AcceptTroupeInvitation"; break;
		case 187: std::get<1>(result) = "RefuseTroupeInvitation"; break;
		case 188: std::get<1>(result) = "KickOutOfTroupe"; break;
		case 189: std::get<1>(result) = "CreateTroupe"; break;
		case 190: std::get<1>(result) = "LeaveTroupe"; break;
		case 191: std::get<1>(result) = "YellServiceOrder"; break;
		case 192: std::get<1>(result) = "TellBePatientForService"; break;
		case 193: std::get<1>(result) = "TellNoServices"; break;
		case 194: std::get<1>(result) = "AskWaitUntilThere"; break;
		case 195: std::get<1>(result) = "DenyWorkingHere"; break;
		case 196: std::get<1>(result) = "ExpressEmotionMenu"; break;
		case 197: std::get<1>(result) = "StateValueMenu"; break;
		case 198: std::get<1>(result) = "StateValue"; break;
		case 199: std::get<1>(result) = "SayNoOrderYet"; break;
		case 200: std::get<1>(result) = "ProvideDirectionsBuilding"; break;
		case 201: std::get<1>(result) = "Argue"; break;
		case 202: std::get<1>(result) = "Flatter"; break;
		case 203: std::get<1>(result) = "DismissArgument"; break;
		case 204: std::get<1>(result) = "RespondPassively"; break;
		case 205: std::get<1>(result) = "Acquiesce"; break;
		case 206: std::get<1>(result) = "DerideFlattery"; break;
		case 207: std::get<1>(result) = "ExpressOutrageAtDismissal"; break;
		case 208: std::get<1>(result) = "PressArgument"; break;
		case 209: std::get<1>(result) = "DropArgument"; break;
		case 210: std::get<1>(result) = "AskWork"; break;
		case 211: std::get<1>(result) = "AskWorkGroup"; break;
		case 212: std::get<1>(result) = "GrantWork"; break;
		case 213: std::get<1>(result) = "RefuseWork"; break;
		case 214: std::get<1>(result) = "GrantWorkGroup"; break;
		case 215: std::get<1>(result) = "RefuseWorkGroup"; break;
		case 216: std::get<1>(result) = "GiveSquadOrder"; break;
		case 217: std::get<1>(result) = "Artifact"; break;
		case 218: std::get<1>(result) = "PraiseReturn"; break;
		case 219: std::get<1>(result) = "ProvideLocation"; break;
		case 220: std::get<1>(result) = "Prophesize"; break;
		case 221: std::get<1>(result) = "TalkAboutAncestor"; break;
		case 222: std::get<1>(result) = "SuggestTrade"; break;
		case 223: std::get<1>(result) = "AcceptNotTrade"; break;
		case 224: std::get<1>(result) = "DemandIdentity"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_announcement_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "REACHED_PEAK"; break;
		case 1: std::get<1>(result) = "ERA_CHANGE"; break;
		case 2: std::get<1>(result) = "FEATURE_DISCOVERY"; break;
		case 3: std::get<1>(result) = "STRUCK_DEEP_METAL"; break;
		case 4: std::get<1>(result) = "STRUCK_MINERAL"; break;
		case 5: std::get<1>(result) = "STRUCK_ECONOMIC_MINERAL"; break;
		case 6: std::get<1>(result) = "COMBAT_TWIST_WEAPON"; break;
		case 7: std::get<1>(result) = "COMBAT_LET_ITEM_DROP"; break;
		case 8: std::get<1>(result) = "COMBAT_START_CHARGE"; break;
		case 9: std::get<1>(result) = "COMBAT_SURPRISE_CHARGE"; break;
		case 10: std::get<1>(result) = "COMBAT_JUMP_DODGE_PROJ"; break;
		case 11: std::get<1>(result) = "COMBAT_JUMP_DODGE_STRIKE"; break;
		case 12: std::get<1>(result) = "COMBAT_DODGE"; break;
		case 13: std::get<1>(result) = "COMBAT_COUNTERSTRIKE"; break;
		case 14: std::get<1>(result) = "COMBAT_BLOCK"; break;
		case 15: std::get<1>(result) = "COMBAT_PARRY"; break;
		case 16: std::get<1>(result) = "COMBAT_CHARGE_COLLISION"; break;
		case 17: std::get<1>(result) = "COMBAT_CHARGE_DEFENDER_TUMBLES"; break;
		case 18: std::get<1>(result) = "COMBAT_CHARGE_DEFENDER_KNOCKED_OVER"; break;
		case 19: std::get<1>(result) = "COMBAT_CHARGE_ATTACKER_TUMBLES"; break;
		case 20: std::get<1>(result) = "COMBAT_CHARGE_ATTACKER_BOUNCE_BACK"; break;
		case 21: std::get<1>(result) = "COMBAT_CHARGE_TANGLE_TOGETHER"; break;
		case 22: std::get<1>(result) = "COMBAT_CHARGE_TANGLE_TUMBLE"; break;
		case 23: std::get<1>(result) = "COMBAT_CHARGE_RUSH_BY"; break;
		case 24: std::get<1>(result) = "COMBAT_CHARGE_MANAGE_STOP"; break;
		case 25: std::get<1>(result) = "COMBAT_CHARGE_OBSTACLE_SLAM"; break;
		case 26: std::get<1>(result) = "COMBAT_WRESTLE_LOCK"; break;
		case 27: std::get<1>(result) = "COMBAT_WRESTLE_CHOKEHOLD"; break;
		case 28: std::get<1>(result) = "COMBAT_WRESTLE_TAKEDOWN"; break;
		case 29: std::get<1>(result) = "COMBAT_WRESTLE_THROW"; break;
		case 30: std::get<1>(result) = "COMBAT_WRESTLE_RELEASE_LOCK"; break;
		case 31: std::get<1>(result) = "COMBAT_WRESTLE_RELEASE_CHOKE"; break;
		case 32: std::get<1>(result) = "COMBAT_WRESTLE_RELEASE_GRIP"; break;
		case 33: std::get<1>(result) = "COMBAT_WRESTLE_STRUGGLE"; break;
		case 34: std::get<1>(result) = "COMBAT_WRESTLE_RELEASE_LATCH"; break;
		case 35: std::get<1>(result) = "COMBAT_WRESTLE_STRANGLE_KO"; break;
		case 36: std::get<1>(result) = "COMBAT_WRESTLE_ADJUST_GRIP"; break;
		case 37: std::get<1>(result) = "COMBAT_GRAB_TEAR"; break;
		case 38: std::get<1>(result) = "COMBAT_STRIKE_DETAILS"; break;
		case 39: std::get<1>(result) = "COMBAT_STRIKE_DETAILS_2"; break;
		case 40: std::get<1>(result) = "COMBAT_EVENT_ENRAGED"; break;
		case 41: std::get<1>(result) = "COMBAT_EVENT_STUCKIN"; break;
		case 42: std::get<1>(result) = "COMBAT_EVENT_LATCH_BP"; break;
		case 43: std::get<1>(result) = "COMBAT_EVENT_LATCH_GENERAL"; break;
		case 44: std::get<1>(result) = "COMBAT_EVENT_PROPELLED_AWAY"; break;
		case 45: std::get<1>(result) = "COMBAT_EVENT_KNOCKED_OUT"; break;
		case 46: std::get<1>(result) = "COMBAT_EVENT_STUNNED"; break;
		case 47: std::get<1>(result) = "COMBAT_EVENT_WINDED"; break;
		case 48: std::get<1>(result) = "COMBAT_EVENT_NAUSEATED"; break;
		case 49: std::get<1>(result) = "MIGRANT_ARRIVAL_NAMED"; break;
		case 50: std::get<1>(result) = "MIGRANT_ARRIVAL"; break;
		case 51: std::get<1>(result) = "DIG_CANCEL_WARM"; break;
		case 52: std::get<1>(result) = "DIG_CANCEL_DAMP"; break;
		case 53: std::get<1>(result) = "AMBUSH_DEFENDER"; break;
		case 54: std::get<1>(result) = "AMBUSH_RESIDENT"; break;
		case 55: std::get<1>(result) = "AMBUSH_THIEF"; break;
		case 56: std::get<1>(result) = "AMBUSH_THIEF_SUPPORT_SKULKING"; break;
		case 57: std::get<1>(result) = "AMBUSH_THIEF_SUPPORT_NATURE"; break;
		case 58: std::get<1>(result) = "AMBUSH_THIEF_SUPPORT"; break;
		case 59: std::get<1>(result) = "AMBUSH_MISCHIEVOUS"; break;
		case 60: std::get<1>(result) = "AMBUSH_SNATCHER"; break;
		case 61: std::get<1>(result) = "AMBUSH_SNATCHER_SUPPORT"; break;
		case 62: std::get<1>(result) = "AMBUSH_AMBUSHER_NATURE"; break;
		case 63: std::get<1>(result) = "AMBUSH_AMBUSHER"; break;
		case 64: std::get<1>(result) = "AMBUSH_INJURED"; break;
		case 65: std::get<1>(result) = "AMBUSH_OTHER"; break;
		case 66: std::get<1>(result) = "AMBUSH_INCAPACITATED"; break;
		case 67: std::get<1>(result) = "CARAVAN_ARRIVAL"; break;
		case 68: std::get<1>(result) = "NOBLE_ARRIVAL"; break;
		case 69: std::get<1>(result) = "D_MIGRANTS_ARRIVAL"; break;
		case 70: std::get<1>(result) = "D_MIGRANT_ARRIVAL"; break;
		case 71: std::get<1>(result) = "D_MIGRANT_ARRIVAL_DISCOURAGED"; break;
		case 72: std::get<1>(result) = "D_NO_MIGRANT_ARRIVAL"; break;
		case 73: std::get<1>(result) = "ANIMAL_TRAP_CATCH"; break;
		case 74: std::get<1>(result) = "ANIMAL_TRAP_ROBBED"; break;
		case 75: std::get<1>(result) = "MISCHIEF_LEVER"; break;
		case 76: std::get<1>(result) = "MISCHIEF_PLATE"; break;
		case 77: std::get<1>(result) = "MISCHIEF_CAGE"; break;
		case 78: std::get<1>(result) = "MISCHIEF_CHAIN"; break;
		case 79: std::get<1>(result) = "DIPLOMAT_ARRIVAL"; break;
		case 80: std::get<1>(result) = "LIAISON_ARRIVAL"; break;
		case 81: std::get<1>(result) = "TRADE_DIPLOMAT_ARRIVAL"; break;
		case 82: std::get<1>(result) = "CAVE_COLLAPSE"; break;
		case 83: std::get<1>(result) = "BIRTH_CITIZEN"; break;
		case 84: std::get<1>(result) = "BIRTH_ANIMAL"; break;
		case 85: std::get<1>(result) = "STRANGE_MOOD"; break;
		case 86: std::get<1>(result) = "MADE_ARTIFACT"; break;
		case 87: std::get<1>(result) = "NAMED_ARTIFACT"; break;
		case 88: std::get<1>(result) = "ITEM_ATTACHMENT"; break;
		case 89: std::get<1>(result) = "VERMIN_CAGE_ESCAPE"; break;
		case 90: std::get<1>(result) = "TRIGGER_WEB"; break;
		case 91: std::get<1>(result) = "MOOD_BUILDING_CLAIMED"; break;
		case 92: std::get<1>(result) = "ARTIFACT_BEGUN"; break;
		case 93: std::get<1>(result) = "MEGABEAST_ARRIVAL"; break;
		case 94: std::get<1>(result) = "BERSERK_CITIZEN"; break;
		case 95: std::get<1>(result) = "MAGMA_DEFACES_ENGRAVING"; break;
		case 96: std::get<1>(result) = "ENGRAVING_MELTS"; break;
		case 97: std::get<1>(result) = "MASTERPIECE_ARCHITECTURE"; break;
		case 98: std::get<1>(result) = "MASTERPIECE_CONSTRUCTION"; break;
		case 99: std::get<1>(result) = "MASTER_ARCHITECTURE_LOST"; break;
		case 100: std::get<1>(result) = "MASTER_CONSTRUCTION_LOST"; break;
		case 101: std::get<1>(result) = "ADV_AWAKEN"; break;
		case 102: std::get<1>(result) = "ADV_SLEEP_INTERRUPTED"; break;
		case 103: std::get<1>(result) = "CANCEL_JOB"; break;
		case 104: std::get<1>(result) = "ADV_CREATURE_DEATH"; break;
		case 105: std::get<1>(result) = "CITIZEN_DEATH"; break;
		case 106: std::get<1>(result) = "PET_DEATH"; break;
		case 107: std::get<1>(result) = "ENDGAME_EVENT_1"; break;
		case 108: std::get<1>(result) = "ENDGAME_EVENT_2"; break;
		case 109: std::get<1>(result) = "FALL_OVER"; break;
		case 110: std::get<1>(result) = "CAUGHT_IN_FLAMES"; break;
		case 111: std::get<1>(result) = "CAUGHT_IN_WEB"; break;
		case 112: std::get<1>(result) = "UNIT_PROJECTILE_SLAM_BLOW_APART"; break;
		case 113: std::get<1>(result) = "UNIT_PROJECTILE_SLAM"; break;
		case 114: std::get<1>(result) = "UNIT_PROJECTILE_SLAM_INTO_UNIT"; break;
		case 115: std::get<1>(result) = "VOMIT"; break;
		case 116: std::get<1>(result) = "LOSE_HOLD_OF_ITEM"; break;
		case 117: std::get<1>(result) = "REGAIN_CONSCIOUSNESS"; break;
		case 118: std::get<1>(result) = "FREE_FROM_WEB"; break;
		case 119: std::get<1>(result) = "PARALYZED"; break;
		case 120: std::get<1>(result) = "OVERCOME_PARALYSIS"; break;
		case 121: std::get<1>(result) = "NOT_STUNNED"; break;
		case 122: std::get<1>(result) = "EXHAUSTION"; break;
		case 123: std::get<1>(result) = "PAIN_KO"; break;
		case 124: std::get<1>(result) = "BREAK_GRIP"; break;
		case 125: std::get<1>(result) = "NO_BREAK_GRIP"; break;
		case 126: std::get<1>(result) = "BLOCK_FIRE"; break;
		case 127: std::get<1>(result) = "BREATHE_FIRE"; break;
		case 128: std::get<1>(result) = "SHOOT_WEB"; break;
		case 129: std::get<1>(result) = "PULL_OUT_DROP"; break;
		case 130: std::get<1>(result) = "STAND_UP"; break;
		case 131: std::get<1>(result) = "MARTIAL_TRANCE"; break;
		case 132: std::get<1>(result) = "MAT_BREATH"; break;
		case 133: std::get<1>(result) = "ADV_REACTION_PRODUCTS"; break;
		case 134: std::get<1>(result) = "NIGHT_ATTACK_STARTS"; break;
		case 135: std::get<1>(result) = "NIGHT_ATTACK_ENDS"; break;
		case 136: std::get<1>(result) = "NIGHT_ATTACK_TRAVEL"; break;
		case 137: std::get<1>(result) = "GHOST_ATTACK"; break;
		case 138: std::get<1>(result) = "FLAME_HIT"; break;
		case 139: std::get<1>(result) = "TRAVEL_SITE_DISCOVERY"; break;
		case 140: std::get<1>(result) = "TRAVEL_SITE_BUMP"; break;
		case 141: std::get<1>(result) = "ADVENTURE_INTRO"; break;
		case 142: std::get<1>(result) = "CREATURE_SOUND"; break;
		case 143: std::get<1>(result) = "CREATURE_STEALS_OBJECT"; break;
		case 144: std::get<1>(result) = "FOUND_TRAP"; break;
		case 145: std::get<1>(result) = "BODY_TRANSFORMATION"; break;
		case 146: std::get<1>(result) = "INTERACTION_ACTOR"; break;
		case 147: std::get<1>(result) = "INTERACTION_TARGET"; break;
		case 148: std::get<1>(result) = "UNDEAD_ATTACK"; break;
		case 149: std::get<1>(result) = "CITIZEN_MISSING"; break;
		case 150: std::get<1>(result) = "PET_MISSING"; break;
		case 151: std::get<1>(result) = "EMBRACE"; break;
		case 152: std::get<1>(result) = "STRANGE_RAIN_SNOW"; break;
		case 153: std::get<1>(result) = "STRANGE_CLOUD"; break;
		case 154: std::get<1>(result) = "SIMPLE_ANIMAL_ACTION"; break;
		case 155: std::get<1>(result) = "FLOUNDER_IN_LIQUID"; break;
		case 156: std::get<1>(result) = "TRAINING_DOWN_TO_SEMI_WILD"; break;
		case 157: std::get<1>(result) = "TRAINING_FULL_REVERSION"; break;
		case 158: std::get<1>(result) = "ANIMAL_TRAINING_KNOWLEDGE"; break;
		case 159: std::get<1>(result) = "SKIP_ON_LIQUID"; break;
		case 160: std::get<1>(result) = "DODGE_FLYING_OBJECT"; break;
		case 161: std::get<1>(result) = "REGULAR_CONVERSATION"; break;
		case 162: std::get<1>(result) = "BANDIT_EMPTY_CONTAINER"; break;
		case 163: std::get<1>(result) = "BANDIT_GRAB_ITEM"; break;
		case 164: std::get<1>(result) = "COMBAT_EVENT_ATTACK_INTERRUPTED"; break;
		case 165: std::get<1>(result) = "COMBAT_WRESTLE_CATCH_ATTACK"; break;
		case 166: std::get<1>(result) = "FAIL_TO_GRAB_SURFACE"; break;
		case 167: std::get<1>(result) = "LOSE_HOLD_OF_SURFACE"; break;
		case 168: std::get<1>(result) = "TRAVEL_COMPLAINT"; break;
		case 169: std::get<1>(result) = "LOSE_EMOTION"; break;
		case 170: std::get<1>(result) = "REORGANIZE_POSSESSIONS"; break;
		case 171: std::get<1>(result) = "PUSH_ITEM"; break;
		case 172: std::get<1>(result) = "DRAW_ITEM"; break;
		case 173: std::get<1>(result) = "STRAP_ITEM"; break;
		case 174: std::get<1>(result) = "GAIN_SITE_CONTROL"; break;
		case 175: std::get<1>(result) = "CONFLICT_CONVERSATION"; break;
		case 176: std::get<1>(result) = "FORT_POSITION_SUCCESSION"; break;
		case 177: std::get<1>(result) = "MECHANISM_SOUND"; break;
		case 178: std::get<1>(result) = "BIRTH_WILD_ANIMAL"; break;
		case 179: std::get<1>(result) = "STRESSED_CITIZEN"; break;
		case 180: std::get<1>(result) = "CITIZEN_LOST_TO_STRESS"; break;
		case 181: std::get<1>(result) = "CITIZEN_TANTRUM"; break;
		case 182: std::get<1>(result) = "MOVED_OUT_OF_RANGE"; break;
		case 183: std::get<1>(result) = "CANNOT_JUMP"; break;
		case 184: std::get<1>(result) = "NO_TRACKS"; break;
		case 185: std::get<1>(result) = "ALREADY_SEARCHED_AREA"; break;
		case 186: std::get<1>(result) = "SEARCH_FOUND_SOMETHING"; break;
		case 187: std::get<1>(result) = "SEARCH_FOUND_NOTHING"; break;
		case 188: std::get<1>(result) = "NOTHING_TO_INTERACT"; break;
		case 189: std::get<1>(result) = "NOTHING_TO_EXAMINE"; break;
		case 190: std::get<1>(result) = "YOU_YIELDED"; break;
		case 191: std::get<1>(result) = "YOU_UNYIELDED"; break;
		case 192: std::get<1>(result) = "YOU_STRAP_ITEM"; break;
		case 193: std::get<1>(result) = "YOU_DRAW_ITEM"; break;
		case 194: std::get<1>(result) = "NO_GRASP_TO_DRAW_ITEM"; break;
		case 195: std::get<1>(result) = "NO_ITEM_TO_STRAP"; break;
		case 196: std::get<1>(result) = "NO_INV_TO_REMOVE"; break;
		case 197: std::get<1>(result) = "NO_INV_TO_WEAR"; break;
		case 198: std::get<1>(result) = "NO_INV_TO_EAT"; break;
		case 199: std::get<1>(result) = "NO_INV_TO_CONTAIN"; break;
		case 200: std::get<1>(result) = "NO_INV_TO_DROP"; break;
		case 201: std::get<1>(result) = "NOTHING_TO_PICK_UP"; break;
		case 202: std::get<1>(result) = "NO_INV_TO_THROW"; break;
		case 203: std::get<1>(result) = "NO_INV_TO_FIRE"; break;
		case 204: std::get<1>(result) = "CURRENT_SMELL"; break;
		case 205: std::get<1>(result) = "CURRENT_WEATHER"; break;
		case 206: std::get<1>(result) = "CURRENT_TEMPERATURE"; break;
		case 207: std::get<1>(result) = "CURRENT_DATE"; break;
		case 208: std::get<1>(result) = "NO_GRASP_FOR_PICKUP"; break;
		case 209: std::get<1>(result) = "TRAVEL_ADVISORY"; break;
		case 210: std::get<1>(result) = "CANNOT_CLIMB"; break;
		case 211: std::get<1>(result) = "CANNOT_STAND"; break;
		case 212: std::get<1>(result) = "MUST_UNRETRACT_FIRST"; break;
		case 213: std::get<1>(result) = "CANNOT_REST"; break;
		case 214: std::get<1>(result) = "CANNOT_MAKE_CAMPFIRE"; break;
		case 215: std::get<1>(result) = "MADE_CAMPFIRE"; break;
		case 216: std::get<1>(result) = "CANNOT_SET_FIRE"; break;
		case 217: std::get<1>(result) = "SET_FIRE"; break;
		case 218: std::get<1>(result) = "DAWN_BREAKS"; break;
		case 219: std::get<1>(result) = "NOON"; break;
		case 220: std::get<1>(result) = "NIGHTFALL"; break;
		case 221: std::get<1>(result) = "NO_INV_INTERACTION"; break;
		case 222: std::get<1>(result) = "EMPTY_CONTAINER"; break;
		case 223: std::get<1>(result) = "TAKE_OUT_OF_CONTAINER"; break;
		case 224: std::get<1>(result) = "NO_CONTAINER_FOR_ITEM"; break;
		case 225: std::get<1>(result) = "PUT_INTO_CONTAINER"; break;
		case 226: std::get<1>(result) = "EAT_ITEM"; break;
		case 227: std::get<1>(result) = "DRINK_ITEM"; break;
		case 228: std::get<1>(result) = "CONSUME_FAILURE"; break;
		case 229: std::get<1>(result) = "DROP_ITEM"; break;
		case 230: std::get<1>(result) = "PICK_UP_ITEM"; break;
		case 231: std::get<1>(result) = "YOU_BUILDING_INTERACTION"; break;
		case 232: std::get<1>(result) = "YOU_ITEM_INTERACTION"; break;
		case 233: std::get<1>(result) = "YOU_TEMPERATURE_EFFECTS"; break;
		case 234: std::get<1>(result) = "PROFESSION_CHANGES"; break;
		case 235: std::get<1>(result) = "RECRUIT_PROMOTED"; break;
		case 236: std::get<1>(result) = "SOLDIER_BECOMES_MASTER"; break;
		case 237: std::get<1>(result) = "RESOLVE_SHARED_ITEMS"; break;
		case 238: std::get<1>(result) = "COUGH_BLOOD"; break;
		case 239: std::get<1>(result) = "VOMIT_BLOOD"; break;
		case 240: std::get<1>(result) = "MERCHANTS_UNLOADING"; break;
		case 241: std::get<1>(result) = "MERCHANTS_NEED_DEPOT"; break;
		case 242: std::get<1>(result) = "MERCHANT_WAGONS_BYPASSED"; break;
		case 243: std::get<1>(result) = "MERCHANTS_LEAVING_SOON"; break;
		case 244: std::get<1>(result) = "MERCHANTS_EMBARKED"; break;
		case 245: std::get<1>(result) = "PET_LOSES_DEAD_OWNER"; break;
		case 246: std::get<1>(result) = "PET_ADOPTS_OWNER"; break;
		case 247: std::get<1>(result) = "VERMIN_BITE"; break;
		case 248: std::get<1>(result) = "UNABLE_TO_COMPLETE_BUILDING"; break;
		case 249: std::get<1>(result) = "JOBS_REMOVED_FROM_UNPOWERED_BUILDING"; break;
		case 250: std::get<1>(result) = "CITIZEN_SNATCHED"; break;
		case 251: std::get<1>(result) = "VERMIN_DISTURBED"; break;
		case 252: std::get<1>(result) = "LAND_GAINS_STATUS"; break;
		case 253: std::get<1>(result) = "LAND_ELEVATED_STATUS"; break;
		case 254: std::get<1>(result) = "MASTERPIECE_CRAFTED"; break;
		case 255: std::get<1>(result) = "ARTWORK_DEFACED"; break;
		case 256: std::get<1>(result) = "POWER_LEARNED"; break;
		case 257: std::get<1>(result) = "YOU_FEED_ON_SUCKEE"; break;
		case 258: std::get<1>(result) = "ANIMAL_TRAINED"; break;
		case 259: std::get<1>(result) = "DYED_MASTERPIECE"; break;
		case 260: std::get<1>(result) = "COOKED_MASTERPIECE"; break;
		case 261: std::get<1>(result) = "MANDATE_ENDS"; break;
		case 262: std::get<1>(result) = "SLOWDOWN_ENDS"; break;
		case 263: std::get<1>(result) = "FAREWELL_HELPER"; break;
		case 264: std::get<1>(result) = "ELECTION_RESULTS"; break;
		case 265: std::get<1>(result) = "SITE_PRESENT"; break;
		case 266: std::get<1>(result) = "CONSTRUCTION_SUSPENDED"; break;
		case 267: std::get<1>(result) = "LINKAGE_SUSPENDED"; break;
		case 268: std::get<1>(result) = "QUOTA_FILLED"; break;
		case 269: std::get<1>(result) = "JOB_OVERWRITTEN"; break;
		case 270: std::get<1>(result) = "NOTHING_TO_CATCH_IN_WATER"; break;
		case 271: std::get<1>(result) = "DEMAND_FORGOTTEN"; break;
		case 272: std::get<1>(result) = "NEW_DEMAND"; break;
		case 273: std::get<1>(result) = "NEW_MANDATE"; break;
		case 274: std::get<1>(result) = "PRICES_ALTERED"; break;
		case 275: std::get<1>(result) = "NAMED_RESIDENT_CREATURE"; break;
		case 276: std::get<1>(result) = "SOMEBODY_GROWS_UP"; break;
		case 277: std::get<1>(result) = "GUILD_REQUEST_TAKEN"; break;
		case 278: std::get<1>(result) = "GUILD_WAGES_CHANGED"; break;
		case 279: std::get<1>(result) = "NEW_WORK_MANDATE"; break;
		case 280: std::get<1>(result) = "CITIZEN_BECOMES_SOLDIER"; break;
		case 281: std::get<1>(result) = "CITIZEN_BECOMES_NONSOLDIER"; break;
		case 282: std::get<1>(result) = "PARTY_ORGANIZED"; break;
		case 283: std::get<1>(result) = "POSSESSED_TANTRUM"; break;
		case 284: std::get<1>(result) = "BUILDING_TOPPLED_BY_GHOST"; break;
		case 285: std::get<1>(result) = "MASTERFUL_IMPROVEMENT"; break;
		case 286: std::get<1>(result) = "MASTERPIECE_ENGRAVING"; break;
		case 287: std::get<1>(result) = "MARRIAGE"; break;
		case 288: std::get<1>(result) = "NO_MARRIAGE_CELEBRATION"; break;
		case 289: std::get<1>(result) = "CURIOUS_GUZZLER"; break;
		case 290: std::get<1>(result) = "WEATHER_BECOMES_CLEAR"; break;
		case 291: std::get<1>(result) = "WEATHER_BECOMES_SNOW"; break;
		case 292: std::get<1>(result) = "WEATHER_BECOMES_RAIN"; break;
		case 293: std::get<1>(result) = "SEASON_WET"; break;
		case 294: std::get<1>(result) = "SEASON_DRY"; break;
		case 295: std::get<1>(result) = "SEASON_SPRING"; break;
		case 296: std::get<1>(result) = "SEASON_SUMMER"; break;
		case 297: std::get<1>(result) = "SEASON_AUTUMN"; break;
		case 298: std::get<1>(result) = "SEASON_WINTER"; break;
		case 299: std::get<1>(result) = "GUEST_ARRIVAL"; break;
		case 300: std::get<1>(result) = "CANNOT_SPEAK"; break;
		case 301: std::get<1>(result) = "RESEARCH_BREAKTHROUGH"; break;
		case 302: std::get<1>(result) = "SERVICE_ORDER_DELIVERY"; break;
		case 303: std::get<1>(result) = "PERFORMANCE_START_FAILURE"; break;
		case 304: std::get<1>(result) = "BEGIN_ACTIVITY"; break;
		case 305: std::get<1>(result) = "MIDDLE_OF_ACTIVITY"; break;
		case 306: std::get<1>(result) = "ACTIVITY_SECTION_CHANGE"; break;
		case 307: std::get<1>(result) = "CONCLUDE_ACTIVITY"; break;
		case 308: std::get<1>(result) = "LEARNED_WRITTEN_CONTENT"; break;
		case 309: std::get<1>(result) = "LEARNED_ART_FORM"; break;
		case 310: std::get<1>(result) = "PERFORMER_UPDATE"; break;
		case 311: std::get<1>(result) = "BUILDING_DESTROYED_OR_TOPPLED"; break;
		case 312: std::get<1>(result) = "DEITY_CURSE"; break;
		case 313: std::get<1>(result) = "COMPOSITION_COMPLETE"; break;
		case 314: std::get<1>(result) = "COMPOSITION_FAILED"; break;
		case 315: std::get<1>(result) = "NEW_APPRENTICESHIP"; break;
		case 316: std::get<1>(result) = "PETITION_IGNORED"; break;
		case 317: std::get<1>(result) = "CHOP_TREE"; break;
		case 318: std::get<1>(result) = "CANNOT_CONSTRUCT"; break;
		case 319: std::get<1>(result) = "RUMOR_SPREAD"; break;
		case 320: std::get<1>(result) = "AMBUSH_HERO"; break;
		case 321: std::get<1>(result) = "SERVICE_ORDER_RUMOR_RECEIVED"; break;
		case 322: std::get<1>(result) = "RETURNING_RUMOR_RECEIVED"; break;
		case 323: std::get<1>(result) = "NEW_HOLDING"; break;
		case 324: std::get<1>(result) = "NEW_MARKET_LINK"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_art_image_element_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "CREATURE"; break;
		case 1: std::get<1>(result) = "PLANT"; break;
		case 2: std::get<1>(result) = "TREE"; break;
		case 3: std::get<1>(result) = "SHAPE"; break;
		case 4: std::get<1>(result) = "ITEM"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_art_image_property_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "transitive_verb"; break;
		case 1: std::get<1>(result) = "intransitive_verb"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_art_image_property_verb_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Withering"; break;
		case 1: std::get<1>(result) = "SurroundedBy"; break;
		case 2: std::get<1>(result) = "Massacring"; break;
		case 3: std::get<1>(result) = "Fighting"; break;
		case 4: std::get<1>(result) = "Laboring"; break;
		case 5: std::get<1>(result) = "Greeting"; break;
		case 6: std::get<1>(result) = "Refusing"; break;
		case 7: std::get<1>(result) = "Speaking"; break;
		case 8: std::get<1>(result) = "Embracing"; break;
		case 9: std::get<1>(result) = "StrikingDown"; break;
		case 10: std::get<1>(result) = "MenacingPose"; break;
		case 11: std::get<1>(result) = "Traveling"; break;
		case 12: std::get<1>(result) = "Raising"; break;
		case 13: std::get<1>(result) = "Hiding"; break;
		case 14: std::get<1>(result) = "LookingConfused"; break;
		case 15: std::get<1>(result) = "LookingTerrified"; break;
		case 16: std::get<1>(result) = "Devouring"; break;
		case 17: std::get<1>(result) = "Admiring"; break;
		case 18: std::get<1>(result) = "Burning"; break;
		case 19: std::get<1>(result) = "Weeping"; break;
		case 20: std::get<1>(result) = "LookingDejected"; break;
		case 21: std::get<1>(result) = "Cringing"; break;
		case 22: std::get<1>(result) = "Screaming"; break;
		case 23: std::get<1>(result) = "SubmissiveGesture"; break;
		case 24: std::get<1>(result) = "FetalPosition"; break;
		case 25: std::get<1>(result) = "SmearedIntoSpiral"; break;
		case 26: std::get<1>(result) = "Falling"; break;
		case 27: std::get<1>(result) = "Dead"; break;
		case 28: std::get<1>(result) = "Laughing"; break;
		case 29: std::get<1>(result) = "LookingOffended"; break;
		case 30: std::get<1>(result) = "BeingShot"; break;
		case 31: std::get<1>(result) = "PlaintiveGesture"; break;
		case 32: std::get<1>(result) = "Melting"; break;
		case 33: std::get<1>(result) = "Shooting"; break;
		case 34: std::get<1>(result) = "Torturing"; break;
		case 35: std::get<1>(result) = "CommittingDepravedAct"; break;
		case 36: std::get<1>(result) = "Praying"; break;
		case 37: std::get<1>(result) = "Contemplating"; break;
		case 38: std::get<1>(result) = "Cooking"; break;
		case 39: std::get<1>(result) = "Engraving"; break;
		case 40: std::get<1>(result) = "Prostrating"; break;
		case 41: std::get<1>(result) = "Suffering"; break;
		case 42: std::get<1>(result) = "BeingImpaled"; break;
		case 43: std::get<1>(result) = "BeingContorted"; break;
		case 44: std::get<1>(result) = "BeingFlayed"; break;
		case 45: std::get<1>(result) = "HangingFrom"; break;
		case 46: std::get<1>(result) = "BeingMutilated"; break;
		case 47: std::get<1>(result) = "TriumphantPose"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_art_facet_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "OWN_RACE"; break;
		case 1: std::get<1>(result) = "FANCIFUL"; break;
		case 2: std::get<1>(result) = "GOOD"; break;
		case 3: std::get<1>(result) = "EVIL"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_poetic_form_action_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Describe"; break;
		case 1: std::get<1>(result) = "Satirize"; break;
		case 2: std::get<1>(result) = "AmuseAudience"; break;
		case 3: std::get<1>(result) = "Complain"; break;
		case 4: std::get<1>(result) = "Renounce"; break;
		case 5: std::get<1>(result) = "MakeApology"; break;
		case 6: std::get<1>(result) = "ExpressPleasure"; break;
		case 7: std::get<1>(result) = "ExpressGrief"; break;
		case 8: std::get<1>(result) = "Praise"; break;
		case 9: std::get<1>(result) = "TeachMoralLesson"; break;
		case 10: std::get<1>(result) = "MakeAssertion"; break;
		case 11: std::get<1>(result) = "MakeCounterAssertion"; break;
		case 12: std::get<1>(result) = "MakeConsession"; break;
		case 13: std::get<1>(result) = "SynthesizePreviousIdeas"; break;
		case 14: std::get<1>(result) = "DevelopPreviousIdea"; break;
		case 15: std::get<1>(result) = "InvertTheAssertion"; break;
		case 16: std::get<1>(result) = "UndercutAssertion"; break;
		case 17: std::get<1>(result) = "MoveAwayFromPreviousIdeas"; break;
		case 18: std::get<1>(result) = "ReflectPreviousIdeas"; break;
		case 19: std::get<1>(result) = "ConsoleAudience"; break;
		case 20: std::get<1>(result) = "RefuseConsolation"; break;
		case 21: std::get<1>(result) = "OfferDifferentPerspective"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_poetic_form_pattern_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "AA"; break;
		case 1: std::get<1>(result) = "AB"; break;
		case 2: std::get<1>(result) = "BA"; break;
		case 3: std::get<1>(result) = "BB"; break;
		case 4: std::get<1>(result) = "AAA"; break;
		case 5: std::get<1>(result) = "BAA"; break;
		case 6: std::get<1>(result) = "ABA"; break;
		case 7: std::get<1>(result) = "AAB"; break;
		case 8: std::get<1>(result) = "ABB"; break;
		case 9: std::get<1>(result) = "BBA"; break;
		case 10: std::get<1>(result) = "BAB"; break;
		case 11: std::get<1>(result) = "BBB"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_poetic_form_caesura_position_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Initial"; break;
		case 1: std::get<1>(result) = "Medial"; break;
		case 2: std::get<1>(result) = "Terminal"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_poetic_form_mood_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Narrative"; break;
		case 1: std::get<1>(result) = "Dramatic"; break;
		case 2: std::get<1>(result) = "Reflective"; break;
		case 3: std::get<1>(result) = "Riddle"; break;
		case 4: std::get<1>(result) = "Ribald"; break;
		case 5: std::get<1>(result) = "Light"; break;
		case 6: std::get<1>(result) = "Solemn"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_poetic_form_subject_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Past"; break;
		case 1: std::get<1>(result) = "CurrentEvents"; break;
		case 2: std::get<1>(result) = "Future"; break;
		case 3: std::get<1>(result) = "SomeoneRecentlyDeceased"; break;
		case 4: std::get<1>(result) = "SomeoneRecentlyRetired"; break;
		case 5: std::get<1>(result) = "Religion"; break;
		case 6: std::get<1>(result) = "SpecificPlace"; break;
		case 7: std::get<1>(result) = "SpecificWildernessRegion"; break;
		case 8: std::get<1>(result) = "Nature"; break;
		case 9: std::get<1>(result) = "Lover"; break;
		case 10: std::get<1>(result) = "Family"; break;
		case 11: std::get<1>(result) = "AlcoholicBeverages"; break;
		case 12: std::get<1>(result) = "Journey"; break;
		case 13: std::get<1>(result) = "War"; break;
		case 14: std::get<1>(result) = "Hunt"; break;
		case 15: std::get<1>(result) = "Mining"; break;
		case 16: std::get<1>(result) = "Death"; break;
		case 17: std::get<1>(result) = "Immortality"; break;
		case 18: std::get<1>(result) = "SomeonesCharacter"; break;
		case 19: std::get<1>(result) = "Histfig"; break;
		case 20: std::get<1>(result) = "Concept"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_poetic_form_additional_feature_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SharesUnderlyingMeaning"; break;
		case 1: std::get<1>(result) = "ContrastsUnderlyingMeaning"; break;
		case 2: std::get<1>(result) = "RequiredToMaintainPhrasing"; break;
		case 3: std::get<1>(result) = "SameGrammaticalStructure"; break;
		case 4: std::get<1>(result) = "SamePlacementOfAllusions"; break;
		case 5: std::get<1>(result) = "ReverseWordOrder"; break;
		case 6: std::get<1>(result) = "ReverseGrammaticalStructure"; break;
		case 7: std::get<1>(result) = "PresentsDifferentView"; break;
		case 8: std::get<1>(result) = "MustExpandIdea"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_poetic_form_perspective__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Author"; break;
		case 1: std::get<1>(result) = "Soldier"; break;
		case 2: std::get<1>(result) = "Traveller"; break;
		case 3: std::get<1>(result) = "RelativeOfAuthor"; break;
		case 4: std::get<1>(result) = "PartyOfDebate"; break;
		case 5: std::get<1>(result) = "FictionalPoet"; break;
		case 6: std::get<1>(result) = "Histfig"; break;
		case 7: std::get<1>(result) = "Animal"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_occupation_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "TAVERN_KEEPER"; break;
		case 1: std::get<1>(result) = "PERFORMER"; break;
		case 2: std::get<1>(result) = "SCHOLAR"; break;
		case 3: std::get<1>(result) = "MERCENARY"; break;
		case 4: std::get<1>(result) = "MONSTER_SLAYER"; break;
		case 5: std::get<1>(result) = "SCRIBE"; break;
		case 6: std::get<1>(result) = "MESSENGER"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_buildings_other_id_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "ANY"; break;
		case 0: std::get<1>(result) = "IN_PLAY"; std::get<2>(result) = "actually on the map, as opposed to in an offloaded fortress elsewhere"; break;
		case 1: std::get<1>(result) = "LOCATION_ASSIGNED"; break;
		case 2: std::get<1>(result) = "STOCKPILE"; break;
		case 3: std::get<1>(result) = "ANY_ZONE"; break;
		case 4: std::get<1>(result) = "ACTIVITY_ZONE"; break;
		case 5: std::get<1>(result) = "ANY_ACTUAL"; break;
		case 6: std::get<1>(result) = "ANY_MACHINE"; break;
		case 7: std::get<1>(result) = "ANY_HOSPITAL_STORAGE"; break;
		case 8: std::get<1>(result) = "ANY_STORAGE"; break;
		case 9: std::get<1>(result) = "ANY_BARRACKS"; break;
		case 10: std::get<1>(result) = "ANY_NOBLE_ROOM"; break;
		case 11: std::get<1>(result) = "ANY_HOSPITAL"; break;
		case 12: std::get<1>(result) = "BOX"; break;
		case 13: std::get<1>(result) = "CABINET"; break;
		case 14: std::get<1>(result) = "TRAP"; break;
		case 15: std::get<1>(result) = "DOOR"; break;
		case 16: std::get<1>(result) = "FLOODGATE"; break;
		case 17: std::get<1>(result) = "HATCH"; break;
		case 18: std::get<1>(result) = "GRATE_WALL"; break;
		case 19: std::get<1>(result) = "GRATE_FLOOR"; break;
		case 20: std::get<1>(result) = "BARS_VERTICAL"; break;
		case 21: std::get<1>(result) = "BARS_FLOOR"; break;
		case 22: std::get<1>(result) = "WINDOW_ANY"; break;
		case 23: std::get<1>(result) = "WELL"; break;
		case 24: std::get<1>(result) = "TABLE"; break;
		case 25: std::get<1>(result) = "BRIDGE"; break;
		case 26: std::get<1>(result) = "CHAIR"; break;
		case 27: std::get<1>(result) = "TRADE_DEPOT"; break;
		case 28: std::get<1>(result) = "NEST"; break;
		case 29: std::get<1>(result) = "NEST_BOX"; break;
		case 30: std::get<1>(result) = "BOOKCASE"; break;
		case 31: std::get<1>(result) = "DISPLAY_CASE"; break;
		case 32: std::get<1>(result) = "HIVE"; break;
		case 33: std::get<1>(result) = "WAGON"; break;
		case 34: std::get<1>(result) = "SHOP"; break;
		case 35: std::get<1>(result) = "BED"; break;
		case 36: std::get<1>(result) = "TRACTION_BENCH"; break;
		case 37: std::get<1>(result) = "ANY_ROAD"; break;
		case 38: std::get<1>(result) = "FARM_PLOT"; break;
		case 39: std::get<1>(result) = "GEAR_ASSEMBLY"; break;
		case 40: std::get<1>(result) = "ROLLERS"; break;
		case 41: std::get<1>(result) = "AXLE_HORIZONTAL"; break;
		case 42: std::get<1>(result) = "AXLE_VERTICAL"; break;
		case 43: std::get<1>(result) = "SUPPORT"; break;
		case 44: std::get<1>(result) = "ARCHERY_TARGET"; break;
		case 45: std::get<1>(result) = "SCREW_PUMP"; break;
		case 46: std::get<1>(result) = "WATER_WHEEL"; break;
		case 47: std::get<1>(result) = "WINDMILL"; break;
		case 48: std::get<1>(result) = "CHAIN"; break;
		case 49: std::get<1>(result) = "CAGE"; break;
		case 50: std::get<1>(result) = "STATUE"; break;
		case 51: std::get<1>(result) = "SLAB"; break;
		case 52: std::get<1>(result) = "COFFIN"; break;
		case 53: std::get<1>(result) = "WEAPON_RACK"; break;
		case 54: std::get<1>(result) = "ARMOR_STAND"; break;
		case 55: std::get<1>(result) = "FURNACE_ANY"; break;
		case 56: std::get<1>(result) = "FURNACE_WOOD"; break;
		case 57: std::get<1>(result) = "FURNACE_SMELTER_ANY"; break;
		case 58: std::get<1>(result) = "FURNACE_SMELTER_MAGMA"; break;
		case 59: std::get<1>(result) = "FURNACE_KILN_ANY"; break;
		case 60: std::get<1>(result) = "FURNACE_GLASS_ANY"; break;
		case 61: std::get<1>(result) = "FURNACE_CUSTOM"; break;
		case 62: std::get<1>(result) = "WORKSHOP_ANY"; break;
		case 63: std::get<1>(result) = "WORKSHOP_BUTCHER"; break;
		case 64: std::get<1>(result) = "WORKSHOP_MASON"; break;
		case 65: std::get<1>(result) = "WORKSHOP_KENNEL"; break;
		case 66: std::get<1>(result) = "WORKSHOP_FISHERY"; break;
		case 67: std::get<1>(result) = "WORKSHOP_JEWELER"; break;
		case 68: std::get<1>(result) = "WORKSHOP_LOOM"; break;
		case 69: std::get<1>(result) = "WORKSHOP_TANNER"; break;
		case 70: std::get<1>(result) = "WORKSHOP_DYER"; break;
		case 71: std::get<1>(result) = "WORKSHOP_MILL_ANY"; break;
		case 72: std::get<1>(result) = "WORKSHOP_QUERN"; break;
		case 73: std::get<1>(result) = "WORKSHOP_TOOL"; break;
		case 74: std::get<1>(result) = "WORKSHOP_MILLSTONE"; break;
		case 75: std::get<1>(result) = "WORKSHOP_KITCHEN"; break;
		case 76: std::get<1>(result) = "WORKSHOP_STILL"; break;
		case 77: std::get<1>(result) = "WORKSHOP_FARMER"; break;
		case 78: std::get<1>(result) = "WORKSHOP_ASHERY"; break;
		case 79: std::get<1>(result) = "WORKSHOP_CARPENTER"; break;
		case 80: std::get<1>(result) = "WORKSHOP_CRAFTSDWARF"; break;
		case 81: std::get<1>(result) = "WORKSHOP_MECHANIC"; break;
		case 82: std::get<1>(result) = "WORKSHOP_SIEGE"; break;
		case 83: std::get<1>(result) = "WORKSHOP_CLOTHIER"; break;
		case 84: std::get<1>(result) = "WORKSHOP_LEATHER"; break;
		case 85: std::get<1>(result) = "WORKSHOP_BOWYER"; break;
		case 86: std::get<1>(result) = "WORKSHOP_MAGMA_FORGE"; break;
		case 87: std::get<1>(result) = "WORKSHOP_FORGE_ANY"; break;
		case 88: std::get<1>(result) = "WORKSHOP_CUSTOM"; break;
		case 89: std::get<1>(result) = "WEAPON_UPRIGHT"; break;
		case 90: std::get<1>(result) = "INSTRUMENT_STATIONARY"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_building_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "Chair"; break;
		case 1: std::get<1>(result) = "Bed"; break;
		case 2: std::get<1>(result) = "Table"; break;
		case 3: std::get<1>(result) = "Coffin"; break;
		case 4: std::get<1>(result) = "FarmPlot"; break;
		case 5: std::get<1>(result) = "Furnace"; break;
		case 6: std::get<1>(result) = "TradeDepot"; break;
		case 7: std::get<1>(result) = "Shop"; break;
		case 8: std::get<1>(result) = "Door"; break;
		case 9: std::get<1>(result) = "Floodgate"; break;
		case 10: std::get<1>(result) = "Box"; break;
		case 11: std::get<1>(result) = "Weaponrack"; break;
		case 12: std::get<1>(result) = "Armorstand"; break;
		case 13: std::get<1>(result) = "Workshop"; break;
		case 14: std::get<1>(result) = "Cabinet"; break;
		case 15: std::get<1>(result) = "Statue"; break;
		case 16: std::get<1>(result) = "WindowGlass"; break;
		case 17: std::get<1>(result) = "WindowGem"; break;
		case 18: std::get<1>(result) = "Well"; break;
		case 19: std::get<1>(result) = "Bridge"; break;
		case 20: std::get<1>(result) = "RoadDirt"; break;
		case 21: std::get<1>(result) = "RoadPaved"; break;
		case 22: std::get<1>(result) = "SiegeEngine"; break;
		case 23: std::get<1>(result) = "Trap"; break;
		case 24: std::get<1>(result) = "AnimalTrap"; break;
		case 25: std::get<1>(result) = "Support"; break;
		case 26: std::get<1>(result) = "ArcheryTarget"; break;
		case 27: std::get<1>(result) = "Chain"; break;
		case 28: std::get<1>(result) = "Cage"; break;
		case 29: std::get<1>(result) = "Stockpile"; break;
		case 30: std::get<1>(result) = "Civzone"; break;
		case 31: std::get<1>(result) = "Weapon"; break;
		case 32: std::get<1>(result) = "Wagon"; break;
		case 33: std::get<1>(result) = "ScrewPump"; break;
		case 34: std::get<1>(result) = "Construction"; break;
		case 35: std::get<1>(result) = "Hatch"; break;
		case 36: std::get<1>(result) = "GrateWall"; break;
		case 37: std::get<1>(result) = "GrateFloor"; break;
		case 38: std::get<1>(result) = "BarsVertical"; break;
		case 39: std::get<1>(result) = "BarsFloor"; break;
		case 40: std::get<1>(result) = "GearAssembly"; break;
		case 41: std::get<1>(result) = "AxleHorizontal"; break;
		case 42: std::get<1>(result) = "AxleVertical"; break;
		case 43: std::get<1>(result) = "WaterWheel"; break;
		case 44: std::get<1>(result) = "Windmill"; break;
		case 45: std::get<1>(result) = "TractionBench"; break;
		case 46: std::get<1>(result) = "Slab"; break;
		case 47: std::get<1>(result) = "Nest"; break;
		case 48: std::get<1>(result) = "NestBox"; break;
		case 49: std::get<1>(result) = "Hive"; break;
		case 50: std::get<1>(result) = "Rollers"; break;
		case 51: std::get<1>(result) = "Instrument"; break;
		case 52: std::get<1>(result) = "Bookcase"; break;
		case 53: std::get<1>(result) = "DisplayFurniture"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_civzone_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Home"; break;
		case 1: std::get<1>(result) = "Depot"; break;
		case 2: std::get<1>(result) = "Stockpile"; break;
		case 3: std::get<1>(result) = "NobleQuarters"; break;
		case 4: std::get<1>(result) = "anon_1"; break;
		case 5: std::get<1>(result) = "anon_2"; break;
		case 6: std::get<1>(result) = "anon_3"; break;
		case 7: std::get<1>(result) = "MeadHall"; break;
		case 8: std::get<1>(result) = "ThroneRoom"; break;
		case 9: std::get<1>(result) = "ActivityZone"; break;
		case 10: std::get<1>(result) = "Temple"; break;
		case 11: std::get<1>(result) = "Kitchen"; break;
		case 12: std::get<1>(result) = "CaptiveRoom"; break;
		case 13: std::get<1>(result) = "TowerTop"; break;
		case 14: std::get<1>(result) = "Courtyard"; break;
		case 15: std::get<1>(result) = "Treasury"; break;
		case 16: std::get<1>(result) = "GuardPost"; break;
		case 17: std::get<1>(result) = "Entrance"; break;
		case 18: std::get<1>(result) = "SecretLibrary"; break;
		case 19: std::get<1>(result) = "Library"; break;
		case 20: std::get<1>(result) = "Plot"; break;
		case 21: std::get<1>(result) = "MarketStall"; break;
		case 22: std::get<1>(result) = "anon_4"; break;
		case 23: std::get<1>(result) = "Campground"; break;
		case 24: std::get<1>(result) = "CommandTent"; break;
		case 25: std::get<1>(result) = "Tent"; break;
		case 26: std::get<1>(result) = "CommandTentBld"; break;
		case 27: std::get<1>(result) = "TentBld"; break;
		case 28: std::get<1>(result) = "MechanismRoom"; break;
		case 29: std::get<1>(result) = "DungeonCell"; break;
		case 30: std::get<1>(result) = "AnimalPit"; break;
		case 31: std::get<1>(result) = "ClothPit"; break;
		case 32: std::get<1>(result) = "TanningPit"; break;
		case 33: std::get<1>(result) = "ClothClothingPit"; break;
		case 34: std::get<1>(result) = "LeatherClothingPit"; break;
		case 35: std::get<1>(result) = "BoneCarvingPit"; break;
		case 36: std::get<1>(result) = "GemCuttingPit"; break;
		case 37: std::get<1>(result) = "WeaponsmithingPit"; break;
		case 38: std::get<1>(result) = "BowmakingPit"; break;
		case 39: std::get<1>(result) = "BlacksmithingPit"; break;
		case 40: std::get<1>(result) = "ArmorsmithingPit"; break;
		case 41: std::get<1>(result) = "MetalCraftingPit"; break;
		case 42: std::get<1>(result) = "LeatherworkingPit"; break;
		case 43: std::get<1>(result) = "CarpentryPit"; break;
		case 44: std::get<1>(result) = "StoneworkingPit"; break;
		case 45: std::get<1>(result) = "ForgingPit"; break;
		case 46: std::get<1>(result) = "FightingPit"; break;
		case 47: std::get<1>(result) = "anon_5"; break;
		case 48: std::get<1>(result) = "anon_6"; break;
		case 49: std::get<1>(result) = "anon_7"; break;
		case 50: std::get<1>(result) = "anon_8"; break;
		case 51: std::get<1>(result) = "anon_9"; break;
		case 52: std::get<1>(result) = "anon_10"; break;
		case 53: std::get<1>(result) = "AnimalWorkshop"; break;
		case 54: std::get<1>(result) = "ClothWorkshop"; break;
		case 55: std::get<1>(result) = "TanningWorkshop"; break;
		case 56: std::get<1>(result) = "ClothClothingWorkshop"; break;
		case 57: std::get<1>(result) = "LeatherClothingWorkshop"; break;
		case 58: std::get<1>(result) = "BoneCarvingWorkshop"; break;
		case 59: std::get<1>(result) = "GemCuttingWorkshop"; break;
		case 60: std::get<1>(result) = "WeaponsmithingWorkshop"; break;
		case 61: std::get<1>(result) = "BowmakingWorkshop"; break;
		case 62: std::get<1>(result) = "BlacksmithingWorkshop"; break;
		case 63: std::get<1>(result) = "ArmorsmithingWorkshop"; break;
		case 64: std::get<1>(result) = "MetalCraftingWorkshop"; break;
		case 65: std::get<1>(result) = "LeatherworkingShop"; break;
		case 66: std::get<1>(result) = "CarpentryWorkshop"; break;
		case 67: std::get<1>(result) = "StoneworkingWorkshop"; break;
		case 68: std::get<1>(result) = "ForgingWorkshop"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_furnace_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "WoodFurnace"; break;
		case 1: std::get<1>(result) = "Smelter"; break;
		case 2: std::get<1>(result) = "GlassFurnace"; break;
		case 3: std::get<1>(result) = "Kiln"; break;
		case 4: std::get<1>(result) = "MagmaSmelter"; break;
		case 5: std::get<1>(result) = "MagmaGlassFurnace"; break;
		case 6: std::get<1>(result) = "MagmaKiln"; break;
		case 7: std::get<1>(result) = "Custom"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_workshop_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Carpenters"; break;
		case 1: std::get<1>(result) = "Farmers"; break;
		case 2: std::get<1>(result) = "Masons"; break;
		case 3: std::get<1>(result) = "Craftsdwarfs"; break;
		case 4: std::get<1>(result) = "Jewelers"; break;
		case 5: std::get<1>(result) = "MetalsmithsForge"; break;
		case 6: std::get<1>(result) = "MagmaForge"; break;
		case 7: std::get<1>(result) = "Bowyers"; break;
		case 8: std::get<1>(result) = "Mechanics"; break;
		case 9: std::get<1>(result) = "Siege"; break;
		case 10: std::get<1>(result) = "Butchers"; break;
		case 11: std::get<1>(result) = "Leatherworks"; break;
		case 12: std::get<1>(result) = "Tanners"; break;
		case 13: std::get<1>(result) = "Clothiers"; break;
		case 14: std::get<1>(result) = "Fishery"; break;
		case 15: std::get<1>(result) = "Still"; break;
		case 16: std::get<1>(result) = "Loom"; break;
		case 17: std::get<1>(result) = "Quern"; break;
		case 18: std::get<1>(result) = "Kennels"; break;
		case 19: std::get<1>(result) = "Kitchen"; break;
		case 20: std::get<1>(result) = "Ashery"; break;
		case 21: std::get<1>(result) = "Dyers"; break;
		case 22: std::get<1>(result) = "Millstone"; break;
		case 23: std::get<1>(result) = "Custom"; break;
		case 24: std::get<1>(result) = "Tool"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_construction_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; std::get<2>(result) = "unused"; break;
		case 0: std::get<1>(result) = "Fortification"; break;
		case 1: std::get<1>(result) = "Wall"; break;
		case 2: std::get<1>(result) = "Floor"; break;
		case 3: std::get<1>(result) = "UpStair"; break;
		case 4: std::get<1>(result) = "DownStair"; break;
		case 5: std::get<1>(result) = "UpDownStair"; break;
		case 6: std::get<1>(result) = "Ramp"; break;
		case 7: std::get<1>(result) = "TrackN"; break;
		case 8: std::get<1>(result) = "TrackS"; break;
		case 9: std::get<1>(result) = "TrackE"; break;
		case 10: std::get<1>(result) = "TrackW"; break;
		case 11: std::get<1>(result) = "TrackNS"; break;
		case 12: std::get<1>(result) = "TrackNE"; break;
		case 13: std::get<1>(result) = "TrackNW"; break;
		case 14: std::get<1>(result) = "TrackSE"; break;
		case 15: std::get<1>(result) = "TrackSW"; break;
		case 16: std::get<1>(result) = "TrackEW"; break;
		case 17: std::get<1>(result) = "TrackNSE"; break;
		case 18: std::get<1>(result) = "TrackNSW"; break;
		case 19: std::get<1>(result) = "TrackNEW"; break;
		case 20: std::get<1>(result) = "TrackSEW"; break;
		case 21: std::get<1>(result) = "TrackNSEW"; break;
		case 22: std::get<1>(result) = "TrackRampN"; break;
		case 23: std::get<1>(result) = "TrackRampS"; break;
		case 24: std::get<1>(result) = "TrackRampE"; break;
		case 25: std::get<1>(result) = "TrackRampW"; break;
		case 26: std::get<1>(result) = "TrackRampNS"; break;
		case 27: std::get<1>(result) = "TrackRampNE"; break;
		case 28: std::get<1>(result) = "TrackRampNW"; break;
		case 29: std::get<1>(result) = "TrackRampSE"; break;
		case 30: std::get<1>(result) = "TrackRampSW"; break;
		case 31: std::get<1>(result) = "TrackRampEW"; break;
		case 32: std::get<1>(result) = "TrackRampNSE"; break;
		case 33: std::get<1>(result) = "TrackRampNSW"; break;
		case 34: std::get<1>(result) = "TrackRampNEW"; break;
		case 35: std::get<1>(result) = "TrackRampSEW"; break;
		case 36: std::get<1>(result) = "TrackRampNSEW"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_shop_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "GeneralStore"; break;
		case 1: std::get<1>(result) = "CraftsMarket"; break;
		case 2: std::get<1>(result) = "ClothingShop"; break;
		case 3: std::get<1>(result) = "ExoticClothingShop"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_siegeengine_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Catapult"; break;
		case 1: std::get<1>(result) = "Ballista"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_trap_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Lever"; break;
		case 1: std::get<1>(result) = "PressurePlate"; break;
		case 2: std::get<1>(result) = "CageTrap"; break;
		case 3: std::get<1>(result) = "StoneFallTrap"; break;
		case 4: std::get<1>(result) = "WeaponTrap"; break;
		case 5: std::get<1>(result) = "TrackStop"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_dfhack_room_quality_level_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Meager"; break;
		case 1: std::get<1>(result) = "Modest"; break;
		case 2: std::get<1>(result) = "Normal"; break;
		case 3: std::get<1>(result) = "Decent"; break;
		case 4: std::get<1>(result) = "Fine"; break;
		case 5: std::get<1>(result) = "Great"; break;
		case 6: std::get<1>(result) = "Grand"; break;
		case 7: std::get<1>(result) = "Royal"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_creature_raw_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "unk_wagon"; break;
		case 1: std::get<1>(result) = "EQUIPMENT_WAGON"; break;
		case 2: std::get<1>(result) = "MUNDANE"; break;
		case 3: std::get<1>(result) = "VERMIN_EATER"; break;
		case 4: std::get<1>(result) = "VERMIN_GROUNDER"; break;
		case 5: std::get<1>(result) = "VERMIN_ROTTER"; break;
		case 6: std::get<1>(result) = "VERMIN_SOIL"; break;
		case 7: std::get<1>(result) = "VERMIN_SOIL_COLONY"; break;
		case 8: std::get<1>(result) = "LARGE_ROAMING"; break;
		case 9: std::get<1>(result) = "VERMIN_FISH"; break;
		case 10: std::get<1>(result) = "LOOSE_CLUSTERS"; break;
		case 11: std::get<1>(result) = "FANCIFUL"; break;
		case 12: std::get<1>(result) = "BIOME_MOUNTAIN"; break;
		case 13: std::get<1>(result) = "BIOME_GLACIER"; break;
		case 14: std::get<1>(result) = "BIOME_TUNDRA"; break;
		case 15: std::get<1>(result) = "BIOME_SWAMP_TEMPERATE_FRESHWATER"; break;
		case 16: std::get<1>(result) = "BIOME_SWAMP_TEMPERATE_SALTWATER"; break;
		case 17: std::get<1>(result) = "BIOME_MARSH_TEMPERATE_FRESHWATER"; break;
		case 18: std::get<1>(result) = "BIOME_MARSH_TEMPERATE_SALTWATER"; break;
		case 19: std::get<1>(result) = "BIOME_SWAMP_TROPICAL_FRESHWATER"; break;
		case 20: std::get<1>(result) = "BIOME_SWAMP_TROPICAL_SALTWATER"; break;
		case 21: std::get<1>(result) = "BIOME_SWAMP_MANGROVE"; break;
		case 22: std::get<1>(result) = "BIOME_MARSH_TROPICAL_FRESHWATER"; break;
		case 23: std::get<1>(result) = "BIOME_MARSH_TROPICAL_SALTWATER"; break;
		case 24: std::get<1>(result) = "BIOME_FOREST_TAIGA"; break;
		case 25: std::get<1>(result) = "BIOME_FOREST_TEMPERATE_CONIFER"; break;
		case 26: std::get<1>(result) = "BIOME_FOREST_TEMPERATE_BROADLEAF"; break;
		case 27: std::get<1>(result) = "BIOME_FOREST_TROPICAL_CONIFER"; break;
		case 28: std::get<1>(result) = "BIOME_FOREST_TROPICAL_DRY_BROADLEAF"; break;
		case 29: std::get<1>(result) = "BIOME_FOREST_TROPICAL_MOIST_BROADLEAF"; break;
		case 30: std::get<1>(result) = "BIOME_GRASSLAND_TEMPERATE"; break;
		case 31: std::get<1>(result) = "BIOME_SAVANNA_TEMPERATE"; break;
		case 32: std::get<1>(result) = "BIOME_SHRUBLAND_TEMPERATE"; break;
		case 33: std::get<1>(result) = "BIOME_GRASSLAND_TROPICAL"; break;
		case 34: std::get<1>(result) = "BIOME_SAVANNA_TROPICAL"; break;
		case 35: std::get<1>(result) = "BIOME_SHRUBLAND_TROPICAL"; break;
		case 36: std::get<1>(result) = "BIOME_DESERT_BADLAND"; break;
		case 37: std::get<1>(result) = "BIOME_DESERT_ROCK"; break;
		case 38: std::get<1>(result) = "BIOME_DESERT_SAND"; break;
		case 39: std::get<1>(result) = "BIOME_OCEAN_TROPICAL"; break;
		case 40: std::get<1>(result) = "BIOME_OCEAN_TEMPERATE"; break;
		case 41: std::get<1>(result) = "BIOME_OCEAN_ARCTIC"; break;
		case 42: std::get<1>(result) = "BIOME_SUBTERRANEAN_WATER"; break;
		case 43: std::get<1>(result) = "BIOME_SUBTERRANEAN_CHASM"; break;
		case 44: std::get<1>(result) = "BIOME_SUBTERRANEAN_LAVA"; break;
		case 45: std::get<1>(result) = "BIOME_POOL_TEMPERATE_FRESHWATER"; break;
		case 46: std::get<1>(result) = "BIOME_POOL_TEMPERATE_BRACKISHWATER"; break;
		case 47: std::get<1>(result) = "BIOME_POOL_TEMPERATE_SALTWATER"; break;
		case 48: std::get<1>(result) = "BIOME_POOL_TROPICAL_FRESHWATER"; break;
		case 49: std::get<1>(result) = "BIOME_POOL_TROPICAL_BRACKISHWATER"; break;
		case 50: std::get<1>(result) = "BIOME_POOL_TROPICAL_SALTWATER"; break;
		case 51: std::get<1>(result) = "BIOME_LAKE_TEMPERATE_FRESHWATER"; break;
		case 52: std::get<1>(result) = "BIOME_LAKE_TEMPERATE_BRACKISHWATER"; break;
		case 53: std::get<1>(result) = "BIOME_LAKE_TEMPERATE_SALTWATER"; break;
		case 54: std::get<1>(result) = "BIOME_LAKE_TROPICAL_FRESHWATER"; break;
		case 55: std::get<1>(result) = "BIOME_LAKE_TROPICAL_BRACKISHWATER"; break;
		case 56: std::get<1>(result) = "BIOME_LAKE_TROPICAL_SALTWATER"; break;
		case 57: std::get<1>(result) = "BIOME_RIVER_TEMPERATE_FRESHWATER"; break;
		case 58: std::get<1>(result) = "BIOME_RIVER_TEMPERATE_BRACKISHWATER"; break;
		case 59: std::get<1>(result) = "BIOME_RIVER_TEMPERATE_SALTWATER"; break;
		case 60: std::get<1>(result) = "BIOME_RIVER_TROPICAL_FRESHWATER"; break;
		case 61: std::get<1>(result) = "BIOME_RIVER_TROPICAL_BRACKISHWATER"; break;
		case 62: std::get<1>(result) = "BIOME_RIVER_TROPICAL_SALTWATER"; break;
		case 63: std::get<1>(result) = "GOOD"; break;
		case 64: std::get<1>(result) = "EVIL"; break;
		case 65: std::get<1>(result) = "SAVAGE"; break;
		case 66: std::get<1>(result) = "NOT_ASEXUAL"; break;
		case 67: std::get<1>(result) = "unk_43"; std::get<2>(result) = "capable of breeding"; break;
		case 68: std::get<1>(result) = "unk_44"; break;
		case 69: std::get<1>(result) = "unk_45"; break;
		case 70: std::get<1>(result) = "any_vermin"; break;
		case 71: std::get<1>(result) = "CASTE_CAN_LEARN"; break;
		case 72: std::get<1>(result) = "CASTE_VERMIN_HATEABLE"; break;
		case 73: std::get<1>(result) = "unk_49"; break;
		case 74: std::get<1>(result) = "CASTE_LARGE_PREDATOR"; break;
		case 75: std::get<1>(result) = "CASTE_CURIOUSBEAST"; break;
		case 76: std::get<1>(result) = "CASTE_BENIGN"; break;
		case 77: std::get<1>(result) = "CASTE_NATURAL"; break;
		case 78: std::get<1>(result) = "CASTE_MEGABEAST"; break;
		case 79: std::get<1>(result) = "CASTE_SEMIMEGABEAST"; break;
		case 80: std::get<1>(result) = "CASTE_POWER"; break;
		case 81: std::get<1>(result) = "CASTE_VERMIN_MICRO"; break;
		case 82: std::get<1>(result) = "CASTE_NOT_FIREIMMUNE"; break;
		case 83: std::get<1>(result) = "CASTE_MUST_BREATHE_AIR"; break;
		case 84: std::get<1>(result) = "CASTE_MUST_BREATHE_WATER"; break;
		case 85: std::get<1>(result) = "unk_55"; break;
		case 86: std::get<1>(result) = "CASTE_SWIMS_LEARNED"; break;
		case 87: std::get<1>(result) = "CASTE_COMMON_DOMESTIC"; break;
		case 88: std::get<1>(result) = "CASTE_UTTERANCES"; break;
		case 89: std::get<1>(result) = "CASTE_CAN_SPEAK"; break;
		case 90: std::get<1>(result) = "CASTE_FEATURE_BEAST"; break;
		case 91: std::get<1>(result) = "GENERATED"; break;
		case 92: std::get<1>(result) = "CASTE_TITAN"; break;
		case 93: std::get<1>(result) = "CASTE_UNIQUE_DEMON"; break;
		case 94: std::get<1>(result) = "DOES_NOT_EXIST"; break;
		case 95: std::get<1>(result) = "CASTE_NOT_LIVING"; break;
		case 96: std::get<1>(result) = "CASTE_MISCHIEVOUS"; break;
		case 97: std::get<1>(result) = "CASTE_FLIER"; break;
		case 98: std::get<1>(result) = "CASTE_DEMON"; break;
		case 99: std::get<1>(result) = "CASTE_NIGHT_CREATURE_ANY"; break;
		case 100: std::get<1>(result) = "CASTE_NIGHT_CREATURE_HUNTER"; break;
		case 101: std::get<1>(result) = "CASTE_NIGHT_CREATURE_BOGEYMAN"; break;
		case 102: std::get<1>(result) = "CASTE_CARNIVORE"; break;
		case 103: std::get<1>(result) = "ARTIFICIAL_HIVEABLE"; break;
		case 104: std::get<1>(result) = "UBIQUITOUS"; break;
		case 105: std::get<1>(result) = "unk_69"; break;
		case 106: std::get<1>(result) = "CASTE_SUPERNATURAL"; break;
		case 107: std::get<1>(result) = "CASTE_BLOOD"; break;
		case 108: std::get<1>(result) = "CASTE_GRAZER"; break;
		case 109: std::get<1>(result) = "CASTE_unk_31"; break;
		case 110: std::get<1>(result) = "unk_6e"; break;
		case 111: std::get<1>(result) = "unk_6f"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_caste_raw_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "AMPHIBIOUS"; break;
		case 1: std::get<1>(result) = "AQUATIC"; break;
		case 2: std::get<1>(result) = "LOCKPICKER"; break;
		case 3: std::get<1>(result) = "MISCHIEVOUS"; break;
		case 4: std::get<1>(result) = "PATTERNFLIER"; break;
		case 5: std::get<1>(result) = "CURIOUSBEAST_ANY"; break;
		case 6: std::get<1>(result) = "CURIOUSBEAST_ITEM"; break;
		case 7: std::get<1>(result) = "CURIOUSBEAST_GUZZLER"; break;
		case 8: std::get<1>(result) = "FLEEQUICK"; break;
		case 9: std::get<1>(result) = "AT_PEACE_WITH_WILDLIFE"; break;
		case 10: std::get<1>(result) = "SWIMS_LEARNED"; break;
		case 11: std::get<1>(result) = "OPPOSED_TO_LIFE"; break;
		case 12: std::get<1>(result) = "CURIOUSBEAST_EATER"; break;
		case 13: std::get<1>(result) = "NO_EAT"; break;
		case 14: std::get<1>(result) = "NO_DRINK"; break;
		case 15: std::get<1>(result) = "NO_SLEEP"; break;
		case 16: std::get<1>(result) = "COMMON_DOMESTIC"; break;
		case 17: std::get<1>(result) = "WAGON_PULLER"; break;
		case 18: std::get<1>(result) = "PACK_ANIMAL"; break;
		case 19: std::get<1>(result) = "FLIER"; break;
		case 20: std::get<1>(result) = "LARGE_PREDATOR"; break;
		case 21: std::get<1>(result) = "MAGMA_VISION"; break;
		case 22: std::get<1>(result) = "FIREIMMUNE"; break;
		case 23: std::get<1>(result) = "FIREIMMUNE_SUPER"; break;
		case 24: std::get<1>(result) = "WEBBER"; break;
		case 25: std::get<1>(result) = "WEBIMMUNE"; break;
		case 26: std::get<1>(result) = "FISHITEM"; break;
		case 27: std::get<1>(result) = "IMMOBILE_LAND"; break;
		case 28: std::get<1>(result) = "IMMOLATE"; break;
		case 29: std::get<1>(result) = "MILKABLE"; break;
		case 30: std::get<1>(result) = "NO_SPRING"; break;
		case 31: std::get<1>(result) = "NO_SUMMER"; break;
		case 32: std::get<1>(result) = "NO_AUTUMN"; break;
		case 33: std::get<1>(result) = "NO_WINTER"; break;
		case 34: std::get<1>(result) = "BENIGN"; break;
		case 35: std::get<1>(result) = "VERMIN_NOROAM"; break;
		case 36: std::get<1>(result) = "VERMIN_NOTRAP"; break;
		case 37: std::get<1>(result) = "VERMIN_NOFISH"; break;
		case 38: std::get<1>(result) = "HAS_NERVES"; break;
		case 39: std::get<1>(result) = "NO_DIZZINESS"; break;
		case 40: std::get<1>(result) = "NO_FEVERS"; break;
		case 41: std::get<1>(result) = "NO_UNIT_TYPE_COLOR"; break;
		case 42: std::get<1>(result) = "NO_CONNECTIONS_FOR_MOVEMENT"; break;
		case 43: std::get<1>(result) = "SUPERNATURAL"; break;
		case 44: std::get<1>(result) = "AMBUSHPREDATOR"; break;
		case 45: std::get<1>(result) = "GNAWER"; break;
		case 46: std::get<1>(result) = "NOT_BUTCHERABLE"; break;
		case 47: std::get<1>(result) = "COOKABLE_LIVE"; break;
		case 48: std::get<1>(result) = "SECRETION"; break;
		case 49: std::get<1>(result) = "IMMOBILE"; break;
		case 50: std::get<1>(result) = "MULTIPART_FULL_VISION"; break;
		case 51: std::get<1>(result) = "MEANDERER"; break;
		case 52: std::get<1>(result) = "THICKWEB"; break;
		case 53: std::get<1>(result) = "TRAINABLE_HUNTING"; break;
		case 54: std::get<1>(result) = "PET"; break;
		case 55: std::get<1>(result) = "PET_EXOTIC"; break;
		case 56: std::get<1>(result) = "unk_38"; break;
		case 57: std::get<1>(result) = "CAN_SPEAK"; break;
		case 58: std::get<1>(result) = "CAN_LEARN"; break;
		case 59: std::get<1>(result) = "UTTERANCES"; break;
		case 60: std::get<1>(result) = "BONECARN"; break;
		case 61: std::get<1>(result) = "CARNIVORE"; break;
		case 62: std::get<1>(result) = "UNDERSWIM"; break;
		case 63: std::get<1>(result) = "NOEXERT"; break;
		case 64: std::get<1>(result) = "NOPAIN"; break;
		case 65: std::get<1>(result) = "EXTRAVISION"; break;
		case 66: std::get<1>(result) = "NOBREATHE"; break;
		case 67: std::get<1>(result) = "NOSTUN"; break;
		case 68: std::get<1>(result) = "NONAUSEA"; break;
		case 69: std::get<1>(result) = "BLOOD"; break;
		case 70: std::get<1>(result) = "TRANCES"; break;
		case 71: std::get<1>(result) = "NOEMOTION"; break;
		case 72: std::get<1>(result) = "SLOW_LEARNER"; break;
		case 73: std::get<1>(result) = "NOSTUCKINS"; break;
		case 74: std::get<1>(result) = "PUS"; break;
		case 75: std::get<1>(result) = "NOSKULL"; break;
		case 76: std::get<1>(result) = "NOSKIN"; break;
		case 77: std::get<1>(result) = "NOBONES"; break;
		case 78: std::get<1>(result) = "NOMEAT"; break;
		case 79: std::get<1>(result) = "PARALYZEIMMUNE"; break;
		case 80: std::get<1>(result) = "NOFEAR"; break;
		case 81: std::get<1>(result) = "CANOPENDOORS"; break;
		case 82: std::get<1>(result) = "ITEMCORPSE"; std::get<2>(result) = "set if the tag is present; corpse parts go to map_renderer.cursor_other"; break;
		case 83: std::get<1>(result) = "GETS_WOUND_INFECTIONS"; break;
		case 84: std::get<1>(result) = "NOSMELLYROT"; break;
		case 85: std::get<1>(result) = "REMAINS_UNDETERMINED"; break;
		case 86: std::get<1>(result) = "HASSHELL"; break;
		case 87: std::get<1>(result) = "PEARL"; break;
		case 88: std::get<1>(result) = "TRAINABLE_WAR"; break;
		case 89: std::get<1>(result) = "NO_THOUGHT_CENTER_FOR_MOVEMENT"; break;
		case 90: std::get<1>(result) = "ARENA_RESTRICTED"; break;
		case 91: std::get<1>(result) = "LAIR_HUNTER"; break;
		case 92: std::get<1>(result) = "LIKES_FIGHTING"; break;
		case 93: std::get<1>(result) = "VERMIN_HATEABLE"; break;
		case 94: std::get<1>(result) = "VEGETATION"; break;
		case 95: std::get<1>(result) = "MAGICAL"; break;
		case 96: std::get<1>(result) = "NATURAL"; break;
		case 97: std::get<1>(result) = "BABY"; break;
		case 98: std::get<1>(result) = "CHILD"; break;
		case 99: std::get<1>(result) = "MULTIPLE_LITTER_RARE"; break;
		case 100: std::get<1>(result) = "MOUNT"; break;
		case 101: std::get<1>(result) = "MOUNT_EXOTIC"; break;
		case 102: std::get<1>(result) = "FEATURE_ATTACK_GROUP"; break;
		case 103: std::get<1>(result) = "VERMIN_MICRO"; break;
		case 104: std::get<1>(result) = "EQUIPS"; break;
		case 105: std::get<1>(result) = "LAYS_EGGS"; break;
		case 106: std::get<1>(result) = "GRAZER"; break;
		case 107: std::get<1>(result) = "NOTHOUGHT"; break;
		case 108: std::get<1>(result) = "TRAPAVOID"; break;
		case 109: std::get<1>(result) = "CAVE_ADAPT"; break;
		case 110: std::get<1>(result) = "MEGABEAST"; break;
		case 111: std::get<1>(result) = "SEMIMEGABEAST"; break;
		case 112: std::get<1>(result) = "ALL_ACTIVE"; break;
		case 113: std::get<1>(result) = "DIURNAL"; break;
		case 114: std::get<1>(result) = "NOCTURNAL"; break;
		case 115: std::get<1>(result) = "CREPUSCULAR"; break;
		case 116: std::get<1>(result) = "MATUTINAL"; break;
		case 117: std::get<1>(result) = "VESPERTINE"; break;
		case 118: std::get<1>(result) = "LIGHT_GEN"; break;
		case 119: std::get<1>(result) = "LISP"; break;
		case 120: std::get<1>(result) = "GETS_INFECTIONS_FROM_ROT"; break;
		case 121: std::get<1>(result) = "CASTE_SOLDIER_TILE"; break;
		case 122: std::get<1>(result) = "ALCOHOL_DEPENDENT"; break;
		case 123: std::get<1>(result) = "SWIMS_INNATE"; break;
		case 124: std::get<1>(result) = "POWER"; break;
		case 125: std::get<1>(result) = "TENDONS"; break;
		case 126: std::get<1>(result) = "LIGAMENTS"; break;
		case 127: std::get<1>(result) = "CASTE_TILE"; break;
		case 128: std::get<1>(result) = "CASTE_COLOR"; break;
		case 129: std::get<1>(result) = "CASTE_GLOWTILE"; break;
		case 130: std::get<1>(result) = "CASTE_GLOWCOLOR"; break;
		case 131: std::get<1>(result) = "FEATURE_BEAST"; break;
		case 132: std::get<1>(result) = "TITAN"; break;
		case 133: std::get<1>(result) = "UNIQUE_DEMON"; break;
		case 134: std::get<1>(result) = "DEMON"; break;
		case 135: std::get<1>(result) = "MANNERISM_LAUGH"; break;
		case 136: std::get<1>(result) = "MANNERISM_SMILE"; break;
		case 137: std::get<1>(result) = "MANNERISM_WALK"; break;
		case 138: std::get<1>(result) = "MANNERISM_SIT"; break;
		case 139: std::get<1>(result) = "MANNERISM_BREATH"; break;
		case 140: std::get<1>(result) = "MANNERISM_POSTURE"; break;
		case 141: std::get<1>(result) = "MANNERISM_STRETCH"; break;
		case 142: std::get<1>(result) = "MANNERISM_EYELIDS"; break;
		case 143: std::get<1>(result) = "NIGHT_CREATURE_ANY"; break;
		case 144: std::get<1>(result) = "NIGHT_CREATURE_HUNTER"; break;
		case 145: std::get<1>(result) = "NIGHT_CREATURE_BOGEYMAN"; break;
		case 146: std::get<1>(result) = "CONVERTED_SPOUSE"; break;
		case 147: std::get<1>(result) = "SPOUSE_CONVERTER"; break;
		case 148: std::get<1>(result) = "SPOUSE_CONVERSION_TARGET"; break;
		case 149: std::get<1>(result) = "DIE_WHEN_VERMIN_BITE"; break;
		case 150: std::get<1>(result) = "REMAINS_ON_VERMIN_BITE_DEATH"; break;
		case 151: std::get<1>(result) = "COLONY_EXTERNAL"; break;
		case 152: std::get<1>(result) = "LAYS_UNUSUAL_EGGS"; break;
		case 153: std::get<1>(result) = "RETURNS_VERMIN_KILLS_TO_OWNER"; break;
		case 154: std::get<1>(result) = "HUNTS_VERMIN"; break;
		case 155: std::get<1>(result) = "ADOPTS_OWNER"; break;
		case 156: std::get<1>(result) = "SOUND_ALERT"; break;
		case 157: std::get<1>(result) = "SOUND_PEACEFUL_INTERMITTENT"; break;
		case 158: std::get<1>(result) = "NOT_LIVING"; break;
		case 159: std::get<1>(result) = "NO_PHYS_ATT_GAIN"; break;
		case 160: std::get<1>(result) = "NO_PHYS_ATT_RUST"; break;
		case 161: std::get<1>(result) = "CRAZED"; break;
		case 162: std::get<1>(result) = "BLOODSUCKER"; break;
		case 163: std::get<1>(result) = "NO_VEGETATION_PERTURB"; break;
		case 164: std::get<1>(result) = "DIVE_HUNTS_VERMIN"; break;
		case 165: std::get<1>(result) = "GOBBLE_VERMIN"; break;
		case 166: std::get<1>(result) = "CANNOT_JUMP"; break;
		case 167: std::get<1>(result) = "STANCE_CLIMBER"; break;
		case 168: std::get<1>(result) = "CANNOT_CLIMB"; break;
		case 169: std::get<1>(result) = "LOCAL_POPS_CONTROLLABLE"; break;
		case 170: std::get<1>(result) = "OUTSIDER_CONTROLLABLE"; break;
		case 171: std::get<1>(result) = "LOCAL_POPS_PRODUCE_HEROES"; break;
		case 172: std::get<1>(result) = "STRANGE_MOODS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_body_part_raw_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "HEAD"; break;
		case 1: std::get<1>(result) = "UPPERBODY"; break;
		case 2: std::get<1>(result) = "LOWERBODY"; break;
		case 3: std::get<1>(result) = "SIGHT"; break;
		case 4: std::get<1>(result) = "EMBEDDED"; break;
		case 5: std::get<1>(result) = "INTERNAL"; break;
		case 6: std::get<1>(result) = "CIRCULATION"; break;
		case 7: std::get<1>(result) = "SKELETON"; break;
		case 8: std::get<1>(result) = "LIMB"; break;
		case 9: std::get<1>(result) = "GRASP"; break;
		case 10: std::get<1>(result) = "STANCE"; break;
		case 11: std::get<1>(result) = "GUTS"; break;
		case 12: std::get<1>(result) = "BREATHE"; break;
		case 13: std::get<1>(result) = "SMALL"; break;
		case 14: std::get<1>(result) = "THROAT"; break;
		case 15: std::get<1>(result) = "JOINT"; break;
		case 16: std::get<1>(result) = "THOUGHT"; break;
		case 17: std::get<1>(result) = "NERVOUS"; break;
		case 18: std::get<1>(result) = "RIGHT"; break;
		case 19: std::get<1>(result) = "LEFT"; break;
		case 20: std::get<1>(result) = "HEAR"; break;
		case 21: std::get<1>(result) = "SMELL"; break;
		case 22: std::get<1>(result) = "FLIER"; break;
		case 23: std::get<1>(result) = "DIGIT"; break;
		case 24: std::get<1>(result) = "MOUTH"; break;
		case 25: std::get<1>(result) = "APERTURE"; break;
		case 26: std::get<1>(result) = "SOCKET"; break;
		case 27: std::get<1>(result) = "TOTEMABLE"; break;
		case 28: std::get<1>(result) = "anon_1"; break;
		case 29: std::get<1>(result) = "anon_2"; break;
		case 30: std::get<1>(result) = "UNDER_PRESSURE"; break;
		case 31: std::get<1>(result) = "anon_3"; break;
		case 32: std::get<1>(result) = "VERMIN_BUTCHER_ITEM"; break;
		case 33: std::get<1>(result) = "CONNECTOR"; break;
		case 34: std::get<1>(result) = "anon_4"; break;
		case 35: std::get<1>(result) = "anon_5"; break;
		case 36: std::get<1>(result) = "anon_6"; break;
		case 37: std::get<1>(result) = "anon_7"; break;
		case 38: std::get<1>(result) = "GELDABLE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_appearance_modifier_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "HEIGHT"; break;
		case 1: std::get<1>(result) = "BROADNESS"; break;
		case 2: std::get<1>(result) = "LENGTH"; break;
		case 3: std::get<1>(result) = "CLOSE_SET"; break;
		case 4: std::get<1>(result) = "DEEP_SET"; break;
		case 5: std::get<1>(result) = "HIGH_POSITION"; break;
		case 6: std::get<1>(result) = "LARGE_IRIS"; break;
		case 7: std::get<1>(result) = "WRINKLY"; break;
		case 8: std::get<1>(result) = "CURLY"; break;
		case 9: std::get<1>(result) = "CONVEX"; break;
		case 10: std::get<1>(result) = "DENSE"; break;
		case 11: std::get<1>(result) = "THICKNESS"; break;
		case 12: std::get<1>(result) = "UPTURNED"; break;
		case 13: std::get<1>(result) = "SPLAYED_OUT"; break;
		case 14: std::get<1>(result) = "HANGING_LOBES"; break;
		case 15: std::get<1>(result) = "GAPS"; break;
		case 16: std::get<1>(result) = "HIGH_CHEEKBONES"; break;
		case 17: std::get<1>(result) = "BROAD_CHIN"; break;
		case 18: std::get<1>(result) = "JUTTING_CHIN"; break;
		case 19: std::get<1>(result) = "SQUARE_CHIN"; break;
		case 20: std::get<1>(result) = "ROUND_VS_NARROW"; break;
		case 21: std::get<1>(result) = "GREASY"; break;
		case 22: std::get<1>(result) = "DEEP_VOICE"; break;
		case 23: std::get<1>(result) = "RASPY_VOICE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_body_part_layer_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "CONNECTS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_appearance_modifier_growth_interval_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "DAILY"; break;
		case 1: std::get<1>(result) = "WEEKLY"; break;
		case 2: std::get<1>(result) = "MONTHLY"; break;
		case 3: std::get<1>(result) = "YEARLY"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_gait_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "WALK"; break;
		case 1: std::get<1>(result) = "FLY"; break;
		case 2: std::get<1>(result) = "SWIM"; break;
		case 3: std::get<1>(result) = "CRAWL"; break;
		case 4: std::get<1>(result) = "CLIMB"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_creature_graphics_role_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "DEFAULT"; break;
		case 1: std::get<1>(result) = "ADVENTURER"; break;
		case 2: std::get<1>(result) = "GUARD"; break;
		case 3: std::get<1>(result) = "ROYALGUARD"; break;
		case 4: std::get<1>(result) = "ANIMATED"; break;
		case 5: std::get<1>(result) = "GHOST"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tissue_style_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "NEATLY_COMBED"; break;
		case 1: std::get<1>(result) = "BRAIDED"; break;
		case 2: std::get<1>(result) = "DOUBLE_BRAIDS"; break;
		case 3: std::get<1>(result) = "PONY_TAILS"; break;
		case 4: std::get<1>(result) = "CLEAN_SHAVEN"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_body_part_template_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "HEAD"; break;
		case 1: std::get<1>(result) = "UPPERBODY"; break;
		case 2: std::get<1>(result) = "LOWERBODY"; break;
		case 3: std::get<1>(result) = "SIGHT"; break;
		case 4: std::get<1>(result) = "EMBEDDED"; break;
		case 5: std::get<1>(result) = "INTERNAL"; break;
		case 6: std::get<1>(result) = "CIRCULATION"; break;
		case 7: std::get<1>(result) = "SKELETON"; break;
		case 8: std::get<1>(result) = "LIMB"; break;
		case 9: std::get<1>(result) = "GRASP"; break;
		case 10: std::get<1>(result) = "STANCE"; break;
		case 11: std::get<1>(result) = "GUTS"; break;
		case 12: std::get<1>(result) = "BREATHE"; break;
		case 13: std::get<1>(result) = "SMALL"; break;
		case 14: std::get<1>(result) = "THROAT"; break;
		case 15: std::get<1>(result) = "JOINT"; break;
		case 16: std::get<1>(result) = "THOUGHT"; break;
		case 17: std::get<1>(result) = "NERVOUS"; break;
		case 18: std::get<1>(result) = "RIGHT"; break;
		case 19: std::get<1>(result) = "LEFT"; break;
		case 20: std::get<1>(result) = "HEAR"; break;
		case 21: std::get<1>(result) = "SMELL"; break;
		case 22: std::get<1>(result) = "FLIER"; break;
		case 23: std::get<1>(result) = "DIGIT"; break;
		case 24: std::get<1>(result) = "MOUTH"; break;
		case 25: std::get<1>(result) = "APERTURE"; break;
		case 26: std::get<1>(result) = "SOCKET"; break;
		case 27: std::get<1>(result) = "TOTEMABLE"; break;
		case 28: std::get<1>(result) = "UNDER_PRESSURE"; break;
		case 29: std::get<1>(result) = "VERMIN_BUTCHER_ITEM"; break;
		case 30: std::get<1>(result) = "CONNECTOR"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_body_part_template_contype_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "UPPERBODY"; break;
		case 1: std::get<1>(result) = "LOWERBODY"; break;
		case 2: std::get<1>(result) = "HEAD"; break;
		case 3: std::get<1>(result) = "GRASP"; break;
		case 4: std::get<1>(result) = "STANCE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tissue_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "THICKENS_ON_STRENGTH"; break;
		case 1: std::get<1>(result) = "THICKENS_ON_ENERGY_STORAGE"; break;
		case 2: std::get<1>(result) = "ARTERIES"; break;
		case 3: std::get<1>(result) = "SCARS"; break;
		case 4: std::get<1>(result) = "STRUCTURAL"; break;
		case 5: std::get<1>(result) = "NERVOUS"; break;
		case 6: std::get<1>(result) = "THOUGHT"; break;
		case 7: std::get<1>(result) = "MUSCULAR"; break;
		case 8: std::get<1>(result) = "SMELL"; break;
		case 9: std::get<1>(result) = "HEAR"; break;
		case 10: std::get<1>(result) = "FLIGHT"; break;
		case 11: std::get<1>(result) = "BREATHE"; break;
		case 12: std::get<1>(result) = "SIGHT"; break;
		case 13: std::get<1>(result) = "COSMETIC"; break;
		case 14: std::get<1>(result) = "CONNECTS"; break;
		case 15: std::get<1>(result) = "FUNCTIONAL"; break;
		case 16: std::get<1>(result) = "MAJOR_ARTERIES"; break;
		case 17: std::get<1>(result) = "TISSUE_LEAKS"; break;
		case 18: std::get<1>(result) = "STYLEABLE"; break;
		case 19: std::get<1>(result) = "CONNECTIVE_TISSUE_ANCHOR"; break;
		case 20: std::get<1>(result) = "SETTABLE"; break;
		case 21: std::get<1>(result) = "SPLINTABLE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_d_init_nickname_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "REPLACE_FIRST"; break;
		case 1: std::get<1>(result) = "CENTRALIZE"; break;
		case 2: std::get<1>(result) = "REPLACE_ALL"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_d_init_z_view_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "OFF"; break;
		case 1: std::get<1>(result) = "UNHIDDEN"; break;
		case 2: std::get<1>(result) = "CREATURE"; break;
		case 3: std::get<1>(result) = "ON"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_d_init_embark_confirm_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ALWAYS"; break;
		case 1: std::get<1>(result) = "IF_POINTS_REMAIN"; break;
		case 2: std::get<1>(result) = "NO"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_d_init_idlers_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "OFF"; break;
		case 0: std::get<1>(result) = "TOP"; break;
		case 1: std::get<1>(result) = "BOTTOM"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_d_init_tunnel_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "NO"; break;
		case 1: std::get<1>(result) = "FINDER"; break;
		case 2: std::get<1>(result) = "ALWAYS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_d_init_flags1_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "VARIED_GROUND_TILES"; break;
		case 1: std::get<1>(result) = "ENGRAVINGS_START_OBSCURED"; break;
		case 2: std::get<1>(result) = "SHOW_IMP_QUALITY"; break;
		case 3: std::get<1>(result) = "SHOW_FLOW_AMOUNTS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_d_init_flags2_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MORE"; break;
		case 1: std::get<1>(result) = "ADVENTURER_TRAPS"; break;
		case 2: std::get<1>(result) = "ADVENTURER_ALWAYS_CENTER"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_d_init_flags3_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "COFFIN_NO_PETS_DEFAULT"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_d_init_flags4_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "TEMPERATURE"; break;
		case 1: std::get<1>(result) = "WEATHER"; break;
		case 2: std::get<1>(result) = "ECONOMY"; break;
		case 3: std::get<1>(result) = "ZERO_RENT"; break;
		case 4: std::get<1>(result) = "AUTOSAVE_SEASONAL"; break;
		case 5: std::get<1>(result) = "AUTOSAVE_YEARLY"; break;
		case 6: std::get<1>(result) = "AUTOSAVE_PAUSE"; break;
		case 7: std::get<1>(result) = "AUTOBACKUP"; break;
		case 8: std::get<1>(result) = "INITIAL_SAVE"; break;
		case 9: std::get<1>(result) = "INVADERS"; break;
		case 10: std::get<1>(result) = "CAVEINS"; break;
		case 11: std::get<1>(result) = "ARTIFACTS"; break;
		case 12: std::get<1>(result) = "LOG_MAP_REJECTS"; break;
		case 13: std::get<1>(result) = "PAUSE_ON_LOAD"; break;
		case 14: std::get<1>(result) = "EMBARK_WARNING_ALWAYS"; break;
		case 15: std::get<1>(result) = "SHOW_ALL_HISTORY_IN_DWARF_MODE"; break;
		case 16: std::get<1>(result) = "TESTING_ARENA"; break;
		case 17: std::get<1>(result) = "WALKING_SPREADS_SPATTER_DWF"; break;
		case 18: std::get<1>(result) = "WALKING_SPREADS_SPATTER_ADV"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_pattern_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MONOTONE"; break;
		case 1: std::get<1>(result) = "STRIPES"; break;
		case 2: std::get<1>(result) = "IRIS_EYE"; break;
		case 3: std::get<1>(result) = "SPOTS"; break;
		case 4: std::get<1>(result) = "PUPIL_EYE"; break;
		case 5: std::get<1>(result) = "MOTTLED"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_occasion_schedule_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "DANCE_PERFORMANCE"; break;
		case 1: std::get<1>(result) = "MUSICAL_PERFORMANCE"; break;
		case 2: std::get<1>(result) = "POETRY_RECITAL"; break;
		case 3: std::get<1>(result) = "STORYTELLING"; break;
		case 4: std::get<1>(result) = "DANCE_COMPETITION"; break;
		case 5: std::get<1>(result) = "MUSICAL_COMPETITION"; break;
		case 6: std::get<1>(result) = "POETRY_COMPETITION"; break;
		case 7: std::get<1>(result) = "FOOT_RACE"; break;
		case 8: std::get<1>(result) = "anon_1"; break;
		case 9: std::get<1>(result) = "anon_2"; break;
		case 10: std::get<1>(result) = "WRESTLING_COMPETITION"; break;
		case 11: std::get<1>(result) = "THROWING_COMPETITION"; break;
		case 12: std::get<1>(result) = "GLADIATORY_COMPETITION"; break;
		case 13: std::get<1>(result) = "PROCESSION"; break;
		case 14: std::get<1>(result) = "CEREMONY"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_occasion_schedule_feature_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "anon_1"; break;
		case 1: std::get<1>(result) = "anon_2"; break;
		case 2: std::get<1>(result) = "STORYTELLING"; break;
		case 3: std::get<1>(result) = "POETRY_RECITAL"; break;
		case 4: std::get<1>(result) = "MUSICAL_PERFORMANCE"; break;
		case 5: std::get<1>(result) = "DANCE_PERFORMANCE"; break;
		case 6: std::get<1>(result) = "anon_3"; break;
		case 7: std::get<1>(result) = "CRIERS_IN_FRONT"; break;
		case 8: std::get<1>(result) = "ORDER_OF_PRECEDENCE"; break;
		case 9: std::get<1>(result) = "BANNERS"; break;
		case 10: std::get<1>(result) = "IMAGES"; break;
		case 11: std::get<1>(result) = "anon_4"; break;
		case 12: std::get<1>(result) = "anon_5"; break;
		case 13: std::get<1>(result) = "ACROBATS"; break;
		case 14: std::get<1>(result) = "INCENSE_BURNING"; break;
		case 15: std::get<1>(result) = "COSTUMES"; break;
		case 16: std::get<1>(result) = "CANDLES"; break;
		case 17: std::get<1>(result) = "THE_GIVING_OF_ITEMS"; break;
		case 18: std::get<1>(result) = "THE_SACRIFICE_OF_ITEMS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_entity_sell_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Leather"; break;
		case 1: std::get<1>(result) = "ClothPlant"; break;
		case 2: std::get<1>(result) = "ClothSilk"; break;
		case 3: std::get<1>(result) = "Crafts"; break;
		case 4: std::get<1>(result) = "Wood"; break;
		case 5: std::get<1>(result) = "MetalBars"; break;
		case 6: std::get<1>(result) = "SmallCutGems"; break;
		case 7: std::get<1>(result) = "LargeCutGems"; break;
		case 8: std::get<1>(result) = "StoneBlocks"; break;
		case 9: std::get<1>(result) = "Seeds"; break;
		case 10: std::get<1>(result) = "Anvils"; break;
		case 11: std::get<1>(result) = "Weapons"; break;
		case 12: std::get<1>(result) = "TrainingWeapons"; break;
		case 13: std::get<1>(result) = "Ammo"; break;
		case 14: std::get<1>(result) = "TrapComponents"; break;
		case 15: std::get<1>(result) = "DiggingImplements"; break;
		case 16: std::get<1>(result) = "Bodywear"; break;
		case 17: std::get<1>(result) = "Headwear"; break;
		case 18: std::get<1>(result) = "Handwear"; break;
		case 19: std::get<1>(result) = "Footwear"; break;
		case 20: std::get<1>(result) = "Legwear"; break;
		case 21: std::get<1>(result) = "Shields"; break;
		case 22: std::get<1>(result) = "Toys"; break;
		case 23: std::get<1>(result) = "Instruments"; break;
		case 24: std::get<1>(result) = "Pets"; break;
		case 25: std::get<1>(result) = "Drinks"; break;
		case 26: std::get<1>(result) = "Cheese"; break;
		case 27: std::get<1>(result) = "Powders"; break;
		case 28: std::get<1>(result) = "Extracts"; break;
		case 29: std::get<1>(result) = "Meat"; break;
		case 30: std::get<1>(result) = "Fish"; break;
		case 31: std::get<1>(result) = "Plants"; break;
		case 32: std::get<1>(result) = "FruitsNuts"; break;
		case 33: std::get<1>(result) = "GardenVegetables"; break;
		case 34: std::get<1>(result) = "MeatFishRecipes"; break;
		case 35: std::get<1>(result) = "OtherRecipes"; break;
		case 36: std::get<1>(result) = "Stone"; break;
		case 37: std::get<1>(result) = "Cages"; break;
		case 38: std::get<1>(result) = "BagsLeather"; break;
		case 39: std::get<1>(result) = "BagsPlant"; break;
		case 40: std::get<1>(result) = "BagsSilk"; break;
		case 41: std::get<1>(result) = "ThreadPlant"; break;
		case 42: std::get<1>(result) = "ThreadSilk"; break;
		case 43: std::get<1>(result) = "RopesPlant"; break;
		case 44: std::get<1>(result) = "RopesSilk"; break;
		case 45: std::get<1>(result) = "Barrels"; break;
		case 46: std::get<1>(result) = "FlasksWaterskins"; break;
		case 47: std::get<1>(result) = "Quivers"; break;
		case 48: std::get<1>(result) = "Backpacks"; break;
		case 49: std::get<1>(result) = "Sand"; break;
		case 50: std::get<1>(result) = "Glass"; break;
		case 51: std::get<1>(result) = "Miscellaneous"; break;
		case 52: std::get<1>(result) = "Buckets"; break;
		case 53: std::get<1>(result) = "Splints"; break;
		case 54: std::get<1>(result) = "Crutches"; break;
		case 55: std::get<1>(result) = "Eggs"; break;
		case 56: std::get<1>(result) = "BagsYarn"; break;
		case 57: std::get<1>(result) = "RopesYarn"; break;
		case 58: std::get<1>(result) = "ClothYarn"; break;
		case 59: std::get<1>(result) = "ThreadYarn"; break;
		case 60: std::get<1>(result) = "Tools"; break;
		case 61: std::get<1>(result) = "Clay"; break;
		case 62: std::get<1>(result) = "Parchment"; break;
		case 63: std::get<1>(result) = "CupsMugsGoblets"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_historical_entity_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Civilization"; break;
		case 1: std::get<1>(result) = "SiteGovernment"; break;
		case 2: std::get<1>(result) = "VesselCrew"; break;
		case 3: std::get<1>(result) = "MigratingGroup"; break;
		case 4: std::get<1>(result) = "NomadicGroup"; break;
		case 5: std::get<1>(result) = "Religion"; break;
		case 6: std::get<1>(result) = "MilitaryUnit"; break;
		case 7: std::get<1>(result) = "Outcast"; break;
		case 8: std::get<1>(result) = "PerformanceTroupe"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_training_knowledge_level_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "None"; break;
		case 1: std::get<1>(result) = "FewFacts"; break;
		case 2: std::get<1>(result) = "GeneralFamiliarity"; break;
		case 3: std::get<1>(result) = "Knowledgeable"; break;
		case 4: std::get<1>(result) = "Expert"; break;
		case 5: std::get<1>(result) = "Domesticated"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_entity_position_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "IS_LAW_MAKER"; break;
		case 1: std::get<1>(result) = "ELECTED"; break;
		case 2: std::get<1>(result) = "DUTY_BOUND"; break;
		case 3: std::get<1>(result) = "MILITARY_SCREEN_ONLY"; break;
		case 4: std::get<1>(result) = "GENDER_MALE"; break;
		case 5: std::get<1>(result) = "GENDER_FEMALE"; break;
		case 6: std::get<1>(result) = "SUCCESSION_BY_HEIR"; break;
		case 7: std::get<1>(result) = "HAS_RESPONSIBILITIES"; break;
		case 8: std::get<1>(result) = "FLASHES"; break;
		case 9: std::get<1>(result) = "BRAG_ON_KILL"; break;
		case 10: std::get<1>(result) = "CHAT_WORTHY"; break;
		case 11: std::get<1>(result) = "DO_NOT_CULL"; break;
		case 12: std::get<1>(result) = "KILL_QUEST"; break;
		case 13: std::get<1>(result) = "IS_LEADER"; break;
		case 14: std::get<1>(result) = "IS_DIPLOMAT"; break;
		case 15: std::get<1>(result) = "EXPORTED_IN_LEGENDS"; break;
		case 16: std::get<1>(result) = "DETERMINES_COIN_DESIGN"; break;
		case 17: std::get<1>(result) = "ACCOUNT_EXEMPT"; break;
		case 18: std::get<1>(result) = "unk_12"; break;
		case 19: std::get<1>(result) = "unk_13"; break;
		case 20: std::get<1>(result) = "COLOR"; break;
		case 21: std::get<1>(result) = "RULES_FROM_LOCATION"; break;
		case 22: std::get<1>(result) = "MENIAL_WORK_EXEMPTION"; break;
		case 23: std::get<1>(result) = "MENIAL_WORK_EXEMPTION_SPOUSE"; break;
		case 24: std::get<1>(result) = "SLEEP_PRETENSION"; break;
		case 25: std::get<1>(result) = "PUNISHMENT_EXEMPTION"; break;
		case 26: std::get<1>(result) = "unk_1a"; break;
		case 27: std::get<1>(result) = "unk_1b"; break;
		case 28: std::get<1>(result) = "QUEST_GIVER"; break;
		case 29: std::get<1>(result) = "SPECIAL_BURIAL"; break;
		case 30: std::get<1>(result) = "REQUIRES_MARKET"; break;
		case 31: std::get<1>(result) = "unk_1f"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_entity_material_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Clothing"; std::get<2>(result) = "cloth or leather"; break;
		case 1: std::get<1>(result) = "Leather"; std::get<2>(result) = "organic.leather"; break;
		case 2: std::get<1>(result) = "Cloth"; std::get<2>(result) = "any cloth"; break;
		case 3: std::get<1>(result) = "Wood"; std::get<2>(result) = "organic.wood, used for training weapons"; break;
		case 4: std::get<1>(result) = "Crafts"; std::get<2>(result) = "misc_mat.crafts"; break;
		case 5: std::get<1>(result) = "Stone"; std::get<2>(result) = "stones"; break;
		case 6: std::get<1>(result) = "Improvement"; std::get<2>(result) = "misc_mat.crafts"; break;
		case 7: std::get<1>(result) = "Glass"; std::get<2>(result) = "misc_mat.glass_unused, used for extract vials"; break;
		case 8: std::get<1>(result) = "Wood2"; std::get<2>(result) = "misc_mat.barrels, also used for buckets"; break;
		case 9: std::get<1>(result) = "Bag"; std::get<2>(result) = "cloth/leather"; break;
		case 10: std::get<1>(result) = "Cage"; std::get<2>(result) = "misc_mat.cages"; break;
		case 11: std::get<1>(result) = "WeaponMelee"; std::get<2>(result) = "metal.weapon"; break;
		case 12: std::get<1>(result) = "WeaponRanged"; std::get<2>(result) = "metal.ranged"; break;
		case 13: std::get<1>(result) = "Ammo"; std::get<2>(result) = "metal.ammo"; break;
		case 14: std::get<1>(result) = "Ammo2"; std::get<2>(result) = "metal.ammo2"; break;
		case 15: std::get<1>(result) = "Pick"; std::get<2>(result) = "metal.pick"; break;
		case 16: std::get<1>(result) = "Armor"; std::get<2>(result) = "metal.armor, also used for shields, tools, instruments, and toys"; break;
		case 17: std::get<1>(result) = "Gem"; std::get<2>(result) = "gems"; break;
		case 18: std::get<1>(result) = "Bone"; std::get<2>(result) = "refuse.bone"; break;
		case 19: std::get<1>(result) = "Shell"; std::get<2>(result) = "refuse.shell"; break;
		case 20: std::get<1>(result) = "Pearl"; std::get<2>(result) = "refuse.pearl"; break;
		case 21: std::get<1>(result) = "Ivory"; std::get<2>(result) = "refuse.ivory"; break;
		case 22: std::get<1>(result) = "Horn"; std::get<2>(result) = "refuse.horn"; break;
		case 23: std::get<1>(result) = "Other"; std::get<2>(result) = "misc_mat.others"; break;
		case 24: std::get<1>(result) = "Anvil"; std::get<2>(result) = "metal.anvil"; break;
		case 25: std::get<1>(result) = "Booze"; std::get<2>(result) = "misc_mat.booze"; break;
		case 26: std::get<1>(result) = "Metal"; std::get<2>(result) = "metals with ITEMS_HARD, used for chains"; break;
		case 27: std::get<1>(result) = "PlantFiber"; std::get<2>(result) = "organic.fiber"; break;
		case 28: std::get<1>(result) = "Silk"; std::get<2>(result) = "organic.silk"; break;
		case 29: std::get<1>(result) = "Wool"; std::get<2>(result) = "organic.wool"; break;
		case 30: std::get<1>(result) = "Furniture"; std::get<2>(result) = "misc_mat.rock_metal"; break;
		case 31: std::get<1>(result) = "MiscWood2"; std::get<2>(result) = "misc_mat.wood2"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_entity_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "invasion"; break;
		case 1: std::get<1>(result) = "abduction"; break;
		case 2: std::get<1>(result) = "incident"; break;
		case 3: std::get<1>(result) = "occupation"; break;
		case 4: std::get<1>(result) = "beast"; break;
		case 5: std::get<1>(result) = "group"; break;
		case 6: std::get<1>(result) = "harass"; break;
		case 7: std::get<1>(result) = "flee"; break;
		case 8: std::get<1>(result) = "abandon"; break;
		case 9: std::get<1>(result) = "reclaimed"; break;
		case 10: std::get<1>(result) = "founded"; break;
		case 11: std::get<1>(result) = "reclaiming"; break;
		case 12: std::get<1>(result) = "founding"; break;
		case 13: std::get<1>(result) = "leave"; break;
		case 14: std::get<1>(result) = "insurrection"; break;
		case 15: std::get<1>(result) = "insurrection_end"; break;
		case 16: std::get<1>(result) = "succession"; break;
		case 17: std::get<1>(result) = "claim"; break;
		case 18: std::get<1>(result) = "accept_tribute_offer"; break;
		case 19: std::get<1>(result) = "refuse_tribute_offer"; break;
		case 20: std::get<1>(result) = "accept_tribute_demand"; break;
		case 21: std::get<1>(result) = "refuse_tribute_demand"; break;
		case 22: std::get<1>(result) = "accept_peace_offer"; break;
		case 23: std::get<1>(result) = "refuse_peace_offer"; break;
		case 24: std::get<1>(result) = "cease_tribute_offer"; break;
		case 25: std::get<1>(result) = "artifact_in_site"; break;
		case 26: std::get<1>(result) = "artifact_in_subregion"; break;
		case 27: std::get<1>(result) = "artifact_in_feature_layer"; break;
		case 28: std::get<1>(result) = "artifact_in_inventory"; break;
		case 29: std::get<1>(result) = "artifact_not_in_site"; break;
		case 30: std::get<1>(result) = "artifact_not_in_subregion"; break;
		case 31: std::get<1>(result) = "artifact_not_in_feature_layer"; break;
		case 32: std::get<1>(result) = "artifact_not_in_inventory"; break;
		case 33: std::get<1>(result) = "artifact_was_destroyed"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_entity_raw_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "CIV_CONTROLLABLE"; break;
		case 1: std::get<1>(result) = "INDIV_CONTROLLABLE"; break;
		case 2: std::get<1>(result) = "LAYER_LINKED"; break;
		case 3: std::get<1>(result) = "INDOOR_WOOD"; break;
		case 4: std::get<1>(result) = "WOOD_ARMOR"; break;
		case 5: std::get<1>(result) = "SIEGER"; break;
		case 6: std::get<1>(result) = "AMBUSHER"; break;
		case 7: std::get<1>(result) = "BABYSNATCHER"; break;
		case 8: std::get<1>(result) = "ITEM_THIEF"; break;
		case 9: std::get<1>(result) = "CLOTHING"; break;
		case 10: std::get<1>(result) = "CURRENCY_BY_YEAR"; break;
		case 11: std::get<1>(result) = "METAL_PREF"; break;
		case 12: std::get<1>(result) = "GEM_PREF"; break;
		case 13: std::get<1>(result) = "STONE_PREF"; break;
		case 14: std::get<1>(result) = "WOOD_WEAPONS"; break;
		case 15: std::get<1>(result) = "BUILDS_OUTDOOR_FORTIFICATIONS"; break;
		case 16: std::get<1>(result) = "RIVER_PRODUCTS"; break;
		case 17: std::get<1>(result) = "OCEAN_PRODUCTS"; break;
		case 18: std::get<1>(result) = "INDOOR_FARMING"; break;
		case 19: std::get<1>(result) = "OUTDOOR_FARMING"; break;
		case 20: std::get<1>(result) = "USE_CAVE_ANIMALS"; break;
		case 21: std::get<1>(result) = "USE_EVIL_ANIMALS"; break;
		case 22: std::get<1>(result) = "USE_ANIMAL_PRODUCTS"; break;
		case 23: std::get<1>(result) = "COMMON_DOMESTIC_PACK"; break;
		case 24: std::get<1>(result) = "COMMON_DOMESTIC_PULL"; break;
		case 25: std::get<1>(result) = "COMMON_DOMESTIC_MOUNT"; break;
		case 26: std::get<1>(result) = "COMMON_DOMESTIC_PET"; break;
		case 27: std::get<1>(result) = "SUBTERRANEAN_CLOTHING"; break;
		case 28: std::get<1>(result) = "USE_EVIL_WOOD"; break;
		case 29: std::get<1>(result) = "USE_GOOD_WOOD"; break;
		case 30: std::get<1>(result) = "USE_EVIL_PLANTS"; break;
		case 31: std::get<1>(result) = "USE_GOOD_PLANTS"; break;
		case 32: std::get<1>(result) = "USE_GOOD_ANIMALS"; break;
		case 33: std::get<1>(result) = "USE_ANY_PET_RACE"; break;
		case 34: std::get<1>(result) = "USE_MISC_PROCESSED_WOOD_PRODUCTS"; break;
		case 35: std::get<1>(result) = "IMPROVED_BOWS"; break;
		case 36: std::get<1>(result) = "OUTDOOR_WOOD"; break;
		case 37: std::get<1>(result) = "LOCAL_BANDITRY"; break;
		case 38: std::get<1>(result) = "BUILDS_OUTDOOR_TOMBS"; break;
		case 39: std::get<1>(result) = "INVADERS_IGNORE_NEUTRALS"; break;
		case 40: std::get<1>(result) = "AT_PEACE_WITH_WILDLIFE"; break;
		case 41: std::get<1>(result) = "EQUIPMENT_IMPROVEMENTS"; break;
		case 42: std::get<1>(result) = "ABUSE_BODIES"; break;
		case 43: std::get<1>(result) = "UNDEAD_CANDIDATE"; break;
		case 44: std::get<1>(result) = "GENERATED"; break;
		case 45: std::get<1>(result) = "SKULKING"; break;
		case 46: std::get<1>(result) = "anon_1"; break;
		case 47: std::get<1>(result) = "MERCHANT_NOBILITY"; break;
		case 48: std::get<1>(result) = "TREE_CAP_DIPLOMACY"; break;
		case 49: std::get<1>(result) = "DIPLOMAT_BODYGUARDS"; break;
		case 50: std::get<1>(result) = "MERCHANT_BODYGUARDS"; break;
		case 51: std::get<1>(result) = "INDOOR_ORCHARDS"; break;
		case 52: std::get<1>(result) = "OUTDOOR_ORCHARDS"; break;
		case 53: std::get<1>(result) = "WANDERER"; break;
		case 54: std::get<1>(result) = "BEAST_HUNTER"; break;
		case 55: std::get<1>(result) = "SCOUT"; break;
		case 56: std::get<1>(result) = "WILL_ACCEPT_TRIBUTE"; break;
		case 57: std::get<1>(result) = "INDOOR_GARDENS"; break;
		case 58: std::get<1>(result) = "OUTDOOR_GARDENS"; break;
		case 59: std::get<1>(result) = "MERCENARY"; break;
		case 60: std::get<1>(result) = "SITE_GUARDIAN"; break;
		case 61: std::get<1>(result) = "DIVINE_MAT_WEAPONS"; break;
		case 62: std::get<1>(result) = "DIVINE_MAT_ARMOR"; break;
		case 63: std::get<1>(result) = "DIVINE_MAT_CRAFTS"; break;
		case 64: std::get<1>(result) = "DIVINE_MAT_CLOTHING"; break;
		case 65: std::get<1>(result) = "GENERATE_KEYBOARD_INSTRUMENTS"; break;
		case 66: std::get<1>(result) = "GENERATE_STRINGED_INSTRUMENTS"; break;
		case 67: std::get<1>(result) = "GENERATE_WIND_INSTRUMENTS"; break;
		case 68: std::get<1>(result) = "GENERATE_PERCUSSION_INSTRUMENTS"; break;
		case 69: std::get<1>(result) = "GENERATE_POETIC_FORMS"; break;
		case 70: std::get<1>(result) = "GENERATE_MUSICAL_FORMS"; break;
		case 71: std::get<1>(result) = "GENERATE_DANCE_FORMS"; break;
		case 72: std::get<1>(result) = "SET_SCHOLARS_ON_VALUES_AND_JOBS"; break;
		case 73: std::get<1>(result) = "NO_ARTIFACT_CLAIMS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_site_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "PLAYER_FORTRESS"; break;
		case 1: std::get<1>(result) = "DARK_FORTRESS"; break;
		case 2: std::get<1>(result) = "CAVE"; break;
		case 3: std::get<1>(result) = "CAVE_DETAILED"; break;
		case 4: std::get<1>(result) = "TREE_CITY"; break;
		case 5: std::get<1>(result) = "CITY"; break;
		case 6: std::get<1>(result) = "anon_1"; break;
		case 7: std::get<1>(result) = "anon_2"; break;
		case 8: std::get<1>(result) = "FORTRESS"; break;
		case 9: std::get<1>(result) = "anon_3"; break;
		case 10: std::get<1>(result) = "MONUMENT"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ethic_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "KILL_ENTITY_MEMBER"; break;
		case 1: std::get<1>(result) = "KILL_NEUTRAL"; break;
		case 2: std::get<1>(result) = "KILL_ENEMY"; break;
		case 3: std::get<1>(result) = "KILL_ANIMAL"; break;
		case 4: std::get<1>(result) = "KILL_PLANT"; break;
		case 5: std::get<1>(result) = "TORTURE_AS_EXAMPLE"; break;
		case 6: std::get<1>(result) = "TORTURE_FOR_INFORMATION"; break;
		case 7: std::get<1>(result) = "TORTURE_FOR_FUN"; break;
		case 8: std::get<1>(result) = "TORTURE_ANIMALS"; break;
		case 9: std::get<1>(result) = "TREASON"; break;
		case 10: std::get<1>(result) = "OATH_BREAKING"; break;
		case 11: std::get<1>(result) = "LYING"; break;
		case 12: std::get<1>(result) = "VANDALISM"; break;
		case 13: std::get<1>(result) = "TRESPASSING"; break;
		case 14: std::get<1>(result) = "THEFT"; break;
		case 15: std::get<1>(result) = "ASSAULT"; break;
		case 16: std::get<1>(result) = "SLAVERY"; break;
		case 17: std::get<1>(result) = "EAT_SAPIENT_OTHER"; break;
		case 18: std::get<1>(result) = "EAT_SAPIENT_KILL"; break;
		case 19: std::get<1>(result) = "MAKE_TROPHY_SAME_RACE"; break;
		case 20: std::get<1>(result) = "MAKE_TROPHY_SAPIENT"; break;
		case 21: std::get<1>(result) = "MAKE_TROPHY_ANIMAL"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ethic_response_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "NOT_APPLICABLE"; break;
		case 1: std::get<1>(result) = "ACCEPTABLE"; break;
		case 2: std::get<1>(result) = "PERSONAL_MATTER"; break;
		case 3: std::get<1>(result) = "JUSTIFIED_IF_NO_REPERCUSSIONS"; break;
		case 4: std::get<1>(result) = "JUSTIFIED_IF_GOOD_REASON"; break;
		case 5: std::get<1>(result) = "JUSTIFIED_IF_EXTREME_REASON"; break;
		case 6: std::get<1>(result) = "JUSTIFIED_IF_SELF_DEFENSE"; break;
		case 7: std::get<1>(result) = "ONLY_IF_SANCTIONED"; break;
		case 8: std::get<1>(result) = "MISGUIDED"; break;
		case 9: std::get<1>(result) = "SHUN"; break;
		case 10: std::get<1>(result) = "APPALLING"; break;
		case 11: std::get<1>(result) = "PUNISH_REPRIMAND"; break;
		case 12: std::get<1>(result) = "PUNISH_SERIOUS"; break;
		case 13: std::get<1>(result) = "PUNISH_EXILE"; break;
		case 14: std::get<1>(result) = "PUNISH_CAPITAL"; break;
		case 15: std::get<1>(result) = "UNTHINKABLE"; break;
		case 16: std::get<1>(result) = "REQUIRED"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_entity_name_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "OTHER"; break;
		case 1: std::get<1>(result) = "CIV"; break;
		case 2: std::get<1>(result) = "SITE"; break;
		case 3: std::get<1>(result) = "VESSEL"; break;
		case 4: std::get<1>(result) = "MILITARY_UNIT"; break;
		case 5: std::get<1>(result) = "RELIGION"; break;
		case 6: std::get<1>(result) = "TEMPLE"; break;
		case 7: std::get<1>(result) = "WAR"; break;
		case 8: std::get<1>(result) = "BATTLE"; break;
		case 9: std::get<1>(result) = "SIEGE"; break;
		case 10: std::get<1>(result) = "ROAD"; break;
		case 11: std::get<1>(result) = "BRIDGE"; break;
		case 12: std::get<1>(result) = "TUNNEL"; break;
		case 13: std::get<1>(result) = "WALL"; break;
		case 14: std::get<1>(result) = "LIBRARY"; break;
		case 15: std::get<1>(result) = "FESTIVAL"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_entity_position_raw_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SITE"; break;
		case 1: std::get<1>(result) = "ELECTED"; break;
		case 2: std::get<1>(result) = "CONQUERED_SITE"; break;
		case 3: std::get<1>(result) = "MILITARY_SCREEN_ONLY"; break;
		case 4: std::get<1>(result) = "GENDER_MALE"; break;
		case 5: std::get<1>(result) = "GENDER_FEMALE"; break;
		case 6: std::get<1>(result) = "SUCCESSION_BY_HEIR"; break;
		case 7: std::get<1>(result) = "EXPORTED_IN_LEGENDS"; break;
		case 8: std::get<1>(result) = "FLASHES"; break;
		case 9: std::get<1>(result) = "BRAG_ON_KILL"; break;
		case 10: std::get<1>(result) = "CHAT_WORTHY"; break;
		case 11: std::get<1>(result) = "DO_NOT_CULL"; break;
		case 12: std::get<1>(result) = "KILL_QUEST"; break;
		case 13: std::get<1>(result) = "DETERMINES_COIN_DESIGN"; break;
		case 14: std::get<1>(result) = "ACCOUNT_EXEMPT"; break;
		case 15: std::get<1>(result) = "DUTY_BOUND"; break;
		case 16: std::get<1>(result) = "COLOR"; break;
		case 17: std::get<1>(result) = "RULES_FROM_LOCATION"; break;
		case 18: std::get<1>(result) = "MENIAL_WORK_EXEMPTION"; break;
		case 19: std::get<1>(result) = "MENIAL_WORK_EXEMPTION_SPOUSE"; break;
		case 20: std::get<1>(result) = "SLEEP_PRETENSION"; break;
		case 21: std::get<1>(result) = "PUNISHMENT_EXEMPTION"; break;
		case 22: std::get<1>(result) = "QUEST_GIVER"; break;
		case 23: std::get<1>(result) = "SPECIAL_BURIAL"; break;
		case 24: std::get<1>(result) = "REQUIRES_MARKET"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_entity_position_responsibility_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "LAW_MAKING"; break;
		case 1: std::get<1>(result) = "LAW_ENFORCEMENT"; break;
		case 2: std::get<1>(result) = "RECEIVE_DIPLOMATS"; break;
		case 3: std::get<1>(result) = "MEET_WORKERS"; break;
		case 4: std::get<1>(result) = "MANAGE_PRODUCTION"; break;
		case 5: std::get<1>(result) = "TRADE"; break;
		case 6: std::get<1>(result) = "ACCOUNTING"; break;
		case 7: std::get<1>(result) = "ESTABLISH_COLONY_TRADE_AGREEMENTS"; break;
		case 8: std::get<1>(result) = "MAKE_INTRODUCTIONS"; break;
		case 9: std::get<1>(result) = "MAKE_PEACE_AGREEMENTS"; break;
		case 10: std::get<1>(result) = "MAKE_TOPIC_AGREEMENTS"; break;
		case 11: std::get<1>(result) = "COLLECT_TAXES"; break;
		case 12: std::get<1>(result) = "ESCORT_TAX_COLLECTOR"; break;
		case 13: std::get<1>(result) = "EXECUTIONS"; break;
		case 14: std::get<1>(result) = "TAME_EXOTICS"; break;
		case 15: std::get<1>(result) = "RELIGION"; break;
		case 16: std::get<1>(result) = "ATTACK_ENEMIES"; break;
		case 17: std::get<1>(result) = "PATROL_TERRITORY"; break;
		case 18: std::get<1>(result) = "MILITARY_GOALS"; break;
		case 19: std::get<1>(result) = "MILITARY_STRATEGY"; break;
		case 20: std::get<1>(result) = "UPGRADE_SQUAD_EQUIPMENT"; break;
		case 21: std::get<1>(result) = "EQUIPMENT_MANIFESTS"; break;
		case 22: std::get<1>(result) = "SORT_AMMUNITION"; break;
		case 23: std::get<1>(result) = "BUILD_MORALE"; break;
		case 24: std::get<1>(result) = "HEALTH_MANAGEMENT"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_weather_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "None"; break;
		case 1: std::get<1>(result) = "Rain"; break;
		case 2: std::get<1>(result) = "Snow"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_game_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "DWARF"; break;
		case 1: std::get<1>(result) = "ADVENTURE"; break;
		case 2: std::get<1>(result) = "num"; break;
		case 3: std::get<1>(result) = "NONE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_game_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "DWARF_MAIN"; break;
		case 1: std::get<1>(result) = "ADVENTURE_MAIN"; break;
		case 2: std::get<1>(result) = "VIEW_LEGENDS"; break;
		case 3: std::get<1>(result) = "DWARF_RECLAIM"; break;
		case 4: std::get<1>(result) = "DWARF_ARENA"; break;
		case 5: std::get<1>(result) = "ADVENTURE_ARENA"; break;
		case 6: std::get<1>(result) = "ADVENTURE_DUNGEON"; break;
		case 7: std::get<1>(result) = "DWARF_TUTORIAL"; break;
		case 8: std::get<1>(result) = "DWARF_UNRETIRE"; break;
		case 9: std::get<1>(result) = "ADVENTURE_WORLD_DEBUG"; break;
		case 10: std::get<1>(result) = "num"; break;
		case 11: std::get<1>(result) = "NONE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_lever_target_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 66: std::get<1>(result) = "BarsVertical"; break;
		case 70: std::get<1>(result) = "BarsFloor"; break;
		case 83: std::get<1>(result) = "SpearsSpikes"; break;
		case 84: std::get<1>(result) = "TrackStop"; break;
		case 97: std::get<1>(result) = "GearAssembly"; break;
		case 98: std::get<1>(result) = "Bridge"; break;
		case 99: std::get<1>(result) = "Chain"; break;
		case 100: std::get<1>(result) = "Door"; break;
		case 101: std::get<1>(result) = "EncrustGems"; break;
		case 102: std::get<1>(result) = "Floodgate"; break;
		case 103: std::get<1>(result) = "GrateFloor"; break;
		case 104: std::get<1>(result) = "Hatch"; break;
		case 106: std::get<1>(result) = "Cage"; break;
		case 115: std::get<1>(result) = "Support"; break;
		case 119: std::get<1>(result) = "GrateWall"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_zoom_commands_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "zoom_in"; break;
		case 1: std::get<1>(result) = "zoom_out"; break;
		case 2: std::get<1>(result) = "zoom_reset"; break;
		case 3: std::get<1>(result) = "zoom_fullscreen"; break;
		case 4: std::get<1>(result) = "zoom_resetgrid"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_reputation_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Hero"; break;
		case 1: std::get<1>(result) = "Buddy"; break;
		case 2: std::get<1>(result) = "Grudge"; break;
		case 3: std::get<1>(result) = "AnimalPartner"; break;
		case 4: std::get<1>(result) = "Brawler"; break;
		case 5: std::get<1>(result) = "Psycho"; break;
		case 6: std::get<1>(result) = "TradePartner"; break;
		case 7: std::get<1>(result) = "Friendly"; break;
		case 8: std::get<1>(result) = "Killer"; break;
		case 9: std::get<1>(result) = "Murderer"; break;
		case 10: std::get<1>(result) = "Comrade"; break;
		case 11: std::get<1>(result) = "RespectedGroup"; break;
		case 12: std::get<1>(result) = "HatedGroup"; break;
		case 13: std::get<1>(result) = "EnemyFighter"; break;
		case 14: std::get<1>(result) = "FriendlyFighter"; break;
		case 15: std::get<1>(result) = "Bully"; break;
		case 16: std::get<1>(result) = "Brigand"; break;
		case 17: std::get<1>(result) = "LoyalSoldier"; break;
		case 18: std::get<1>(result) = "Monster"; break;
		case 19: std::get<1>(result) = "Storyteller"; break;
		case 20: std::get<1>(result) = "Poet"; break;
		case 21: std::get<1>(result) = "Bard"; break;
		case 22: std::get<1>(result) = "Dancer"; break;
		case 23: std::get<1>(result) = "Quarreler"; break;
		case 24: std::get<1>(result) = "Flatterer"; break;
		case 25: std::get<1>(result) = "Hunter"; break;
		case 26: std::get<1>(result) = "ProtectorOfWeak"; break;
		case 27: std::get<1>(result) = "TreasureHunter"; break;
		case 28: std::get<1>(result) = "Thief"; break;
		case 29: std::get<1>(result) = "InformationSource"; break;
		case 30: std::get<1>(result) = "PreserverOfKnowledge"; break;
		case 31: std::get<1>(result) = "Intruder"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_histfig_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "reveal_artwork"; break;
		case 1: std::get<1>(result) = "equipment_created"; break;
		case 2: std::get<1>(result) = "deity"; break;
		case 3: std::get<1>(result) = "force"; break;
		case 4: std::get<1>(result) = "skeletal_deity"; break;
		case 5: std::get<1>(result) = "rotting_deity"; break;
		case 6: std::get<1>(result) = "worldgen_acted"; break;
		case 7: std::get<1>(result) = "ghost"; break;
		case 8: std::get<1>(result) = "skin_destroyed"; break;
		case 9: std::get<1>(result) = "meat_destroyed"; break;
		case 10: std::get<1>(result) = "bones_destroyed"; break;
		case 11: std::get<1>(result) = "brag_on_kill"; break;
		case 12: std::get<1>(result) = "kill_quest"; break;
		case 13: std::get<1>(result) = "chatworthy"; break;
		case 14: std::get<1>(result) = "flashes"; break;
		case 15: std::get<1>(result) = "never_cull"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_histfig_relationship_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Mother"; break;
		case 1: std::get<1>(result) = "Father"; break;
		case 2: std::get<1>(result) = "Parent"; break;
		case 3: std::get<1>(result) = "Husband"; break;
		case 4: std::get<1>(result) = "Wife"; break;
		case 5: std::get<1>(result) = "Spouse"; break;
		case 6: std::get<1>(result) = "SonEldest"; break;
		case 7: std::get<1>(result) = "SonEldest2"; break;
		case 8: std::get<1>(result) = "SonEldest3"; break;
		case 9: std::get<1>(result) = "SonEldest4"; break;
		case 10: std::get<1>(result) = "SonEldest5"; break;
		case 11: std::get<1>(result) = "SonEldest6"; break;
		case 12: std::get<1>(result) = "SonEldest7"; break;
		case 13: std::get<1>(result) = "SonEldest8"; break;
		case 14: std::get<1>(result) = "SonEldest9"; break;
		case 15: std::get<1>(result) = "SonEldest10"; break;
		case 16: std::get<1>(result) = "Son"; break;
		case 17: std::get<1>(result) = "SonYoungest"; break;
		case 18: std::get<1>(result) = "SonOnly"; break;
		case 19: std::get<1>(result) = "DaughterEldest"; break;
		case 20: std::get<1>(result) = "DaughterEldest2"; break;
		case 21: std::get<1>(result) = "DaughterEldest3"; break;
		case 22: std::get<1>(result) = "DaughterEldest4"; break;
		case 23: std::get<1>(result) = "DaughterEldest5"; break;
		case 24: std::get<1>(result) = "DaughterEldest6"; break;
		case 25: std::get<1>(result) = "DaughterEldest7"; break;
		case 26: std::get<1>(result) = "DaughterEldest8"; break;
		case 27: std::get<1>(result) = "DaughterEldest9"; break;
		case 28: std::get<1>(result) = "DaughterEldest10"; break;
		case 29: std::get<1>(result) = "Daughter"; break;
		case 30: std::get<1>(result) = "DaughterOnly"; break;
		case 31: std::get<1>(result) = "DaughterYoungest"; break;
		case 32: std::get<1>(result) = "ChildEldest"; break;
		case 33: std::get<1>(result) = "ChildEldest2"; break;
		case 34: std::get<1>(result) = "ChildEldest3"; break;
		case 35: std::get<1>(result) = "ChildEldest4"; break;
		case 36: std::get<1>(result) = "ChildEldest5"; break;
		case 37: std::get<1>(result) = "ChildEldest6"; break;
		case 38: std::get<1>(result) = "ChildEldest7"; break;
		case 39: std::get<1>(result) = "ChildEldest8"; break;
		case 40: std::get<1>(result) = "ChildEldest9"; break;
		case 41: std::get<1>(result) = "ChildEldest10"; break;
		case 42: std::get<1>(result) = "Child"; break;
		case 43: std::get<1>(result) = "ChildYoungest"; break;
		case 44: std::get<1>(result) = "ChildOnly"; break;
		case 45: std::get<1>(result) = "PaternalGrandmother"; break;
		case 46: std::get<1>(result) = "PaternalGrandfather"; break;
		case 47: std::get<1>(result) = "MaternalGrandmother"; break;
		case 48: std::get<1>(result) = "MaternalGrandfather"; break;
		case 49: std::get<1>(result) = "Grandmother"; break;
		case 50: std::get<1>(result) = "Grandfather"; break;
		case 51: std::get<1>(result) = "Grandparent"; break;
		case 52: std::get<1>(result) = "OlderBrother"; break;
		case 53: std::get<1>(result) = "OlderSister"; break;
		case 54: std::get<1>(result) = "OlderSibling"; break;
		case 55: std::get<1>(result) = "YoungerBrother"; break;
		case 56: std::get<1>(result) = "YoungerSister"; break;
		case 57: std::get<1>(result) = "YoungerSibling"; break;
		case 58: std::get<1>(result) = "Cousin"; break;
		case 59: std::get<1>(result) = "Aunt"; break;
		case 60: std::get<1>(result) = "Uncle"; break;
		case 61: std::get<1>(result) = "Niece"; break;
		case 62: std::get<1>(result) = "Nephew"; break;
		case 63: std::get<1>(result) = "Sibling"; break;
		case 64: std::get<1>(result) = "Grandchild"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_mental_picture_property_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "DATE"; break;
		case 1: std::get<1>(result) = "ACTION"; break;
		case 2: std::get<1>(result) = "TOOL"; break;
		case 3: std::get<1>(result) = "EMOTION"; break;
		case 4: std::get<1>(result) = "COLOR_PATTERN"; break;
		case 5: std::get<1>(result) = "SHAPE"; break;
		case 6: std::get<1>(result) = "ADJECTIVE"; break;
		case 7: std::get<1>(result) = "POSITION"; break;
		case 8: std::get<1>(result) = "TIME"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_mental_picture_element_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "HF"; break;
		case 1: std::get<1>(result) = "SITE"; break;
		case 2: std::get<1>(result) = "REGION"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_history_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "WAR_ATTACKED_SITE"; break;
		case 1: std::get<1>(result) = "WAR_DESTROYED_SITE"; break;
		case 2: std::get<1>(result) = "CREATED_SITE"; break;
		case 3: std::get<1>(result) = "HIST_FIGURE_DIED"; break;
		case 4: std::get<1>(result) = "ADD_HF_ENTITY_LINK"; break;
		case 5: std::get<1>(result) = "REMOVE_HF_ENTITY_LINK"; break;
		case 6: std::get<1>(result) = "FIRST_CONTACT"; break;
		case 7: std::get<1>(result) = "FIRST_CONTACT_FAILED"; break;
		case 8: std::get<1>(result) = "TOPICAGREEMENT_CONCLUDED"; break;
		case 9: std::get<1>(result) = "TOPICAGREEMENT_REJECTED"; break;
		case 10: std::get<1>(result) = "TOPICAGREEMENT_MADE"; break;
		case 11: std::get<1>(result) = "WAR_PEACE_ACCEPTED"; break;
		case 12: std::get<1>(result) = "WAR_PEACE_REJECTED"; break;
		case 13: std::get<1>(result) = "DIPLOMAT_LOST"; break;
		case 14: std::get<1>(result) = "AGREEMENTS_VOIDED"; break;
		case 15: std::get<1>(result) = "MERCHANT"; break;
		case 16: std::get<1>(result) = "ARTIFACT_HIDDEN"; break;
		case 17: std::get<1>(result) = "ARTIFACT_POSSESSED"; break;
		case 18: std::get<1>(result) = "ARTIFACT_CREATED"; break;
		case 19: std::get<1>(result) = "ARTIFACT_LOST"; break;
		case 20: std::get<1>(result) = "ARTIFACT_FOUND"; break;
		case 21: std::get<1>(result) = "ARTIFACT_RECOVERED"; break;
		case 22: std::get<1>(result) = "ARTIFACT_DROPPED"; break;
		case 23: std::get<1>(result) = "RECLAIM_SITE"; break;
		case 24: std::get<1>(result) = "HF_DESTROYED_SITE"; break;
		case 25: std::get<1>(result) = "SITE_DIED"; break;
		case 26: std::get<1>(result) = "SITE_RETIRED"; break;
		case 27: std::get<1>(result) = "ENTITY_CREATED"; break;
		case 28: std::get<1>(result) = "ENTITY_ACTION"; break;
		case 29: std::get<1>(result) = "ENTITY_INCORPORATED"; break;
		case 30: std::get<1>(result) = "CREATED_BUILDING"; break;
		case 31: std::get<1>(result) = "REPLACED_BUILDING"; break;
		case 32: std::get<1>(result) = "ADD_HF_SITE_LINK"; break;
		case 33: std::get<1>(result) = "REMOVE_HF_SITE_LINK"; break;
		case 34: std::get<1>(result) = "ADD_HF_HF_LINK"; break;
		case 35: std::get<1>(result) = "REMOVE_HF_HF_LINK"; break;
		case 36: std::get<1>(result) = "ENTITY_RAZED_BUILDING"; break;
		case 37: std::get<1>(result) = "MASTERPIECE_CREATED_ARCH_DESIGN"; break;
		case 38: std::get<1>(result) = "MASTERPIECE_CREATED_ARCH_CONSTRUCT"; break;
		case 39: std::get<1>(result) = "MASTERPIECE_CREATED_ITEM"; break;
		case 40: std::get<1>(result) = "MASTERPIECE_CREATED_DYE_ITEM"; break;
		case 41: std::get<1>(result) = "MASTERPIECE_CREATED_ITEM_IMPROVEMENT"; break;
		case 42: std::get<1>(result) = "MASTERPIECE_CREATED_FOOD"; break;
		case 43: std::get<1>(result) = "MASTERPIECE_CREATED_ENGRAVING"; break;
		case 44: std::get<1>(result) = "MASTERPIECE_LOST"; break;
		case 45: std::get<1>(result) = "CHANGE_HF_STATE"; break;
		case 46: std::get<1>(result) = "CHANGE_HF_JOB"; break;
		case 47: std::get<1>(result) = "WAR_FIELD_BATTLE"; break;
		case 48: std::get<1>(result) = "WAR_PLUNDERED_SITE"; break;
		case 49: std::get<1>(result) = "WAR_SITE_NEW_LEADER"; break;
		case 50: std::get<1>(result) = "WAR_SITE_TRIBUTE_FORCED"; break;
		case 51: std::get<1>(result) = "WAR_SITE_TAKEN_OVER"; break;
		case 52: std::get<1>(result) = "BODY_ABUSED"; break;
		case 53: std::get<1>(result) = "HIST_FIGURE_ABDUCTED"; break;
		case 54: std::get<1>(result) = "ITEM_STOLEN"; break;
		case 55: std::get<1>(result) = "HF_RAZED_BUILDING"; break;
		case 56: std::get<1>(result) = "CREATURE_DEVOURED"; break;
		case 57: std::get<1>(result) = "HIST_FIGURE_WOUNDED"; break;
		case 58: std::get<1>(result) = "HIST_FIGURE_SIMPLE_BATTLE_EVENT"; break;
		case 59: std::get<1>(result) = "CREATED_WORLD_CONSTRUCTION"; break;
		case 60: std::get<1>(result) = "HIST_FIGURE_REUNION"; break;
		case 61: std::get<1>(result) = "HIST_FIGURE_REACH_SUMMIT"; break;
		case 62: std::get<1>(result) = "HIST_FIGURE_TRAVEL"; break;
		case 63: std::get<1>(result) = "HIST_FIGURE_NEW_PET"; break;
		case 64: std::get<1>(result) = "ASSUME_IDENTITY"; break;
		case 65: std::get<1>(result) = "CREATE_ENTITY_POSITION"; break;
		case 66: std::get<1>(result) = "CHANGE_CREATURE_TYPE"; break;
		case 67: std::get<1>(result) = "HIST_FIGURE_REVIVED"; break;
		case 68: std::get<1>(result) = "HF_LEARNS_SECRET"; break;
		case 69: std::get<1>(result) = "CHANGE_HF_BODY_STATE"; break;
		case 70: std::get<1>(result) = "HF_ACT_ON_BUILDING"; break;
		case 71: std::get<1>(result) = "HF_DOES_INTERACTION"; break;
		case 72: std::get<1>(result) = "HF_CONFRONTED"; break;
		case 73: std::get<1>(result) = "ENTITY_LAW"; break;
		case 74: std::get<1>(result) = "HF_GAINS_SECRET_GOAL"; break;
		case 75: std::get<1>(result) = "ARTIFACT_STORED"; break;
		case 76: std::get<1>(result) = "AGREEMENT_FORMED"; break;
		case 77: std::get<1>(result) = "SITE_DISPUTE"; break;
		case 78: std::get<1>(result) = "AGREEMENT_CONCLUDED"; break;
		case 79: std::get<1>(result) = "INSURRECTION_STARTED"; break;
		case 80: std::get<1>(result) = "INSURRECTION_ENDED"; break;
		case 81: std::get<1>(result) = "HF_ATTACKED_SITE"; break;
		case 82: std::get<1>(result) = "PERFORMANCE"; break;
		case 83: std::get<1>(result) = "COMPETITION"; break;
		case 84: std::get<1>(result) = "PROCESSION"; break;
		case 85: std::get<1>(result) = "CEREMONY"; break;
		case 86: std::get<1>(result) = "KNOWLEDGE_DISCOVERED"; break;
		case 87: std::get<1>(result) = "ARTIFACT_TRANSFORMED"; break;
		case 88: std::get<1>(result) = "ARTIFACT_DESTROYED"; break;
		case 89: std::get<1>(result) = "HF_RELATIONSHIP_DENIED"; break;
		case 90: std::get<1>(result) = "REGIONPOP_INCORPORATED_INTO_ENTITY"; break;
		case 91: std::get<1>(result) = "POETIC_FORM_CREATED"; break;
		case 92: std::get<1>(result) = "MUSICAL_FORM_CREATED"; break;
		case 93: std::get<1>(result) = "DANCE_FORM_CREATED"; break;
		case 94: std::get<1>(result) = "WRITTEN_CONTENT_COMPOSED"; break;
		case 95: std::get<1>(result) = "CHANGE_HF_MOOD"; break;
		case 96: std::get<1>(result) = "ARTIFACT_CLAIM_FORMED"; break;
		case 97: std::get<1>(result) = "ARTIFACT_GIVEN"; break;
		case 98: std::get<1>(result) = "HF_ACT_ON_ARTIFACT"; break;
		case 99: std::get<1>(result) = "HF_RECRUITED_UNIT_TYPE_FOR_ENTITY"; break;
		case 100: std::get<1>(result) = "HFS_FORMED_REPUTATION_RELATIONSHIP"; break;
		case 101: std::get<1>(result) = "ARTIFACT_COPIED"; break;
		case 102: std::get<1>(result) = "SNEAK_INTO_SITE"; break;
		case 103: std::get<1>(result) = "SPOTTED_LEAVING_SITE"; break;
		case 104: std::get<1>(result) = "ENTITY_SEARCHED_SITE"; break;
		case 105: std::get<1>(result) = "HF_FREED"; break;
		case 106: std::get<1>(result) = "HIST_FIGURE_SIMPLE_ACTION"; break;
		case 107: std::get<1>(result) = "ENTITY_RAMPAGED_IN_SITE"; break;
		case 108: std::get<1>(result) = "ENTITY_FLED_SITE"; break;
		case 109: std::get<1>(result) = "TACTICAL_SITUATION"; break;
		case 110: std::get<1>(result) = "SQUAD_VS_SQUAD"; break;
		case 111: std::get<1>(result) = "SITE_SURRENDERED"; break;
		case 112: std::get<1>(result) = "ENTITY_EXPELS_HF"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_history_event_reason_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "none"; break;
		case 0: std::get<1>(result) = "insurrection"; break;
		case 1: std::get<1>(result) = "adventure"; break;
		case 2: std::get<1>(result) = "guide"; break;
		case 3: std::get<1>(result) = "rescued"; break;
		case 4: std::get<1>(result) = "sphere_alignment"; break;
		case 5: std::get<1>(result) = "maintain_balance_in_universe"; break;
		case 6: std::get<1>(result) = "highlight_boundaries_between_worlds"; break;
		case 7: std::get<1>(result) = "sow_the_seeds_of_chaos_in_the_world"; break;
		case 8: std::get<1>(result) = "provide_opportunities_for_courage"; break;
		case 9: std::get<1>(result) = "bring_death_to_the_world"; break;
		case 10: std::get<1>(result) = "liked_appearance"; break;
		case 11: std::get<1>(result) = "because_it_was_destined"; break;
		case 12: std::get<1>(result) = "great_fortresses_built_and_tested"; break;
		case 13: std::get<1>(result) = "whim"; break;
		case 14: std::get<1>(result) = "bring_misery_to_the_world"; break;
		case 15: std::get<1>(result) = "bring_murder_to_the_world"; break;
		case 16: std::get<1>(result) = "bring_nightmares_into_reality"; break;
		case 17: std::get<1>(result) = "bring_thralldom_to_the_world"; break;
		case 18: std::get<1>(result) = "bring_torture_to_the_world"; break;
		case 19: std::get<1>(result) = "provide_opportunities_for_acts_of_valor"; break;
		case 20: std::get<1>(result) = "bring_war_to_the_world"; break;
		case 21: std::get<1>(result) = "find_relative"; break;
		case 22: std::get<1>(result) = "offer_condolences"; break;
		case 23: std::get<1>(result) = "be_brought_to_safety"; break;
		case 24: std::get<1>(result) = "help_with_rescue"; break;
		case 25: std::get<1>(result) = "insufficient_work"; break;
		case 26: std::get<1>(result) = "work_request"; break;
		case 27: std::get<1>(result) = "make_weapon"; break;
		case 28: std::get<1>(result) = "vent_at_boss"; break;
		case 29: std::get<1>(result) = "cry_on_boss"; break;
		case 30: std::get<1>(result) = "should_have_reached_goal"; break;
		case 31: std::get<1>(result) = "insufficient_progress_toward_goal"; break;
		case 32: std::get<1>(result) = "going_wrong_direction"; break;
		case 33: std::get<1>(result) = "arrived_at_location"; break;
		case 34: std::get<1>(result) = "entity_no_longer_rules"; break;
		case 35: std::get<1>(result) = "left_site"; break;
		case 36: std::get<1>(result) = "reunited_with_loved_one"; break;
		case 37: std::get<1>(result) = "violent_disagreement"; break;
		case 38: std::get<1>(result) = "adopted"; break;
		case 39: std::get<1>(result) = "true_name_invocation"; break;
		case 40: std::get<1>(result) = "arrived_at_person"; break;
		case 41: std::get<1>(result) = "eradicate_beasts"; break;
		case 42: std::get<1>(result) = "entertain_people"; break;
		case 43: std::get<1>(result) = "make_a_living_as_a_warrior"; break;
		case 44: std::get<1>(result) = "study"; break;
		case 45: std::get<1>(result) = "flight"; break;
		case 46: std::get<1>(result) = "scholarship"; break;
		case 47: std::get<1>(result) = "be_with_master"; break;
		case 48: std::get<1>(result) = "become_citizen"; break;
		case 49: std::get<1>(result) = "prefers_working_alone"; break;
		case 50: std::get<1>(result) = "jealousy"; break;
		case 51: std::get<1>(result) = "glorify_hf"; break;
		case 52: std::get<1>(result) = "have_not_performed"; break;
		case 53: std::get<1>(result) = "prevented_from_leaving"; break;
		case 54: std::get<1>(result) = "curiosity"; break;
		case 55: std::get<1>(result) = "hire_on_as_mercenary"; break;
		case 56: std::get<1>(result) = "hire_on_as_performer"; break;
		case 57: std::get<1>(result) = "hire_on_as_scholar"; break;
		case 58: std::get<1>(result) = "drink"; break;
		case 59: std::get<1>(result) = "admire_architecture"; break;
		case 60: std::get<1>(result) = "pray"; break;
		case 61: std::get<1>(result) = "relax"; break;
		case 62: std::get<1>(result) = "danger"; break;
		case 63: std::get<1>(result) = "cannot_find_artifact"; break;
		case 64: std::get<1>(result) = "failed_mood"; break;
		case 65: std::get<1>(result) = "lack_of_sleep"; break;
		case 66: std::get<1>(result) = "trapped_in_cage"; break;
		case 67: std::get<1>(result) = "great_deal_of_stress"; break;
		case 68: std::get<1>(result) = "unable_to_leave_location"; break;
		case 69: std::get<1>(result) = "sanctify_hf"; break;
		case 70: std::get<1>(result) = "artifact_is_heirloom_of_family_hfid"; break;
		case 71: std::get<1>(result) = "cement_bonds_of_friendship"; break;
		case 72: std::get<1>(result) = "as_a_symbol_of_everlasting_peace"; break;
		case 73: std::get<1>(result) = "on_a_pilgrimage"; break;
		case 74: std::get<1>(result) = "gather_information"; break;
		case 75: std::get<1>(result) = "seek_sanctuary"; break;
		case 76: std::get<1>(result) = "part_of_trade_negotiation"; break;
		case 77: std::get<1>(result) = "artifact_is_symbol_of_entity_position"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_death_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "OLD_AGE"; break;
		case 1: std::get<1>(result) = "HUNGER"; break;
		case 2: std::get<1>(result) = "THIRST"; break;
		case 3: std::get<1>(result) = "SHOT"; break;
		case 4: std::get<1>(result) = "BLEED"; break;
		case 5: std::get<1>(result) = "DROWN"; break;
		case 6: std::get<1>(result) = "SUFFOCATE"; break;
		case 7: std::get<1>(result) = "STRUCK_DOWN"; break;
		case 8: std::get<1>(result) = "SCUTTLE"; std::get<2>(result) = "stuck wagons"; break;
		case 9: std::get<1>(result) = "COLLISION"; break;
		case 10: std::get<1>(result) = "MAGMA"; std::get<2>(result) = "does not happen anymore?"; break;
		case 11: std::get<1>(result) = "MAGMA_MIST"; std::get<2>(result) = "does not happen anymore?"; break;
		case 12: std::get<1>(result) = "DRAGONFIRE"; break;
		case 13: std::get<1>(result) = "FIRE"; break;
		case 14: std::get<1>(result) = "SCALD"; std::get<2>(result) = "does not happen anymore?"; break;
		case 15: std::get<1>(result) = "CAVEIN"; break;
		case 16: std::get<1>(result) = "DRAWBRIDGE"; break;
		case 17: std::get<1>(result) = "FALLING_ROCKS"; std::get<2>(result) = "does not happen anymore?"; break;
		case 18: std::get<1>(result) = "CHASM"; break;
		case 19: std::get<1>(result) = "CAGE"; break;
		case 20: std::get<1>(result) = "MURDER"; break;
		case 21: std::get<1>(result) = "TRAP"; break;
		case 22: std::get<1>(result) = "VANISH"; std::get<2>(result) = "bogeyman"; break;
		case 23: std::get<1>(result) = "QUIT"; std::get<2>(result) = "Give in to starvation as adventurer"; break;
		case 24: std::get<1>(result) = "ABANDON"; break;
		case 25: std::get<1>(result) = "HEAT"; break;
		case 26: std::get<1>(result) = "COLD"; break;
		case 27: std::get<1>(result) = "SPIKE"; break;
		case 28: std::get<1>(result) = "ENCASE_LAVA"; break;
		case 29: std::get<1>(result) = "ENCASE_MAGMA"; break;
		case 30: std::get<1>(result) = "ENCASE_ICE"; break;
		case 31: std::get<1>(result) = "BEHEAD"; std::get<2>(result) = "execution during worldgen"; break;
		case 32: std::get<1>(result) = "CRUCIFY"; std::get<2>(result) = "execution during worldgen"; break;
		case 33: std::get<1>(result) = "BURY_ALIVE"; std::get<2>(result) = "execution during worldgen"; break;
		case 34: std::get<1>(result) = "DROWN_ALT"; std::get<2>(result) = "execution during worldgen"; break;
		case 35: std::get<1>(result) = "BURN_ALIVE"; std::get<2>(result) = "execution during worldgen"; break;
		case 36: std::get<1>(result) = "FEED_TO_BEASTS"; std::get<2>(result) = "execution during worldgen"; break;
		case 37: std::get<1>(result) = "HACK_TO_PIECES"; std::get<2>(result) = "execution during worldgen"; break;
		case 38: std::get<1>(result) = "LEAVE_OUT_IN_AIR"; std::get<2>(result) = "execution during worldgen"; break;
		case 39: std::get<1>(result) = "BOIL"; std::get<2>(result) = "material state change"; break;
		case 40: std::get<1>(result) = "MELT"; std::get<2>(result) = "material state change"; break;
		case 41: std::get<1>(result) = "CONDENSE"; std::get<2>(result) = "material state change"; break;
		case 42: std::get<1>(result) = "SOLIDIFY"; std::get<2>(result) = "material state change"; break;
		case 43: std::get<1>(result) = "INFECTION"; break;
		case 44: std::get<1>(result) = "MEMORIALIZE"; std::get<2>(result) = "put to rest"; break;
		case 45: std::get<1>(result) = "SCARE"; break;
		case 46: std::get<1>(result) = "DARKNESS"; std::get<2>(result) = "died in the dark"; break;
		case 47: std::get<1>(result) = "COLLAPSE"; std::get<2>(result) = "used in 0.31 for undead"; break;
		case 48: std::get<1>(result) = "DRAIN_BLOOD"; break;
		case 49: std::get<1>(result) = "SLAUGHTER"; break;
		case 50: std::get<1>(result) = "VEHICLE"; break;
		case 51: std::get<1>(result) = "FALLING_OBJECT"; break;
		case 52: std::get<1>(result) = "LEAPT_FROM_HEIGHT"; break;
		case 53: std::get<1>(result) = "DROWN_ALT2"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_entity_action_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "entity_primary_criminals"; break;
		case 1: std::get<1>(result) = "entity_relocate"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_masterpiece_loss_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MELT"; break;
		case 1: std::get<1>(result) = "MAGMA"; break;
		case 2: std::get<1>(result) = "FORTIFICATION"; break;
		case 3: std::get<1>(result) = "MINING"; break;
		case 4: std::get<1>(result) = "CAVEIN"; break;
		case 5: std::get<1>(result) = "VEGETATION"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_history_event_hist_figure_woundedst__T_injury_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Smash"; break;
		case 1: std::get<1>(result) = "Slash"; break;
		case 2: std::get<1>(result) = "Stab"; break;
		case 3: std::get<1>(result) = "Rip"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_history_event_simple_battle_subtype_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SCUFFLE"; break;
		case 1: std::get<1>(result) = "ATTACK"; break;
		case 2: std::get<1>(result) = "SURPRISE"; break;
		case 3: std::get<1>(result) = "AMBUSH"; break;
		case 4: std::get<1>(result) = "HAPPEN_UPON"; break;
		case 5: std::get<1>(result) = "CORNER"; break;
		case 6: std::get<1>(result) = "CONFRONT"; break;
		case 7: std::get<1>(result) = "LOSE_AFTER_RECEIVE_WOUND"; break;
		case 8: std::get<1>(result) = "LOSE_AFTER_INFLICT_WOUND"; break;
		case 9: std::get<1>(result) = "LOSE_AFTER_EXCHANGE_WOUND"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_histfig_body_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Active"; break;
		case 1: std::get<1>(result) = "BuriedAtSite"; break;
		case 2: std::get<1>(result) = "UnburiedAtBattlefield"; break;
		case 3: std::get<1>(result) = "UnburiedAtSubregion"; break;
		case 4: std::get<1>(result) = "UnburiedAtFeatureLayer"; break;
		case 5: std::get<1>(result) = "EntombedAtSite"; break;
		case 6: std::get<1>(result) = "UnburiedAtSite"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_history_event_hf_act_on_buildingst__T_action_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Profane"; break;
		case 1: std::get<1>(result) = "Disturb"; break;
		case 2: std::get<1>(result) = "PrayedInside"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_site_dispute_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Territory"; break;
		case 1: std::get<1>(result) = "WaterRights"; break;
		case 2: std::get<1>(result) = "GrazingRights"; break;
		case 3: std::get<1>(result) = "FishingRights"; break;
		case 4: std::get<1>(result) = "RightsOfWay"; break;
		case 5: std::get<1>(result) = "LivestockOwnership"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_insurrection_outcome_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "LeadershipOverthrown"; break;
		case 1: std::get<1>(result) = "PopulationGone"; break;
		case 2: std::get<1>(result) = "Crushed"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_history_event_hf_act_on_artifactst__T_action_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "View"; break;
		case 1: std::get<1>(result) = "AskAbout"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tactical_situation_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "attacker_strongly_favored"; break;
		case 1: std::get<1>(result) = "attacker_favored"; break;
		case 2: std::get<1>(result) = "attacker_slightly_favored"; break;
		case 3: std::get<1>(result) = "defender_strongly_favored"; break;
		case 4: std::get<1>(result) = "defender_favored"; break;
		case 5: std::get<1>(result) = "defender_slightly_favored"; break;
		case 6: std::get<1>(result) = "neither_favored"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_history_event_collection_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "WAR"; break;
		case 1: std::get<1>(result) = "BATTLE"; break;
		case 2: std::get<1>(result) = "DUEL"; break;
		case 3: std::get<1>(result) = "SITE_CONQUERED"; break;
		case 4: std::get<1>(result) = "ABDUCTION"; break;
		case 5: std::get<1>(result) = "THEFT"; break;
		case 6: std::get<1>(result) = "BEAST_ATTACK"; break;
		case 7: std::get<1>(result) = "JOURNEY"; break;
		case 8: std::get<1>(result) = "INSURRECTION"; break;
		case 9: std::get<1>(result) = "OCCASION"; break;
		case 10: std::get<1>(result) = "PERFORMANCE"; break;
		case 11: std::get<1>(result) = "COMPETITION"; break;
		case 12: std::get<1>(result) = "PROCESSION"; break;
		case 13: std::get<1>(result) = "CEREMONY"; break;
		case 14: std::get<1>(result) = "PURGE"; break;
		case 15: std::get<1>(result) = "RAID"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_era_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ThreePowers"; break;
		case 1: std::get<1>(result) = "TwoPowers"; break;
		case 2: std::get<1>(result) = "OnePower"; break;
		case 3: std::get<1>(result) = "Myth"; break;
		case 4: std::get<1>(result) = "Legends"; break;
		case 5: std::get<1>(result) = "Twilight"; break;
		case 6: std::get<1>(result) = "FairyTales"; break;
		case 7: std::get<1>(result) = "Race"; break;
		case 8: std::get<1>(result) = "Heroes"; break;
		case 9: std::get<1>(result) = "Golden"; break;
		case 10: std::get<1>(result) = "Death"; break;
		case 11: std::get<1>(result) = "Civilization"; break;
		case 12: std::get<1>(result) = "Emptiness"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_init_display_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "USE_GRAPHICS"; break;
		case 1: std::get<1>(result) = "BLACK_SPACE"; break;
		case 2: std::get<1>(result) = "PARTIAL_PRINT"; break;
		case 3: std::get<1>(result) = "FRAME_BUFFER"; break;
		case 4: std::get<1>(result) = "SINGLE_BUFFER"; break;
		case 5: std::get<1>(result) = "ACCUM_BUFFER"; break;
		case 6: std::get<1>(result) = "VBO"; break;
		case 7: std::get<1>(result) = "RENDER_2D"; break;
		case 8: std::get<1>(result) = "RENDER_2DHW"; break;
		case 9: std::get<1>(result) = "RENDER_2DASYNC"; break;
		case 10: std::get<1>(result) = "UNUSED_01_08"; break;
		case 11: std::get<1>(result) = "TEXT"; break;
		case 12: std::get<1>(result) = "SHADER"; break;
		case 13: std::get<1>(result) = "NOT_RESIZABLE"; break;
		case 14: std::get<1>(result) = "ARB_SYNC"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_init_media_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SOUND_OFF"; break;
		case 1: std::get<1>(result) = "INTRO_OFF"; break;
		case 2: std::get<1>(result) = "COMPRESS_SAVES"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_init_input_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MOUSE_OFF"; break;
		case 1: std::get<1>(result) = "MOUSE_PICTURE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_init_window_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "TOPMOST"; break;
		case 1: std::get<1>(result) = "VSYNC_ON"; break;
		case 2: std::get<1>(result) = "VSYNC_OFF"; break;
		case 3: std::get<1>(result) = "TEXTURE_LINEAR"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_interaction_effect_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ANIMATE"; break;
		case 1: std::get<1>(result) = "ADD_SYNDROME"; break;
		case 2: std::get<1>(result) = "RESURRECT"; break;
		case 3: std::get<1>(result) = "CLEAN"; break;
		case 4: std::get<1>(result) = "CONTACT"; break;
		case 5: std::get<1>(result) = "MATERIAL_EMISSION"; break;
		case 6: std::get<1>(result) = "HIDE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_interaction_effect_location_hint_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "IN_WATER"; break;
		case 1: std::get<1>(result) = "IN_MAGMA"; break;
		case 2: std::get<1>(result) = "NO_WATER"; break;
		case 3: std::get<1>(result) = "NO_MAGMA"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_interaction_source_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "REGION"; break;
		case 1: std::get<1>(result) = "SECRET"; break;
		case 2: std::get<1>(result) = "DISTURBANCE"; break;
		case 3: std::get<1>(result) = "DEITY"; break;
		case 4: std::get<1>(result) = "ATTACK"; break;
		case 5: std::get<1>(result) = "INGESTION"; break;
		case 6: std::get<1>(result) = "CREATURE_ACTION"; break;
		case 7: std::get<1>(result) = "UNDERGROUND_SPECIAL"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_interaction_source_usage_hint_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MAJOR_CURSE"; break;
		case 1: std::get<1>(result) = "GREETING"; break;
		case 2: std::get<1>(result) = "CLEAN_SELF"; break;
		case 3: std::get<1>(result) = "CLEAN_FRIEND"; break;
		case 4: std::get<1>(result) = "ATTACK"; break;
		case 5: std::get<1>(result) = "FLEEING"; break;
		case 6: std::get<1>(result) = "NEGATIVE_SOCIAL_RESPONSE"; break;
		case 7: std::get<1>(result) = "TORMENT"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_interaction_target_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "CORPSE"; break;
		case 1: std::get<1>(result) = "CREATURE"; break;
		case 2: std::get<1>(result) = "MATERIAL"; break;
		case 3: std::get<1>(result) = "LOCATION"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_interaction_target_location_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "CONTEXT_NONE"; break;
		case 0: std::get<1>(result) = "CONTEXT_REGION"; break;
		case 1: std::get<1>(result) = "CONTEXT_CREATURE"; break;
		case 2: std::get<1>(result) = "CONTEXT_ITEM"; break;
		case 3: std::get<1>(result) = "CONTEXT_BP"; break;
		case 4: std::get<1>(result) = "CONTEXT_LOCATION"; break;
		case 5: std::get<1>(result) = "CONTEXT_CREATURE_OR_LOCATION"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_breath_attack_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "TRAILING_DUST_FLOW"; break;
		case 1: std::get<1>(result) = "TRAILING_VAPOR_FLOW"; break;
		case 2: std::get<1>(result) = "TRAILING_GAS_FLOW"; break;
		case 3: std::get<1>(result) = "SOLID_GLOB"; break;
		case 4: std::get<1>(result) = "LIQUID_GLOB"; break;
		case 5: std::get<1>(result) = "UNDIRECTED_GAS"; break;
		case 6: std::get<1>(result) = "UNDIRECTED_VAPOR"; break;
		case 7: std::get<1>(result) = "UNDIRECTED_DUST"; break;
		case 8: std::get<1>(result) = "WEB_SPRAY"; break;
		case 9: std::get<1>(result) = "DRAGONFIRE"; break;
		case 10: std::get<1>(result) = "FIREJET"; break;
		case 11: std::get<1>(result) = "FIREBALL"; break;
		case 12: std::get<1>(result) = "WEATHER_CREEPING_GAS"; break;
		case 13: std::get<1>(result) = "WEATHER_CREEPING_VAPOR"; break;
		case 14: std::get<1>(result) = "WEATHER_CREEPING_DUST"; break;
		case 15: std::get<1>(result) = "WEATHER_FALLING_MATERIAL"; break;
		case 16: std::get<1>(result) = "SPATTER_POWDER"; break;
		case 17: std::get<1>(result) = "SPATTER_LIQUID"; break;
		case 18: std::get<1>(result) = "UNDIRECTED_ITEM_CLOUD"; break;
		case 19: std::get<1>(result) = "TRAILING_ITEM_FLOW"; break;
		case 20: std::get<1>(result) = "OTHER"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_item_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "BAR"; std::get<2>(result) = "Bars, such as metal, fuel, or soap."; break;
		case 1: std::get<1>(result) = "SMALLGEM"; std::get<2>(result) = "Cut gemstones usable in jewelers workshop"; break;
		case 2: std::get<1>(result) = "BLOCKS"; std::get<2>(result) = "Blocks of any kind."; break;
		case 3: std::get<1>(result) = "ROUGH"; std::get<2>(result) = "Rough gemstones."; break;
		case 4: std::get<1>(result) = "BOULDER"; std::get<2>(result) = "Raw mined stone."; break;
		case 5: std::get<1>(result) = "WOOD"; std::get<2>(result) = "Wooden logs."; break;
		case 6: std::get<1>(result) = "DOOR"; std::get<2>(result) = "Doors."; break;
		case 7: std::get<1>(result) = "FLOODGATE"; std::get<2>(result) = "Floodgates."; break;
		case 8: std::get<1>(result) = "BED"; std::get<2>(result) = "Beds."; break;
		case 9: std::get<1>(result) = "CHAIR"; std::get<2>(result) = "Chairs and thrones."; break;
		case 10: std::get<1>(result) = "CHAIN"; std::get<2>(result) = "Restraints."; break;
		case 11: std::get<1>(result) = "FLASK"; std::get<2>(result) = "Flasks."; break;
		case 12: std::get<1>(result) = "GOBLET"; std::get<2>(result) = "Goblets."; break;
		case 13: std::get<1>(result) = "INSTRUMENT"; std::get<2>(result) = "Musical instruments."; break;
		case 14: std::get<1>(result) = "TOY"; std::get<2>(result) = "Toys."; break;
		case 15: std::get<1>(result) = "WINDOW"; std::get<2>(result) = "Glass windows."; break;
		case 16: std::get<1>(result) = "CAGE"; std::get<2>(result) = "Cages."; break;
		case 17: std::get<1>(result) = "BARREL"; std::get<2>(result) = "Barrels."; break;
		case 18: std::get<1>(result) = "BUCKET"; std::get<2>(result) = "Buckets."; break;
		case 19: std::get<1>(result) = "ANIMALTRAP"; std::get<2>(result) = "Animal traps."; break;
		case 20: std::get<1>(result) = "TABLE"; std::get<2>(result) = "Tables."; break;
		case 21: std::get<1>(result) = "COFFIN"; std::get<2>(result) = "Coffins."; break;
		case 22: std::get<1>(result) = "STATUE"; std::get<2>(result) = "Statues."; break;
		case 23: std::get<1>(result) = "CORPSE"; std::get<2>(result) = "Corpses. Does not have a material."; break;
		case 24: std::get<1>(result) = "WEAPON"; std::get<2>(result) = "Weapons."; break;
		case 25: std::get<1>(result) = "ARMOR"; std::get<2>(result) = "Armor and clothing worn on the upper body."; break;
		case 26: std::get<1>(result) = "SHOES"; std::get<2>(result) = "Armor and clothing worn on the feet."; break;
		case 27: std::get<1>(result) = "SHIELD"; std::get<2>(result) = "Shields and bucklers."; break;
		case 28: std::get<1>(result) = "HELM"; std::get<2>(result) = "Armor and clothing worn on the head."; break;
		case 29: std::get<1>(result) = "GLOVES"; std::get<2>(result) = "Armor and clothing worn on the hands."; break;
		case 30: std::get<1>(result) = "BOX"; std::get<2>(result) = "Chests (wood), coffers (stone), boxes (glass), and bags (cloth or leather)."; break;
		case 31: std::get<1>(result) = "BIN"; std::get<2>(result) = "Bins."; break;
		case 32: std::get<1>(result) = "ARMORSTAND"; std::get<2>(result) = "Armor stands."; break;
		case 33: std::get<1>(result) = "WEAPONRACK"; std::get<2>(result) = "Weapon racks."; break;
		case 34: std::get<1>(result) = "CABINET"; std::get<2>(result) = "Cabinets."; break;
		case 35: std::get<1>(result) = "FIGURINE"; std::get<2>(result) = "Figurines."; break;
		case 36: std::get<1>(result) = "AMULET"; std::get<2>(result) = "Amulets."; break;
		case 37: std::get<1>(result) = "SCEPTER"; std::get<2>(result) = "Scepters."; break;
		case 38: std::get<1>(result) = "AMMO"; std::get<2>(result) = "Ammunition for hand-held weapons."; break;
		case 39: std::get<1>(result) = "CROWN"; std::get<2>(result) = "Crowns."; break;
		case 40: std::get<1>(result) = "RING"; std::get<2>(result) = "Rings."; break;
		case 41: std::get<1>(result) = "EARRING"; std::get<2>(result) = "Earrings."; break;
		case 42: std::get<1>(result) = "BRACELET"; std::get<2>(result) = "Bracelets."; break;
		case 43: std::get<1>(result) = "GEM"; std::get<2>(result) = "Large gems."; break;
		case 44: std::get<1>(result) = "ANVIL"; std::get<2>(result) = "Anvils."; break;
		case 45: std::get<1>(result) = "CORPSEPIECE"; std::get<2>(result) = "Body parts. Does not have a material."; break;
		case 46: std::get<1>(result) = "REMAINS"; std::get<2>(result) = "Dead vermin bodies. Material is CREATURE_ID:CASTE."; break;
		case 47: std::get<1>(result) = "MEAT"; std::get<2>(result) = "Butchered meat."; break;
		case 48: std::get<1>(result) = "FISH"; std::get<2>(result) = "Prepared fish. Material is CREATURE_ID:CASTE."; break;
		case 49: std::get<1>(result) = "FISH_RAW"; std::get<2>(result) = "Unprepared fish. Material is CREATURE_ID:CASTE."; break;
		case 50: std::get<1>(result) = "VERMIN"; std::get<2>(result) = "Live vermin. Material is CREATURE_ID:CASTE."; break;
		case 51: std::get<1>(result) = "PET"; std::get<2>(result) = "Tame vermin. Material is CREATURE_ID:CASTE."; break;
		case 52: std::get<1>(result) = "SEEDS"; std::get<2>(result) = "Seeds from plants."; break;
		case 53: std::get<1>(result) = "PLANT"; std::get<2>(result) = "Plants."; break;
		case 54: std::get<1>(result) = "SKIN_TANNED"; std::get<2>(result) = "Tanned skins."; break;
		case 55: std::get<1>(result) = "PLANT_GROWTH"; std::get<2>(result) = "Assorted plant growths, including leaves and berries"; break;
		case 56: std::get<1>(result) = "THREAD"; std::get<2>(result) = "Thread gathered from webs or made at the farmers workshop."; break;
		case 57: std::get<1>(result) = "CLOTH"; std::get<2>(result) = "Cloth made at the loom."; break;
		case 58: std::get<1>(result) = "TOTEM"; std::get<2>(result) = "Skull totems."; break;
		case 59: std::get<1>(result) = "PANTS"; std::get<2>(result) = "Armor and clothing worn on the legs."; break;
		case 60: std::get<1>(result) = "BACKPACK"; std::get<2>(result) = "Backpacks."; break;
		case 61: std::get<1>(result) = "QUIVER"; std::get<2>(result) = "Quivers."; break;
		case 62: std::get<1>(result) = "CATAPULTPARTS"; std::get<2>(result) = "Catapult parts."; break;
		case 63: std::get<1>(result) = "BALLISTAPARTS"; std::get<2>(result) = "Ballista parts."; break;
		case 64: std::get<1>(result) = "SIEGEAMMO"; std::get<2>(result) = "Siege engine ammunition."; break;
		case 65: std::get<1>(result) = "BALLISTAARROWHEAD"; std::get<2>(result) = "Ballista arrow heads."; break;
		case 66: std::get<1>(result) = "TRAPPARTS"; std::get<2>(result) = "Mechanisms."; break;
		case 67: std::get<1>(result) = "TRAPCOMP"; std::get<2>(result) = "Trap components."; break;
		case 68: std::get<1>(result) = "DRINK"; std::get<2>(result) = "Alcoholic drinks."; break;
		case 69: std::get<1>(result) = "POWDER_MISC"; std::get<2>(result) = "Powders such as flour, gypsum plaster, dye, or sand."; break;
		case 70: std::get<1>(result) = "CHEESE"; std::get<2>(result) = "Pieces of cheese."; break;
		case 71: std::get<1>(result) = "FOOD"; std::get<2>(result) = "Prepared meals. Subtypes come from item_food.txt"; break;
		case 72: std::get<1>(result) = "LIQUID_MISC"; std::get<2>(result) = "Liquids such as water, lye, and extracts."; break;
		case 73: std::get<1>(result) = "COIN"; std::get<2>(result) = "Coins."; break;
		case 74: std::get<1>(result) = "GLOB"; std::get<2>(result) = "Fat, tallow, pastes/pressed objects, and small bits of molten rock/metal."; break;
		case 75: std::get<1>(result) = "ROCK"; std::get<2>(result) = "Small rocks (usually sharpened and/or thrown in adventurer mode)"; break;
		case 76: std::get<1>(result) = "PIPE_SECTION"; std::get<2>(result) = "Pipe sections."; break;
		case 77: std::get<1>(result) = "HATCH_COVER"; std::get<2>(result) = "Hatch covers."; break;
		case 78: std::get<1>(result) = "GRATE"; std::get<2>(result) = "Grates."; break;
		case 79: std::get<1>(result) = "QUERN"; std::get<2>(result) = "Querns."; break;
		case 80: std::get<1>(result) = "MILLSTONE"; std::get<2>(result) = "Millstones."; break;
		case 81: std::get<1>(result) = "SPLINT"; std::get<2>(result) = "Splints."; break;
		case 82: std::get<1>(result) = "CRUTCH"; std::get<2>(result) = "Crutches."; break;
		case 83: std::get<1>(result) = "TRACTION_BENCH"; std::get<2>(result) = "Traction benches."; break;
		case 84: std::get<1>(result) = "ORTHOPEDIC_CAST"; std::get<2>(result) = "Casts"; break;
		case 85: std::get<1>(result) = "TOOL"; std::get<2>(result) = "Tools."; break;
		case 86: std::get<1>(result) = "SLAB"; std::get<2>(result) = "Slabs."; break;
		case 87: std::get<1>(result) = "EGG"; std::get<2>(result) = "Eggs. Material is CREATURE_ID:CASTE."; break;
		case 88: std::get<1>(result) = "BOOK"; std::get<2>(result) = "Books."; break;
		case 89: std::get<1>(result) = "SHEET"; std::get<2>(result) = "Sheets of paper"; break;
		case 90: std::get<1>(result) = "BRANCH"; std::get<2>(result) = "Tree branches"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ammo_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "HAS_EDGE_ATTACK"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_armor_general_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SOFT"; break;
		case 1: std::get<1>(result) = "HARD"; break;
		case 2: std::get<1>(result) = "METAL"; break;
		case 3: std::get<1>(result) = "BARRED"; break;
		case 4: std::get<1>(result) = "SCALED"; break;
		case 5: std::get<1>(result) = "LEATHER"; break;
		case 6: std::get<1>(result) = "SHAPED"; break;
		case 7: std::get<1>(result) = "CHAIN_METAL_TEXT"; break;
		case 8: std::get<1>(result) = "STRUCTURAL_ELASTICITY_WOVEN_THREAD"; break;
		case 9: std::get<1>(result) = "STRUCTURAL_ELASTICITY_CHAIN_METAL"; break;
		case 10: std::get<1>(result) = "STRUCTURAL_ELASTICITY_CHAIN_ALL"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_armor_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "METAL_ARMOR_LEVELS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_gloves_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "METAL_ARMOR_LEVELS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_helm_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "METAL_ARMOR_LEVELS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_instrument_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "INDEFINITE_PITCH"; break;
		case 1: std::get<1>(result) = "PLACED_AS_BUILDING"; break;
		case 2: std::get<1>(result) = "METAL_MAT"; break;
		case 3: std::get<1>(result) = "STONE_MAT"; break;
		case 4: std::get<1>(result) = "WOOD_MAT"; break;
		case 5: std::get<1>(result) = "GLASS_MAT"; break;
		case 6: std::get<1>(result) = "CERAMIC_MAT"; break;
		case 7: std::get<1>(result) = "SHELL_MAT"; break;
		case 8: std::get<1>(result) = "BONE_MAT"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_sound_production_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "PLUCKED_BY_BP"; break;
		case 1: std::get<1>(result) = "PLUCKED"; break;
		case 2: std::get<1>(result) = "BOWED"; break;
		case 3: std::get<1>(result) = "STRUCK_BY_BP"; break;
		case 4: std::get<1>(result) = "STRUCK"; break;
		case 5: std::get<1>(result) = "VIBRATE_BP_AGAINST_OPENING"; break;
		case 6: std::get<1>(result) = "BLOW_AGAINST_FIPPLE"; break;
		case 7: std::get<1>(result) = "BLOW_OVER_OPENING_SIDE"; break;
		case 8: std::get<1>(result) = "BLOW_OVER_OPENING_END"; break;
		case 9: std::get<1>(result) = "BLOW_OVER_SINGLE_REED"; break;
		case 10: std::get<1>(result) = "BLOW_OVER_DOUBLE_REED"; break;
		case 11: std::get<1>(result) = "BLOW_OVER_FREE_REED"; break;
		case 12: std::get<1>(result) = "STRUCK_TOGETHER"; break;
		case 13: std::get<1>(result) = "SHAKEN"; break;
		case 14: std::get<1>(result) = "SCRAPED"; break;
		case 15: std::get<1>(result) = "FRICTION"; break;
		case 16: std::get<1>(result) = "RESONATOR"; break;
		case 17: std::get<1>(result) = "BAG_OVER_REED"; break;
		case 18: std::get<1>(result) = "AIR_OVER_REED"; break;
		case 19: std::get<1>(result) = "AIR_OVER_FREE_REED"; break;
		case 20: std::get<1>(result) = "AIR_AGAINST_FIPPLE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_pitch_choice_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MEMBRANE_POSITION"; break;
		case 1: std::get<1>(result) = "SUBPART_CHOICE"; break;
		case 2: std::get<1>(result) = "KEYBOARD"; break;
		case 3: std::get<1>(result) = "STOPPING_FRET"; break;
		case 4: std::get<1>(result) = "STOPPING_AGAINST_BODY"; break;
		case 5: std::get<1>(result) = "STOPPING_HOLE"; break;
		case 6: std::get<1>(result) = "STOPPING_HOLE_KEY"; break;
		case 7: std::get<1>(result) = "SLIDE"; break;
		case 8: std::get<1>(result) = "HARMONIC_SERIES"; break;
		case 9: std::get<1>(result) = "VALVE_ROUTES_AIR"; break;
		case 10: std::get<1>(result) = "BP_IN_BELL"; break;
		case 11: std::get<1>(result) = "FOOT_PEDALS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tuning_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "PEGS"; break;
		case 1: std::get<1>(result) = "ADJUSTABLE_BRIDGES"; break;
		case 2: std::get<1>(result) = "CROOKS"; break;
		case 3: std::get<1>(result) = "TIGHTENING"; break;
		case 4: std::get<1>(result) = "LEVERS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_timbre_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "CLEAR"; break;
		case 1: std::get<1>(result) = "NOISY"; break;
		case 2: std::get<1>(result) = "FULL"; break;
		case 3: std::get<1>(result) = "THIN"; break;
		case 4: std::get<1>(result) = "ROUND"; break;
		case 5: std::get<1>(result) = "SHARP"; break;
		case 6: std::get<1>(result) = "SMOOTH"; break;
		case 7: std::get<1>(result) = "CHOPPY"; break;
		case 8: std::get<1>(result) = "STEADY"; break;
		case 9: std::get<1>(result) = "EVOLVING"; break;
		case 10: std::get<1>(result) = "STRONG"; break;
		case 11: std::get<1>(result) = "DELICATE"; break;
		case 12: std::get<1>(result) = "BRIGHT"; break;
		case 13: std::get<1>(result) = "GRACEFUL"; break;
		case 14: std::get<1>(result) = "SPARSE"; break;
		case 15: std::get<1>(result) = "BREATHY"; break;
		case 16: std::get<1>(result) = "STRAINED"; break;
		case 17: std::get<1>(result) = "BROAD"; break;
		case 18: std::get<1>(result) = "LIGHT"; break;
		case 19: std::get<1>(result) = "MELLOW"; break;
		case 20: std::get<1>(result) = "WOBBLING"; break;
		case 21: std::get<1>(result) = "FOCUSED"; break;
		case 22: std::get<1>(result) = "EVEN"; break;
		case 23: std::get<1>(result) = "FLUID"; break;
		case 24: std::get<1>(result) = "VIBRATING"; break;
		case 25: std::get<1>(result) = "QUAVERING"; break;
		case 26: std::get<1>(result) = "EERIE"; break;
		case 27: std::get<1>(result) = "FRAGILE"; break;
		case 28: std::get<1>(result) = "BRITTLE"; break;
		case 29: std::get<1>(result) = "PURE_"; break;
		case 30: std::get<1>(result) = "PIERCING"; break;
		case 31: std::get<1>(result) = "STRIDENT"; break;
		case 32: std::get<1>(result) = "WAVERING"; break;
		case 33: std::get<1>(result) = "HARSH"; break;
		case 34: std::get<1>(result) = "REEDY"; break;
		case 35: std::get<1>(result) = "NASAL"; break;
		case 36: std::get<1>(result) = "BUZZY"; break;
		case 37: std::get<1>(result) = "ROUGH"; break;
		case 38: std::get<1>(result) = "WARM"; break;
		case 39: std::get<1>(result) = "RUGGED"; break;
		case 40: std::get<1>(result) = "HEAVY"; break;
		case 41: std::get<1>(result) = "FLAT"; break;
		case 42: std::get<1>(result) = "DARK"; break;
		case 43: std::get<1>(result) = "CRISP"; break;
		case 44: std::get<1>(result) = "SONOROUS"; break;
		case 45: std::get<1>(result) = "WATERY"; break;
		case 46: std::get<1>(result) = "GENTLE"; break;
		case 47: std::get<1>(result) = "SLICING"; break;
		case 48: std::get<1>(result) = "LIQUID"; break;
		case 49: std::get<1>(result) = "RAUCOUS"; break;
		case 50: std::get<1>(result) = "BREEZY"; break;
		case 51: std::get<1>(result) = "RASPY"; break;
		case 52: std::get<1>(result) = "WISPY"; break;
		case 53: std::get<1>(result) = "SHRILL"; break;
		case 54: std::get<1>(result) = "MUDDY"; break;
		case 55: std::get<1>(result) = "RICH"; break;
		case 56: std::get<1>(result) = "DULL"; break;
		case 57: std::get<1>(result) = "FLOATING"; break;
		case 58: std::get<1>(result) = "RINGING"; break;
		case 59: std::get<1>(result) = "RESONANT"; break;
		case 60: std::get<1>(result) = "SWEET"; break;
		case 61: std::get<1>(result) = "RIPPLING"; break;
		case 62: std::get<1>(result) = "SPARKLING"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_pants_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "METAL_ARMOR_LEVELS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_shoes_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "METAL_ARMOR_LEVELS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tool_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "HARD_MAT"; break;
		case 1: std::get<1>(result) = "METAL_MAT"; break;
		case 2: std::get<1>(result) = "HAS_EDGE_ATTACK"; break;
		case 3: std::get<1>(result) = "METAL_WEAPON_MAT"; break;
		case 4: std::get<1>(result) = "UNIMPROVABLE"; break;
		case 5: std::get<1>(result) = "SOFT_MAT"; break;
		case 6: std::get<1>(result) = "WOOD_MAT"; break;
		case 7: std::get<1>(result) = "INVERTED_TILE"; break;
		case 8: std::get<1>(result) = "FURNITURE"; break;
		case 9: std::get<1>(result) = "LEATHER_MAT"; break;
		case 10: std::get<1>(result) = "SILK_MAT"; break;
		case 11: std::get<1>(result) = "THREAD_PLANT_MAT"; break;
		case 12: std::get<1>(result) = "GLASS_MAT"; break;
		case 13: std::get<1>(result) = "CERAMIC_MAT"; break;
		case 14: std::get<1>(result) = "STONE_MAT"; break;
		case 15: std::get<1>(result) = "SHELL_MAT"; break;
		case 16: std::get<1>(result) = "BONE_MAT"; break;
		case 17: std::get<1>(result) = "NO_DEFAULT_JOB"; break;
		case 18: std::get<1>(result) = "INCOMPLETE_ITEM"; break;
		case 19: std::get<1>(result) = "SHEET_MAT"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tool_uses_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "LIQUID_COOKING"; break;
		case 1: std::get<1>(result) = "LIQUID_SCOOP"; break;
		case 2: std::get<1>(result) = "GRIND_POWDER_RECEPTACLE"; break;
		case 3: std::get<1>(result) = "GRIND_POWDER_GRINDER"; break;
		case 4: std::get<1>(result) = "MEAT_CARVING"; break;
		case 5: std::get<1>(result) = "MEAT_BONING"; break;
		case 6: std::get<1>(result) = "MEAT_SLICING"; break;
		case 7: std::get<1>(result) = "MEAT_CLEAVING"; break;
		case 8: std::get<1>(result) = "HOLD_MEAT_FOR_CARVING"; break;
		case 9: std::get<1>(result) = "MEAL_CONTAINER"; break;
		case 10: std::get<1>(result) = "LIQUID_CONTAINER"; break;
		case 11: std::get<1>(result) = "FOOD_STORAGE"; break;
		case 12: std::get<1>(result) = "HIVE"; break;
		case 13: std::get<1>(result) = "NEST_BOX"; break;
		case 14: std::get<1>(result) = "SMALL_OBJECT_STORAGE"; break;
		case 15: std::get<1>(result) = "TRACK_CART"; break;
		case 16: std::get<1>(result) = "HEAVY_OBJECT_HAULING"; break;
		case 17: std::get<1>(result) = "STAND_AND_WORK_ABOVE"; break;
		case 18: std::get<1>(result) = "ROLL_UP_SHEET"; break;
		case 19: std::get<1>(result) = "PROTECT_FOLDED_SHEETS"; break;
		case 20: std::get<1>(result) = "CONTAIN_WRITING"; break;
		case 21: std::get<1>(result) = "BOOKCASE"; break;
		case 22: std::get<1>(result) = "DISPLAY_OBJECT"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_toy_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "HARD_MAT"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_trapcomp_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "IS_SCREW"; break;
		case 1: std::get<1>(result) = "IS_SPIKE"; break;
		case 2: std::get<1>(result) = "WOOD"; break;
		case 3: std::get<1>(result) = "METAL"; break;
		case 4: std::get<1>(result) = "HAS_EDGE_ATTACK"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_weapon_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "CAN_STONE"; break;
		case 1: std::get<1>(result) = "HAS_EDGE_ATTACK"; break;
		case 2: std::get<1>(result) = "TRAINING"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_items_other_id_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "ANY"; break;
		case 0: std::get<1>(result) = "IN_PLAY"; std::get<2>(result) = "actually on the map, as opposed to in an offloaded fortress elsewhere"; break;
		case 1: std::get<1>(result) = "ANY_ARTIFACT"; break;
		case 2: std::get<1>(result) = "WEAPON"; break;
		case 3: std::get<1>(result) = "ANY_WEAPON"; break;
		case 4: std::get<1>(result) = "ANY_SPIKE"; break;
		case 5: std::get<1>(result) = "ANY_TRUE_ARMOR"; break;
		case 6: std::get<1>(result) = "ANY_ARMOR_HELM"; break;
		case 7: std::get<1>(result) = "ANY_ARMOR_SHOES"; break;
		case 8: std::get<1>(result) = "SHIELD"; break;
		case 9: std::get<1>(result) = "ANY_ARMOR_GLOVES"; break;
		case 10: std::get<1>(result) = "ANY_ARMOR_PANTS"; break;
		case 11: std::get<1>(result) = "QUIVER"; break;
		case 12: std::get<1>(result) = "SPLINT"; break;
		case 13: std::get<1>(result) = "ORTHOPEDIC_CAST"; break;
		case 14: std::get<1>(result) = "CRUTCH"; break;
		case 15: std::get<1>(result) = "BACKPACK"; break;
		case 16: std::get<1>(result) = "AMMO"; break;
		case 17: std::get<1>(result) = "WOOD"; break;
		case 18: std::get<1>(result) = "BRANCH"; break;
		case 19: std::get<1>(result) = "BOULDER"; break;
		case 20: std::get<1>(result) = "ROCK"; break;
		case 21: std::get<1>(result) = "ANY_REFUSE"; break;
		case 22: std::get<1>(result) = "ANY_GOOD_FOOD"; break;
		case 23: std::get<1>(result) = "ANY_AUTO_CLEAN"; break;
		case 24: std::get<1>(result) = "ANY_GENERIC24"; break;
		case 25: std::get<1>(result) = "ANY_GENERIC25"; break;
		case 26: std::get<1>(result) = "ANY_FURNITURE"; break;
		case 27: std::get<1>(result) = "ANY_CAGE_OR_TRAP"; break;
		case 28: std::get<1>(result) = "ANY_EDIBLE_RAW"; break;
		case 29: std::get<1>(result) = "ANY_EDIBLE_CARNIVORE"; break;
		case 30: std::get<1>(result) = "ANY_EDIBLE_BONECARN"; break;
		case 31: std::get<1>(result) = "ANY_EDIBLE_VERMIN"; break;
		case 32: std::get<1>(result) = "ANY_EDIBLE_VERMIN_BOX"; break;
		case 33: std::get<1>(result) = "ANY_CAN_ROT"; break;
		case 34: std::get<1>(result) = "ANY_MURDERED"; break;
		case 35: std::get<1>(result) = "ANY_DEAD_DWARF"; break;
		case 36: std::get<1>(result) = "ANY_GENERIC36"; break;
		case 37: std::get<1>(result) = "ANY_GENERIC37"; break;
		case 38: std::get<1>(result) = "ANY_GENERIC38"; break;
		case 39: std::get<1>(result) = "ANY_GENERIC39"; break;
		case 40: std::get<1>(result) = "DOOR"; break;
		case 41: std::get<1>(result) = "FLOODGATE"; break;
		case 42: std::get<1>(result) = "HATCH_COVER"; break;
		case 43: std::get<1>(result) = "GRATE"; break;
		case 44: std::get<1>(result) = "CAGE"; break;
		case 45: std::get<1>(result) = "FLASK"; break;
		case 46: std::get<1>(result) = "WINDOW"; break;
		case 47: std::get<1>(result) = "GOBLET"; break;
		case 48: std::get<1>(result) = "INSTRUMENT"; break;
		case 49: std::get<1>(result) = "INSTRUMENT_STATIONARY"; break;
		case 50: std::get<1>(result) = "TOY"; break;
		case 51: std::get<1>(result) = "TOOL"; break;
		case 52: std::get<1>(result) = "BUCKET"; break;
		case 53: std::get<1>(result) = "BARREL"; break;
		case 54: std::get<1>(result) = "CHAIN"; break;
		case 55: std::get<1>(result) = "ANIMALTRAP"; break;
		case 56: std::get<1>(result) = "BED"; break;
		case 57: std::get<1>(result) = "TRACTION_BENCH"; break;
		case 58: std::get<1>(result) = "CHAIR"; break;
		case 59: std::get<1>(result) = "COFFIN"; break;
		case 60: std::get<1>(result) = "TABLE"; break;
		case 61: std::get<1>(result) = "STATUE"; break;
		case 62: std::get<1>(result) = "SLAB"; break;
		case 63: std::get<1>(result) = "QUERN"; break;
		case 64: std::get<1>(result) = "MILLSTONE"; break;
		case 65: std::get<1>(result) = "BOX"; break;
		case 66: std::get<1>(result) = "BIN"; break;
		case 67: std::get<1>(result) = "ARMORSTAND"; break;
		case 68: std::get<1>(result) = "WEAPONRACK"; break;
		case 69: std::get<1>(result) = "CABINET"; break;
		case 70: std::get<1>(result) = "ANVIL"; break;
		case 71: std::get<1>(result) = "CATAPULTPARTS"; break;
		case 72: std::get<1>(result) = "BALLISTAPARTS"; break;
		case 73: std::get<1>(result) = "SIEGEAMMO"; break;
		case 74: std::get<1>(result) = "TRAPPARTS"; break;
		case 75: std::get<1>(result) = "ANY_WEBS"; break;
		case 76: std::get<1>(result) = "PIPE_SECTION"; break;
		case 77: std::get<1>(result) = "ANY_ENCASED"; break;
		case 78: std::get<1>(result) = "ANY_IN_CONSTRUCTION"; break;
		case 79: std::get<1>(result) = "DRINK"; break;
		case 80: std::get<1>(result) = "ANY_DRINK"; break;
		case 81: std::get<1>(result) = "LIQUID_MISC"; break;
		case 82: std::get<1>(result) = "POWDER_MISC"; break;
		case 83: std::get<1>(result) = "ANY_COOKABLE"; break;
		case 84: std::get<1>(result) = "ANY_GENERIC84"; break;
		case 85: std::get<1>(result) = "VERMIN"; break;
		case 86: std::get<1>(result) = "PET"; break;
		case 87: std::get<1>(result) = "ANY_CRITTER"; break;
		case 88: std::get<1>(result) = "COIN"; break;
		case 89: std::get<1>(result) = "GLOB"; break;
		case 90: std::get<1>(result) = "TRAPCOMP"; break;
		case 91: std::get<1>(result) = "BAR"; break;
		case 92: std::get<1>(result) = "SMALLGEM"; break;
		case 93: std::get<1>(result) = "BLOCKS"; break;
		case 94: std::get<1>(result) = "ROUGH"; break;
		case 95: std::get<1>(result) = "ANY_CORPSE"; break;
		case 96: std::get<1>(result) = "CORPSE"; break;
		case 97: std::get<1>(result) = "BOOK"; break;
		case 98: std::get<1>(result) = "FIGURINE"; break;
		case 99: std::get<1>(result) = "AMULET"; break;
		case 100: std::get<1>(result) = "SCEPTER"; break;
		case 101: std::get<1>(result) = "CROWN"; break;
		case 102: std::get<1>(result) = "RING"; break;
		case 103: std::get<1>(result) = "EARRING"; break;
		case 104: std::get<1>(result) = "BRACELET"; break;
		case 105: std::get<1>(result) = "GEM"; break;
		case 106: std::get<1>(result) = "CORPSEPIECE"; break;
		case 107: std::get<1>(result) = "REMAINS"; break;
		case 108: std::get<1>(result) = "MEAT"; break;
		case 109: std::get<1>(result) = "FISH"; break;
		case 110: std::get<1>(result) = "FISH_RAW"; break;
		case 111: std::get<1>(result) = "EGG"; break;
		case 112: std::get<1>(result) = "SEEDS"; break;
		case 113: std::get<1>(result) = "PLANT"; break;
		case 114: std::get<1>(result) = "SKIN_TANNED"; break;
		case 115: std::get<1>(result) = "PLANT_GROWTH"; break;
		case 116: std::get<1>(result) = "THREAD"; break;
		case 117: std::get<1>(result) = "CLOTH"; break;
		case 118: std::get<1>(result) = "SHEET"; break;
		case 119: std::get<1>(result) = "TOTEM"; break;
		case 120: std::get<1>(result) = "PANTS"; break;
		case 121: std::get<1>(result) = "CHEESE"; break;
		case 122: std::get<1>(result) = "FOOD"; break;
		case 123: std::get<1>(result) = "BALLISTAARROWHEAD"; break;
		case 124: std::get<1>(result) = "ARMOR"; break;
		case 125: std::get<1>(result) = "SHOES"; break;
		case 126: std::get<1>(result) = "HELM"; break;
		case 127: std::get<1>(result) = "GLOVES"; break;
		case 128: std::get<1>(result) = "ANY_GENERIC128"; break;
		case 129: std::get<1>(result) = "FOOD_STORAGE"; break;
		case 130: std::get<1>(result) = "ANY_RECENTLY_DROPPED"; break;
		case 131: std::get<1>(result) = "ANY_MELT_DESIGNATED"; break;
		case 132: std::get<1>(result) = "BAD"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_job_item_vector_id_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ANY"; break;
		case 1: std::get<1>(result) = "IN_PLAY"; break;
		case 2: std::get<1>(result) = "ANY_ARTIFACT"; break;
		case 3: std::get<1>(result) = "WEAPON"; break;
		case 4: std::get<1>(result) = "ANY_WEAPON"; break;
		case 5: std::get<1>(result) = "ANY_SPIKE"; break;
		case 6: std::get<1>(result) = "ANY_TRUE_ARMOR"; break;
		case 7: std::get<1>(result) = "ANY_ARMOR_HELM"; break;
		case 8: std::get<1>(result) = "ANY_ARMOR_SHOES"; break;
		case 9: std::get<1>(result) = "SHIELD"; break;
		case 10: std::get<1>(result) = "ANY_ARMOR_GLOVES"; break;
		case 11: std::get<1>(result) = "ANY_ARMOR_PANTS"; break;
		case 12: std::get<1>(result) = "QUIVER"; break;
		case 13: std::get<1>(result) = "SPLINT"; break;
		case 14: std::get<1>(result) = "ANY_14"; std::get<2>(result) = "supposed to be ORTHOPEDIC_CAST"; break;
		case 15: std::get<1>(result) = "CRUTCH"; break;
		case 16: std::get<1>(result) = "BACKPACK"; break;
		case 17: std::get<1>(result) = "AMMO"; break;
		case 18: std::get<1>(result) = "WOOD"; break;
		case 19: std::get<1>(result) = "BOULDER"; break;
		case 20: std::get<1>(result) = "ROCK"; break;
		case 21: std::get<1>(result) = "ANY_REFUSE"; break;
		case 22: std::get<1>(result) = "ANY_GOOD_FOOD"; break;
		case 23: std::get<1>(result) = "ANY_AUTO_CLEAN"; break;
		case 24: std::get<1>(result) = "ANY_GENERIC24"; break;
		case 25: std::get<1>(result) = "ANY_GENERIC25"; break;
		case 26: std::get<1>(result) = "ANY_FURNITURE"; break;
		case 27: std::get<1>(result) = "ANY_CAGE_OR_TRAP"; break;
		case 28: std::get<1>(result) = "ANY_EDIBLE_RAW"; break;
		case 29: std::get<1>(result) = "ANY_EDIBLE_CARNIVORE"; break;
		case 30: std::get<1>(result) = "ANY_EDIBLE_BONECARN"; break;
		case 31: std::get<1>(result) = "ANY_EDIBLE_VERMIN"; break;
		case 32: std::get<1>(result) = "ANY_EDIBLE_VERMIN_BOX"; break;
		case 33: std::get<1>(result) = "ANY_CAN_ROT"; break;
		case 34: std::get<1>(result) = "ANY_MURDERED"; break;
		case 35: std::get<1>(result) = "ANY_DEAD_DWARF"; break;
		case 36: std::get<1>(result) = "ANY_GENERIC36"; break;
		case 37: std::get<1>(result) = "ANY_GENERIC37"; break;
		case 38: std::get<1>(result) = "ANY_GENERIC38"; break;
		case 39: std::get<1>(result) = "ANY_GENERIC39"; break;
		case 40: std::get<1>(result) = "DOOR"; break;
		case 41: std::get<1>(result) = "FLOODGATE"; break;
		case 42: std::get<1>(result) = "HATCH_COVER"; break;
		case 43: std::get<1>(result) = "GRATE"; break;
		case 44: std::get<1>(result) = "CAGE"; break;
		case 45: std::get<1>(result) = "FLASK"; break;
		case 46: std::get<1>(result) = "WINDOW"; break;
		case 47: std::get<1>(result) = "GOBLET"; break;
		case 48: std::get<1>(result) = "INSTRUMENT"; break;
		case 49: std::get<1>(result) = "TOY"; break;
		case 50: std::get<1>(result) = "BUCKET"; break;
		case 51: std::get<1>(result) = "BARREL"; break;
		case 52: std::get<1>(result) = "CHAIN"; break;
		case 53: std::get<1>(result) = "ANIMALTRAP"; break;
		case 54: std::get<1>(result) = "BED"; break;
		case 55: std::get<1>(result) = "TRACTION_BENCH"; break;
		case 56: std::get<1>(result) = "CHAIR"; break;
		case 57: std::get<1>(result) = "COFFIN"; break;
		case 58: std::get<1>(result) = "TABLE"; break;
		case 59: std::get<1>(result) = "STATUE"; break;
		case 60: std::get<1>(result) = "QUERN"; break;
		case 61: std::get<1>(result) = "MILLSTONE"; break;
		case 62: std::get<1>(result) = "BOX"; break;
		case 63: std::get<1>(result) = "BIN"; break;
		case 64: std::get<1>(result) = "ARMORSTAND"; break;
		case 65: std::get<1>(result) = "WEAPONRACK"; break;
		case 66: std::get<1>(result) = "CABINET"; break;
		case 67: std::get<1>(result) = "ANVIL"; break;
		case 68: std::get<1>(result) = "CATAPULTPARTS"; break;
		case 69: std::get<1>(result) = "BALLISTAPARTS"; break;
		case 70: std::get<1>(result) = "SIEGEAMMO"; break;
		case 71: std::get<1>(result) = "TRAPPARTS"; break;
		case 72: std::get<1>(result) = "ANY_WEBS"; break;
		case 73: std::get<1>(result) = "PIPE_SECTION"; break;
		case 74: std::get<1>(result) = "ANY_ENCASED"; break;
		case 75: std::get<1>(result) = "ANY_IN_CONSTRUCTION"; break;
		case 76: std::get<1>(result) = "DRINK"; break;
		case 77: std::get<1>(result) = "ANY_DRINK"; break;
		case 78: std::get<1>(result) = "LIQUID_MISC"; break;
		case 79: std::get<1>(result) = "POWDER_MISC"; break;
		case 80: std::get<1>(result) = "ANY_COOKABLE"; break;
		case 81: std::get<1>(result) = "ANY_GENERIC84"; break;
		case 82: std::get<1>(result) = "VERMIN"; break;
		case 83: std::get<1>(result) = "PET"; break;
		case 84: std::get<1>(result) = "ANY_CRITTER"; break;
		case 85: std::get<1>(result) = "COIN"; break;
		case 86: std::get<1>(result) = "GLOB"; break;
		case 87: std::get<1>(result) = "ANY_RECENTLY_DROPPED"; break;
		case 88: std::get<1>(result) = "ANY_MELT_DESIGNATED"; break;
		case 89: std::get<1>(result) = "BAD"; break;
		case 90: std::get<1>(result) = "TRAPCOMP"; break;
		case 91: std::get<1>(result) = "BAR"; break;
		case 92: std::get<1>(result) = "SMALLGEM"; break;
		case 93: std::get<1>(result) = "BLOCKS"; break;
		case 94: std::get<1>(result) = "ROUGH"; break;
		case 95: std::get<1>(result) = "CORPSE"; break;
		case 96: std::get<1>(result) = "FIGURINE"; break;
		case 97: std::get<1>(result) = "AMULET"; break;
		case 98: std::get<1>(result) = "SCEPTER"; break;
		case 99: std::get<1>(result) = "CROWN"; break;
		case 100: std::get<1>(result) = "RING"; break;
		case 101: std::get<1>(result) = "EARRING"; break;
		case 102: std::get<1>(result) = "BRACELET"; break;
		case 103: std::get<1>(result) = "GEM"; break;
		case 104: std::get<1>(result) = "CORPSEPIECE"; break;
		case 105: std::get<1>(result) = "REMAINS"; break;
		case 106: std::get<1>(result) = "MEAT"; break;
		case 107: std::get<1>(result) = "FISH"; break;
		case 108: std::get<1>(result) = "FISH_RAW"; break;
		case 109: std::get<1>(result) = "SEEDS"; break;
		case 110: std::get<1>(result) = "PLANT"; break;
		case 111: std::get<1>(result) = "SKIN_TANNED"; break;
		case 112: std::get<1>(result) = "PLANT_GROWTH"; break;
		case 113: std::get<1>(result) = "THREAD"; break;
		case 114: std::get<1>(result) = "CLOTH"; break;
		case 115: std::get<1>(result) = "TOTEM"; break;
		case 116: std::get<1>(result) = "PANTS"; break;
		case 117: std::get<1>(result) = "CHEESE"; break;
		case 118: std::get<1>(result) = "FOOD"; break;
		case 119: std::get<1>(result) = "BALLISTAARROWHEAD"; break;
		case 120: std::get<1>(result) = "ARMOR"; break;
		case 121: std::get<1>(result) = "SHOES"; break;
		case 122: std::get<1>(result) = "HELM"; break;
		case 123: std::get<1>(result) = "GLOVES"; break;
		case 124: std::get<1>(result) = "ANY_124"; std::get<2>(result) = "supposed to be TOOL"; break;
		case 125: std::get<1>(result) = "ANY_125"; std::get<2>(result) = "supposed to be SLAB"; break;
		case 126: std::get<1>(result) = "EGG"; break;
		case 127: std::get<1>(result) = "ANY_127"; std::get<2>(result) = "supposed to be FOOD_STORAGE"; break;
		case 128: std::get<1>(result) = "ANY_CORPSE"; break;
		case 129: std::get<1>(result) = "BOOK"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_improvement_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ART_IMAGE"; break;
		case 1: std::get<1>(result) = "COVERED"; break;
		case 2: std::get<1>(result) = "RINGS_HANGING"; break;
		case 3: std::get<1>(result) = "BANDS"; break;
		case 4: std::get<1>(result) = "SPIKES"; break;
		case 5: std::get<1>(result) = "ITEMSPECIFIC"; break;
		case 6: std::get<1>(result) = "THREAD"; break;
		case 7: std::get<1>(result) = "CLOTH"; break;
		case 8: std::get<1>(result) = "SEWN_IMAGE"; break;
		case 9: std::get<1>(result) = "PAGES"; break;
		case 10: std::get<1>(result) = "ILLUSTRATION"; break;
		case 11: std::get<1>(result) = "INSTRUMENT_PIECE"; break;
		case 12: std::get<1>(result) = "WRITING"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_itemimprovement_specific_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "HANDLE"; break;
		case 1: std::get<1>(result) = "ROLLERS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_written_content_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Manual"; break;
		case 1: std::get<1>(result) = "Guide"; break;
		case 2: std::get<1>(result) = "Chronicle"; break;
		case 3: std::get<1>(result) = "ShortStory"; break;
		case 4: std::get<1>(result) = "Novel"; break;
		case 5: std::get<1>(result) = "Biography"; break;
		case 6: std::get<1>(result) = "Autobiography"; break;
		case 7: std::get<1>(result) = "Poem"; break;
		case 8: std::get<1>(result) = "Play"; break;
		case 9: std::get<1>(result) = "Letter"; break;
		case 10: std::get<1>(result) = "Essay"; break;
		case 11: std::get<1>(result) = "Dialog"; break;
		case 12: std::get<1>(result) = "MusicalComposition"; break;
		case 13: std::get<1>(result) = "Choreography"; break;
		case 14: std::get<1>(result) = "ComparativeBiography"; break;
		case 15: std::get<1>(result) = "BiographicalDictionary"; break;
		case 16: std::get<1>(result) = "Genealogy"; break;
		case 17: std::get<1>(result) = "Encyclopedia"; break;
		case 18: std::get<1>(result) = "CulturalHistory"; break;
		case 19: std::get<1>(result) = "CulturalComparison"; break;
		case 20: std::get<1>(result) = "AlternateHistory"; break;
		case 21: std::get<1>(result) = "TreatiseOnTechnologicalEvolution"; break;
		case 22: std::get<1>(result) = "Dictionary"; break;
		case 23: std::get<1>(result) = "StarChart"; break;
		case 24: std::get<1>(result) = "StarCatalogue"; break;
		case 25: std::get<1>(result) = "Atlas"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_written_content_style_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Meandering"; break;
		case 1: std::get<1>(result) = "Cheerful"; break;
		case 2: std::get<1>(result) = "Depressing"; break;
		case 3: std::get<1>(result) = "Rigid"; break;
		case 4: std::get<1>(result) = "Serious"; break;
		case 5: std::get<1>(result) = "Disjointed"; break;
		case 6: std::get<1>(result) = "Ornate"; break;
		case 7: std::get<1>(result) = "Forceful"; break;
		case 8: std::get<1>(result) = "Humorous"; break;
		case 9: std::get<1>(result) = "Immature"; break;
		case 10: std::get<1>(result) = "SelfIndulgent"; break;
		case 11: std::get<1>(result) = "Touching"; break;
		case 12: std::get<1>(result) = "Compassionate"; break;
		case 13: std::get<1>(result) = "Vicious"; break;
		case 14: std::get<1>(result) = "Concise"; break;
		case 15: std::get<1>(result) = "Scornful"; break;
		case 16: std::get<1>(result) = "Witty"; break;
		case 17: std::get<1>(result) = "Ranting"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_item_magicness_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Sparkle"; break;
		case 1: std::get<1>(result) = "AirWarped"; break;
		case 2: std::get<1>(result) = "Whistle"; break;
		case 3: std::get<1>(result) = "OddlySquare"; break;
		case 4: std::get<1>(result) = "SmallBumps"; break;
		case 5: std::get<1>(result) = "EarthSmell"; break;
		case 6: std::get<1>(result) = "Lightning"; break;
		case 7: std::get<1>(result) = "GrayHairs"; std::get<2>(result) = "with value of 10 or higher, creatures that look at the item cannot think negative thoughts"; break;
		case 8: std::get<1>(result) = "RustlingLeaves"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_item_quality_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Ordinary"; break;
		case 1: std::get<1>(result) = "WellCrafted"; break;
		case 2: std::get<1>(result) = "FinelyCrafted"; break;
		case 3: std::get<1>(result) = "Superior"; break;
		case 4: std::get<1>(result) = "Exceptional"; break;
		case 5: std::get<1>(result) = "Masterful"; break;
		case 6: std::get<1>(result) = "Artifact"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_slab_engraving_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "Slab"; break;
		case 0: std::get<1>(result) = "Memorial"; break;
		case 1: std::get<1>(result) = "CraftShopSign"; break;
		case 2: std::get<1>(result) = "WeaponsmithShopSign"; break;
		case 3: std::get<1>(result) = "ArmorsmithShopSign"; break;
		case 4: std::get<1>(result) = "GeneralStoreSign"; break;
		case 5: std::get<1>(result) = "FoodShopSign"; break;
		case 6: std::get<1>(result) = "Secrets"; std::get<2>(result) = "from the gods?"; break;
		case 7: std::get<1>(result) = "FoodImportsSign"; break;
		case 8: std::get<1>(result) = "ClothingImportsSign"; break;
		case 9: std::get<1>(result) = "GeneralImportsSign"; break;
		case 10: std::get<1>(result) = "ClothShopSign"; break;
		case 11: std::get<1>(result) = "LeatherShopSign"; break;
		case 12: std::get<1>(result) = "WovenClothingShopSign"; break;
		case 13: std::get<1>(result) = "LeatherClothingShopSign"; break;
		case 14: std::get<1>(result) = "BoneCarverShopSign"; break;
		case 15: std::get<1>(result) = "GemCutterShopSign"; break;
		case 16: std::get<1>(result) = "WeaponsmithShopSign2"; break;
		case 17: std::get<1>(result) = "BowyerShopSign"; break;
		case 18: std::get<1>(result) = "BlacksmithShopSign"; break;
		case 19: std::get<1>(result) = "ArmorsmithShopSign2"; break;
		case 20: std::get<1>(result) = "MetalCraftShopSign"; break;
		case 21: std::get<1>(result) = "LeatherGoodsShopSign"; break;
		case 22: std::get<1>(result) = "CarpenterShopSign"; break;
		case 23: std::get<1>(result) = "StoneFurnitureShopSign"; break;
		case 24: std::get<1>(result) = "MetalFurnitureShopSign"; break;
		case 25: std::get<1>(result) = "DemonIdentity"; std::get<2>(result) = "when a demon assumes identity?"; break;
		case 26: std::get<1>(result) = "TavernSign"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_corpse_material_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Plant"; break;
		case 1: std::get<1>(result) = "Silk"; break;
		case 2: std::get<1>(result) = "Leather"; break;
		case 3: std::get<1>(result) = "Bone"; break;
		case 4: std::get<1>(result) = "Shell"; break;
		case 5: std::get<1>(result) = "anon_1"; break;
		case 6: std::get<1>(result) = "Soap"; break;
		case 7: std::get<1>(result) = "Tooth"; break;
		case 8: std::get<1>(result) = "Horn"; break;
		case 9: std::get<1>(result) = "Pearl"; break;
		case 10: std::get<1>(result) = "HairWool"; break;
		case 11: std::get<1>(result) = "Yarn"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_job_type_class_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Misc"; break;
		case 1: std::get<1>(result) = "Digging"; break;
		case 2: std::get<1>(result) = "Building"; break;
		case 3: std::get<1>(result) = "Hauling"; break;
		case 4: std::get<1>(result) = "LifeSupport"; break;
		case 5: std::get<1>(result) = "TidyUp"; break;
		case 6: std::get<1>(result) = "Leisure"; break;
		case 7: std::get<1>(result) = "Gathering"; break;
		case 8: std::get<1>(result) = "Manufacture"; break;
		case 9: std::get<1>(result) = "Improvement"; break;
		case 10: std::get<1>(result) = "Crime"; break;
		case 11: std::get<1>(result) = "LawEnforcement"; break;
		case 12: std::get<1>(result) = "StrangeMood"; break;
		case 13: std::get<1>(result) = "UnitHandling"; break;
		case 14: std::get<1>(result) = "SiegeWeapon"; break;
		case 15: std::get<1>(result) = "Medicine"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_job_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; std::get<2>(result) = "unused"; break;
		case 0: std::get<1>(result) = "CarveFortification"; break;
		case 1: std::get<1>(result) = "DetailWall"; break;
		case 2: std::get<1>(result) = "DetailFloor"; break;
		case 3: std::get<1>(result) = "Dig"; break;
		case 4: std::get<1>(result) = "CarveUpwardStaircase"; break;
		case 5: std::get<1>(result) = "CarveDownwardStaircase"; break;
		case 6: std::get<1>(result) = "CarveUpDownStaircase"; break;
		case 7: std::get<1>(result) = "CarveRamp"; break;
		case 8: std::get<1>(result) = "DigChannel"; break;
		case 9: std::get<1>(result) = "FellTree"; break;
		case 10: std::get<1>(result) = "GatherPlants"; break;
		case 11: std::get<1>(result) = "RemoveConstruction"; break;
		case 12: std::get<1>(result) = "CollectWebs"; break;
		case 13: std::get<1>(result) = "BringItemToDepot"; break;
		case 14: std::get<1>(result) = "BringItemToShop"; break;
		case 15: std::get<1>(result) = "Eat"; break;
		case 16: std::get<1>(result) = "GetProvisions"; break;
		case 17: std::get<1>(result) = "Drink"; break;
		case 18: std::get<1>(result) = "Drink2"; break;
		case 19: std::get<1>(result) = "FillWaterskin"; break;
		case 20: std::get<1>(result) = "FillWaterskin2"; break;
		case 21: std::get<1>(result) = "Sleep"; break;
		case 22: std::get<1>(result) = "CollectSand"; break;
		case 23: std::get<1>(result) = "Fish"; break;
		case 24: std::get<1>(result) = "Hunt"; break;
		case 25: std::get<1>(result) = "HuntVermin"; break;
		case 26: std::get<1>(result) = "Kidnap"; break;
		case 27: std::get<1>(result) = "BeatCriminal"; break;
		case 28: std::get<1>(result) = "StartingFistFight"; break;
		case 29: std::get<1>(result) = "CollectTaxes"; break;
		case 30: std::get<1>(result) = "GuardTaxCollector"; break;
		case 31: std::get<1>(result) = "CatchLiveLandAnimal"; break;
		case 32: std::get<1>(result) = "CatchLiveFish"; break;
		case 33: std::get<1>(result) = "ReturnKill"; break;
		case 34: std::get<1>(result) = "CheckChest"; break;
		case 35: std::get<1>(result) = "StoreOwnedItem"; break;
		case 36: std::get<1>(result) = "PlaceItemInTomb"; break;
		case 37: std::get<1>(result) = "StoreItemInStockpile"; break;
		case 38: std::get<1>(result) = "StoreItemInBag"; break;
		case 39: std::get<1>(result) = "StoreItemInHospital"; break;
		case 40: std::get<1>(result) = "StoreItemInLocation"; break;
		case 41: std::get<1>(result) = "anon_1"; break;
		case 42: std::get<1>(result) = "StoreWeapon"; break;
		case 43: std::get<1>(result) = "StoreArmor"; break;
		case 44: std::get<1>(result) = "StoreItemInBarrel"; break;
		case 45: std::get<1>(result) = "StoreItemInBin"; break;
		case 46: std::get<1>(result) = "SeekArtifact"; break;
		case 47: std::get<1>(result) = "SeekInfant"; break;
		case 48: std::get<1>(result) = "AttendParty"; break;
		case 49: std::get<1>(result) = "GoShopping"; break;
		case 50: std::get<1>(result) = "GoShopping2"; break;
		case 51: std::get<1>(result) = "Clean"; break;
		case 52: std::get<1>(result) = "Rest"; break;
		case 53: std::get<1>(result) = "PickupEquipment"; break;
		case 54: std::get<1>(result) = "DumpItem"; break;
		case 55: std::get<1>(result) = "StrangeMoodCrafter"; break;
		case 56: std::get<1>(result) = "StrangeMoodJeweller"; break;
		case 57: std::get<1>(result) = "StrangeMoodForge"; break;
		case 58: std::get<1>(result) = "StrangeMoodMagmaForge"; break;
		case 59: std::get<1>(result) = "StrangeMoodBrooding"; break;
		case 60: std::get<1>(result) = "StrangeMoodFell"; break;
		case 61: std::get<1>(result) = "StrangeMoodCarpenter"; break;
		case 62: std::get<1>(result) = "StrangeMoodMason"; break;
		case 63: std::get<1>(result) = "StrangeMoodBowyer"; break;
		case 64: std::get<1>(result) = "StrangeMoodTanner"; break;
		case 65: std::get<1>(result) = "StrangeMoodWeaver"; break;
		case 66: std::get<1>(result) = "StrangeMoodGlassmaker"; break;
		case 67: std::get<1>(result) = "StrangeMoodMechanics"; break;
		case 68: std::get<1>(result) = "ConstructBuilding"; break;
		case 69: std::get<1>(result) = "ConstructDoor"; break;
		case 70: std::get<1>(result) = "ConstructFloodgate"; break;
		case 71: std::get<1>(result) = "ConstructBed"; break;
		case 72: std::get<1>(result) = "ConstructThrone"; break;
		case 73: std::get<1>(result) = "ConstructCoffin"; break;
		case 74: std::get<1>(result) = "ConstructTable"; break;
		case 75: std::get<1>(result) = "ConstructChest"; break;
		case 76: std::get<1>(result) = "ConstructBin"; break;
		case 77: std::get<1>(result) = "ConstructArmorStand"; break;
		case 78: std::get<1>(result) = "ConstructWeaponRack"; break;
		case 79: std::get<1>(result) = "ConstructCabinet"; break;
		case 80: std::get<1>(result) = "ConstructStatue"; break;
		case 81: std::get<1>(result) = "ConstructBlocks"; break;
		case 82: std::get<1>(result) = "MakeRawGlass"; break;
		case 83: std::get<1>(result) = "MakeCrafts"; break;
		case 84: std::get<1>(result) = "MintCoins"; break;
		case 85: std::get<1>(result) = "CutGems"; break;
		case 86: std::get<1>(result) = "CutGlass"; break;
		case 87: std::get<1>(result) = "EncrustWithGems"; break;
		case 88: std::get<1>(result) = "EncrustWithGlass"; break;
		case 89: std::get<1>(result) = "DestroyBuilding"; break;
		case 90: std::get<1>(result) = "SmeltOre"; break;
		case 91: std::get<1>(result) = "MeltMetalObject"; break;
		case 92: std::get<1>(result) = "ExtractMetalStrands"; break;
		case 93: std::get<1>(result) = "PlantSeeds"; break;
		case 94: std::get<1>(result) = "HarvestPlants"; break;
		case 95: std::get<1>(result) = "TrainHuntingAnimal"; break;
		case 96: std::get<1>(result) = "TrainWarAnimal"; break;
		case 97: std::get<1>(result) = "MakeWeapon"; break;
		case 98: std::get<1>(result) = "ForgeAnvil"; break;
		case 99: std::get<1>(result) = "ConstructCatapultParts"; break;
		case 100: std::get<1>(result) = "ConstructBallistaParts"; break;
		case 101: std::get<1>(result) = "MakeArmor"; break;
		case 102: std::get<1>(result) = "MakeHelm"; break;
		case 103: std::get<1>(result) = "MakePants"; break;
		case 104: std::get<1>(result) = "StudWith"; break;
		case 105: std::get<1>(result) = "ButcherAnimal"; break;
		case 106: std::get<1>(result) = "PrepareRawFish"; break;
		case 107: std::get<1>(result) = "MillPlants"; break;
		case 108: std::get<1>(result) = "BaitTrap"; break;
		case 109: std::get<1>(result) = "MilkCreature"; break;
		case 110: std::get<1>(result) = "MakeCheese"; break;
		case 111: std::get<1>(result) = "ProcessPlants"; break;
		case 112: std::get<1>(result) = "anon_2"; break;
		case 113: std::get<1>(result) = "ProcessPlantsVial"; break;
		case 114: std::get<1>(result) = "ProcessPlantsBarrel"; break;
		case 115: std::get<1>(result) = "PrepareMeal"; break;
		case 116: std::get<1>(result) = "WeaveCloth"; break;
		case 117: std::get<1>(result) = "MakeGloves"; break;
		case 118: std::get<1>(result) = "MakeShoes"; break;
		case 119: std::get<1>(result) = "MakeShield"; break;
		case 120: std::get<1>(result) = "MakeCage"; break;
		case 121: std::get<1>(result) = "MakeChain"; break;
		case 122: std::get<1>(result) = "MakeFlask"; break;
		case 123: std::get<1>(result) = "MakeGoblet"; break;
		case 124: std::get<1>(result) = "anon_3"; break;
		case 125: std::get<1>(result) = "MakeToy"; break;
		case 126: std::get<1>(result) = "MakeAnimalTrap"; break;
		case 127: std::get<1>(result) = "MakeBarrel"; break;
		case 128: std::get<1>(result) = "MakeBucket"; break;
		case 129: std::get<1>(result) = "MakeWindow"; break;
		case 130: std::get<1>(result) = "MakeTotem"; break;
		case 131: std::get<1>(result) = "MakeAmmo"; break;
		case 132: std::get<1>(result) = "DecorateWith"; break;
		case 133: std::get<1>(result) = "MakeBackpack"; break;
		case 134: std::get<1>(result) = "MakeQuiver"; break;
		case 135: std::get<1>(result) = "MakeBallistaArrowHead"; break;
		case 136: std::get<1>(result) = "AssembleSiegeAmmo"; break;
		case 137: std::get<1>(result) = "LoadCatapult"; break;
		case 138: std::get<1>(result) = "LoadBallista"; break;
		case 139: std::get<1>(result) = "FireCatapult"; break;
		case 140: std::get<1>(result) = "FireBallista"; break;
		case 141: std::get<1>(result) = "ConstructMechanisms"; break;
		case 142: std::get<1>(result) = "MakeTrapComponent"; break;
		case 143: std::get<1>(result) = "LoadCageTrap"; break;
		case 144: std::get<1>(result) = "LoadStoneTrap"; break;
		case 145: std::get<1>(result) = "LoadWeaponTrap"; break;
		case 146: std::get<1>(result) = "CleanTrap"; break;
		case 147: std::get<1>(result) = "CastSpell"; break;
		case 148: std::get<1>(result) = "LinkBuildingToTrigger"; break;
		case 149: std::get<1>(result) = "PullLever"; break;
		case 150: std::get<1>(result) = "anon_4"; break;
		case 151: std::get<1>(result) = "ExtractFromPlants"; break;
		case 152: std::get<1>(result) = "ExtractFromRawFish"; break;
		case 153: std::get<1>(result) = "ExtractFromLandAnimal"; break;
		case 154: std::get<1>(result) = "TameVermin"; break;
		case 155: std::get<1>(result) = "TameAnimal"; break;
		case 156: std::get<1>(result) = "ChainAnimal"; break;
		case 157: std::get<1>(result) = "UnchainAnimal"; break;
		case 158: std::get<1>(result) = "UnchainPet"; break;
		case 159: std::get<1>(result) = "ReleaseLargeCreature"; break;
		case 160: std::get<1>(result) = "ReleasePet"; break;
		case 161: std::get<1>(result) = "ReleaseSmallCreature"; break;
		case 162: std::get<1>(result) = "HandleSmallCreature"; break;
		case 163: std::get<1>(result) = "HandleLargeCreature"; break;
		case 164: std::get<1>(result) = "CageLargeCreature"; break;
		case 165: std::get<1>(result) = "CageSmallCreature"; break;
		case 166: std::get<1>(result) = "RecoverWounded"; break;
		case 167: std::get<1>(result) = "DiagnosePatient"; break;
		case 168: std::get<1>(result) = "ImmobilizeBreak"; break;
		case 169: std::get<1>(result) = "DressWound"; break;
		case 170: std::get<1>(result) = "CleanPatient"; break;
		case 171: std::get<1>(result) = "Surgery"; break;
		case 172: std::get<1>(result) = "Suture"; break;
		case 173: std::get<1>(result) = "SetBone"; break;
		case 174: std::get<1>(result) = "PlaceInTraction"; break;
		case 175: std::get<1>(result) = "DrainAquarium"; break;
		case 176: std::get<1>(result) = "FillAquarium"; break;
		case 177: std::get<1>(result) = "FillPond"; break;
		case 178: std::get<1>(result) = "GiveWater"; break;
		case 179: std::get<1>(result) = "GiveFood"; break;
		case 180: std::get<1>(result) = "GiveWater2"; std::get<2>(result) = "for pets"; break;
		case 181: std::get<1>(result) = "GiveFood2"; std::get<2>(result) = "for pets"; break;
		case 182: std::get<1>(result) = "RecoverPet"; break;
		case 183: std::get<1>(result) = "PitLargeAnimal"; break;
		case 184: std::get<1>(result) = "PitSmallAnimal"; break;
		case 185: std::get<1>(result) = "SlaughterAnimal"; break;
		case 186: std::get<1>(result) = "MakeCharcoal"; break;
		case 187: std::get<1>(result) = "MakeAsh"; break;
		case 188: std::get<1>(result) = "MakeLye"; break;
		case 189: std::get<1>(result) = "MakePotashFromLye"; break;
		case 190: std::get<1>(result) = "FertilizeField"; break;
		case 191: std::get<1>(result) = "MakePotashFromAsh"; break;
		case 192: std::get<1>(result) = "DyeThread"; break;
		case 193: std::get<1>(result) = "DyeCloth"; break;
		case 194: std::get<1>(result) = "SewImage"; break;
		case 195: std::get<1>(result) = "MakePipeSection"; break;
		case 196: std::get<1>(result) = "OperatePump"; break;
		case 197: std::get<1>(result) = "ManageWorkOrders"; break;
		case 198: std::get<1>(result) = "UpdateStockpileRecords"; break;
		case 199: std::get<1>(result) = "TradeAtDepot"; break;
		case 200: std::get<1>(result) = "ConstructHatchCover"; break;
		case 201: std::get<1>(result) = "ConstructGrate"; break;
		case 202: std::get<1>(result) = "RemoveStairs"; break;
		case 203: std::get<1>(result) = "ConstructQuern"; break;
		case 204: std::get<1>(result) = "ConstructMillstone"; break;
		case 205: std::get<1>(result) = "ConstructSplint"; break;
		case 206: std::get<1>(result) = "ConstructCrutch"; break;
		case 207: std::get<1>(result) = "ConstructTractionBench"; break;
		case 208: std::get<1>(result) = "CleanSelf"; break;
		case 209: std::get<1>(result) = "BringCrutch"; break;
		case 210: std::get<1>(result) = "ApplyCast"; break;
		case 211: std::get<1>(result) = "CustomReaction"; break;
		case 212: std::get<1>(result) = "ConstructSlab"; break;
		case 213: std::get<1>(result) = "EngraveSlab"; break;
		case 214: std::get<1>(result) = "ShearCreature"; break;
		case 215: std::get<1>(result) = "SpinThread"; break;
		case 216: std::get<1>(result) = "PenLargeAnimal"; break;
		case 217: std::get<1>(result) = "PenSmallAnimal"; break;
		case 218: std::get<1>(result) = "MakeTool"; break;
		case 219: std::get<1>(result) = "CollectClay"; break;
		case 220: std::get<1>(result) = "InstallColonyInHive"; break;
		case 221: std::get<1>(result) = "CollectHiveProducts"; break;
		case 222: std::get<1>(result) = "CauseTrouble"; break;
		case 223: std::get<1>(result) = "DrinkBlood"; std::get<2>(result) = "??"; break;
		case 224: std::get<1>(result) = "ReportCrime"; break;
		case 225: std::get<1>(result) = "ExecuteCriminal"; break;
		case 226: std::get<1>(result) = "TrainAnimal"; break;
		case 227: std::get<1>(result) = "CarveTrack"; break;
		case 228: std::get<1>(result) = "PushTrackVehicle"; break;
		case 229: std::get<1>(result) = "PlaceTrackVehicle"; break;
		case 230: std::get<1>(result) = "StoreItemInVehicle"; break;
		case 231: std::get<1>(result) = "GeldAnimal"; break;
		case 232: std::get<1>(result) = "MakeFigurine"; break;
		case 233: std::get<1>(result) = "MakeAmulet"; break;
		case 234: std::get<1>(result) = "MakeScepter"; break;
		case 235: std::get<1>(result) = "MakeCrown"; break;
		case 236: std::get<1>(result) = "MakeRing"; break;
		case 237: std::get<1>(result) = "MakeEarring"; break;
		case 238: std::get<1>(result) = "MakeBracelet"; break;
		case 239: std::get<1>(result) = "MakeGem"; break;
		case 240: std::get<1>(result) = "PutItemOnDisplay"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_job_subtype_surgery_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Surgery"; break;
		case 1: std::get<1>(result) = "StopBleeding"; break;
		case 2: std::get<1>(result) = "RepairCompoundFracture"; break;
		case 3: std::get<1>(result) = "RemoveRottenTissue"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_job_art_specification__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "HistoricalFigure"; break;
		case 1: std::get<1>(result) = "Site"; break;
		case 2: std::get<1>(result) = "Entity"; break;
		case 3: std::get<1>(result) = "ArtImage"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_manager_order_condition_order__T_condition_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Activated"; break;
		case 1: std::get<1>(result) = "Completed"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_guild_id_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Miners"; break;
		case 1: std::get<1>(result) = "Carpenters"; break;
		case 2: std::get<1>(result) = "Masons"; break;
		case 3: std::get<1>(result) = "Metalsmiths"; break;
		case 4: std::get<1>(result) = "Jewelers"; break;
		case 5: std::get<1>(result) = "Craftsmen"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_interface_key_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "NONE"; break;
		case 1: std::get<1>(result) = "SELECT"; break;
		case 2: std::get<1>(result) = "SEC_SELECT"; break;
		case 3: std::get<1>(result) = "DESELECT"; break;
		case 4: std::get<1>(result) = "SELECT_ALL"; break;
		case 5: std::get<1>(result) = "DESELECT_ALL"; break;
		case 6: std::get<1>(result) = "LEAVESCREEN"; break;
		case 7: std::get<1>(result) = "LEAVESCREEN_ALL"; break;
		case 8: std::get<1>(result) = "CLOSE_MEGA_ANNOUNCEMENT"; break;
		case 9: std::get<1>(result) = "OPTIONS"; break;
		case 10: std::get<1>(result) = "OPTION_EXPORT"; break;
		case 11: std::get<1>(result) = "HELP"; break;
		case 12: std::get<1>(result) = "TOGGLE_FULLSCREEN"; break;
		case 13: std::get<1>(result) = "MOVIES"; break;
		case 14: std::get<1>(result) = "ZOOM_IN"; break;
		case 15: std::get<1>(result) = "ZOOM_OUT"; break;
		case 16: std::get<1>(result) = "ZOOM_TOGGLE"; break;
		case 17: std::get<1>(result) = "ZOOM_RESET"; break;
		case 18: std::get<1>(result) = "MOVIE_RECORD"; break;
		case 19: std::get<1>(result) = "MOVIE_PLAY"; break;
		case 20: std::get<1>(result) = "MOVIE_SAVE"; break;
		case 21: std::get<1>(result) = "MOVIE_LOAD"; break;
		case 22: std::get<1>(result) = "TOGGLE_TTF"; break;
		case 23: std::get<1>(result) = "FPS_UP"; break;
		case 24: std::get<1>(result) = "FPS_DOWN"; break;
		case 25: std::get<1>(result) = "CHANGETAB"; break;
		case 26: std::get<1>(result) = "SEC_CHANGETAB"; break;
		case 27: std::get<1>(result) = "STANDARDSCROLL_UP"; break;
		case 28: std::get<1>(result) = "STANDARDSCROLL_DOWN"; break;
		case 29: std::get<1>(result) = "STANDARDSCROLL_LEFT"; break;
		case 30: std::get<1>(result) = "STANDARDSCROLL_RIGHT"; break;
		case 31: std::get<1>(result) = "STANDARDSCROLL_PAGEUP"; break;
		case 32: std::get<1>(result) = "STANDARDSCROLL_PAGEDOWN"; break;
		case 33: std::get<1>(result) = "SECONDSCROLL_UP"; break;
		case 34: std::get<1>(result) = "SECONDSCROLL_DOWN"; break;
		case 35: std::get<1>(result) = "SECONDSCROLL_PAGEUP"; break;
		case 36: std::get<1>(result) = "SECONDSCROLL_PAGEDOWN"; break;
		case 37: std::get<1>(result) = "CURSOR_UP"; break;
		case 38: std::get<1>(result) = "CURSOR_DOWN"; break;
		case 39: std::get<1>(result) = "CURSOR_LEFT"; break;
		case 40: std::get<1>(result) = "CURSOR_RIGHT"; break;
		case 41: std::get<1>(result) = "CURSOR_UPLEFT"; break;
		case 42: std::get<1>(result) = "CURSOR_UPRIGHT"; break;
		case 43: std::get<1>(result) = "CURSOR_DOWNLEFT"; break;
		case 44: std::get<1>(result) = "CURSOR_DOWNRIGHT"; break;
		case 45: std::get<1>(result) = "CURSOR_UP_FAST"; break;
		case 46: std::get<1>(result) = "CURSOR_DOWN_FAST"; break;
		case 47: std::get<1>(result) = "CURSOR_LEFT_FAST"; break;
		case 48: std::get<1>(result) = "CURSOR_RIGHT_FAST"; break;
		case 49: std::get<1>(result) = "CURSOR_UPLEFT_FAST"; break;
		case 50: std::get<1>(result) = "CURSOR_UPRIGHT_FAST"; break;
		case 51: std::get<1>(result) = "CURSOR_DOWNLEFT_FAST"; break;
		case 52: std::get<1>(result) = "CURSOR_DOWNRIGHT_FAST"; break;
		case 53: std::get<1>(result) = "CURSOR_UP_Z"; break;
		case 54: std::get<1>(result) = "CURSOR_DOWN_Z"; break;
		case 55: std::get<1>(result) = "CURSOR_UP_Z_AUX"; break;
		case 56: std::get<1>(result) = "CURSOR_DOWN_Z_AUX"; break;
		case 57: std::get<1>(result) = "MENU_CONFIRM"; break;
		case 58: std::get<1>(result) = "SAVE_BINDINGS"; break;
		case 59: std::get<1>(result) = "LOAD_BINDINGS"; break;
		case 60: std::get<1>(result) = "MACRO_BREAK"; break;
		case 61: std::get<1>(result) = "RECORD_MACRO"; break;
		case 62: std::get<1>(result) = "PLAY_MACRO"; break;
		case 63: std::get<1>(result) = "SAVE_MACRO"; break;
		case 64: std::get<1>(result) = "LOAD_MACRO"; break;
		case 65: std::get<1>(result) = "PREFIX"; break;
		case 66: std::get<1>(result) = "OPTION1"; break;
		case 67: std::get<1>(result) = "OPTION2"; break;
		case 68: std::get<1>(result) = "OPTION3"; break;
		case 69: std::get<1>(result) = "OPTION4"; break;
		case 70: std::get<1>(result) = "OPTION5"; break;
		case 71: std::get<1>(result) = "OPTION6"; break;
		case 72: std::get<1>(result) = "OPTION7"; break;
		case 73: std::get<1>(result) = "OPTION8"; break;
		case 74: std::get<1>(result) = "OPTION9"; break;
		case 75: std::get<1>(result) = "OPTION10"; break;
		case 76: std::get<1>(result) = "OPTION11"; break;
		case 77: std::get<1>(result) = "OPTION12"; break;
		case 78: std::get<1>(result) = "OPTION13"; break;
		case 79: std::get<1>(result) = "OPTION14"; break;
		case 80: std::get<1>(result) = "OPTION15"; break;
		case 81: std::get<1>(result) = "OPTION16"; break;
		case 82: std::get<1>(result) = "OPTION17"; break;
		case 83: std::get<1>(result) = "OPTION18"; break;
		case 84: std::get<1>(result) = "OPTION19"; break;
		case 85: std::get<1>(result) = "OPTION20"; break;
		case 86: std::get<1>(result) = "SEC_OPTION1"; break;
		case 87: std::get<1>(result) = "SEC_OPTION2"; break;
		case 88: std::get<1>(result) = "SEC_OPTION3"; break;
		case 89: std::get<1>(result) = "SEC_OPTION4"; break;
		case 90: std::get<1>(result) = "SEC_OPTION5"; break;
		case 91: std::get<1>(result) = "SEC_OPTION6"; break;
		case 92: std::get<1>(result) = "SEC_OPTION7"; break;
		case 93: std::get<1>(result) = "SEC_OPTION8"; break;
		case 94: std::get<1>(result) = "SEC_OPTION9"; break;
		case 95: std::get<1>(result) = "SEC_OPTION10"; break;
		case 96: std::get<1>(result) = "SEC_OPTION11"; break;
		case 97: std::get<1>(result) = "SEC_OPTION12"; break;
		case 98: std::get<1>(result) = "SEC_OPTION13"; break;
		case 99: std::get<1>(result) = "SEC_OPTION14"; break;
		case 100: std::get<1>(result) = "SEC_OPTION15"; break;
		case 101: std::get<1>(result) = "SEC_OPTION16"; break;
		case 102: std::get<1>(result) = "SEC_OPTION17"; break;
		case 103: std::get<1>(result) = "SEC_OPTION18"; break;
		case 104: std::get<1>(result) = "SEC_OPTION19"; break;
		case 105: std::get<1>(result) = "SEC_OPTION20"; break;
		case 106: std::get<1>(result) = "CUSTOM_A"; break;
		case 107: std::get<1>(result) = "CUSTOM_B"; break;
		case 108: std::get<1>(result) = "CUSTOM_C"; break;
		case 109: std::get<1>(result) = "CUSTOM_D"; break;
		case 110: std::get<1>(result) = "CUSTOM_E"; break;
		case 111: std::get<1>(result) = "CUSTOM_F"; break;
		case 112: std::get<1>(result) = "CUSTOM_G"; break;
		case 113: std::get<1>(result) = "CUSTOM_H"; break;
		case 114: std::get<1>(result) = "CUSTOM_I"; break;
		case 115: std::get<1>(result) = "CUSTOM_J"; break;
		case 116: std::get<1>(result) = "CUSTOM_K"; break;
		case 117: std::get<1>(result) = "CUSTOM_L"; break;
		case 118: std::get<1>(result) = "CUSTOM_M"; break;
		case 119: std::get<1>(result) = "CUSTOM_N"; break;
		case 120: std::get<1>(result) = "CUSTOM_O"; break;
		case 121: std::get<1>(result) = "CUSTOM_P"; break;
		case 122: std::get<1>(result) = "CUSTOM_Q"; break;
		case 123: std::get<1>(result) = "CUSTOM_R"; break;
		case 124: std::get<1>(result) = "CUSTOM_S"; break;
		case 125: std::get<1>(result) = "CUSTOM_T"; break;
		case 126: std::get<1>(result) = "CUSTOM_U"; break;
		case 127: std::get<1>(result) = "CUSTOM_V"; break;
		case 128: std::get<1>(result) = "CUSTOM_W"; break;
		case 129: std::get<1>(result) = "CUSTOM_X"; break;
		case 130: std::get<1>(result) = "CUSTOM_Y"; break;
		case 131: std::get<1>(result) = "CUSTOM_Z"; break;
		case 132: std::get<1>(result) = "CUSTOM_SHIFT_A"; break;
		case 133: std::get<1>(result) = "CUSTOM_SHIFT_B"; break;
		case 134: std::get<1>(result) = "CUSTOM_SHIFT_C"; break;
		case 135: std::get<1>(result) = "CUSTOM_SHIFT_D"; break;
		case 136: std::get<1>(result) = "CUSTOM_SHIFT_E"; break;
		case 137: std::get<1>(result) = "CUSTOM_SHIFT_F"; break;
		case 138: std::get<1>(result) = "CUSTOM_SHIFT_G"; break;
		case 139: std::get<1>(result) = "CUSTOM_SHIFT_H"; break;
		case 140: std::get<1>(result) = "CUSTOM_SHIFT_I"; break;
		case 141: std::get<1>(result) = "CUSTOM_SHIFT_J"; break;
		case 142: std::get<1>(result) = "CUSTOM_SHIFT_K"; break;
		case 143: std::get<1>(result) = "CUSTOM_SHIFT_L"; break;
		case 144: std::get<1>(result) = "CUSTOM_SHIFT_M"; break;
		case 145: std::get<1>(result) = "CUSTOM_SHIFT_N"; break;
		case 146: std::get<1>(result) = "CUSTOM_SHIFT_O"; break;
		case 147: std::get<1>(result) = "CUSTOM_SHIFT_P"; break;
		case 148: std::get<1>(result) = "CUSTOM_SHIFT_Q"; break;
		case 149: std::get<1>(result) = "CUSTOM_SHIFT_R"; break;
		case 150: std::get<1>(result) = "CUSTOM_SHIFT_S"; break;
		case 151: std::get<1>(result) = "CUSTOM_SHIFT_T"; break;
		case 152: std::get<1>(result) = "CUSTOM_SHIFT_U"; break;
		case 153: std::get<1>(result) = "CUSTOM_SHIFT_V"; break;
		case 154: std::get<1>(result) = "CUSTOM_SHIFT_W"; break;
		case 155: std::get<1>(result) = "CUSTOM_SHIFT_X"; break;
		case 156: std::get<1>(result) = "CUSTOM_SHIFT_Y"; break;
		case 157: std::get<1>(result) = "CUSTOM_SHIFT_Z"; break;
		case 158: std::get<1>(result) = "CUSTOM_CTRL_A"; break;
		case 159: std::get<1>(result) = "CUSTOM_CTRL_B"; break;
		case 160: std::get<1>(result) = "CUSTOM_CTRL_C"; break;
		case 161: std::get<1>(result) = "CUSTOM_CTRL_D"; break;
		case 162: std::get<1>(result) = "CUSTOM_CTRL_E"; break;
		case 163: std::get<1>(result) = "CUSTOM_CTRL_F"; break;
		case 164: std::get<1>(result) = "CUSTOM_CTRL_G"; break;
		case 165: std::get<1>(result) = "CUSTOM_CTRL_H"; break;
		case 166: std::get<1>(result) = "CUSTOM_CTRL_I"; break;
		case 167: std::get<1>(result) = "CUSTOM_CTRL_J"; break;
		case 168: std::get<1>(result) = "CUSTOM_CTRL_K"; break;
		case 169: std::get<1>(result) = "CUSTOM_CTRL_L"; break;
		case 170: std::get<1>(result) = "CUSTOM_CTRL_M"; break;
		case 171: std::get<1>(result) = "CUSTOM_CTRL_N"; break;
		case 172: std::get<1>(result) = "CUSTOM_CTRL_O"; break;
		case 173: std::get<1>(result) = "CUSTOM_CTRL_P"; break;
		case 174: std::get<1>(result) = "CUSTOM_CTRL_Q"; break;
		case 175: std::get<1>(result) = "CUSTOM_CTRL_R"; break;
		case 176: std::get<1>(result) = "CUSTOM_CTRL_S"; break;
		case 177: std::get<1>(result) = "CUSTOM_CTRL_T"; break;
		case 178: std::get<1>(result) = "CUSTOM_CTRL_U"; break;
		case 179: std::get<1>(result) = "CUSTOM_CTRL_V"; break;
		case 180: std::get<1>(result) = "CUSTOM_CTRL_W"; break;
		case 181: std::get<1>(result) = "CUSTOM_CTRL_X"; break;
		case 182: std::get<1>(result) = "CUSTOM_CTRL_Y"; break;
		case 183: std::get<1>(result) = "CUSTOM_CTRL_Z"; break;
		case 184: std::get<1>(result) = "CUSTOM_ALT_A"; break;
		case 185: std::get<1>(result) = "CUSTOM_ALT_B"; break;
		case 186: std::get<1>(result) = "CUSTOM_ALT_C"; break;
		case 187: std::get<1>(result) = "CUSTOM_ALT_D"; break;
		case 188: std::get<1>(result) = "CUSTOM_ALT_E"; break;
		case 189: std::get<1>(result) = "CUSTOM_ALT_F"; break;
		case 190: std::get<1>(result) = "CUSTOM_ALT_G"; break;
		case 191: std::get<1>(result) = "CUSTOM_ALT_H"; break;
		case 192: std::get<1>(result) = "CUSTOM_ALT_I"; break;
		case 193: std::get<1>(result) = "CUSTOM_ALT_J"; break;
		case 194: std::get<1>(result) = "CUSTOM_ALT_K"; break;
		case 195: std::get<1>(result) = "CUSTOM_ALT_L"; break;
		case 196: std::get<1>(result) = "CUSTOM_ALT_M"; break;
		case 197: std::get<1>(result) = "CUSTOM_ALT_N"; break;
		case 198: std::get<1>(result) = "CUSTOM_ALT_O"; break;
		case 199: std::get<1>(result) = "CUSTOM_ALT_P"; break;
		case 200: std::get<1>(result) = "CUSTOM_ALT_Q"; break;
		case 201: std::get<1>(result) = "CUSTOM_ALT_R"; break;
		case 202: std::get<1>(result) = "CUSTOM_ALT_S"; break;
		case 203: std::get<1>(result) = "CUSTOM_ALT_T"; break;
		case 204: std::get<1>(result) = "CUSTOM_ALT_U"; break;
		case 205: std::get<1>(result) = "CUSTOM_ALT_V"; break;
		case 206: std::get<1>(result) = "CUSTOM_ALT_W"; break;
		case 207: std::get<1>(result) = "CUSTOM_ALT_X"; break;
		case 208: std::get<1>(result) = "CUSTOM_ALT_Y"; break;
		case 209: std::get<1>(result) = "CUSTOM_ALT_Z"; break;
		case 210: std::get<1>(result) = "WORLD_PARAM_TITLE"; break;
		case 211: std::get<1>(result) = "WORLD_PARAM_ADD"; break;
		case 212: std::get<1>(result) = "WORLD_PARAM_COPY"; break;
		case 213: std::get<1>(result) = "WORLD_PARAM_DELETE"; break;
		case 214: std::get<1>(result) = "WORLD_PARAM_NAME_RANDOM"; break;
		case 215: std::get<1>(result) = "WORLD_PARAM_NAME_ENTER"; break;
		case 216: std::get<1>(result) = "WORLD_PARAM_SEED_RANDOM"; break;
		case 217: std::get<1>(result) = "WORLD_PARAM_SEED_ENTER"; break;
		case 218: std::get<1>(result) = "WORLD_PARAM_LOAD"; break;
		case 219: std::get<1>(result) = "WORLD_PARAM_SAVE"; break;
		case 220: std::get<1>(result) = "WORLD_PARAM_DIM_X_UP"; break;
		case 221: std::get<1>(result) = "WORLD_PARAM_DIM_X_DOWN"; break;
		case 222: std::get<1>(result) = "WORLD_PARAM_DIM_Y_UP"; break;
		case 223: std::get<1>(result) = "WORLD_PARAM_DIM_Y_DOWN"; break;
		case 224: std::get<1>(result) = "WORLD_PARAM_SET"; break;
		case 225: std::get<1>(result) = "WORLD_PARAM_INCREASE"; break;
		case 226: std::get<1>(result) = "WORLD_PARAM_DECREASE"; break;
		case 227: std::get<1>(result) = "WORLD_PARAM_ENTER_VALUE"; break;
		case 228: std::get<1>(result) = "WORLD_PARAM_NULLIFY"; break;
		case 229: std::get<1>(result) = "WORLD_PARAM_PRESET"; break;
		case 230: std::get<1>(result) = "WORLD_PARAM_REJECT_CONTINUE"; break;
		case 231: std::get<1>(result) = "WORLD_PARAM_REJECT_ABORT"; break;
		case 232: std::get<1>(result) = "WORLD_PARAM_REJECT_ALLOW_THIS"; break;
		case 233: std::get<1>(result) = "WORLD_PARAM_REJECT_ALLOW_ALL"; break;
		case 234: std::get<1>(result) = "WORLD_GEN_CONTINUE"; break;
		case 235: std::get<1>(result) = "WORLD_GEN_USE"; break;
		case 236: std::get<1>(result) = "WORLD_GEN_ABORT"; break;
		case 237: std::get<1>(result) = "WORLDGEN_EXPORT_MAP"; break;
		case 238: std::get<1>(result) = "LEGENDS_EXPORT_MAP"; break;
		case 239: std::get<1>(result) = "LEGENDS_EXPORT_XML"; break;
		case 240: std::get<1>(result) = "LEGENDS_EXPORT_DETAILED_MAP"; break;
		case 241: std::get<1>(result) = "LEGENDS_TOGGLE_CIVSITE"; break;
		case 242: std::get<1>(result) = "LEGENDS_STRING_FILTER"; break;
		case 243: std::get<1>(result) = "A_RETURN_TO_ARENA"; break;
		case 244: std::get<1>(result) = "A_MOVE_N"; break;
		case 245: std::get<1>(result) = "A_MOVE_S"; break;
		case 246: std::get<1>(result) = "A_MOVE_E"; break;
		case 247: std::get<1>(result) = "A_MOVE_W"; break;
		case 248: std::get<1>(result) = "A_MOVE_NW"; break;
		case 249: std::get<1>(result) = "A_MOVE_NE"; break;
		case 250: std::get<1>(result) = "A_MOVE_SW"; break;
		case 251: std::get<1>(result) = "A_MOVE_SE"; break;
		case 252: std::get<1>(result) = "A_MOVE_SAME_SQUARE"; break;
		case 253: std::get<1>(result) = "A_CARE_MOVE_N"; break;
		case 254: std::get<1>(result) = "A_CARE_MOVE_S"; break;
		case 255: std::get<1>(result) = "A_CARE_MOVE_E"; break;
		case 256: std::get<1>(result) = "A_CARE_MOVE_W"; break;
		case 257: std::get<1>(result) = "A_CARE_MOVE_NW"; break;
		case 258: std::get<1>(result) = "A_CARE_MOVE_NE"; break;
		case 259: std::get<1>(result) = "A_CARE_MOVE_SW"; break;
		case 260: std::get<1>(result) = "A_CARE_MOVE_SE"; break;
		case 261: std::get<1>(result) = "A_CARE_MOVE_UPDOWN"; break;
		case 262: std::get<1>(result) = "A_MOVE_N_UP"; break;
		case 263: std::get<1>(result) = "A_MOVE_S_UP"; break;
		case 264: std::get<1>(result) = "A_MOVE_E_UP"; break;
		case 265: std::get<1>(result) = "A_MOVE_W_UP"; break;
		case 266: std::get<1>(result) = "A_MOVE_NW_UP"; break;
		case 267: std::get<1>(result) = "A_MOVE_NE_UP"; break;
		case 268: std::get<1>(result) = "A_MOVE_SW_UP"; break;
		case 269: std::get<1>(result) = "A_MOVE_SE_UP"; break;
		case 270: std::get<1>(result) = "A_MOVE_UP"; break;
		case 271: std::get<1>(result) = "A_MOVE_N_DOWN"; break;
		case 272: std::get<1>(result) = "A_MOVE_S_DOWN"; break;
		case 273: std::get<1>(result) = "A_MOVE_E_DOWN"; break;
		case 274: std::get<1>(result) = "A_MOVE_W_DOWN"; break;
		case 275: std::get<1>(result) = "A_MOVE_NW_DOWN"; break;
		case 276: std::get<1>(result) = "A_MOVE_NE_DOWN"; break;
		case 277: std::get<1>(result) = "A_MOVE_SW_DOWN"; break;
		case 278: std::get<1>(result) = "A_MOVE_SE_DOWN"; break;
		case 279: std::get<1>(result) = "A_MOVE_DOWN"; break;
		case 280: std::get<1>(result) = "A_MOVE_UP_AUX"; break;
		case 281: std::get<1>(result) = "A_MOVE_DOWN_AUX"; break;
		case 282: std::get<1>(result) = "A_COMBAT_ATTACK"; break;
		case 283: std::get<1>(result) = "A_COMBAT_DODGE"; break;
		case 284: std::get<1>(result) = "A_COMBAT_CHARGEDEF"; break;
		case 285: std::get<1>(result) = "A_STATUS"; break;
		case 286: std::get<1>(result) = "A_STATUS_WRESTLE"; break;
		case 287: std::get<1>(result) = "A_STATUS_CUSTOMIZE"; break;
		case 288: std::get<1>(result) = "A_STATUS_KILLS"; break;
		case 289: std::get<1>(result) = "A_STATUS_HEALTH"; break;
		case 290: std::get<1>(result) = "A_STATUS_ATT_SKILL"; break;
		case 291: std::get<1>(result) = "A_STATUS_DESC"; break;
		case 292: std::get<1>(result) = "A_CLEAR_ANNOUNCEMENTS"; break;
		case 293: std::get<1>(result) = "A_SLEEP"; break;
		case 294: std::get<1>(result) = "A_SLEEP_SLEEP"; break;
		case 295: std::get<1>(result) = "A_SLEEP_WAIT"; break;
		case 296: std::get<1>(result) = "A_SLEEP_DAWN"; break;
		case 297: std::get<1>(result) = "A_WAIT"; break;
		case 298: std::get<1>(result) = "A_SHORT_WAIT"; break;
		case 299: std::get<1>(result) = "A_ATTACK"; break;
		case 300: std::get<1>(result) = "A_ATTACK_CONFIRM"; break;
		case 301: std::get<1>(result) = "QUICK_ATTACK"; break;
		case 302: std::get<1>(result) = "HEAVY_ATTACK"; break;
		case 303: std::get<1>(result) = "WILD_ATTACK"; break;
		case 304: std::get<1>(result) = "PRECISE_ATTACK"; break;
		case 305: std::get<1>(result) = "CHARGE_ATTACK"; break;
		case 306: std::get<1>(result) = "MULTI_ATTACK"; break;
		case 307: std::get<1>(result) = "A_LOOK"; break;
		case 308: std::get<1>(result) = "A_SEARCH"; break;
		case 309: std::get<1>(result) = "A_ODOR"; break;
		case 310: std::get<1>(result) = "A_DISPLAY_ODOR"; break;
		case 311: std::get<1>(result) = "A_YIELD"; break;
		case 312: std::get<1>(result) = "A_DISPLAY_TRACKS"; break;
		case 313: std::get<1>(result) = "A_FRESHEST_TRACK"; break;
		case 314: std::get<1>(result) = "A_INV_DRAW_WEAPON"; break;
		case 315: std::get<1>(result) = "A_JUMP"; break;
		case 316: std::get<1>(result) = "A_HOLD"; break;
		case 317: std::get<1>(result) = "A_TALK"; break;
		case 318: std::get<1>(result) = "A_ASSUME_IDENTITY_NEW"; break;
		case 319: std::get<1>(result) = "A_ASSUME_IDENTITY_NONE"; break;
		case 320: std::get<1>(result) = "A_ASSUME_IDENTITY_NAME"; break;
		case 321: std::get<1>(result) = "A_ASSUME_IDENTITY_ORIGIN"; break;
		case 322: std::get<1>(result) = "A_ASSUME_IDENTITY_PROFESSION"; break;
		case 323: std::get<1>(result) = "A_ASSUME_IDENTITY_WORSHIP"; break;
		case 324: std::get<1>(result) = "A_INTERACT"; break;
		case 325: std::get<1>(result) = "A_ACTION"; break;
		case 326: std::get<1>(result) = "A_ACTION_CREATE"; break;
		case 327: std::get<1>(result) = "A_ACTION_BUTCHER"; break;
		case 328: std::get<1>(result) = "A_ACTION_ABILITY"; break;
		case 329: std::get<1>(result) = "A_ACTION_POWER"; break;
		case 330: std::get<1>(result) = "A_ACTION_COMPOSE"; break;
		case 331: std::get<1>(result) = "A_ACTION_WRITE"; break;
		case 332: std::get<1>(result) = "A_CONSTRUCTION"; break;
		case 333: std::get<1>(result) = "ADV_CONSTRUCTION_ZONE_NEW"; break;
		case 334: std::get<1>(result) = "ADV_CONSTRUCTION_ZONE_EDIT"; break;
		case 335: std::get<1>(result) = "ADV_CONSTRUCTION_ZONE_ASSIGN"; break;
		case 336: std::get<1>(result) = "ADV_CONSTRUCTION_ZONE_DELETE"; break;
		case 337: std::get<1>(result) = "ADV_CONSTRUCTION_ZONE_RECT"; break;
		case 338: std::get<1>(result) = "ADV_CONSTRUCTION_ZONE_FLOW"; break;
		case 339: std::get<1>(result) = "ADV_CONSTRUCTION_ZONE_REMOVE_RECT"; break;
		case 340: std::get<1>(result) = "ADV_CONSTRUCTION_STAIR_UPDOWN"; break;
		case 341: std::get<1>(result) = "ADV_CONSTRUCTION_REMOVE_PLANS"; break;
		case 342: std::get<1>(result) = "ADV_CONSTRUCTION_REMOVE_EXISTING"; break;
		case 343: std::get<1>(result) = "ADV_CONSTRUCTION_MATERIAL"; break;
		case 344: std::get<1>(result) = "ADV_CONSTRUCTION_CONSTRUCTION"; break;
		case 345: std::get<1>(result) = "ADV_CONSTRUCTION_BUILDING"; break;
		case 346: std::get<1>(result) = "ADV_CONSTRUCTION_ZONE"; break;
		case 347: std::get<1>(result) = "ADV_CONSTRUCTION_WORK_MENU"; break;
		case 348: std::get<1>(result) = "ADV_CONSTRUCTION_NAME_SITE"; break;
		case 349: std::get<1>(result) = "ADV_CONSTRUCTION_YOU_WORK"; break;
		case 350: std::get<1>(result) = "ADV_CONSTRUCTION_START"; break;
		case 351: std::get<1>(result) = "A_COMPOSE_FILTER"; break;
		case 352: std::get<1>(result) = "A_INV_LOOK"; break;
		case 353: std::get<1>(result) = "A_INV_REMOVE"; break;
		case 354: std::get<1>(result) = "A_INV_WEAR"; break;
		case 355: std::get<1>(result) = "A_INV_EATDRINK"; break;
		case 356: std::get<1>(result) = "A_INV_PUTIN"; break;
		case 357: std::get<1>(result) = "A_INV_DROP"; break;
		case 358: std::get<1>(result) = "A_GROUND"; break;
		case 359: std::get<1>(result) = "A_THROW"; break;
		case 360: std::get<1>(result) = "A_SHOOT"; break;
		case 361: std::get<1>(result) = "A_ANNOUNCEMENTS"; break;
		case 362: std::get<1>(result) = "A_COMBAT"; break;
		case 363: std::get<1>(result) = "A_MOVEMENT"; break;
		case 364: std::get<1>(result) = "A_MOVEMENT_SWIM"; break;
		case 365: std::get<1>(result) = "A_SNEAK"; break;
		case 366: std::get<1>(result) = "A_SPEED_SNEAK"; break;
		case 367: std::get<1>(result) = "A_CENTER"; break;
		case 368: std::get<1>(result) = "A_COMPANIONS"; break;
		case 369: std::get<1>(result) = "A_BUILDING"; break;
		case 370: std::get<1>(result) = "A_TRAVEL"; break;
		case 371: std::get<1>(result) = "A_TRAVEL_SLEEP"; break;
		case 372: std::get<1>(result) = "A_TRAVEL_MAP"; break;
		case 373: std::get<1>(result) = "A_TRAVEL_HIDE_INSTRUCTIONS"; break;
		case 374: std::get<1>(result) = "A_DATE"; break;
		case 375: std::get<1>(result) = "A_WEATHER"; break;
		case 376: std::get<1>(result) = "A_TEMPERATURE"; break;
		case 377: std::get<1>(result) = "A_STANCE"; break;
		case 378: std::get<1>(result) = "A_ENTER_NAME"; break;
		case 379: std::get<1>(result) = "A_CUST_NAME"; break;
		case 380: std::get<1>(result) = "A_RANDOM_NAME"; break;
		case 381: std::get<1>(result) = "A_RANDOM_APPEARANCE"; break;
		case 382: std::get<1>(result) = "A_RANDOM_APPEARANCE_FULL"; break;
		case 383: std::get<1>(result) = "A_RANDOM_PERSONALITY"; break;
		case 384: std::get<1>(result) = "A_CUSTOM_PERSONALITY"; break;
		case 385: std::get<1>(result) = "A_CHANGE_DREAM"; break;
		case 386: std::get<1>(result) = "A_CHANGE_GENDER"; break;
		case 387: std::get<1>(result) = "A_END_TRAVEL"; break;
		case 388: std::get<1>(result) = "A_TRAVEL_CLOUDS"; break;
		case 389: std::get<1>(result) = "A_LOG"; break;
		case 390: std::get<1>(result) = "A_TRAVEL_LOG"; break;
		case 391: std::get<1>(result) = "A_LOG_SORT"; break;
		case 392: std::get<1>(result) = "A_LOG_PIN"; break;
		case 393: std::get<1>(result) = "A_LOG_ENTITIES"; break;
		case 394: std::get<1>(result) = "A_LOG_SITES"; break;
		case 395: std::get<1>(result) = "A_LOG_SUBREGIONS"; break;
		case 396: std::get<1>(result) = "A_LOG_FEATURE_LAYERS"; break;
		case 397: std::get<1>(result) = "A_LOG_PEOPLE"; break;
		case 398: std::get<1>(result) = "A_LOG_AGREEMENTS"; break;
		case 399: std::get<1>(result) = "A_LOG_EVENTS"; break;
		case 400: std::get<1>(result) = "A_LOG_BESTIARY"; break;
		case 401: std::get<1>(result) = "A_LOG_ARTIFACTS"; break;
		case 402: std::get<1>(result) = "A_LOG_FILTER"; break;
		case 403: std::get<1>(result) = "A_LOG_ZOOM_CURRENT_LOCATION"; break;
		case 404: std::get<1>(result) = "A_LOG_ZOOM_SELECTED"; break;
		case 405: std::get<1>(result) = "A_LOG_LINE"; break;
		case 406: std::get<1>(result) = "A_LOG_MAP"; break;
		case 407: std::get<1>(result) = "A_BARTER_VIEW"; break;
		case 408: std::get<1>(result) = "A_BARTER_CURRENCY_1"; break;
		case 409: std::get<1>(result) = "A_BARTER_CURRENCY_2"; break;
		case 410: std::get<1>(result) = "A_BARTER_TRADE"; break;
		case 411: std::get<1>(result) = "A_BARTER_SHOW"; break;
		case 412: std::get<1>(result) = "SETUP_EMBARK"; break;
		case 413: std::get<1>(result) = "SETUP_NAME_FORT"; break;
		case 414: std::get<1>(result) = "SETUP_NAME_GROUP"; break;
		case 415: std::get<1>(result) = "SETUP_SYMBOL"; break;
		case 416: std::get<1>(result) = "SETUP_RECLAIM"; break;
		case 417: std::get<1>(result) = "SETUP_FIND"; break;
		case 418: std::get<1>(result) = "SETUP_NOTES"; break;
		case 419: std::get<1>(result) = "SETUP_NOTES_TAKE_NOTES"; break;
		case 420: std::get<1>(result) = "SETUP_NOTES_DELETE_NOTE"; break;
		case 421: std::get<1>(result) = "SETUP_NOTES_CHANGE_SYMBOL_SELECTION"; break;
		case 422: std::get<1>(result) = "SETUP_NOTES_ADOPT_SYMBOL"; break;
		case 423: std::get<1>(result) = "SETUP_LOCAL_Y_UP"; break;
		case 424: std::get<1>(result) = "SETUP_LOCAL_Y_DOWN"; break;
		case 425: std::get<1>(result) = "SETUP_LOCAL_X_UP"; break;
		case 426: std::get<1>(result) = "SETUP_LOCAL_X_DOWN"; break;
		case 427: std::get<1>(result) = "SETUP_LOCAL_Y_MUP"; break;
		case 428: std::get<1>(result) = "SETUP_LOCAL_Y_MDOWN"; break;
		case 429: std::get<1>(result) = "SETUP_LOCAL_X_MUP"; break;
		case 430: std::get<1>(result) = "SETUP_LOCAL_X_MDOWN"; break;
		case 431: std::get<1>(result) = "SETUP_BIOME_1"; break;
		case 432: std::get<1>(result) = "SETUP_BIOME_2"; break;
		case 433: std::get<1>(result) = "SETUP_BIOME_3"; break;
		case 434: std::get<1>(result) = "SETUP_BIOME_4"; break;
		case 435: std::get<1>(result) = "SETUP_BIOME_5"; break;
		case 436: std::get<1>(result) = "SETUP_BIOME_6"; break;
		case 437: std::get<1>(result) = "SETUP_BIOME_7"; break;
		case 438: std::get<1>(result) = "SETUP_BIOME_8"; break;
		case 439: std::get<1>(result) = "SETUP_BIOME_9"; break;
		case 440: std::get<1>(result) = "CHOOSE_NAME_RANDOM"; break;
		case 441: std::get<1>(result) = "CHOOSE_NAME_CLEAR"; break;
		case 442: std::get<1>(result) = "CHOOSE_NAME_TYPE"; break;
		case 443: std::get<1>(result) = "CHOOSE_NAME_FIRST"; break;
		case 444: std::get<1>(result) = "SETUPGAME_NEW"; break;
		case 445: std::get<1>(result) = "SETUPGAME_VIEW"; break;
		case 446: std::get<1>(result) = "SETUPGAME_CUSTOMIZE_UNIT"; break;
		case 447: std::get<1>(result) = "SETUPGAME_SAVE_PROFILE"; break;
		case 448: std::get<1>(result) = "SETUPGAME_SAVE_PROFILE_ABORT"; break;
		case 449: std::get<1>(result) = "SETUPGAME_SAVE_PROFILE_GO"; break;
		case 450: std::get<1>(result) = "SETUPGAME_VIEW_PROFILE_PROBLEMS"; break;
		case 451: std::get<1>(result) = "BUILDJOB_ADD"; break;
		case 452: std::get<1>(result) = "BUILDJOB_CANCEL"; break;
		case 453: std::get<1>(result) = "BUILDJOB_NAME"; break;
		case 454: std::get<1>(result) = "BUILDJOB_PROMOTE"; break;
		case 455: std::get<1>(result) = "BUILDJOB_NOW"; break;
		case 456: std::get<1>(result) = "BUILDJOB_REPEAT"; break;
		case 457: std::get<1>(result) = "BUILDJOB_SUSPEND"; break;
		case 458: std::get<1>(result) = "BUILDJOB_WORKSHOP_PROFILE"; break;
		case 459: std::get<1>(result) = "BUILDJOB_DETAILS"; break;
		case 460: std::get<1>(result) = "BUILDJOB_DETAILS_FILTER"; break;
		case 461: std::get<1>(result) = "BUILDJOB_WELL_FREE"; break;
		case 462: std::get<1>(result) = "BUILDJOB_WELL_SIZE"; break;
		case 463: std::get<1>(result) = "BUILDJOB_TARGET_FREE"; break;
		case 464: std::get<1>(result) = "BUILDJOB_TARGET_SIZE"; break;
		case 465: std::get<1>(result) = "BUILDJOB_TARGET_DOWN"; break;
		case 466: std::get<1>(result) = "BUILDJOB_TARGET_UP"; break;
		case 467: std::get<1>(result) = "BUILDJOB_TARGET_RIGHT"; break;
		case 468: std::get<1>(result) = "BUILDJOB_TARGET_LEFT"; break;
		case 469: std::get<1>(result) = "BUILDJOB_STATUE_ASSIGN"; break;
		case 470: std::get<1>(result) = "BUILDJOB_STATUE_FREE"; break;
		case 471: std::get<1>(result) = "BUILDJOB_STATUE_SIZE"; break;
		case 472: std::get<1>(result) = "BUILDJOB_CAGE_JUSTICE"; break;
		case 473: std::get<1>(result) = "BUILDJOB_CAGE_FREE"; break;
		case 474: std::get<1>(result) = "BUILDJOB_CAGE_SIZE"; break;
		case 475: std::get<1>(result) = "BUILDJOB_CAGE_ASSIGN_OCC"; break;
		case 476: std::get<1>(result) = "BUILDJOB_CAGE_WATER"; break;
		case 477: std::get<1>(result) = "BUILDJOB_CAGE_ASSIGN"; break;
		case 478: std::get<1>(result) = "BUILDJOB_CHAIN_ASSIGN_OCC"; break;
		case 479: std::get<1>(result) = "BUILDJOB_CHAIN_JUSTICE"; break;
		case 480: std::get<1>(result) = "BUILDJOB_CHAIN_ASSIGN"; break;
		case 481: std::get<1>(result) = "BUILDJOB_CHAIN_FREE"; break;
		case 482: std::get<1>(result) = "BUILDJOB_CHAIN_SIZE"; break;
		case 483: std::get<1>(result) = "BUILDJOB_SIEGE_FIRING"; break;
		case 484: std::get<1>(result) = "BUILDJOB_SIEGE_ORIENT"; break;
		case 485: std::get<1>(result) = "BUILDJOB_DOOR_INTERNAL"; break;
		case 486: std::get<1>(result) = "BUILDJOB_DOOR_LOCK"; break;
		case 487: std::get<1>(result) = "BUILDJOB_DOOR_AJAR"; break;
		case 488: std::get<1>(result) = "BUILDJOB_COFFIN_ASSIGN"; break;
		case 489: std::get<1>(result) = "BUILDJOB_COFFIN_FREE"; break;
		case 490: std::get<1>(result) = "BUILDJOB_COFFIN_SIZE"; break;
		case 491: std::get<1>(result) = "BUILDJOB_COFFIN_BURIAL"; break;
		case 492: std::get<1>(result) = "BUILDJOB_COFFIN_CIV"; break;
		case 493: std::get<1>(result) = "BUILDJOB_COFFIN_PET"; break;
		case 494: std::get<1>(result) = "BUILDJOB_CHAIR_ASSIGN"; break;
		case 495: std::get<1>(result) = "BUILDJOB_CHAIR_FREE"; break;
		case 496: std::get<1>(result) = "BUILDJOB_CHAIR_SIZE"; break;
		case 497: std::get<1>(result) = "BUILDJOB_TABLE_ASSIGN"; break;
		case 498: std::get<1>(result) = "BUILDJOB_TABLE_HALL"; break;
		case 499: std::get<1>(result) = "BUILDJOB_TABLE_FREE"; break;
		case 500: std::get<1>(result) = "BUILDJOB_TABLE_SIZE"; break;
		case 501: std::get<1>(result) = "BUILDJOB_BED_ASSIGN"; break;
		case 502: std::get<1>(result) = "BUILDJOB_BED_FREE"; break;
		case 503: std::get<1>(result) = "BUILDJOB_BED_BARRACKS"; break;
		case 504: std::get<1>(result) = "BUILDJOB_BED_DORMITORY"; break;
		case 505: std::get<1>(result) = "BUILDJOB_BED_RENT"; break;
		case 506: std::get<1>(result) = "BUILDJOB_BED_SIZE"; break;
		case 507: std::get<1>(result) = "BUILDJOB_BED_SLEEP"; break;
		case 508: std::get<1>(result) = "BUILDJOB_BED_TRAIN"; break;
		case 509: std::get<1>(result) = "BUILDJOB_BED_INDIV_EQ"; break;
		case 510: std::get<1>(result) = "BUILDJOB_BED_SQUAD_EQ"; break;
		case 511: std::get<1>(result) = "BUILDJOB_BED_POSITION"; break;
		case 512: std::get<1>(result) = "BUILDJOB_DEPOT_BRING"; break;
		case 513: std::get<1>(result) = "BUILDJOB_DEPOT_TRADE"; break;
		case 514: std::get<1>(result) = "BUILDJOB_DEPOT_REQUEST_TRADER"; break;
		case 515: std::get<1>(result) = "BUILDJOB_DEPOT_BROKER_ONLY"; break;
		case 516: std::get<1>(result) = "BUILDJOB_ANIMALTRAP_BAIT_NONE"; break;
		case 517: std::get<1>(result) = "BUILDJOB_ANIMALTRAP_BAIT_MEAT"; break;
		case 518: std::get<1>(result) = "BUILDJOB_ANIMALTRAP_BAIT_FISH"; break;
		case 519: std::get<1>(result) = "BUILDJOB_ANIMALTRAP_BAIT_GEM"; break;
		case 520: std::get<1>(result) = "BUILDJOB_FARM_FALLOW"; break;
		case 521: std::get<1>(result) = "BUILDJOB_FARM_FERTILIZE"; break;
		case 522: std::get<1>(result) = "BUILDJOB_FARM_SEASFERT"; break;
		case 523: std::get<1>(result) = "BUILDJOB_FARM_SPRING"; break;
		case 524: std::get<1>(result) = "BUILDJOB_FARM_SUMMER"; break;
		case 525: std::get<1>(result) = "BUILDJOB_FARM_AUTUMN"; break;
		case 526: std::get<1>(result) = "BUILDJOB_FARM_WINTER"; break;
		case 527: std::get<1>(result) = "BUILDJOB_RACK_MAT_BONE"; break;
		case 528: std::get<1>(result) = "BUILDJOB_RACK_MAT_BRONZE"; break;
		case 529: std::get<1>(result) = "BUILDJOB_RACK_MAT_COPPER"; break;
		case 530: std::get<1>(result) = "BUILDJOB_RACK_MAT_IRON"; break;
		case 531: std::get<1>(result) = "BUILDJOB_RACK_MAT_STEEL"; break;
		case 532: std::get<1>(result) = "BUILDJOB_RACK_MAT_WOOD"; break;
		case 533: std::get<1>(result) = "BUILDJOB_RACK_MAT_METAL"; break;
		case 534: std::get<1>(result) = "BUILDJOB_STAND_MAT_BONE"; break;
		case 535: std::get<1>(result) = "BUILDJOB_STAND_MAT_LEATHER"; break;
		case 536: std::get<1>(result) = "BUILDJOB_STAND_MAT_COPPER"; break;
		case 537: std::get<1>(result) = "BUILDJOB_STAND_MAT_BRONZE"; break;
		case 538: std::get<1>(result) = "BUILDJOB_STAND_MAT_STEEL"; break;
		case 539: std::get<1>(result) = "BUILDJOB_STAND_MAT_IRON"; break;
		case 540: std::get<1>(result) = "BUILDJOB_STAND_MAT_WOOD"; break;
		case 541: std::get<1>(result) = "BUILDJOB_STAND_MAT_METAL"; break;
		case 542: std::get<1>(result) = "BUILDJOB_RACKSTAND_ASSIGN"; break;
		case 543: std::get<1>(result) = "BUILDJOB_RACKSTAND_FREE"; break;
		case 544: std::get<1>(result) = "BUILDJOB_RACKSTAND_SIZE"; break;
		case 545: std::get<1>(result) = "BUILDJOB_RACKSTAND_ITEM"; break;
		case 546: std::get<1>(result) = "BUILDJOB_RACKSTAND_MAT"; break;
		case 547: std::get<1>(result) = "BUILDJOB_RACKSTAND_DEFAULTS1"; break;
		case 548: std::get<1>(result) = "BUILDJOB_RACKSTAND_KILL1"; break;
		case 549: std::get<1>(result) = "BUILDJOB_RACKSTAND_DEFAULTS2"; break;
		case 550: std::get<1>(result) = "BUILDJOB_RACKSTAND_KILL2"; break;
		case 551: std::get<1>(result) = "BUILDJOB_DISPLAY_FURNITURE_SET"; break;
		case 552: std::get<1>(result) = "BUILDJOB_DISPLAY_FURNITURE_CANCEL"; break;
		case 553: std::get<1>(result) = "HOTKEY_BUILDING_ARMORSTAND"; break;
		case 554: std::get<1>(result) = "HOTKEY_BUILDING_BED"; break;
		case 555: std::get<1>(result) = "HOTKEY_BUILDING_CHAIR"; break;
		case 556: std::get<1>(result) = "HOTKEY_BUILDING_COFFIN"; break;
		case 557: std::get<1>(result) = "HOTKEY_BUILDING_DOOR"; break;
		case 558: std::get<1>(result) = "HOTKEY_BUILDING_FLOODGATE"; break;
		case 559: std::get<1>(result) = "HOTKEY_BUILDING_HATCH"; break;
		case 560: std::get<1>(result) = "HOTKEY_BUILDING_GRATE_WALL"; break;
		case 561: std::get<1>(result) = "HOTKEY_BUILDING_GRATE_FLOOR"; break;
		case 562: std::get<1>(result) = "HOTKEY_BUILDING_BARS_VERTICAL"; break;
		case 563: std::get<1>(result) = "HOTKEY_BUILDING_BARS_FLOOR"; break;
		case 564: std::get<1>(result) = "HOTKEY_BUILDING_CABINET"; break;
		case 565: std::get<1>(result) = "HOTKEY_BUILDING_BOX"; break;
		case 566: std::get<1>(result) = "HOTKEY_BUILDING_KENNEL"; break;
		case 567: std::get<1>(result) = "HOTKEY_BUILDING_FARMPLOT"; break;
		case 568: std::get<1>(result) = "HOTKEY_BUILDING_WEAPONRACK"; break;
		case 569: std::get<1>(result) = "HOTKEY_BUILDING_STATUE"; break;
		case 570: std::get<1>(result) = "HOTKEY_BUILDING_TABLE"; break;
		case 571: std::get<1>(result) = "HOTKEY_BUILDING_ROAD_DIRT"; break;
		case 572: std::get<1>(result) = "HOTKEY_BUILDING_ROAD_PAVED"; break;
		case 573: std::get<1>(result) = "HOTKEY_BUILDING_BRIDGE"; break;
		case 574: std::get<1>(result) = "HOTKEY_BUILDING_WELL"; break;
		case 575: std::get<1>(result) = "HOTKEY_BUILDING_SIEGEENGINE"; break;
		case 576: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP"; break;
		case 577: std::get<1>(result) = "HOTKEY_BUILDING_FURNACE"; break;
		case 578: std::get<1>(result) = "HOTKEY_BUILDING_WINDOW_GLASS"; break;
		case 579: std::get<1>(result) = "HOTKEY_BUILDING_WINDOW_GEM"; break;
		case 580: std::get<1>(result) = "HOTKEY_BUILDING_SHOP"; break;
		case 581: std::get<1>(result) = "HOTKEY_BUILDING_ANIMALTRAP"; break;
		case 582: std::get<1>(result) = "HOTKEY_BUILDING_CHAIN"; break;
		case 583: std::get<1>(result) = "HOTKEY_BUILDING_CAGE"; break;
		case 584: std::get<1>(result) = "HOTKEY_BUILDING_TRADEDEPOT"; break;
		case 585: std::get<1>(result) = "HOTKEY_BUILDING_TRAP"; break;
		case 586: std::get<1>(result) = "HOTKEY_BUILDING_MACHINE"; break;
		case 587: std::get<1>(result) = "HOTKEY_BUILDING_INSTRUMENT"; break;
		case 588: std::get<1>(result) = "HOTKEY_BUILDING_SUPPORT"; break;
		case 589: std::get<1>(result) = "HOTKEY_BUILDING_ARCHERYTARGET"; break;
		case 590: std::get<1>(result) = "HOTKEY_BUILDING_TRACTION_BENCH"; break;
		case 591: std::get<1>(result) = "HOTKEY_BUILDING_SLAB"; break;
		case 592: std::get<1>(result) = "HOTKEY_BUILDING_NEST_BOX"; break;
		case 593: std::get<1>(result) = "HOTKEY_BUILDING_BOOKCASE"; break;
		case 594: std::get<1>(result) = "HOTKEY_BUILDING_HIVE"; break;
		case 595: std::get<1>(result) = "HOTKEY_BUILDING_DISPLAY_FURNITURE"; break;
		case 596: std::get<1>(result) = "HOTKEY_BUILDING_MACHINE_SCREW_PUMP"; break;
		case 597: std::get<1>(result) = "HOTKEY_BUILDING_MACHINE_WATER_WHEEL"; break;
		case 598: std::get<1>(result) = "HOTKEY_BUILDING_MACHINE_WINDMILL"; break;
		case 599: std::get<1>(result) = "HOTKEY_BUILDING_MACHINE_GEAR_ASSEMBLY"; break;
		case 600: std::get<1>(result) = "HOTKEY_BUILDING_MACHINE_AXLE_VERTICAL"; break;
		case 601: std::get<1>(result) = "HOTKEY_BUILDING_MACHINE_AXLE_HORIZONTAL"; break;
		case 602: std::get<1>(result) = "HOTKEY_BUILDING_MACHINE_ROLLERS"; break;
		case 603: std::get<1>(result) = "HOTKEY_BUILDING_SIEGEENGINE_BALLISTA"; break;
		case 604: std::get<1>(result) = "HOTKEY_BUILDING_SIEGEENGINE_CATAPULT"; break;
		case 605: std::get<1>(result) = "HOTKEY_BUILDING_TRAP_STONE"; break;
		case 606: std::get<1>(result) = "HOTKEY_BUILDING_TRAP_WEAPON"; break;
		case 607: std::get<1>(result) = "HOTKEY_BUILDING_TRAP_LEVER"; break;
		case 608: std::get<1>(result) = "HOTKEY_BUILDING_TRAP_TRIGGER"; break;
		case 609: std::get<1>(result) = "HOTKEY_BUILDING_TRAP_CAGE"; break;
		case 610: std::get<1>(result) = "HOTKEY_BUILDING_TRAP_SPIKE"; break;
		case 611: std::get<1>(result) = "HOTKEY_BUILDING_CONSTRUCTION"; break;
		case 612: std::get<1>(result) = "HOTKEY_BUILDING_CONSTRUCTION_WALL"; break;
		case 613: std::get<1>(result) = "HOTKEY_BUILDING_CONSTRUCTION_FLOOR"; break;
		case 614: std::get<1>(result) = "HOTKEY_BUILDING_CONSTRUCTION_RAMP"; break;
		case 615: std::get<1>(result) = "HOTKEY_BUILDING_CONSTRUCTION_STAIR_UP"; break;
		case 616: std::get<1>(result) = "HOTKEY_BUILDING_CONSTRUCTION_STAIR_DOWN"; break;
		case 617: std::get<1>(result) = "HOTKEY_BUILDING_CONSTRUCTION_STAIR_UPDOWN"; break;
		case 618: std::get<1>(result) = "HOTKEY_BUILDING_CONSTRUCTION_FORTIFICATION"; break;
		case 619: std::get<1>(result) = "HOTKEY_BUILDING_CONSTRUCTION_TRACK"; break;
		case 620: std::get<1>(result) = "HOTKEY_BUILDING_CONSTRUCTION_TRACK_STOP"; break;
		case 621: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_LEATHER"; break;
		case 622: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_QUERN"; break;
		case 623: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_MILLSTONE"; break;
		case 624: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_LOOM"; break;
		case 625: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_CLOTHES"; break;
		case 626: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_BOWYER"; break;
		case 627: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_CARPENTER"; break;
		case 628: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_METALSMITH"; break;
		case 629: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_LAVAMILL"; break;
		case 630: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_JEWELER"; break;
		case 631: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_MASON"; break;
		case 632: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_BUTCHER"; break;
		case 633: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_TANNER"; break;
		case 634: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_DYER"; break;
		case 635: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_CRAFTSMAN"; break;
		case 636: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_SIEGE"; break;
		case 637: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_MECHANIC"; break;
		case 638: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_STILL"; break;
		case 639: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_FARMER"; break;
		case 640: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_KITCHEN"; break;
		case 641: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_FISHERY"; break;
		case 642: std::get<1>(result) = "HOTKEY_BUILDING_WORKSHOP_ASHERY"; break;
		case 643: std::get<1>(result) = "HOTKEY_BUILDING_FURNACE_WOOD"; break;
		case 644: std::get<1>(result) = "HOTKEY_BUILDING_FURNACE_SMELTER"; break;
		case 645: std::get<1>(result) = "HOTKEY_BUILDING_FURNACE_GLASS"; break;
		case 646: std::get<1>(result) = "HOTKEY_BUILDING_FURNACE_KILN"; break;
		case 647: std::get<1>(result) = "HOTKEY_BUILDING_FURNACE_SMELTER_LAVA"; break;
		case 648: std::get<1>(result) = "HOTKEY_BUILDING_FURNACE_GLASS_LAVA"; break;
		case 649: std::get<1>(result) = "HOTKEY_BUILDING_FURNACE_KILN_LAVA"; break;
		case 650: std::get<1>(result) = "HIVE_INSTALL_COLONY"; break;
		case 651: std::get<1>(result) = "HIVE_GATHER_PRODUCTS"; break;
		case 652: std::get<1>(result) = "BUILDING_DIM_Y_UP"; break;
		case 653: std::get<1>(result) = "BUILDING_DIM_Y_DOWN"; break;
		case 654: std::get<1>(result) = "BUILDING_DIM_X_UP"; break;
		case 655: std::get<1>(result) = "BUILDING_DIM_X_DOWN"; break;
		case 656: std::get<1>(result) = "BUILDING_ORIENT_UP"; break;
		case 657: std::get<1>(result) = "BUILDING_ORIENT_LEFT"; break;
		case 658: std::get<1>(result) = "BUILDING_ORIENT_RIGHT"; break;
		case 659: std::get<1>(result) = "BUILDING_ORIENT_DOWN"; break;
		case 660: std::get<1>(result) = "BUILDING_ORIENT_NONE"; break;
		case 661: std::get<1>(result) = "BUILDING_VIEW_ITEM"; break;
		case 662: std::get<1>(result) = "BUILDING_ADVANCE_STAGE"; break;
		case 663: std::get<1>(result) = "BUILDING_EXPAND_CONTRACT"; break;
		case 664: std::get<1>(result) = "BUILDING_TRIGGER_ENABLE_WATER"; break;
		case 665: std::get<1>(result) = "BUILDING_TRIGGER_MIN_WATER_UP"; break;
		case 666: std::get<1>(result) = "BUILDING_TRIGGER_MIN_WATER_DOWN"; break;
		case 667: std::get<1>(result) = "BUILDING_TRIGGER_MAX_WATER_UP"; break;
		case 668: std::get<1>(result) = "BUILDING_TRIGGER_MAX_WATER_DOWN"; break;
		case 669: std::get<1>(result) = "BUILDING_TRIGGER_ENABLE_MAGMA"; break;
		case 670: std::get<1>(result) = "BUILDING_TRIGGER_MIN_MAGMA_UP"; break;
		case 671: std::get<1>(result) = "BUILDING_TRIGGER_MIN_MAGMA_DOWN"; break;
		case 672: std::get<1>(result) = "BUILDING_TRIGGER_MAX_MAGMA_UP"; break;
		case 673: std::get<1>(result) = "BUILDING_TRIGGER_MAX_MAGMA_DOWN"; break;
		case 674: std::get<1>(result) = "BUILDING_TRIGGER_ENABLE_TRACK_CART"; break;
		case 675: std::get<1>(result) = "BUILDING_TRIGGER_MIN_TRACK_CART_DOWN"; break;
		case 676: std::get<1>(result) = "BUILDING_TRIGGER_MIN_TRACK_CART_UP"; break;
		case 677: std::get<1>(result) = "BUILDING_TRIGGER_MAX_TRACK_CART_DOWN"; break;
		case 678: std::get<1>(result) = "BUILDING_TRIGGER_MAX_TRACK_CART_UP"; break;
		case 679: std::get<1>(result) = "BUILDING_TRIGGER_ENABLE_CREATURE"; break;
		case 680: std::get<1>(result) = "BUILDING_TRIGGER_ENABLE_LOCALS"; break;
		case 681: std::get<1>(result) = "BUILDING_TRIGGER_RESETS"; break;
		case 682: std::get<1>(result) = "BUILDING_TRIGGER_MIN_SIZE_UP"; break;
		case 683: std::get<1>(result) = "BUILDING_TRIGGER_MIN_SIZE_DOWN"; break;
		case 684: std::get<1>(result) = "BUILDING_TRIGGER_MAX_SIZE_UP"; break;
		case 685: std::get<1>(result) = "BUILDING_TRIGGER_MAX_SIZE_DOWN"; break;
		case 686: std::get<1>(result) = "BUILDING_TRIGGER_MIN_SIZE_UP_PLUS"; break;
		case 687: std::get<1>(result) = "BUILDING_TRIGGER_MIN_SIZE_DOWN_PLUS"; break;
		case 688: std::get<1>(result) = "BUILDING_TRIGGER_MAX_SIZE_UP_PLUS"; break;
		case 689: std::get<1>(result) = "BUILDING_TRIGGER_MAX_SIZE_DOWN_PLUS"; break;
		case 690: std::get<1>(result) = "BUILDING_ROLLERS_SPEED_UP"; break;
		case 691: std::get<1>(result) = "BUILDING_ROLLERS_SPEED_DOWN"; break;
		case 692: std::get<1>(result) = "BUILDING_TRACK_STOP_FRICTION_UP"; break;
		case 693: std::get<1>(result) = "BUILDING_TRACK_STOP_FRICTION_DOWN"; break;
		case 694: std::get<1>(result) = "BUILDING_TRACK_STOP_DUMP"; break;
		case 695: std::get<1>(result) = "DESTROYBUILDING"; break;
		case 696: std::get<1>(result) = "SUSPENDBUILDING"; break;
		case 697: std::get<1>(result) = "BUILDINGLIST_ZOOM_T"; break;
		case 698: std::get<1>(result) = "BUILDINGLIST_ZOOM_Q"; break;
		case 699: std::get<1>(result) = "RECENTER_ON_LEVER"; break;
		case 700: std::get<1>(result) = "ASSIGN_LOCATION"; break;
		case 701: std::get<1>(result) = "LOCATION_NEW"; break;
		case 702: std::get<1>(result) = "LOCATION_RETIRE"; break;
		case 703: std::get<1>(result) = "LOCATION_INN_TAVERN"; break;
		case 704: std::get<1>(result) = "LOCATION_TEMPLE"; break;
		case 705: std::get<1>(result) = "LOCATION_LIBRARY"; break;
		case 706: std::get<1>(result) = "LOCATION_MAIN_HALL"; break;
		case 707: std::get<1>(result) = "LOCATION_RENAME"; break;
		case 708: std::get<1>(result) = "LOCATION_DETAILS"; break;
		case 709: std::get<1>(result) = "LOCATION_RESTRICTION"; break;
		case 710: std::get<1>(result) = "LOCATION_SET_NUMBER_1"; break;
		case 711: std::get<1>(result) = "LOCATION_SET_NUMBER_2"; break;
		case 712: std::get<1>(result) = "HOTKEY_MAKE_ASH"; break;
		case 713: std::get<1>(result) = "HOTKEY_MAKE_CHARCOAL"; break;
		case 714: std::get<1>(result) = "HOTKEY_MELT_OBJECT"; break;
		case 715: std::get<1>(result) = "HOTKEY_GLASS_GREEN"; break;
		case 716: std::get<1>(result) = "HOTKEY_GLASS_CLEAR"; break;
		case 717: std::get<1>(result) = "HOTKEY_GLASS_CRYSTAL"; break;
		case 718: std::get<1>(result) = "HOTKEY_COLLECT_SAND"; break;
		case 719: std::get<1>(result) = "HOTKEY_COLLECT_CLAY"; break;
		case 720: std::get<1>(result) = "HOTKEY_GLASS_ROUGH"; break;
		case 721: std::get<1>(result) = "HOTKEY_GLASS_ARMORSTAND"; break;
		case 722: std::get<1>(result) = "HOTKEY_GLASS_BOX"; break;
		case 723: std::get<1>(result) = "HOTKEY_GLASS_CABINET"; break;
		case 724: std::get<1>(result) = "HOTKEY_GLASS_COFFIN"; break;
		case 725: std::get<1>(result) = "HOTKEY_GLASS_FLOODGATE"; break;
		case 726: std::get<1>(result) = "HOTKEY_GLASS_HATCH_COVER"; break;
		case 727: std::get<1>(result) = "HOTKEY_GLASS_GRATE"; break;
		case 728: std::get<1>(result) = "HOTKEY_GLASS_GOBLET"; break;
		case 729: std::get<1>(result) = "HOTKEY_GLASS_TOY"; break;
		case 730: std::get<1>(result) = "HOTKEY_GLASS_DOOR"; break;
		case 731: std::get<1>(result) = "HOTKEY_GLASS_STATUE"; break;
		case 732: std::get<1>(result) = "HOTKEY_GLASS_TABLE"; break;
		case 733: std::get<1>(result) = "HOTKEY_GLASS_CAGE"; break;
		case 734: std::get<1>(result) = "HOTKEY_GLASS_CHAIR"; break;
		case 735: std::get<1>(result) = "HOTKEY_GLASS_BLOCKS"; break;
		case 736: std::get<1>(result) = "HOTKEY_GLASS_FLASK"; break;
		case 737: std::get<1>(result) = "HOTKEY_GLASS_WEAPONRACK"; break;
		case 738: std::get<1>(result) = "HOTKEY_GLASS_WINDOW"; break;
		case 739: std::get<1>(result) = "HOTKEY_ASHERY_LYE"; break;
		case 740: std::get<1>(result) = "HOTKEY_ASHERY_POTASH"; break;
		case 741: std::get<1>(result) = "HOTKEY_ASHERY_POTASH_DIRECT"; break;
		case 742: std::get<1>(result) = "HOTKEY_CARPENTER_BARREL"; break;
		case 743: std::get<1>(result) = "HOTKEY_CARPENTER_BLOCKS"; break;
		case 744: std::get<1>(result) = "HOTKEY_CARPENTER_BUCKET"; break;
		case 745: std::get<1>(result) = "HOTKEY_CARPENTER_TRAP_ANIMAL"; break;
		case 746: std::get<1>(result) = "HOTKEY_CARPENTER_CAGE"; break;
		case 747: std::get<1>(result) = "HOTKEY_CARPENTER_ARMORSTAND"; break;
		case 748: std::get<1>(result) = "HOTKEY_CARPENTER_BED"; break;
		case 749: std::get<1>(result) = "HOTKEY_CARPENTER_CHAIR"; break;
		case 750: std::get<1>(result) = "HOTKEY_CARPENTER_COFFIN"; break;
		case 751: std::get<1>(result) = "HOTKEY_CARPENTER_DOOR"; break;
		case 752: std::get<1>(result) = "HOTKEY_CARPENTER_FLOODGATE"; break;
		case 753: std::get<1>(result) = "HOTKEY_CARPENTER_HATCH_COVER"; break;
		case 754: std::get<1>(result) = "HOTKEY_CARPENTER_GRATE"; break;
		case 755: std::get<1>(result) = "HOTKEY_CARPENTER_CABINET"; break;
		case 756: std::get<1>(result) = "HOTKEY_CARPENTER_BIN"; break;
		case 757: std::get<1>(result) = "HOTKEY_CARPENTER_BOX"; break;
		case 758: std::get<1>(result) = "HOTKEY_CARPENTER_WEAPONRACK"; break;
		case 759: std::get<1>(result) = "HOTKEY_CARPENTER_TABLE"; break;
		case 760: std::get<1>(result) = "HOTKEY_SIEGE_BALLISTA"; break;
		case 761: std::get<1>(result) = "HOTKEY_SIEGE_CATAPULT"; break;
		case 762: std::get<1>(result) = "HOTKEY_LEATHER_BOX"; break;
		case 763: std::get<1>(result) = "HOTKEY_LEATHER_FLASK"; break;
		case 764: std::get<1>(result) = "HOTKEY_LEATHER_SHIRT"; break;
		case 765: std::get<1>(result) = "HOTKEY_LEATHER_CLOAK"; break;
		case 766: std::get<1>(result) = "HOTKEY_LEATHER_BACKPACK"; break;
		case 767: std::get<1>(result) = "HOTKEY_LEATHER_QUIVER"; break;
		case 768: std::get<1>(result) = "HOTKEY_LEATHER_IMAGE"; break;
		case 769: std::get<1>(result) = "HOTKEY_CLOTHES_MAT_PLANT"; break;
		case 770: std::get<1>(result) = "HOTKEY_CLOTHES_MAT_SILK"; break;
		case 771: std::get<1>(result) = "HOTKEY_CLOTHES_MAT_YARN"; break;
		case 772: std::get<1>(result) = "HOTKEY_CLOTHES_SHIRT"; break;
		case 773: std::get<1>(result) = "HOTKEY_CLOTHES_CLOAK"; break;
		case 774: std::get<1>(result) = "HOTKEY_CLOTHES_BOX"; break;
		case 775: std::get<1>(result) = "HOTKEY_CLOTHES_CHAIN"; break;
		case 776: std::get<1>(result) = "HOTKEY_CLOTHES_IMAGE"; break;
		case 777: std::get<1>(result) = "HOTKEY_CRAFTS_MAT_STONE"; break;
		case 778: std::get<1>(result) = "HOTKEY_CRAFTS_MAT_WOOD"; break;
		case 779: std::get<1>(result) = "HOTKEY_CRAFTS_DEC_BONE"; break;
		case 780: std::get<1>(result) = "HOTKEY_CRAFTS_DEC_SHELL"; break;
		case 781: std::get<1>(result) = "HOTKEY_CRAFTS_DEC_TOOTH"; break;
		case 782: std::get<1>(result) = "HOTKEY_CRAFTS_DEC_HORN"; break;
		case 783: std::get<1>(result) = "HOTKEY_CRAFTS_DEC_PEARL"; break;
		case 784: std::get<1>(result) = "HOTKEY_CRAFTS_TOTEM"; break;
		case 785: std::get<1>(result) = "HOTKEY_CRAFTS_CLOTH"; break;
		case 786: std::get<1>(result) = "HOTKEY_CRAFTS_SILK"; break;
		case 787: std::get<1>(result) = "HOTKEY_CRAFTS_YARN"; break;
		case 788: std::get<1>(result) = "HOTKEY_CRAFTS_SEL_WOOD"; break;
		case 789: std::get<1>(result) = "HOTKEY_CRAFTS_SEL_BONE"; break;
		case 790: std::get<1>(result) = "HOTKEY_CRAFTS_SEL_SHELL"; break;
		case 791: std::get<1>(result) = "HOTKEY_CRAFTS_SHELL"; break;
		case 792: std::get<1>(result) = "HOTKEY_CRAFTS_TOOTH"; break;
		case 793: std::get<1>(result) = "HOTKEY_CRAFTS_HORN"; break;
		case 794: std::get<1>(result) = "HOTKEY_CRAFTS_PEARL"; break;
		case 795: std::get<1>(result) = "HOTKEY_CRAFTS_BONE"; break;
		case 796: std::get<1>(result) = "HOTKEY_CRAFTS_LEATHER"; break;
		case 797: std::get<1>(result) = "HOTKEY_CRAFTS_SLAB"; break;
		case 798: std::get<1>(result) = "HOTKEY_CRAFTS_MAT_CRAFTS"; break;
		case 799: std::get<1>(result) = "HOTKEY_CRAFTS_MAT_GOBLET"; break;
		case 800: std::get<1>(result) = "HOTKEY_CRAFTS_MAT_TOY"; break;
		case 801: std::get<1>(result) = "HOTKEY_SMITH_WEAPON"; break;
		case 802: std::get<1>(result) = "HOTKEY_SMITH_ARMOR"; break;
		case 803: std::get<1>(result) = "HOTKEY_SMITH_FURNITURE"; break;
		case 804: std::get<1>(result) = "HOTKEY_SMITH_SIEGE"; break;
		case 805: std::get<1>(result) = "HOTKEY_SMITH_TRAP"; break;
		case 806: std::get<1>(result) = "HOTKEY_SMITH_OTHER"; break;
		case 807: std::get<1>(result) = "HOTKEY_SMITH_METAL"; break;
		case 808: std::get<1>(result) = "HOTKEY_ALCHEMIST_SOAP"; break;
		case 809: std::get<1>(result) = "HOTKEY_STILL_BREW"; break;
		case 810: std::get<1>(result) = "HOTKEY_STILL_EXTRACT"; break;
		case 811: std::get<1>(result) = "HOTKEY_LOOM_COLLECT_SILK"; break;
		case 812: std::get<1>(result) = "HOTKEY_LOOM_WEAVE_CLOTH"; break;
		case 813: std::get<1>(result) = "HOTKEY_LOOM_WEAVE_SILK"; break;
		case 814: std::get<1>(result) = "HOTKEY_LOOM_WEAVE_YARN"; break;
		case 815: std::get<1>(result) = "HOTKEY_LOOM_WEAVE_METAL"; break;
		case 816: std::get<1>(result) = "HOTKEY_KITCHEN_COOK_2"; break;
		case 817: std::get<1>(result) = "HOTKEY_KITCHEN_COOK_3"; break;
		case 818: std::get<1>(result) = "HOTKEY_KITCHEN_COOK_4"; break;
		case 819: std::get<1>(result) = "HOTKEY_KITCHEN_RENDER_FAT"; break;
		case 820: std::get<1>(result) = "HOTKEY_FARMER_PROCESS"; break;
		case 821: std::get<1>(result) = "HOTKEY_FARMER_PROCESS_VIAL"; break;
		case 822: std::get<1>(result) = "HOTKEY_FARMER_PROCESS_BAG"; break;
		case 823: std::get<1>(result) = "HOTKEY_FARMER_PROCESS_BARREL"; break;
		case 824: std::get<1>(result) = "HOTKEY_FARMER_CHEESE"; break;
		case 825: std::get<1>(result) = "HOTKEY_FARMER_MILK"; break;
		case 826: std::get<1>(result) = "HOTKEY_FARMER_SHEAR_CREATURE"; break;
		case 827: std::get<1>(result) = "HOTKEY_FARMER_SPIN_THREAD"; break;
		case 828: std::get<1>(result) = "HOTKEY_MILL_MILL"; break;
		case 829: std::get<1>(result) = "HOTKEY_KENNEL_CATCH_VERMIN"; break;
		case 830: std::get<1>(result) = "HOTKEY_KENNEL_TAME_VERMIN"; break;
		case 831: std::get<1>(result) = "HOTKEY_FISHERY_PROCESS"; break;
		case 832: std::get<1>(result) = "HOTKEY_FISHERY_EXTRACT"; break;
		case 833: std::get<1>(result) = "HOTKEY_FISHERY_CATCH"; break;
		case 834: std::get<1>(result) = "HOTKEY_BUTCHER_BUTCHER"; break;
		case 835: std::get<1>(result) = "HOTKEY_BUTCHER_EXTRACT"; break;
		case 836: std::get<1>(result) = "HOTKEY_BUTCHER_CATCH"; break;
		case 837: std::get<1>(result) = "HOTKEY_TANNER_TAN"; break;
		case 838: std::get<1>(result) = "HOTKEY_DYER_THREAD"; break;
		case 839: std::get<1>(result) = "HOTKEY_DYER_CLOTH"; break;
		case 840: std::get<1>(result) = "HOTKEY_JEWELER_FURNITURE"; break;
		case 841: std::get<1>(result) = "HOTKEY_JEWELER_FINISHED"; break;
		case 842: std::get<1>(result) = "HOTKEY_JEWELER_AMMO"; break;
		case 843: std::get<1>(result) = "HOTKEY_JEWELER_CUT"; break;
		case 844: std::get<1>(result) = "HOTKEY_JEWELER_ENCRUST"; break;
		case 845: std::get<1>(result) = "HOTKEY_MECHANIC_PARTS"; break;
		case 846: std::get<1>(result) = "HOTKEY_MECHANIC_TRACTION_BENCH"; break;
		case 847: std::get<1>(result) = "HOTKEY_MASON_ARMORSTAND"; break;
		case 848: std::get<1>(result) = "HOTKEY_MASON_BLOCKS"; break;
		case 849: std::get<1>(result) = "HOTKEY_MASON_CHAIR"; break;
		case 850: std::get<1>(result) = "HOTKEY_MASON_COFFIN"; break;
		case 851: std::get<1>(result) = "HOTKEY_MASON_DOOR"; break;
		case 852: std::get<1>(result) = "HOTKEY_MASON_FLOODGATE"; break;
		case 853: std::get<1>(result) = "HOTKEY_MASON_HATCH_COVER"; break;
		case 854: std::get<1>(result) = "HOTKEY_MASON_GRATE"; break;
		case 855: std::get<1>(result) = "HOTKEY_MASON_CABINET"; break;
		case 856: std::get<1>(result) = "HOTKEY_MASON_BOX"; break;
		case 857: std::get<1>(result) = "HOTKEY_MASON_STATUE"; break;
		case 858: std::get<1>(result) = "HOTKEY_MASON_TABLE"; break;
		case 859: std::get<1>(result) = "HOTKEY_MASON_WEAPONRACK"; break;
		case 860: std::get<1>(result) = "HOTKEY_MASON_QUERN"; break;
		case 861: std::get<1>(result) = "HOTKEY_MASON_MILLSTONE"; break;
		case 862: std::get<1>(result) = "HOTKEY_MASON_SLAB"; break;
		case 863: std::get<1>(result) = "HOTKEY_TRAP_BRIDGE"; break;
		case 864: std::get<1>(result) = "HOTKEY_TRAP_DOOR"; break;
		case 865: std::get<1>(result) = "HOTKEY_TRAP_FLOODGATE"; break;
		case 866: std::get<1>(result) = "HOTKEY_TRAP_SPIKE"; break;
		case 867: std::get<1>(result) = "HOTKEY_TRAP_HATCH"; break;
		case 868: std::get<1>(result) = "HOTKEY_TRAP_GRATE_WALL"; break;
		case 869: std::get<1>(result) = "HOTKEY_TRAP_GRATE_FLOOR"; break;
		case 870: std::get<1>(result) = "HOTKEY_TRAP_BARS_VERTICAL"; break;
		case 871: std::get<1>(result) = "HOTKEY_TRAP_BARS_FLOOR"; break;
		case 872: std::get<1>(result) = "HOTKEY_TRAP_SUPPORT"; break;
		case 873: std::get<1>(result) = "HOTKEY_TRAP_CHAIN"; break;
		case 874: std::get<1>(result) = "HOTKEY_TRAP_CAGE"; break;
		case 875: std::get<1>(result) = "HOTKEY_TRAP_GEAR_ASSEMBLY"; break;
		case 876: std::get<1>(result) = "HOTKEY_TRAP_TRACK_STOP"; break;
		case 877: std::get<1>(result) = "HOTKEY_TRAP_PULL_LEVER"; break;
		case 878: std::get<1>(result) = "BUILDJOB_STOCKPILE_MASTER"; break;
		case 879: std::get<1>(result) = "BUILDJOB_STOCKPILE_LINK_ANYWHERE"; break;
		case 880: std::get<1>(result) = "BUILDJOB_STOCKPILE_GIVE_TO"; break;
		case 881: std::get<1>(result) = "BUILDJOB_STOCKPILE_DELETE_CHILD"; break;
		case 882: std::get<1>(result) = "BUILDJOB_STOCKPILE_SETTINGS"; break;
		case 883: std::get<1>(result) = "BUILDJOB_STOCKPILE_BARREL_UP"; break;
		case 884: std::get<1>(result) = "BUILDJOB_STOCKPILE_BARREL_DOWN"; break;
		case 885: std::get<1>(result) = "BUILDJOB_STOCKPILE_BARREL_ZERO"; break;
		case 886: std::get<1>(result) = "BUILDJOB_STOCKPILE_BARREL_MAX"; break;
		case 887: std::get<1>(result) = "BUILDJOB_STOCKPILE_BIN_UP"; break;
		case 888: std::get<1>(result) = "BUILDJOB_STOCKPILE_BIN_DOWN"; break;
		case 889: std::get<1>(result) = "BUILDJOB_STOCKPILE_BIN_ZERO"; break;
		case 890: std::get<1>(result) = "BUILDJOB_STOCKPILE_BIN_MAX"; break;
		case 891: std::get<1>(result) = "BUILDJOB_STOCKPILE_WHEELBARROW"; break;
		case 892: std::get<1>(result) = "STOCKPILE_ANIMAL"; break;
		case 893: std::get<1>(result) = "STOCKPILE_FOOD"; break;
		case 894: std::get<1>(result) = "STOCKPILE_WEAPON"; break;
		case 895: std::get<1>(result) = "STOCKPILE_ARMOR"; break;
		case 896: std::get<1>(result) = "STOCKPILE_CUSTOM"; break;
		case 897: std::get<1>(result) = "STOCKPILE_CUSTOM_SETTINGS"; break;
		case 898: std::get<1>(result) = "STOCKPILE_FURNITURE"; break;
		case 899: std::get<1>(result) = "STOCKPILE_GRAVEYARD"; break;
		case 900: std::get<1>(result) = "STOCKPILE_REFUSE"; break;
		case 901: std::get<1>(result) = "STOCKPILE_WOOD"; break;
		case 902: std::get<1>(result) = "STOCKPILE_STONE"; break;
		case 903: std::get<1>(result) = "STOCKPILE_GEM"; break;
		case 904: std::get<1>(result) = "STOCKPILE_BARBLOCK"; break;
		case 905: std::get<1>(result) = "STOCKPILE_CLOTH"; break;
		case 906: std::get<1>(result) = "STOCKPILE_LEATHER"; break;
		case 907: std::get<1>(result) = "STOCKPILE_AMMO"; break;
		case 908: std::get<1>(result) = "STOCKPILE_COINS"; break;
		case 909: std::get<1>(result) = "STOCKPILE_FINISHED"; break;
		case 910: std::get<1>(result) = "STOCKPILE_SHEET"; break;
		case 911: std::get<1>(result) = "STOCKPILE_NONE"; break;
		case 912: std::get<1>(result) = "STOCKPILE_SETTINGS_ENABLE"; break;
		case 913: std::get<1>(result) = "STOCKPILE_SETTINGS_DISABLE"; break;
		case 914: std::get<1>(result) = "STOCKPILE_SETTINGS_PERMIT_ALL"; break;
		case 915: std::get<1>(result) = "STOCKPILE_SETTINGS_FORBID_ALL"; break;
		case 916: std::get<1>(result) = "STOCKPILE_SETTINGS_PERMIT_SUB"; break;
		case 917: std::get<1>(result) = "STOCKPILE_SETTINGS_FORBID_SUB"; break;
		case 918: std::get<1>(result) = "STOCKPILE_SETTINGS_SPECIFIC1"; break;
		case 919: std::get<1>(result) = "STOCKPILE_SETTINGS_SPECIFIC2"; break;
		case 920: std::get<1>(result) = "CIVZONE_NAME"; break;
		case 921: std::get<1>(result) = "CIVZONE_REMOVE"; break;
		case 922: std::get<1>(result) = "CIVZONE_REMOVE_ZONE"; break;
		case 923: std::get<1>(result) = "CIVZONE_SHAPE"; break;
		case 924: std::get<1>(result) = "CIVZONE_NEXT"; break;
		case 925: std::get<1>(result) = "CIVZONE_WATER_SOURCE"; break;
		case 926: std::get<1>(result) = "CIVZONE_FISH"; break;
		case 927: std::get<1>(result) = "CIVZONE_GATHER"; break;
		case 928: std::get<1>(result) = "CIVZONE_DUMP"; break;
		case 929: std::get<1>(result) = "CIVZONE_POND"; break;
		case 930: std::get<1>(result) = "CIVZONE_HOSPITAL"; break;
		case 931: std::get<1>(result) = "CIVZONE_SAND_COLLECT"; break;
		case 932: std::get<1>(result) = "CIVZONE_CLAY_COLLECT"; break;
		case 933: std::get<1>(result) = "CIVZONE_ACTIVE"; break;
		case 934: std::get<1>(result) = "CIVZONE_MEETING"; break;
		case 935: std::get<1>(result) = "CIVZONE_ANIMAL_TRAINING"; break;
		case 936: std::get<1>(result) = "CIVZONE_PEN"; break;
		case 937: std::get<1>(result) = "CIVZONE_PEN_OPTIONS"; break;
		case 938: std::get<1>(result) = "CIVZONE_POND_OPTIONS"; break;
		case 939: std::get<1>(result) = "CIVZONE_POND_WATER"; break;
		case 940: std::get<1>(result) = "CIVZONE_HOSPITAL_OPTIONS"; break;
		case 941: std::get<1>(result) = "CIVZONE_GATHER_OPTIONS"; break;
		case 942: std::get<1>(result) = "CIVZONE_GATHER_OPTIONS_PICK_TREES"; break;
		case 943: std::get<1>(result) = "CIVZONE_GATHER_OPTIONS_PICK_SHRUBS"; break;
		case 944: std::get<1>(result) = "CIVZONE_GATHER_OPTIONS_GATHER_FALLEN"; break;
		case 945: std::get<1>(result) = "STORES_VIEW"; break;
		case 946: std::get<1>(result) = "STORES_ZOOM"; break;
		case 947: std::get<1>(result) = "STORES_FORBID"; break;
		case 948: std::get<1>(result) = "STORES_MELT"; break;
		case 949: std::get<1>(result) = "STORES_DUMP"; break;
		case 950: std::get<1>(result) = "STORES_HIDE"; break;
		case 951: std::get<1>(result) = "PET_BUTCHER"; break;
		case 952: std::get<1>(result) = "PET_GELD"; break;
		case 953: std::get<1>(result) = "ANIMAL_SELECT_TRAINER"; break;
		case 954: std::get<1>(result) = "ANIMAL_WAR_TRAINING"; break;
		case 955: std::get<1>(result) = "ANIMAL_HUNTING_TRAINING"; break;
		case 956: std::get<1>(result) = "KITCHEN_COOK"; break;
		case 957: std::get<1>(result) = "KITCHEN_BREW"; break;
		case 958: std::get<1>(result) = "ORDERS_AUTOFORBID"; break;
		case 959: std::get<1>(result) = "ORDERS_FORBID_PROJECTILE"; break;
		case 960: std::get<1>(result) = "ORDERS_FORBID_YOUR_CORPSE"; break;
		case 961: std::get<1>(result) = "ORDERS_FORBID_YOUR_ITEMS"; break;
		case 962: std::get<1>(result) = "ORDERS_FORBID_OTHER_CORPSE"; break;
		case 963: std::get<1>(result) = "ORDERS_FORBID_OTHER_ITEMS"; break;
		case 964: std::get<1>(result) = "ORDERS_REFUSE_GATHER"; break;
		case 965: std::get<1>(result) = "ORDERS_REFUSE_OUTSIDE"; break;
		case 966: std::get<1>(result) = "ORDERS_REFUSE_OUTSIDE_VERMIN"; break;
		case 967: std::get<1>(result) = "ORDERS_REFUSE_DUMP_CORPSE"; break;
		case 968: std::get<1>(result) = "ORDERS_REFUSE_DUMP_SKULL"; break;
		case 969: std::get<1>(result) = "ORDERS_REFUSE_DUMP_BONE"; break;
		case 970: std::get<1>(result) = "ORDERS_REFUSE_DUMP_SHELL"; break;
		case 971: std::get<1>(result) = "ORDERS_REFUSE_DUMP_SKIN"; break;
		case 972: std::get<1>(result) = "ORDERS_REFUSE_DUMP_OTHER"; break;
		case 973: std::get<1>(result) = "ORDERS_REFUSE_DUMP_STRAND_TISSUE"; break;
		case 974: std::get<1>(result) = "ORDERS_GATHER_FURNITURE"; break;
		case 975: std::get<1>(result) = "ORDERS_GATHER_ANIMALS"; break;
		case 976: std::get<1>(result) = "ORDERS_GATHER_FOOD"; break;
		case 977: std::get<1>(result) = "ORDERS_GATHER_BODIES"; break;
		case 978: std::get<1>(result) = "ORDERS_REFUSE"; break;
		case 979: std::get<1>(result) = "ORDERS_GATHER_STONE"; break;
		case 980: std::get<1>(result) = "ORDERS_GATHER_WOOD"; break;
		case 981: std::get<1>(result) = "ORDERS_ALL_HARVEST"; break;
		case 982: std::get<1>(result) = "ORDERS_SAMEPILE"; break;
		case 983: std::get<1>(result) = "ORDERS_MIXFOODS"; break;
		case 984: std::get<1>(result) = "ORDERS_LOOM"; break;
		case 985: std::get<1>(result) = "ORDERS_DYED_CLOTH"; break;
		case 986: std::get<1>(result) = "ORDERS_EXCEPTIONS"; break;
		case 987: std::get<1>(result) = "ORDERS_WORKSHOP"; break;
		case 988: std::get<1>(result) = "ORDERS_COLLECT_WEB"; break;
		case 989: std::get<1>(result) = "ORDERS_SLAUGHTER"; break;
		case 990: std::get<1>(result) = "ORDERS_BUTCHER"; break;
		case 991: std::get<1>(result) = "ORDERS_TAN"; break;
		case 992: std::get<1>(result) = "ORDERS_AUTO_FISHERY"; break;
		case 993: std::get<1>(result) = "ORDERS_AUTO_KITCHEN"; break;
		case 994: std::get<1>(result) = "ORDERS_AUTO_KILN"; break;
		case 995: std::get<1>(result) = "ORDERS_AUTO_SMELTER"; break;
		case 996: std::get<1>(result) = "ORDERS_AUTO_OTHER"; break;
		case 997: std::get<1>(result) = "ORDERS_ZONE"; break;
		case 998: std::get<1>(result) = "ORDERS_ZONE_DRINKING"; break;
		case 999: std::get<1>(result) = "ORDERS_ZONE_FISHING"; break;
		case 1000: std::get<1>(result) = "D_ONESTEP"; break;
		case 1001: std::get<1>(result) = "D_PAUSE"; break;
		case 1002: std::get<1>(result) = "D_DEPOT"; break;
		case 1003: std::get<1>(result) = "D_HOT_KEYS"; break;
		case 1004: std::get<1>(result) = "D_HOTKEY1"; break;
		case 1005: std::get<1>(result) = "D_HOTKEY2"; break;
		case 1006: std::get<1>(result) = "D_HOTKEY3"; break;
		case 1007: std::get<1>(result) = "D_HOTKEY4"; break;
		case 1008: std::get<1>(result) = "D_HOTKEY5"; break;
		case 1009: std::get<1>(result) = "D_HOTKEY6"; break;
		case 1010: std::get<1>(result) = "D_HOTKEY7"; break;
		case 1011: std::get<1>(result) = "D_HOTKEY8"; break;
		case 1012: std::get<1>(result) = "D_HOTKEY9"; break;
		case 1013: std::get<1>(result) = "D_HOTKEY10"; break;
		case 1014: std::get<1>(result) = "D_HOTKEY11"; break;
		case 1015: std::get<1>(result) = "D_HOTKEY12"; break;
		case 1016: std::get<1>(result) = "D_HOTKEY13"; break;
		case 1017: std::get<1>(result) = "D_HOTKEY14"; break;
		case 1018: std::get<1>(result) = "D_HOTKEY15"; break;
		case 1019: std::get<1>(result) = "D_HOTKEY16"; break;
		case 1020: std::get<1>(result) = "D_HOTKEY_CHANGE_NAME"; break;
		case 1021: std::get<1>(result) = "D_HOTKEY_ZOOM"; break;
		case 1022: std::get<1>(result) = "D_ANNOUNCE"; break;
		case 1023: std::get<1>(result) = "D_REPORTS"; break;
		case 1024: std::get<1>(result) = "D_BUILDING"; break;
		case 1025: std::get<1>(result) = "D_CIVLIST"; break;
		case 1026: std::get<1>(result) = "D_DESIGNATE"; break;
		case 1027: std::get<1>(result) = "D_ARTLIST"; break;
		case 1028: std::get<1>(result) = "D_NOBLES"; break;
		case 1029: std::get<1>(result) = "D_ORDERS"; break;
		case 1030: std::get<1>(result) = "D_PETITIONS"; break;
		case 1031: std::get<1>(result) = "D_LOCATIONS"; break;
		case 1032: std::get<1>(result) = "D_MILITARY"; break;
		case 1033: std::get<1>(result) = "D_ROOMS"; break;
		case 1034: std::get<1>(result) = "D_SQUADS"; break;
		case 1035: std::get<1>(result) = "D_STOCKPILES"; break;
		case 1036: std::get<1>(result) = "D_CIVZONE"; break;
		case 1037: std::get<1>(result) = "D_VIEWUNIT"; break;
		case 1038: std::get<1>(result) = "D_JOBLIST"; break;
		case 1039: std::get<1>(result) = "D_UNITLIST"; break;
		case 1040: std::get<1>(result) = "D_LOOK"; break;
		case 1041: std::get<1>(result) = "D_HAULING"; break;
		case 1042: std::get<1>(result) = "D_HAULING_NEW_ROUTE"; break;
		case 1043: std::get<1>(result) = "D_HAULING_NEW_STOP"; break;
		case 1044: std::get<1>(result) = "D_HAULING_REMOVE"; break;
		case 1045: std::get<1>(result) = "D_HAULING_PROMOTE"; break;
		case 1046: std::get<1>(result) = "D_HAULING_VEHICLE"; break;
		case 1047: std::get<1>(result) = "D_HAULING_NICKNAME"; break;
		case 1048: std::get<1>(result) = "D_HAULING_STOP_NEW_DEPART"; break;
		case 1049: std::get<1>(result) = "D_HAULING_STOP_NEW_LINK"; break;
		case 1050: std::get<1>(result) = "D_HAULING_STOP_REMOVE"; break;
		case 1051: std::get<1>(result) = "D_HAULING_STOP_SL_SELECT_PILE"; break;
		case 1052: std::get<1>(result) = "D_HAULING_STOP_SL_TAKE_GIVE"; break;
		case 1053: std::get<1>(result) = "D_HAULING_STOP_LC_DIR"; break;
		case 1054: std::get<1>(result) = "D_HAULING_STOP_LC_MODE"; break;
		case 1055: std::get<1>(result) = "D_HAULING_STOP_LC_TIMER_UP"; break;
		case 1056: std::get<1>(result) = "D_HAULING_STOP_LC_TIMER_DOWN"; break;
		case 1057: std::get<1>(result) = "D_HAULING_STOP_LC_FULLNESS_UP"; break;
		case 1058: std::get<1>(result) = "D_HAULING_STOP_LC_FULLNESS_DOWN"; break;
		case 1059: std::get<1>(result) = "D_HAULING_STOP_LC_MORE_LESS"; break;
		case 1060: std::get<1>(result) = "D_HAULING_STOP_LC_DESIRED_TOTAL"; break;
		case 1061: std::get<1>(result) = "D_HAULING_STOP_LC_CHANGE"; break;
		case 1062: std::get<1>(result) = "D_HAULING_STOP_LC_ADVANCED"; break;
		case 1063: std::get<1>(result) = "D_BURROWS"; break;
		case 1064: std::get<1>(result) = "D_BURROWS_ADD"; break;
		case 1065: std::get<1>(result) = "D_BURROWS_DELETE"; break;
		case 1066: std::get<1>(result) = "D_BURROWS_DEFINE"; break;
		case 1067: std::get<1>(result) = "D_BURROWS_ADD_UNIT"; break;
		case 1068: std::get<1>(result) = "D_BURROWS_WORKSHOP_LIMIT"; break;
		case 1069: std::get<1>(result) = "D_BURROWS_CENTER"; break;
		case 1070: std::get<1>(result) = "D_BURROWS_NAME"; break;
		case 1071: std::get<1>(result) = "D_BURROWS_CHANGE_SELECTION"; break;
		case 1072: std::get<1>(result) = "D_BURROWS_BRUSH"; break;
		case 1073: std::get<1>(result) = "D_BURROWS_REMOVE"; break;
		case 1074: std::get<1>(result) = "D_NOTE"; break;
		case 1075: std::get<1>(result) = "D_NOTE_PLACE"; break;
		case 1076: std::get<1>(result) = "D_NOTE_DELETE"; break;
		case 1077: std::get<1>(result) = "D_NOTE_NAME"; break;
		case 1078: std::get<1>(result) = "D_NOTE_ENTER"; break;
		case 1079: std::get<1>(result) = "D_NOTE_ADOPT_SYMBOL"; break;
		case 1080: std::get<1>(result) = "D_NOTE_CHANGE_SELECTION"; break;
		case 1081: std::get<1>(result) = "D_NOTE_POINTS"; break;
		case 1082: std::get<1>(result) = "D_NOTE_ROUTE"; break;
		case 1083: std::get<1>(result) = "D_NOTE_ROUTE_ADD"; break;
		case 1084: std::get<1>(result) = "D_NOTE_ROUTE_EDIT"; break;
		case 1085: std::get<1>(result) = "D_NOTE_ROUTE_DELETE"; break;
		case 1086: std::get<1>(result) = "D_NOTE_ROUTE_CENTER"; break;
		case 1087: std::get<1>(result) = "D_NOTE_ROUTE_NAME"; break;
		case 1088: std::get<1>(result) = "D_BUILDJOB"; break;
		case 1089: std::get<1>(result) = "D_STATUS"; break;
		case 1090: std::get<1>(result) = "D_STATUS_OVERALL_HEALTH_RECENTER"; break;
		case 1091: std::get<1>(result) = "D_BUILDITEM"; break;
		case 1092: std::get<1>(result) = "D_BITEM_FORBID"; break;
		case 1093: std::get<1>(result) = "D_BITEM_DUMP"; break;
		case 1094: std::get<1>(result) = "D_BITEM_MELT"; break;
		case 1095: std::get<1>(result) = "D_BITEM_HIDE"; break;
		case 1096: std::get<1>(result) = "D_BITEM_NAME"; break;
		case 1097: std::get<1>(result) = "D_LOOK_FORBID"; break;
		case 1098: std::get<1>(result) = "D_LOOK_DUMP"; break;
		case 1099: std::get<1>(result) = "D_LOOK_MELT"; break;
		case 1100: std::get<1>(result) = "D_LOOK_HIDE"; break;
		case 1101: std::get<1>(result) = "D_LOOK_FOLLOW"; break;
		case 1102: std::get<1>(result) = "D_LOOK_ARENA_CREATURE"; break;
		case 1103: std::get<1>(result) = "D_LOOK_ARENA_ADV_MODE"; break;
		case 1104: std::get<1>(result) = "D_LOOK_ARENA_WATER"; break;
		case 1105: std::get<1>(result) = "D_LOOK_ARENA_MAGMA"; break;
		case 1106: std::get<1>(result) = "ARENA_CREATURE_SIDE_DOWN"; break;
		case 1107: std::get<1>(result) = "ARENA_CREATURE_SIDE_UP"; break;
		case 1108: std::get<1>(result) = "ARENA_CREATURE_NEW_ITEM"; break;
		case 1109: std::get<1>(result) = "ARENA_CREATURE_BLANK_LIST"; break;
		case 1110: std::get<1>(result) = "ARENA_CREATURE_REMOVE_ITEM"; break;
		case 1111: std::get<1>(result) = "ARENA_CREATURE_UNDEAD"; break;
		case 1112: std::get<1>(result) = "ARENA_CREATURE_STRING"; break;
		case 1113: std::get<1>(result) = "ARENA_CONFLICT_STATE_1"; break;
		case 1114: std::get<1>(result) = "ARENA_CONFLICT_STATE_2"; break;
		case 1115: std::get<1>(result) = "ARENA_MORALE"; break;
		case 1116: std::get<1>(result) = "ARENA_WEATHER"; break;
		case 1117: std::get<1>(result) = "ARENA_WEATHER_SNOW"; break;
		case 1118: std::get<1>(result) = "ARENA_WEATHER_MUD"; break;
		case 1119: std::get<1>(result) = "ARENA_WEATHER_CLEAR_SPATTER"; break;
		case 1120: std::get<1>(result) = "D_LOOK_ARENA_TREE"; break;
		case 1121: std::get<1>(result) = "ARENA_TREE_FILTER"; break;
		case 1122: std::get<1>(result) = "ARENA_TREE_AGE"; break;
		case 1123: std::get<1>(result) = "D_LOOK_ARENA_MOUNT"; break;
		case 1124: std::get<1>(result) = "ASSIGNTRADE_VIEW"; break;
		case 1125: std::get<1>(result) = "ASSIGNTRADE_STRING"; break;
		case 1126: std::get<1>(result) = "ASSIGNTRADE_EXCLUDE_PROHIBITED"; break;
		case 1127: std::get<1>(result) = "ASSIGNTRADE_PENDING"; break;
		case 1128: std::get<1>(result) = "ASSIGNTRADE_SORT"; break;
		case 1129: std::get<1>(result) = "NOBLELIST_REPLACE"; break;
		case 1130: std::get<1>(result) = "NOBLELIST_SETTINGS"; break;
		case 1131: std::get<1>(result) = "NOBLELIST_CAPITAL"; break;
		case 1132: std::get<1>(result) = "NOBLELIST_VIEW_CANDIDATE"; break;
		case 1133: std::get<1>(result) = "TRADE_VIEW"; break;
		case 1134: std::get<1>(result) = "TRADE_TRADE"; break;
		case 1135: std::get<1>(result) = "TRADE_OFFER"; break;
		case 1136: std::get<1>(result) = "TRADE_SEIZE"; break;
		case 1137: std::get<1>(result) = "MILITARY_ACTIVATE"; break;
		case 1138: std::get<1>(result) = "MILITARY_VIEW"; break;
		case 1139: std::get<1>(result) = "MILITARY_WEAPON"; break;
		case 1140: std::get<1>(result) = "MILITARY_ZOOM"; break;
		case 1141: std::get<1>(result) = "ANNOUNCE_ZOOM"; break;
		case 1142: std::get<1>(result) = "ANNOUNCE_ZOOM_2"; break;
		case 1143: std::get<1>(result) = "UNITJOB_REMOVE_CRE"; break;
		case 1144: std::get<1>(result) = "UNITJOB_ZOOM_CRE"; break;
		case 1145: std::get<1>(result) = "UNITJOB_ZOOM_BUILD"; break;
		case 1146: std::get<1>(result) = "UNITJOB_VIEW_UNIT"; break;
		case 1147: std::get<1>(result) = "UNITJOB_VIEW_JOB"; break;
		case 1148: std::get<1>(result) = "UNITJOB_MANAGER"; break;
		case 1149: std::get<1>(result) = "MANAGER_NEW_ORDER"; break;
		case 1150: std::get<1>(result) = "MANAGER_REMOVE"; break;
		case 1151: std::get<1>(result) = "MANAGER_PROMOTE"; break;
		case 1152: std::get<1>(result) = "MANAGER_MAX"; break;
		case 1153: std::get<1>(result) = "MANAGER_WAGES"; break;
		case 1154: std::get<1>(result) = "MANAGER_CONDITIONS"; break;
		case 1155: std::get<1>(result) = "MANAGER_DETAILS"; break;
		case 1156: std::get<1>(result) = "WORK_ORDER_CONDITION_ADD_ITEM"; break;
		case 1157: std::get<1>(result) = "WORK_ORDER_CONDITION_ADD_ORDER"; break;
		case 1158: std::get<1>(result) = "WORK_ORDER_CONDITION_ITEM_TYPE"; break;
		case 1159: std::get<1>(result) = "WORK_ORDER_CONDITION_ITEM_MATERIAL"; break;
		case 1160: std::get<1>(result) = "WORK_ORDER_CONDITION_ITEM_TRAITS"; break;
		case 1161: std::get<1>(result) = "WORK_ORDER_CONDITION_ITEM_INEQUALITY"; break;
		case 1162: std::get<1>(result) = "WORK_ORDER_CONDITION_ITEM_NUMBER"; break;
		case 1163: std::get<1>(result) = "WORK_ORDER_CONDITION_DELETE"; break;
		case 1164: std::get<1>(result) = "WORK_ORDER_CONDITION_ORDER_ACTIVATION"; break;
		case 1165: std::get<1>(result) = "WORK_ORDER_CONDITION_REAGENTS"; break;
		case 1166: std::get<1>(result) = "WORK_ORDER_CONDITION_PRODUCTS"; break;
		case 1167: std::get<1>(result) = "DESIGNATE_BITEM"; break;
		case 1168: std::get<1>(result) = "DESIGNATE_CLAIM"; break;
		case 1169: std::get<1>(result) = "DESIGNATE_UNCLAIM"; break;
		case 1170: std::get<1>(result) = "DESIGNATE_MELT"; break;
		case 1171: std::get<1>(result) = "DESIGNATE_NO_MELT"; break;
		case 1172: std::get<1>(result) = "DESIGNATE_DUMP"; break;
		case 1173: std::get<1>(result) = "DESIGNATE_NO_DUMP"; break;
		case 1174: std::get<1>(result) = "DESIGNATE_HIDE"; break;
		case 1175: std::get<1>(result) = "DESIGNATE_NO_HIDE"; break;
		case 1176: std::get<1>(result) = "DESIGNATE_DIG"; break;
		case 1177: std::get<1>(result) = "DESIGNATE_DIG_REMOVE_STAIRS_RAMPS"; break;
		case 1178: std::get<1>(result) = "DESIGNATE_TRAFFIC"; break;
		case 1179: std::get<1>(result) = "DESIGNATE_TRAFFIC_HIGH"; break;
		case 1180: std::get<1>(result) = "DESIGNATE_TRAFFIC_NORMAL"; break;
		case 1181: std::get<1>(result) = "DESIGNATE_TRAFFIC_LOW"; break;
		case 1182: std::get<1>(result) = "DESIGNATE_TRAFFIC_RESTRICTED"; break;
		case 1183: std::get<1>(result) = "DESIGNATE_TRAFFIC_INCREASE_WEIGHT"; break;
		case 1184: std::get<1>(result) = "DESIGNATE_TRAFFIC_DECREASE_WEIGHT"; break;
		case 1185: std::get<1>(result) = "DESIGNATE_TRAFFIC_INCREASE_WEIGHT_MORE"; break;
		case 1186: std::get<1>(result) = "DESIGNATE_TRAFFIC_DECREASE_WEIGHT_MORE"; break;
		case 1187: std::get<1>(result) = "DESIGNATE_STAIR_UP"; break;
		case 1188: std::get<1>(result) = "DESIGNATE_STAIR_DOWN"; break;
		case 1189: std::get<1>(result) = "DESIGNATE_STAIR_UPDOWN"; break;
		case 1190: std::get<1>(result) = "DESIGNATE_RAMP"; break;
		case 1191: std::get<1>(result) = "DESIGNATE_CHANNEL"; break;
		case 1192: std::get<1>(result) = "DESIGNATE_CHOP"; break;
		case 1193: std::get<1>(result) = "DESIGNATE_PLANTS"; break;
		case 1194: std::get<1>(result) = "DESIGNATE_SMOOTH"; break;
		case 1195: std::get<1>(result) = "DESIGNATE_ENGRAVE"; break;
		case 1196: std::get<1>(result) = "DESIGNATE_DETAILS"; break;
		case 1197: std::get<1>(result) = "DESIGNATE_FORTIFY"; break;
		case 1198: std::get<1>(result) = "DESIGNATE_TRACK"; break;
		case 1199: std::get<1>(result) = "DESIGNATE_TOGGLE_ENGRAVING"; break;
		case 1200: std::get<1>(result) = "DESIGNATE_STANDARD_MARKER"; break;
		case 1201: std::get<1>(result) = "DESIGNATE_MINE_MODE"; break;
		case 1202: std::get<1>(result) = "DESIGNATE_TOGGLE_MARKER"; break;
		case 1203: std::get<1>(result) = "DESIGNATE_UNDO"; break;
		case 1204: std::get<1>(result) = "DESIGNATE_REMOVE_CONSTRUCTION"; break;
		case 1205: std::get<1>(result) = "ITEM_DESCRIPTION"; break;
		case 1206: std::get<1>(result) = "ITEM_FORBID"; break;
		case 1207: std::get<1>(result) = "ITEM_MELT"; break;
		case 1208: std::get<1>(result) = "ITEM_DUMP"; break;
		case 1209: std::get<1>(result) = "ITEM_HIDE"; break;
		case 1210: std::get<1>(result) = "UNITVIEW_CUSTOMIZE"; break;
		case 1211: std::get<1>(result) = "UNITVIEW_HEALTH"; break;
		case 1212: std::get<1>(result) = "UNITVIEW_RELATIONSHIPS"; break;
		case 1213: std::get<1>(result) = "UNITVIEW_RELATIONSHIPS_ZOOM"; break;
		case 1214: std::get<1>(result) = "UNITVIEW_RELATIONSHIPS_VIEW"; break;
		case 1215: std::get<1>(result) = "UNITVIEW_KILLS"; break;
		case 1216: std::get<1>(result) = "UNITVIEW_GEN"; break;
		case 1217: std::get<1>(result) = "UNITVIEW_INV"; break;
		case 1218: std::get<1>(result) = "UNITVIEW_PRF"; break;
		case 1219: std::get<1>(result) = "UNITVIEW_WND"; break;
		case 1220: std::get<1>(result) = "UNITVIEW_FOLLOW"; break;
		case 1221: std::get<1>(result) = "UNITVIEW_NEXT"; break;
		case 1222: std::get<1>(result) = "UNITVIEW_SLAUGHTER"; break;
		case 1223: std::get<1>(result) = "UNITVIEW_GELD"; break;
		case 1224: std::get<1>(result) = "UNITVIEW_GEN_COMBAT"; break;
		case 1225: std::get<1>(result) = "UNITVIEW_GEN_LABOR"; break;
		case 1226: std::get<1>(result) = "UNITVIEW_GEN_MISC"; break;
		case 1227: std::get<1>(result) = "UNITVIEW_PRF_PROF"; break;
		case 1228: std::get<1>(result) = "UNITVIEW_PRF_PET"; break;
		case 1229: std::get<1>(result) = "UNITVIEW_PRF_EXPEL"; break;
		case 1230: std::get<1>(result) = "UNITVIEW_PRF_VIEW"; break;
		case 1231: std::get<1>(result) = "UNITVIEW_PRF_NEW_SQUAD"; break;
		case 1232: std::get<1>(result) = "UNITVIEW_PRF_REMOVE_FROM_SQUAD"; break;
		case 1233: std::get<1>(result) = "UNITVIEW_PRF_NAME_CURRENT_SQUAD"; break;
		case 1234: std::get<1>(result) = "UNITVIEW_PRF_NAME_SELECTED_SQUAD"; break;
		case 1235: std::get<1>(result) = "UNITVIEW_PRF_OCCUPATION"; break;
		case 1236: std::get<1>(result) = "CUSTOMIZE_UNIT_NICKNAME"; break;
		case 1237: std::get<1>(result) = "CUSTOMIZE_UNIT_PROFNAME"; break;
		case 1238: std::get<1>(result) = "IMAGE_CREATOR_FILTER"; break;
		case 1239: std::get<1>(result) = "IMAGE_CREATOR_NAME"; break;
		case 1240: std::get<1>(result) = "IMAGE_CREATOR_DONE"; break;
		case 1241: std::get<1>(result) = "CIV_RAID"; break;
		case 1242: std::get<1>(result) = "CIV_CENTER_ON_FORT"; break;
		case 1243: std::get<1>(result) = "CIV_HOLDINGS"; break;
		case 1244: std::get<1>(result) = "CIV_MAP_LEGEND"; break;
		case 1245: std::get<1>(result) = "CIV_REMOVE_MISSION"; break;
		case 1246: std::get<1>(result) = "CIV_RESCUE"; break;
		case 1247: std::get<1>(result) = "CIV_RECOVER"; break;
		case 1248: std::get<1>(result) = "CIV_WORLD"; break;
		case 1249: std::get<1>(result) = "CIV_MISSIONS"; break;
		case 1250: std::get<1>(result) = "CIV_MISSION_DETAILS"; break;
		case 1251: std::get<1>(result) = "CIV_MISSION_FREE_CAPTIVES"; break;
		case 1252: std::get<1>(result) = "CIV_MISSION_RELEASE_OTHERS"; break;
		case 1253: std::get<1>(result) = "CIV_MISSION_TAKE_ARTIFACTS"; break;
		case 1254: std::get<1>(result) = "CIV_MISSION_TAKE_ITEMS"; break;
		case 1255: std::get<1>(result) = "CIV_MISSION_TAKE_LIVESTOCK"; break;
		case 1256: std::get<1>(result) = "CIV_MISSION_RAID"; break;
		case 1257: std::get<1>(result) = "CIV_MISSION_PILLAGE"; break;
		case 1258: std::get<1>(result) = "CIV_MISSION_RAZE"; break;
		case 1259: std::get<1>(result) = "CIV_MISSION_TRIBUTE_ONE_TIME"; break;
		case 1260: std::get<1>(result) = "CIV_MISSION_TRIBUTE_ONGOING"; break;
		case 1261: std::get<1>(result) = "CIV_MISSION_CONQUER"; break;
		case 1262: std::get<1>(result) = "CIV_MISSION_DEMAND_SURRENDER"; break;
		case 1263: std::get<1>(result) = "CIV_NEWS"; break;
		case 1264: std::get<1>(result) = "CIV_PEOPLE"; break;
		case 1265: std::get<1>(result) = "CIV_ARTIFACTS"; break;
		case 1266: std::get<1>(result) = "CIV_CIVS"; break;
		case 1267: std::get<1>(result) = "D_MILITARY_CREATE_SQUAD"; break;
		case 1268: std::get<1>(result) = "D_MILITARY_DISBAND_SQUAD"; break;
		case 1269: std::get<1>(result) = "D_MILITARY_CREATE_SUB_SQUAD"; break;
		case 1270: std::get<1>(result) = "D_MILITARY_CANCEL_ORDERS"; break;
		case 1271: std::get<1>(result) = "D_MILITARY_POSITIONS"; break;
		case 1272: std::get<1>(result) = "D_MILITARY_ALERTS"; break;
		case 1273: std::get<1>(result) = "D_MILITARY_ALERTS_ADD"; break;
		case 1274: std::get<1>(result) = "D_MILITARY_ALERTS_DELETE"; break;
		case 1275: std::get<1>(result) = "D_MILITARY_ALERTS_SET"; break;
		case 1276: std::get<1>(result) = "D_MILITARY_ALERTS_NAME"; break;
		case 1277: std::get<1>(result) = "D_MILITARY_ALERTS_SET_RETAIN"; break;
		case 1278: std::get<1>(result) = "D_MILITARY_EQUIP"; break;
		case 1279: std::get<1>(result) = "D_MILITARY_EQUIP_CUSTOMIZE"; break;
		case 1280: std::get<1>(result) = "D_MILITARY_EQUIP_UNIFORM"; break;
		case 1281: std::get<1>(result) = "D_MILITARY_EQUIP_PRIORITY"; break;
		case 1282: std::get<1>(result) = "D_MILITARY_UNIFORMS"; break;
		case 1283: std::get<1>(result) = "D_MILITARY_SUPPLIES"; break;
		case 1284: std::get<1>(result) = "D_MILITARY_SUPPLIES_WATER_DOWN"; break;
		case 1285: std::get<1>(result) = "D_MILITARY_SUPPLIES_WATER_UP"; break;
		case 1286: std::get<1>(result) = "D_MILITARY_SUPPLIES_FOOD_DOWN"; break;
		case 1287: std::get<1>(result) = "D_MILITARY_SUPPLIES_FOOD_UP"; break;
		case 1288: std::get<1>(result) = "D_MILITARY_AMMUNITION"; break;
		case 1289: std::get<1>(result) = "D_MILITARY_AMMUNITION_ADD_ITEM"; break;
		case 1290: std::get<1>(result) = "D_MILITARY_AMMUNITION_REMOVE_ITEM"; break;
		case 1291: std::get<1>(result) = "D_MILITARY_AMMUNITION_LOWER_AMOUNT"; break;
		case 1292: std::get<1>(result) = "D_MILITARY_AMMUNITION_RAISE_AMOUNT"; break;
		case 1293: std::get<1>(result) = "D_MILITARY_AMMUNITION_LOWER_AMOUNT_LOTS"; break;
		case 1294: std::get<1>(result) = "D_MILITARY_AMMUNITION_RAISE_AMOUNT_LOTS"; break;
		case 1295: std::get<1>(result) = "D_MILITARY_AMMUNITION_MATERIAL"; break;
		case 1296: std::get<1>(result) = "D_MILITARY_AMMUNITION_COMBAT"; break;
		case 1297: std::get<1>(result) = "D_MILITARY_AMMUNITION_TRAINING"; break;
		case 1298: std::get<1>(result) = "D_MILITARY_TRAINING"; break;
		case 1299: std::get<1>(result) = "D_MILITARY_SCHEDULE"; break;
		case 1300: std::get<1>(result) = "D_MILITARY_ADD_UNIFORM"; break;
		case 1301: std::get<1>(result) = "D_MILITARY_DELETE_UNIFORM"; break;
		case 1302: std::get<1>(result) = "D_MILITARY_NAME_UNIFORM"; break;
		case 1303: std::get<1>(result) = "D_MILITARY_NAME_SQUAD"; break;
		case 1304: std::get<1>(result) = "D_MILITARY_ADD_ARMOR"; break;
		case 1305: std::get<1>(result) = "D_MILITARY_ADD_PANTS"; break;
		case 1306: std::get<1>(result) = "D_MILITARY_ADD_HELM"; break;
		case 1307: std::get<1>(result) = "D_MILITARY_ADD_GLOVES"; break;
		case 1308: std::get<1>(result) = "D_MILITARY_ADD_BOOTS"; break;
		case 1309: std::get<1>(result) = "D_MILITARY_ADD_SHIELD"; break;
		case 1310: std::get<1>(result) = "D_MILITARY_ADD_WEAPON"; break;
		case 1311: std::get<1>(result) = "D_MILITARY_ADD_MATERIAL"; break;
		case 1312: std::get<1>(result) = "D_MILITARY_ADD_COLOR"; break;
		case 1313: std::get<1>(result) = "D_MILITARY_REPLACE_CLOTHING"; break;
		case 1314: std::get<1>(result) = "D_MILITARY_EXACT_MATCH"; break;
		case 1315: std::get<1>(result) = "D_SQUADS_MOVE"; break;
		case 1316: std::get<1>(result) = "D_SQUADS_KILL"; break;
		case 1317: std::get<1>(result) = "D_SQUADS_KILL_LIST"; break;
		case 1318: std::get<1>(result) = "D_SQUADS_KILL_RECT"; break;
		case 1319: std::get<1>(result) = "D_SQUADS_SCHEDULE"; break;
		case 1320: std::get<1>(result) = "D_SQUADS_CANCEL_ORDER"; break;
		case 1321: std::get<1>(result) = "D_SQUADS_ALERT"; break;
		case 1322: std::get<1>(result) = "D_SQUADS_SELECT_INDIVIDUALS"; break;
		case 1323: std::get<1>(result) = "D_SQUADS_CENTER"; break;
		case 1324: std::get<1>(result) = "D_SQUAD_SCH_SLEEP"; break;
		case 1325: std::get<1>(result) = "D_SQUAD_SCH_CIVILIAN_UNIFORM"; break;
		case 1326: std::get<1>(result) = "D_SQUAD_SCH_GIVE_ORDER"; break;
		case 1327: std::get<1>(result) = "D_SQUAD_SCH_EDIT_ORDER"; break;
		case 1328: std::get<1>(result) = "D_SQUAD_SCH_CANCEL_ORDER"; break;
		case 1329: std::get<1>(result) = "D_SQUAD_SCH_COPY_ORDERS"; break;
		case 1330: std::get<1>(result) = "D_SQUAD_SCH_PASTE_ORDERS"; break;
		case 1331: std::get<1>(result) = "D_SQUAD_SCH_MS_NAME"; break;
		case 1332: std::get<1>(result) = "STRING_A000"; break;
		case 1333: std::get<1>(result) = "STRING_A001"; break;
		case 1334: std::get<1>(result) = "STRING_A002"; break;
		case 1335: std::get<1>(result) = "STRING_A003"; break;
		case 1336: std::get<1>(result) = "STRING_A004"; break;
		case 1337: std::get<1>(result) = "STRING_A005"; break;
		case 1338: std::get<1>(result) = "STRING_A006"; break;
		case 1339: std::get<1>(result) = "STRING_A007"; break;
		case 1340: std::get<1>(result) = "STRING_A008"; break;
		case 1341: std::get<1>(result) = "STRING_A009"; break;
		case 1342: std::get<1>(result) = "STRING_A010"; break;
		case 1343: std::get<1>(result) = "STRING_A011"; break;
		case 1344: std::get<1>(result) = "STRING_A012"; break;
		case 1345: std::get<1>(result) = "STRING_A013"; break;
		case 1346: std::get<1>(result) = "STRING_A014"; break;
		case 1347: std::get<1>(result) = "STRING_A015"; break;
		case 1348: std::get<1>(result) = "STRING_A016"; break;
		case 1349: std::get<1>(result) = "STRING_A017"; break;
		case 1350: std::get<1>(result) = "STRING_A018"; break;
		case 1351: std::get<1>(result) = "STRING_A019"; break;
		case 1352: std::get<1>(result) = "STRING_A020"; break;
		case 1353: std::get<1>(result) = "STRING_A021"; break;
		case 1354: std::get<1>(result) = "STRING_A022"; break;
		case 1355: std::get<1>(result) = "STRING_A023"; break;
		case 1356: std::get<1>(result) = "STRING_A024"; break;
		case 1357: std::get<1>(result) = "STRING_A025"; break;
		case 1358: std::get<1>(result) = "STRING_A026"; break;
		case 1359: std::get<1>(result) = "STRING_A027"; break;
		case 1360: std::get<1>(result) = "STRING_A028"; break;
		case 1361: std::get<1>(result) = "STRING_A029"; break;
		case 1362: std::get<1>(result) = "STRING_A030"; break;
		case 1363: std::get<1>(result) = "STRING_A031"; break;
		case 1364: std::get<1>(result) = "STRING_A032"; break;
		case 1365: std::get<1>(result) = "STRING_A033"; break;
		case 1366: std::get<1>(result) = "STRING_A034"; break;
		case 1367: std::get<1>(result) = "STRING_A035"; break;
		case 1368: std::get<1>(result) = "STRING_A036"; break;
		case 1369: std::get<1>(result) = "STRING_A037"; break;
		case 1370: std::get<1>(result) = "STRING_A038"; break;
		case 1371: std::get<1>(result) = "STRING_A039"; break;
		case 1372: std::get<1>(result) = "STRING_A040"; break;
		case 1373: std::get<1>(result) = "STRING_A041"; break;
		case 1374: std::get<1>(result) = "STRING_A042"; break;
		case 1375: std::get<1>(result) = "STRING_A043"; break;
		case 1376: std::get<1>(result) = "STRING_A044"; break;
		case 1377: std::get<1>(result) = "STRING_A045"; break;
		case 1378: std::get<1>(result) = "STRING_A046"; break;
		case 1379: std::get<1>(result) = "STRING_A047"; break;
		case 1380: std::get<1>(result) = "STRING_A048"; break;
		case 1381: std::get<1>(result) = "STRING_A049"; break;
		case 1382: std::get<1>(result) = "STRING_A050"; break;
		case 1383: std::get<1>(result) = "STRING_A051"; break;
		case 1384: std::get<1>(result) = "STRING_A052"; break;
		case 1385: std::get<1>(result) = "STRING_A053"; break;
		case 1386: std::get<1>(result) = "STRING_A054"; break;
		case 1387: std::get<1>(result) = "STRING_A055"; break;
		case 1388: std::get<1>(result) = "STRING_A056"; break;
		case 1389: std::get<1>(result) = "STRING_A057"; break;
		case 1390: std::get<1>(result) = "STRING_A058"; break;
		case 1391: std::get<1>(result) = "STRING_A059"; break;
		case 1392: std::get<1>(result) = "STRING_A060"; break;
		case 1393: std::get<1>(result) = "STRING_A061"; break;
		case 1394: std::get<1>(result) = "STRING_A062"; break;
		case 1395: std::get<1>(result) = "STRING_A063"; break;
		case 1396: std::get<1>(result) = "STRING_A064"; break;
		case 1397: std::get<1>(result) = "STRING_A065"; break;
		case 1398: std::get<1>(result) = "STRING_A066"; break;
		case 1399: std::get<1>(result) = "STRING_A067"; break;
		case 1400: std::get<1>(result) = "STRING_A068"; break;
		case 1401: std::get<1>(result) = "STRING_A069"; break;
		case 1402: std::get<1>(result) = "STRING_A070"; break;
		case 1403: std::get<1>(result) = "STRING_A071"; break;
		case 1404: std::get<1>(result) = "STRING_A072"; break;
		case 1405: std::get<1>(result) = "STRING_A073"; break;
		case 1406: std::get<1>(result) = "STRING_A074"; break;
		case 1407: std::get<1>(result) = "STRING_A075"; break;
		case 1408: std::get<1>(result) = "STRING_A076"; break;
		case 1409: std::get<1>(result) = "STRING_A077"; break;
		case 1410: std::get<1>(result) = "STRING_A078"; break;
		case 1411: std::get<1>(result) = "STRING_A079"; break;
		case 1412: std::get<1>(result) = "STRING_A080"; break;
		case 1413: std::get<1>(result) = "STRING_A081"; break;
		case 1414: std::get<1>(result) = "STRING_A082"; break;
		case 1415: std::get<1>(result) = "STRING_A083"; break;
		case 1416: std::get<1>(result) = "STRING_A084"; break;
		case 1417: std::get<1>(result) = "STRING_A085"; break;
		case 1418: std::get<1>(result) = "STRING_A086"; break;
		case 1419: std::get<1>(result) = "STRING_A087"; break;
		case 1420: std::get<1>(result) = "STRING_A088"; break;
		case 1421: std::get<1>(result) = "STRING_A089"; break;
		case 1422: std::get<1>(result) = "STRING_A090"; break;
		case 1423: std::get<1>(result) = "STRING_A091"; break;
		case 1424: std::get<1>(result) = "STRING_A092"; break;
		case 1425: std::get<1>(result) = "STRING_A093"; break;
		case 1426: std::get<1>(result) = "STRING_A094"; break;
		case 1427: std::get<1>(result) = "STRING_A095"; break;
		case 1428: std::get<1>(result) = "STRING_A096"; break;
		case 1429: std::get<1>(result) = "STRING_A097"; break;
		case 1430: std::get<1>(result) = "STRING_A098"; break;
		case 1431: std::get<1>(result) = "STRING_A099"; break;
		case 1432: std::get<1>(result) = "STRING_A100"; break;
		case 1433: std::get<1>(result) = "STRING_A101"; break;
		case 1434: std::get<1>(result) = "STRING_A102"; break;
		case 1435: std::get<1>(result) = "STRING_A103"; break;
		case 1436: std::get<1>(result) = "STRING_A104"; break;
		case 1437: std::get<1>(result) = "STRING_A105"; break;
		case 1438: std::get<1>(result) = "STRING_A106"; break;
		case 1439: std::get<1>(result) = "STRING_A107"; break;
		case 1440: std::get<1>(result) = "STRING_A108"; break;
		case 1441: std::get<1>(result) = "STRING_A109"; break;
		case 1442: std::get<1>(result) = "STRING_A110"; break;
		case 1443: std::get<1>(result) = "STRING_A111"; break;
		case 1444: std::get<1>(result) = "STRING_A112"; break;
		case 1445: std::get<1>(result) = "STRING_A113"; break;
		case 1446: std::get<1>(result) = "STRING_A114"; break;
		case 1447: std::get<1>(result) = "STRING_A115"; break;
		case 1448: std::get<1>(result) = "STRING_A116"; break;
		case 1449: std::get<1>(result) = "STRING_A117"; break;
		case 1450: std::get<1>(result) = "STRING_A118"; break;
		case 1451: std::get<1>(result) = "STRING_A119"; break;
		case 1452: std::get<1>(result) = "STRING_A120"; break;
		case 1453: std::get<1>(result) = "STRING_A121"; break;
		case 1454: std::get<1>(result) = "STRING_A122"; break;
		case 1455: std::get<1>(result) = "STRING_A123"; break;
		case 1456: std::get<1>(result) = "STRING_A124"; break;
		case 1457: std::get<1>(result) = "STRING_A125"; break;
		case 1458: std::get<1>(result) = "STRING_A126"; break;
		case 1459: std::get<1>(result) = "STRING_A128"; break;
		case 1460: std::get<1>(result) = "STRING_A129"; break;
		case 1461: std::get<1>(result) = "STRING_A130"; break;
		case 1462: std::get<1>(result) = "STRING_A131"; break;
		case 1463: std::get<1>(result) = "STRING_A132"; break;
		case 1464: std::get<1>(result) = "STRING_A133"; break;
		case 1465: std::get<1>(result) = "STRING_A134"; break;
		case 1466: std::get<1>(result) = "STRING_A135"; break;
		case 1467: std::get<1>(result) = "STRING_A136"; break;
		case 1468: std::get<1>(result) = "STRING_A137"; break;
		case 1469: std::get<1>(result) = "STRING_A138"; break;
		case 1470: std::get<1>(result) = "STRING_A139"; break;
		case 1471: std::get<1>(result) = "STRING_A140"; break;
		case 1472: std::get<1>(result) = "STRING_A141"; break;
		case 1473: std::get<1>(result) = "STRING_A142"; break;
		case 1474: std::get<1>(result) = "STRING_A143"; break;
		case 1475: std::get<1>(result) = "STRING_A144"; break;
		case 1476: std::get<1>(result) = "STRING_A145"; break;
		case 1477: std::get<1>(result) = "STRING_A146"; break;
		case 1478: std::get<1>(result) = "STRING_A147"; break;
		case 1479: std::get<1>(result) = "STRING_A148"; break;
		case 1480: std::get<1>(result) = "STRING_A149"; break;
		case 1481: std::get<1>(result) = "STRING_A150"; break;
		case 1482: std::get<1>(result) = "STRING_A151"; break;
		case 1483: std::get<1>(result) = "STRING_A152"; break;
		case 1484: std::get<1>(result) = "STRING_A153"; break;
		case 1485: std::get<1>(result) = "STRING_A154"; break;
		case 1486: std::get<1>(result) = "STRING_A155"; break;
		case 1487: std::get<1>(result) = "STRING_A156"; break;
		case 1488: std::get<1>(result) = "STRING_A157"; break;
		case 1489: std::get<1>(result) = "STRING_A158"; break;
		case 1490: std::get<1>(result) = "STRING_A159"; break;
		case 1491: std::get<1>(result) = "STRING_A160"; break;
		case 1492: std::get<1>(result) = "STRING_A161"; break;
		case 1493: std::get<1>(result) = "STRING_A162"; break;
		case 1494: std::get<1>(result) = "STRING_A163"; break;
		case 1495: std::get<1>(result) = "STRING_A164"; break;
		case 1496: std::get<1>(result) = "STRING_A165"; break;
		case 1497: std::get<1>(result) = "STRING_A166"; break;
		case 1498: std::get<1>(result) = "STRING_A167"; break;
		case 1499: std::get<1>(result) = "STRING_A168"; break;
		case 1500: std::get<1>(result) = "STRING_A169"; break;
		case 1501: std::get<1>(result) = "STRING_A170"; break;
		case 1502: std::get<1>(result) = "STRING_A171"; break;
		case 1503: std::get<1>(result) = "STRING_A172"; break;
		case 1504: std::get<1>(result) = "STRING_A173"; break;
		case 1505: std::get<1>(result) = "STRING_A174"; break;
		case 1506: std::get<1>(result) = "STRING_A175"; break;
		case 1507: std::get<1>(result) = "STRING_A176"; break;
		case 1508: std::get<1>(result) = "STRING_A177"; break;
		case 1509: std::get<1>(result) = "STRING_A178"; break;
		case 1510: std::get<1>(result) = "STRING_A179"; break;
		case 1511: std::get<1>(result) = "STRING_A180"; break;
		case 1512: std::get<1>(result) = "STRING_A181"; break;
		case 1513: std::get<1>(result) = "STRING_A182"; break;
		case 1514: std::get<1>(result) = "STRING_A183"; break;
		case 1515: std::get<1>(result) = "STRING_A184"; break;
		case 1516: std::get<1>(result) = "STRING_A185"; break;
		case 1517: std::get<1>(result) = "STRING_A186"; break;
		case 1518: std::get<1>(result) = "STRING_A187"; break;
		case 1519: std::get<1>(result) = "STRING_A188"; break;
		case 1520: std::get<1>(result) = "STRING_A189"; break;
		case 1521: std::get<1>(result) = "STRING_A190"; break;
		case 1522: std::get<1>(result) = "STRING_A191"; break;
		case 1523: std::get<1>(result) = "STRING_A192"; break;
		case 1524: std::get<1>(result) = "STRING_A193"; break;
		case 1525: std::get<1>(result) = "STRING_A194"; break;
		case 1526: std::get<1>(result) = "STRING_A195"; break;
		case 1527: std::get<1>(result) = "STRING_A196"; break;
		case 1528: std::get<1>(result) = "STRING_A197"; break;
		case 1529: std::get<1>(result) = "STRING_A198"; break;
		case 1530: std::get<1>(result) = "STRING_A199"; break;
		case 1531: std::get<1>(result) = "STRING_A200"; break;
		case 1532: std::get<1>(result) = "STRING_A201"; break;
		case 1533: std::get<1>(result) = "STRING_A202"; break;
		case 1534: std::get<1>(result) = "STRING_A203"; break;
		case 1535: std::get<1>(result) = "STRING_A204"; break;
		case 1536: std::get<1>(result) = "STRING_A205"; break;
		case 1537: std::get<1>(result) = "STRING_A206"; break;
		case 1538: std::get<1>(result) = "STRING_A207"; break;
		case 1539: std::get<1>(result) = "STRING_A208"; break;
		case 1540: std::get<1>(result) = "STRING_A209"; break;
		case 1541: std::get<1>(result) = "STRING_A210"; break;
		case 1542: std::get<1>(result) = "STRING_A211"; break;
		case 1543: std::get<1>(result) = "STRING_A212"; break;
		case 1544: std::get<1>(result) = "STRING_A213"; break;
		case 1545: std::get<1>(result) = "STRING_A214"; break;
		case 1546: std::get<1>(result) = "STRING_A215"; break;
		case 1547: std::get<1>(result) = "STRING_A216"; break;
		case 1548: std::get<1>(result) = "STRING_A217"; break;
		case 1549: std::get<1>(result) = "STRING_A218"; break;
		case 1550: std::get<1>(result) = "STRING_A219"; break;
		case 1551: std::get<1>(result) = "STRING_A220"; break;
		case 1552: std::get<1>(result) = "STRING_A221"; break;
		case 1553: std::get<1>(result) = "STRING_A222"; break;
		case 1554: std::get<1>(result) = "STRING_A223"; break;
		case 1555: std::get<1>(result) = "STRING_A224"; break;
		case 1556: std::get<1>(result) = "STRING_A225"; break;
		case 1557: std::get<1>(result) = "STRING_A226"; break;
		case 1558: std::get<1>(result) = "STRING_A227"; break;
		case 1559: std::get<1>(result) = "STRING_A228"; break;
		case 1560: std::get<1>(result) = "STRING_A229"; break;
		case 1561: std::get<1>(result) = "STRING_A230"; break;
		case 1562: std::get<1>(result) = "STRING_A231"; break;
		case 1563: std::get<1>(result) = "STRING_A232"; break;
		case 1564: std::get<1>(result) = "STRING_A233"; break;
		case 1565: std::get<1>(result) = "STRING_A234"; break;
		case 1566: std::get<1>(result) = "STRING_A235"; break;
		case 1567: std::get<1>(result) = "STRING_A236"; break;
		case 1568: std::get<1>(result) = "STRING_A237"; break;
		case 1569: std::get<1>(result) = "STRING_A238"; break;
		case 1570: std::get<1>(result) = "STRING_A239"; break;
		case 1571: std::get<1>(result) = "STRING_A240"; break;
		case 1572: std::get<1>(result) = "STRING_A241"; break;
		case 1573: std::get<1>(result) = "STRING_A242"; break;
		case 1574: std::get<1>(result) = "STRING_A243"; break;
		case 1575: std::get<1>(result) = "STRING_A244"; break;
		case 1576: std::get<1>(result) = "STRING_A245"; break;
		case 1577: std::get<1>(result) = "STRING_A246"; break;
		case 1578: std::get<1>(result) = "STRING_A247"; break;
		case 1579: std::get<1>(result) = "STRING_A248"; break;
		case 1580: std::get<1>(result) = "STRING_A249"; break;
		case 1581: std::get<1>(result) = "STRING_A250"; break;
		case 1582: std::get<1>(result) = "STRING_A251"; break;
		case 1583: std::get<1>(result) = "STRING_A252"; break;
		case 1584: std::get<1>(result) = "STRING_A253"; break;
		case 1585: std::get<1>(result) = "STRING_A254"; break;
		case 1586: std::get<1>(result) = "STRING_A255"; break;
		case 1587: std::get<1>(result) = "KEYBINDING_COMPLETE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_dfhack_knowledge_scholar_flag_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "philosophy_logic_formal_reasoning"; break;
		case 1: std::get<1>(result) = "philosophy_logic_deductive_reasoning"; break;
		case 2: std::get<1>(result) = "philosophy_logic_syllogistic_logic"; break;
		case 3: std::get<1>(result) = "philosophy_logic_hypothetical_syllogisms"; break;
		case 4: std::get<1>(result) = "philosophy_logic_propositional_logic"; break;
		case 5: std::get<1>(result) = "philosophy_logic_dialectic_reasoning"; break;
		case 6: std::get<1>(result) = "philosophy_logic_analogical_inference"; break;
		case 7: std::get<1>(result) = "philosophy_ethics_applied_medical"; break;
		case 8: std::get<1>(result) = "philosophy_ethics_individual_value"; break;
		case 9: std::get<1>(result) = "philosophy_ethics_state_consequentialism"; break;
		case 10: std::get<1>(result) = "philosophy_epistemology_truth"; break;
		case 11: std::get<1>(result) = "philosophy_epistemology_perception"; break;
		case 12: std::get<1>(result) = "philosophy_epistemology_justification"; break;
		case 13: std::get<1>(result) = "philosophy_epistemology_belief"; break;
		case 14: std::get<1>(result) = "philosophy_metaphysics_existence"; break;
		case 15: std::get<1>(result) = "philosophy_metaphysics_time"; break;
		case 16: std::get<1>(result) = "philosophy_metaphysics_mind_body"; break;
		case 17: std::get<1>(result) = "philosophy_metaphysics_objects_and_properties"; break;
		case 18: std::get<1>(result) = "philosophy_metaphysics_wholes_and_parts"; break;
		case 19: std::get<1>(result) = "philosophy_metaphysics_events"; break;
		case 20: std::get<1>(result) = "philosophy_metaphysics_processes"; break;
		case 21: std::get<1>(result) = "philosophy_metaphysics_causation"; break;
		case 22: std::get<1>(result) = "philosophy_ethics_applied_military"; break;
		case 23: std::get<1>(result) = "philosophy_ethics_applied_interpersonal_conduct"; break;
		case 24: std::get<1>(result) = "philosophy_specialized_law"; break;
		case 25: std::get<1>(result) = "philosophy_specialized_education"; break;
		case 26: std::get<1>(result) = "philosophy_specialized_language_grammar"; break;
		case 27: std::get<1>(result) = "philosophy_specialized_language_etymology"; break;
		case 28: std::get<1>(result) = "philosophy_specialized_politics_diplomacy"; break;
		case 29: std::get<1>(result) = "philosophy_specialized_politics_government_forms"; break;
		case 30: std::get<1>(result) = "philosophy_specialized_politics_economic_policy"; break;
		case 31: std::get<1>(result) = "philosophy_specialized_politics_social_welfare"; break;
		case 32: std::get<1>(result) = "philosophy_logic_inductive_reasoning"; break;
		case 33: std::get<1>(result) = "philosophy_logic_direct_inference"; break;
		case 34: std::get<1>(result) = "philosophy_aesthetics_nature_of_beauty"; break;
		case 35: std::get<1>(result) = "philosophy_aesthetics_value_of_art"; break;
		case 36: std::get<1>(result) = "philosophy_specialized_language_dictionary"; break;
		case 64: std::get<1>(result) = "mathematics_method_proof_by_contradiction"; break;
		case 65: std::get<1>(result) = "mathematics_notation_zero"; break;
		case 66: std::get<1>(result) = "mathematics_notation_negative_numbers"; break;
		case 67: std::get<1>(result) = "mathematics_notation_large_numbers"; break;
		case 68: std::get<1>(result) = "mathematics_notation_positional"; break;
		case 69: std::get<1>(result) = "mathematics_geometry_basic_objects"; break;
		case 70: std::get<1>(result) = "mathematics_method_exhaustion"; break;
		case 71: std::get<1>(result) = "mathematics_geometry_similar_and_congruent_triangles"; break;
		case 72: std::get<1>(result) = "mathematics_geometry_geometric_mean_theorem"; break;
		case 73: std::get<1>(result) = "mathematics_geometry_isosceles_base_angles_equal"; break;
		case 74: std::get<1>(result) = "mathematics_geometry_inscribed_triangle_on_diameter_is_right"; break;
		case 75: std::get<1>(result) = "mathematics_geometry_pythagorean_theorem"; break;
		case 76: std::get<1>(result) = "mathematics_geometry_pythagorean_triples_small"; break;
		case 77: std::get<1>(result) = "mathematics_geometry_pythagorean_triples_3_digit"; break;
		case 78: std::get<1>(result) = "mathematics_geometry_pythagorean_triples_4_digit"; break;
		case 79: std::get<1>(result) = "mathematics_geometry_existence_of_incommensurable_ratios"; break;
		case 80: std::get<1>(result) = "mathematics_method_axiomatic_reasoning"; break;
		case 81: std::get<1>(result) = "mathematics_numbers_unique_prime_factorization"; break;
		case 82: std::get<1>(result) = "mathematics_numbers_algorithm_for_computing_gcd"; break;
		case 83: std::get<1>(result) = "mathematics_geometry_volume_of_pyramid"; break;
		case 84: std::get<1>(result) = "mathematics_geometry_volume_of_cone"; break;
		case 85: std::get<1>(result) = "mathematics_geometry_volume_of_sphere"; break;
		case 86: std::get<1>(result) = "mathematics_geometry_pi_to_4_digits"; break;
		case 87: std::get<1>(result) = "mathematics_numbers_division_algorithm"; break;
		case 88: std::get<1>(result) = "mathematics_geometry_table_of_chord_values"; break;
		case 89: std::get<1>(result) = "mathematics_geometry_area_of_triangle_from_side_lengths"; break;
		case 90: std::get<1>(result) = "mathematics_geometry_area_of_circle"; break;
		case 91: std::get<1>(result) = "mathematics_geometry_pi_to_6_digits"; break;
		case 92: std::get<1>(result) = "mathematics_geometry_definitions_and_basic_properties_of_conic_sections"; break;
		case 93: std::get<1>(result) = "mathematics_numbers_chinese_remainder_algorithm"; break;
		case 94: std::get<1>(result) = "mathematics_geometry_area_enclosed_by_line_and_parabola"; break;
		case 95: std::get<1>(result) = "mathematics_numbers_sieve_algorithm_for_primes"; break;
		case 96: std::get<1>(result) = "mathematics_numbers_root_2_to_5_digits"; break;
		case 97: std::get<1>(result) = "mathematics_numbers_infinite_primes"; break;
		case 98: std::get<1>(result) = "mathematics_numbers_root_2_irrational"; break;
		case 99: std::get<1>(result) = "mathematics_geometry_surface_area_of_sphere"; break;
		case 100: std::get<1>(result) = "mathematics_algebra_finite_summation_formulas"; break;
		case 101: std::get<1>(result) = "mathematics_algebra_solving_linear_systems"; break;
		case 102: std::get<1>(result) = "mathematics_algebra_balancing_and_completion"; break;
		case 103: std::get<1>(result) = "mathematics_algebra_quadratic_by_completing_square"; break;
		case 104: std::get<1>(result) = "mathematics_algebra_quadratic_formula"; break;
		case 105: std::get<1>(result) = "mathematics_notation_syncopated_algebra"; break;
		case 106: std::get<1>(result) = "mathematics_geometry_law_of_sines"; break;
		case 107: std::get<1>(result) = "mathematics_geometry_angle_sum_difference_trig_identities"; break;
		case 108: std::get<1>(result) = "mathematics_algebra_pascals_triangle"; break;
		case 109: std::get<1>(result) = "mathematics_algebra_solving_higher_order_polynomials"; break;
		case 110: std::get<1>(result) = "mathematics_notation_early_symbols_for_operations"; break;
		case 111: std::get<1>(result) = "mathematics_algebra_divergence_of_harmonic_series"; break;
		case 112: std::get<1>(result) = "mathematics_geometry_properties_of_chords"; break;
		case 128: std::get<1>(result) = "history_sourcing_basic_reliability"; break;
		case 129: std::get<1>(result) = "history_sourcing_role_of_systemic_bias"; break;
		case 130: std::get<1>(result) = "history_sourcing_role_of_state_bias_and_propaganda"; break;
		case 131: std::get<1>(result) = "history_sourcing_personal_interviews"; break;
		case 132: std::get<1>(result) = "history_theory_historical_causation"; break;
		case 133: std::get<1>(result) = "history_theory_historical_cycles"; break;
		case 134: std::get<1>(result) = "history_theory_social_cohesion"; break;
		case 135: std::get<1>(result) = "history_theory_social_conflict"; break;
		case 136: std::get<1>(result) = "history_form_biography"; break;
		case 137: std::get<1>(result) = "history_form_comparative_biography"; break;
		case 138: std::get<1>(result) = "history_form_biographical_dictionaries"; break;
		case 139: std::get<1>(result) = "history_form_autobiographical_adventure"; break;
		case 140: std::get<1>(result) = "history_form_genealogy"; break;
		case 141: std::get<1>(result) = "history_form_encyclopedia"; break;
		case 142: std::get<1>(result) = "history_form_cultural_history"; break;
		case 143: std::get<1>(result) = "history_form_cultural_comparison"; break;
		case 144: std::get<1>(result) = "history_sourcing_role_of_cultural_differences"; break;
		case 145: std::get<1>(result) = "history_form_alternate_history"; break;
		case 146: std::get<1>(result) = "history_sourcing_basic_archaeology"; break;
		case 147: std::get<1>(result) = "history_form_treatise_on_tech_evolution"; break;
		case 160: std::get<1>(result) = "astronomy_phases_of_the_moon"; break;
		case 161: std::get<1>(result) = "astronomy_summer_winter_moon"; break;
		case 162: std::get<1>(result) = "astronomy_path_of_the_moon"; break;
		case 163: std::get<1>(result) = "astronomy_tides_and_the_moon"; break;
		case 164: std::get<1>(result) = "astronomy_height_of_tides_vs_moon_and_sun"; break;
		case 165: std::get<1>(result) = "astronomy_summer_winter_sun"; break;
		case 166: std::get<1>(result) = "astronomy_relationship_between_lunar_solar_year"; break;
		case 167: std::get<1>(result) = "astronomy_daylight_variation_with_solar_year"; break;
		case 168: std::get<1>(result) = "astronomy_geocentric_model"; break;
		case 169: std::get<1>(result) = "astronomy_heliocentric_model"; break;
		case 170: std::get<1>(result) = "astronomy_dates_of_lunar_and_solar_eclipses"; break;
		case 171: std::get<1>(result) = "astronomy_star_charts"; break;
		case 172: std::get<1>(result) = "astronomy_star_catalogues_100"; break;
		case 173: std::get<1>(result) = "astronomy_star_catalogues_1000"; break;
		case 174: std::get<1>(result) = "astronomy_star_color_classification"; break;
		case 175: std::get<1>(result) = "astronomy_star_magnitude_classification"; break;
		case 176: std::get<1>(result) = "astronomy_shape_of_the_world"; break;
		case 177: std::get<1>(result) = "astronomy_precession_of_equinoxes"; break;
		case 178: std::get<1>(result) = "astronomy_method_empirical_observation"; break;
		case 179: std::get<1>(result) = "astronomy_method_path_models"; break;
		case 192: std::get<1>(result) = "naturalist_method_dissection"; break;
		case 193: std::get<1>(result) = "naturalist_observation_anatomy"; break;
		case 194: std::get<1>(result) = "naturalist_theory_comparative_anatomy"; break;
		case 195: std::get<1>(result) = "naturalist_theory_classification_by_physical_features"; break;
		case 196: std::get<1>(result) = "naturalist_observation_migration_patterns"; break;
		case 197: std::get<1>(result) = "naturalist_observation_reproductive_behavior"; break;
		case 198: std::get<1>(result) = "naturalist_observation_foraging_behavior_and_diet"; break;
		case 199: std::get<1>(result) = "naturalist_theory_food_chain"; break;
		case 200: std::get<1>(result) = "naturalist_observation_social_behavior"; break;
		case 201: std::get<1>(result) = "naturalist_observation_diseases"; break;
		case 202: std::get<1>(result) = "naturalist_theory_climactic_adaptation"; break;
		case 203: std::get<1>(result) = "naturalist_observation_embriological_development"; break;
		case 204: std::get<1>(result) = "naturalist_theory_struggle_for_existence"; break;
		case 224: std::get<1>(result) = "chemistry_classification_combustibles"; break;
		case 225: std::get<1>(result) = "chemistry_classification_ores"; break;
		case 226: std::get<1>(result) = "chemistry_metallurgy_alloys"; break;
		case 227: std::get<1>(result) = "chemistry_classification_scratch_test"; break;
		case 228: std::get<1>(result) = "chemistry_classification_elemental_theory"; break;
		case 229: std::get<1>(result) = "chemistry_chemicals_adhesives"; break;
		case 230: std::get<1>(result) = "chemistry_laboratory_blast_furnace"; break;
		case 231: std::get<1>(result) = "chemistry_laboratory_alembic"; break;
		case 232: std::get<1>(result) = "chemistry_laboratory_theory_of_liquid_liquid_extraction"; break;
		case 233: std::get<1>(result) = "chemistry_laboratory_theory_of_distillation"; break;
		case 234: std::get<1>(result) = "chemistry_laboratory_theory_of_evaporation"; break;
		case 235: std::get<1>(result) = "chemistry_classification_alkali_and_acids"; break;
		case 236: std::get<1>(result) = "chemistry_laboratory_systematic_experiments"; break;
		case 237: std::get<1>(result) = "chemistry_laboratory_glass_flask"; break;
		case 238: std::get<1>(result) = "chemistry_laboratory_glass_beaker"; break;
		case 239: std::get<1>(result) = "chemistry_laboratory_glass_vial"; break;
		case 240: std::get<1>(result) = "chemistry_laboratory_glass_funnel"; break;
		case 241: std::get<1>(result) = "chemistry_laboratory_crucible"; break;
		case 242: std::get<1>(result) = "chemistry_chemicals_nitric_acid"; break;
		case 243: std::get<1>(result) = "chemistry_chemicals_sulfuric_acid"; break;
		case 244: std::get<1>(result) = "chemistry_chemicals_aqua_regia"; break;
		case 245: std::get<1>(result) = "chemistry_laboratory_glass_ampoule"; break;
		case 246: std::get<1>(result) = "chemistry_laboratory_glass_retort"; break;
		case 247: std::get<1>(result) = "chemistry_laboratory_lab_ovens"; break;
		case 256: std::get<1>(result) = "geography_surveying_basic"; break;
		case 257: std::get<1>(result) = "geography_surveying_staff"; break;
		case 258: std::get<1>(result) = "geography_cartography_basic"; break;
		case 259: std::get<1>(result) = "geography_surveying_triangulation"; break;
		case 260: std::get<1>(result) = "geography_surveying_cartographical"; break;
		case 261: std::get<1>(result) = "geography_surveying_land"; break;
		case 262: std::get<1>(result) = "geography_surveying_military"; break;
		case 263: std::get<1>(result) = "geography_surveying_engineering"; break;
		case 264: std::get<1>(result) = "geography_cartography_geological"; break;
		case 265: std::get<1>(result) = "geography_cartography_grid_system"; break;
		case 266: std::get<1>(result) = "geography_cartography_distance_scale"; break;
		case 267: std::get<1>(result) = "geography_cartography_height_measurements"; break;
		case 268: std::get<1>(result) = "geography_method_economic_data_collection"; break;
		case 269: std::get<1>(result) = "geography_cartography_economic"; break;
		case 270: std::get<1>(result) = "geography_form_atlas"; break;
		case 271: std::get<1>(result) = "geography_theory_delta_formation"; break;
		case 272: std::get<1>(result) = "geography_theory_wind_patterns"; break;
		case 273: std::get<1>(result) = "geography_theory_origin_of_rainfall_from_evap_condense"; break;
		case 274: std::get<1>(result) = "geography_theory_water_cycle"; break;
		case 275: std::get<1>(result) = "geography_theory_latitude_climate_zones"; break;
		case 276: std::get<1>(result) = "geography_cartography_accurate_maps"; break;
		case 277: std::get<1>(result) = "geography_cartography_map_projections"; break;
		case 288: std::get<1>(result) = "medicine_theory_disease_and_fouled_water"; break;
		case 289: std::get<1>(result) = "medicine_method_physical_examination"; break;
		case 290: std::get<1>(result) = "medicine_method_autopsy"; break;
		case 291: std::get<1>(result) = "medicine_theory_prognosis"; break;
		case 292: std::get<1>(result) = "medicine_tool_herbal_remedies"; break;
		case 293: std::get<1>(result) = "medicine_tool_animal_remedies"; break;
		case 294: std::get<1>(result) = "medicine_tool_mineral_remedies"; break;
		case 295: std::get<1>(result) = "medicine_tool_bandages"; break;
		case 296: std::get<1>(result) = "medicine_theory_disease_classification"; break;
		case 297: std::get<1>(result) = "medicine_theory_toxicology"; break;
		case 298: std::get<1>(result) = "medicine_theory_acute_and_chronic_conditions"; break;
		case 299: std::get<1>(result) = "medicine_theory_endemic_disease"; break;
		case 300: std::get<1>(result) = "medicine_theory_epidemic_disease"; break;
		case 301: std::get<1>(result) = "medicine_theory_exacerbation"; break;
		case 302: std::get<1>(result) = "medicine_theory_paroxysm"; break;
		case 303: std::get<1>(result) = "medicine_theory_relapse"; break;
		case 304: std::get<1>(result) = "medicine_theory_convalescence"; break;
		case 305: std::get<1>(result) = "medicine_method_treatment_of_traumatic_injuries"; break;
		case 306: std::get<1>(result) = "medicine_method_fracture_treatment"; break;
		case 307: std::get<1>(result) = "medicine_theory_fracture_classification"; break;
		case 308: std::get<1>(result) = "medicine_tool_traction_bench"; break;
		case 309: std::get<1>(result) = "medicine_method_fracture_immobilization"; break;
		case 310: std::get<1>(result) = "medicine_tool_orthopedic_cast"; break;
		case 311: std::get<1>(result) = "medicine_method_surgery_excision"; break;
		case 312: std::get<1>(result) = "medicine_method_surgery_incision"; break;
		case 313: std::get<1>(result) = "medicine_method_hernia_surgery"; break;
		case 314: std::get<1>(result) = "medicine_method_tracheotomy_surgery"; break;
		case 315: std::get<1>(result) = "medicine_method_lithotomy_surgery"; break;
		case 316: std::get<1>(result) = "medicine_method_surgery_scraping"; break;
		case 317: std::get<1>(result) = "medicine_method_surgery_draining"; break;
		case 318: std::get<1>(result) = "medicine_method_surgery_probing"; break;
		case 319: std::get<1>(result) = "medicine_method_surgery_suturing"; break;
		case 320: std::get<1>(result) = "medicine_method_surgery_ligature"; break;
		case 321: std::get<1>(result) = "medicine_theory_surgical_models"; break;
		case 322: std::get<1>(result) = "medicine_tool_mud_bags_as_surgical_models"; break;
		case 323: std::get<1>(result) = "medicine_tool_plants_as_surgical_models"; break;
		case 324: std::get<1>(result) = "medicine_tool_animals_as_surgical_models"; break;
		case 325: std::get<1>(result) = "medicine_theory_specialized_surgical_instruments"; break;
		case 326: std::get<1>(result) = "medicine_tool_forceps"; break;
		case 327: std::get<1>(result) = "medicine_tool_scalpel"; break;
		case 328: std::get<1>(result) = "medicine_tool_surgical_scissors"; break;
		case 329: std::get<1>(result) = "medicine_tool_surgical_needles"; break;
		case 330: std::get<1>(result) = "medicine_method_cataract_surgery"; break;
		case 331: std::get<1>(result) = "medicine_method_cauterization"; break;
		case 332: std::get<1>(result) = "medicine_method_anesthesia"; break;
		case 333: std::get<1>(result) = "medicine_theory_pulmonary_medicine"; break;
		case 334: std::get<1>(result) = "medicine_theory_anatomical_studies"; break;
		case 335: std::get<1>(result) = "medicine_theory_classification_of_bodily_fluids"; break;
		case 336: std::get<1>(result) = "medicine_theory_eye_anatomy"; break;
		case 337: std::get<1>(result) = "medicine_theory_motor_vs_sensory_nerves"; break;
		case 338: std::get<1>(result) = "medicine_theory_nervous_system_function"; break;
		case 339: std::get<1>(result) = "medicine_theory_reaction_time"; break;
		case 340: std::get<1>(result) = "medicine_theory_blood_vessels"; break;
		case 341: std::get<1>(result) = "medicine_theory_pulmonary_circulation"; break;
		case 342: std::get<1>(result) = "medicine_theory_comparative_anatomy"; break;
		case 343: std::get<1>(result) = "medicine_theory_the_voice"; break;
		case 344: std::get<1>(result) = "medicine_theory_classification_of_muscles"; break;
		case 345: std::get<1>(result) = "medicine_theory_classification_of_mental_illnesses"; break;
		case 346: std::get<1>(result) = "medicine_theory_treatment_of_mental_illnesses"; break;
		case 347: std::get<1>(result) = "medicine_tool_dedicated_hospitals"; break;
		case 348: std::get<1>(result) = "medicine_method_professional_hospital_staff"; break;
		case 349: std::get<1>(result) = "medicine_method_specialized_wards"; break;
		case 350: std::get<1>(result) = "medicine_method_hospital_lab"; break;
		case 351: std::get<1>(result) = "medicine_method_medical_school"; break;
		case 352: std::get<1>(result) = "medicine_method_asylum_for_mentally_ill"; break;
		case 384: std::get<1>(result) = "engineering_horology_shadow_clock"; break;
		case 385: std::get<1>(result) = "engineering_horology_water_clock"; break;
		case 386: std::get<1>(result) = "engineering_horology_conical_water_clock"; break;
		case 387: std::get<1>(result) = "engineering_horology_water_clock_reservoir"; break;
		case 388: std::get<1>(result) = "engineering_horology_astrarium"; break;
		case 389: std::get<1>(result) = "engineering_horology_hourglass"; break;
		case 390: std::get<1>(result) = "engineering_horology_mechanical_clock"; break;
		case 391: std::get<1>(result) = "engineering_machine_theory_of_pulley"; break;
		case 392: std::get<1>(result) = "engineering_machine_pulley"; break;
		case 393: std::get<1>(result) = "engineering_machine_theory_of_screw"; break;
		case 394: std::get<1>(result) = "engineering_machine_screw"; break;
		case 395: std::get<1>(result) = "engineering_machine_theory_of_wheel_and_axle"; break;
		case 396: std::get<1>(result) = "engineering_machine_windlass"; break;
		case 397: std::get<1>(result) = "engineering_machine_theory_of_wedge"; break;
		case 398: std::get<1>(result) = "engineering_machine_theory_of_lever"; break;
		case 399: std::get<1>(result) = "engineering_machine_lever"; break;
		case 400: std::get<1>(result) = "engineering_machine_straight_beam_balance"; break;
		case 401: std::get<1>(result) = "engineering_machine_theory_of_gears"; break;
		case 402: std::get<1>(result) = "engineering_machine_warded_lock"; break;
		case 403: std::get<1>(result) = "engineering_machine_tumbler_lock"; break;
		case 404: std::get<1>(result) = "engineering_machine_padlock"; break;
		case 405: std::get<1>(result) = "engineering_machine_camshaft"; break;
		case 406: std::get<1>(result) = "engineering_machine_crankshaft"; break;
		case 407: std::get<1>(result) = "engineering_machine_water_powered_sawmill"; break;
		case 408: std::get<1>(result) = "engineering_machine_chariot_odometer"; break;
		case 409: std::get<1>(result) = "engineering_machine_chain_drive"; break;
		case 410: std::get<1>(result) = "engineering_machine_mechanical_compass"; break;
		case 411: std::get<1>(result) = "engineering_machine_differential_gear"; break;
		case 412: std::get<1>(result) = "engineering_machine_combination_lock"; break;
		case 413: std::get<1>(result) = "engineering_machine_verge_escapement"; break;
		case 414: std::get<1>(result) = "engineering_machine_balance_wheel"; break;
		case 415: std::get<1>(result) = "engineering_fluid_theory_of_siphon"; break;
		case 416: std::get<1>(result) = "engineering_fluid_valves"; break;
		case 417: std::get<1>(result) = "engineering_fluid_force_pump"; break;
		case 418: std::get<1>(result) = "engineering_optics_crystal_lens"; break;
		case 419: std::get<1>(result) = "engineering_optics_water_filled_spheres"; break;
		case 420: std::get<1>(result) = "engineering_optics_glass_lens"; break;
		case 421: std::get<1>(result) = "engineering_optics_camera_obscura"; break;
		case 422: std::get<1>(result) = "engineering_optics_parabolic_mirror"; break;
		case 423: std::get<1>(result) = "engineering_optics_theory_of_color"; break;
		case 424: std::get<1>(result) = "engineering_optics_theory_of_rainbows"; break;
		case 425: std::get<1>(result) = "engineering_optics_law_of_refraction"; break;
		case 426: std::get<1>(result) = "engineering_design_models_and_templates"; break;
		case 427: std::get<1>(result) = "engineering_construction_wood_lamination"; break;
		case 428: std::get<1>(result) = "engineering_astronomy_dioptra"; break;
		case 429: std::get<1>(result) = "engineering_astronomy_astrolabe"; break;
		case 430: std::get<1>(result) = "engineering_astronomy_armillary_sphere"; break;
		case 431: std::get<1>(result) = "engineering_astronomy_spherical_astrolabe"; break;
		case 432: std::get<1>(result) = "engineering_astronomy_mural_instrument"; break;
		case 433: std::get<1>(result) = "engineering_astronomy_orrery"; break;
		case 434: std::get<1>(result) = "engineering_machine_water_powered_trip_hammer"; break;
		case 435: std::get<1>(result) = "engineering_machine_double_acting_piston_bellows"; break;
		case 436: std::get<1>(result) = "engineering_fluid_archimedes_principle"; break;
		case 437: std::get<1>(result) = "engineering_optics_atmospheric_refraction"; break;
		case 438: std::get<1>(result) = "engineering_optics_cause_of_twilight"; break;
		case 439: std::get<1>(result) = "engineering_optics_height_of_atmosphere"; break;
		case 440: std::get<1>(result) = "engineering_machine_piston"; break;
		case 441: std::get<1>(result) = "engineering_machine_crank"; break;
		case 442: std::get<1>(result) = "engineering_machine_bellows"; break;
		case 443: std::get<1>(result) = "engineering_machine_water_powered_piston_bellows"; break;
		case 444: std::get<1>(result) = "engineering_machine_water_wheel"; break;
		case 445: std::get<1>(result) = "engineering_machine_trip_hammer"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_part_of_speech_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Noun"; break;
		case 1: std::get<1>(result) = "NounPlural"; break;
		case 2: std::get<1>(result) = "Adjective"; break;
		case 3: std::get<1>(result) = "Prefix"; break;
		case 4: std::get<1>(result) = "Verb"; break;
		case 5: std::get<1>(result) = "Verb3rdPerson"; break;
		case 6: std::get<1>(result) = "VerbPast"; break;
		case 7: std::get<1>(result) = "VerbPassive"; break;
		case 8: std::get<1>(result) = "VerbGerund"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_sphere_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "AGRICULTURE"; break;
		case 1: std::get<1>(result) = "ANIMALS"; break;
		case 2: std::get<1>(result) = "ART"; break;
		case 3: std::get<1>(result) = "BALANCE"; break;
		case 4: std::get<1>(result) = "BEAUTY"; break;
		case 5: std::get<1>(result) = "BIRTH"; break;
		case 6: std::get<1>(result) = "BLIGHT"; break;
		case 7: std::get<1>(result) = "BOUNDARIES"; break;
		case 8: std::get<1>(result) = "CAVERNS"; break;
		case 9: std::get<1>(result) = "CHAOS"; break;
		case 10: std::get<1>(result) = "CHARITY"; break;
		case 11: std::get<1>(result) = "CHILDREN"; break;
		case 12: std::get<1>(result) = "COASTS"; break;
		case 13: std::get<1>(result) = "CONSOLATION"; break;
		case 14: std::get<1>(result) = "COURAGE"; break;
		case 15: std::get<1>(result) = "CRAFTS"; break;
		case 16: std::get<1>(result) = "CREATION"; break;
		case 17: std::get<1>(result) = "DANCE"; break;
		case 18: std::get<1>(result) = "DARKNESS"; break;
		case 19: std::get<1>(result) = "DAWN"; break;
		case 20: std::get<1>(result) = "DAY"; break;
		case 21: std::get<1>(result) = "DEATH"; break;
		case 22: std::get<1>(result) = "DEFORMITY"; break;
		case 23: std::get<1>(result) = "DEPRAVITY"; break;
		case 24: std::get<1>(result) = "DISCIPLINE"; break;
		case 25: std::get<1>(result) = "DISEASE"; break;
		case 26: std::get<1>(result) = "DREAMS"; break;
		case 27: std::get<1>(result) = "DUSK"; break;
		case 28: std::get<1>(result) = "DUTY"; break;
		case 29: std::get<1>(result) = "EARTH"; break;
		case 30: std::get<1>(result) = "FAMILY"; break;
		case 31: std::get<1>(result) = "FAME"; break;
		case 32: std::get<1>(result) = "FATE"; break;
		case 33: std::get<1>(result) = "FERTILITY"; break;
		case 34: std::get<1>(result) = "FESTIVALS"; break;
		case 35: std::get<1>(result) = "FIRE"; break;
		case 36: std::get<1>(result) = "FISH"; break;
		case 37: std::get<1>(result) = "FISHING"; break;
		case 38: std::get<1>(result) = "FOOD"; break;
		case 39: std::get<1>(result) = "FORGIVENESS"; break;
		case 40: std::get<1>(result) = "FORTRESSES"; break;
		case 41: std::get<1>(result) = "FREEDOM"; break;
		case 42: std::get<1>(result) = "GAMBLING"; break;
		case 43: std::get<1>(result) = "GAMES"; break;
		case 44: std::get<1>(result) = "GENEROSITY"; break;
		case 45: std::get<1>(result) = "HAPPINESS"; break;
		case 46: std::get<1>(result) = "HEALING"; break;
		case 47: std::get<1>(result) = "HOSPITALITY"; break;
		case 48: std::get<1>(result) = "HUNTING"; break;
		case 49: std::get<1>(result) = "INSPIRATION"; break;
		case 50: std::get<1>(result) = "JEALOUSY"; break;
		case 51: std::get<1>(result) = "JEWELS"; break;
		case 52: std::get<1>(result) = "JUSTICE"; break;
		case 53: std::get<1>(result) = "LABOR"; break;
		case 54: std::get<1>(result) = "LAKES"; break;
		case 55: std::get<1>(result) = "LAWS"; break;
		case 56: std::get<1>(result) = "LIES"; break;
		case 57: std::get<1>(result) = "LIGHT"; break;
		case 58: std::get<1>(result) = "LIGHTNING"; break;
		case 59: std::get<1>(result) = "LONGEVITY"; break;
		case 60: std::get<1>(result) = "LOVE"; break;
		case 61: std::get<1>(result) = "LOYALTY"; break;
		case 62: std::get<1>(result) = "LUCK"; break;
		case 63: std::get<1>(result) = "LUST"; break;
		case 64: std::get<1>(result) = "MARRIAGE"; break;
		case 65: std::get<1>(result) = "MERCY"; break;
		case 66: std::get<1>(result) = "METALS"; break;
		case 67: std::get<1>(result) = "MINERALS"; break;
		case 68: std::get<1>(result) = "MISERY"; break;
		case 69: std::get<1>(result) = "MIST"; break;
		case 70: std::get<1>(result) = "MOON"; break;
		case 71: std::get<1>(result) = "MOUNTAINS"; break;
		case 72: std::get<1>(result) = "MUCK"; break;
		case 73: std::get<1>(result) = "MURDER"; break;
		case 74: std::get<1>(result) = "MUSIC"; break;
		case 75: std::get<1>(result) = "NATURE"; break;
		case 76: std::get<1>(result) = "NIGHT"; break;
		case 77: std::get<1>(result) = "NIGHTMARES"; break;
		case 78: std::get<1>(result) = "OATHS"; break;
		case 79: std::get<1>(result) = "OCEANS"; break;
		case 80: std::get<1>(result) = "ORDER"; break;
		case 81: std::get<1>(result) = "PAINTING"; break;
		case 82: std::get<1>(result) = "PEACE"; break;
		case 83: std::get<1>(result) = "PERSUASION"; break;
		case 84: std::get<1>(result) = "PLANTS"; break;
		case 85: std::get<1>(result) = "POETRY"; break;
		case 86: std::get<1>(result) = "PREGNANCY"; break;
		case 87: std::get<1>(result) = "RAIN"; break;
		case 88: std::get<1>(result) = "RAINBOWS"; break;
		case 89: std::get<1>(result) = "REBIRTH"; break;
		case 90: std::get<1>(result) = "REVELRY"; break;
		case 91: std::get<1>(result) = "REVENGE"; break;
		case 92: std::get<1>(result) = "RIVERS"; break;
		case 93: std::get<1>(result) = "RULERSHIP"; break;
		case 94: std::get<1>(result) = "RUMORS"; break;
		case 95: std::get<1>(result) = "SACRIFICE"; break;
		case 96: std::get<1>(result) = "SALT"; break;
		case 97: std::get<1>(result) = "SCHOLARSHIP"; break;
		case 98: std::get<1>(result) = "SEASONS"; break;
		case 99: std::get<1>(result) = "SILENCE"; break;
		case 100: std::get<1>(result) = "SKY"; break;
		case 101: std::get<1>(result) = "SONG"; break;
		case 102: std::get<1>(result) = "SPEECH"; break;
		case 103: std::get<1>(result) = "STARS"; break;
		case 104: std::get<1>(result) = "STORMS"; break;
		case 105: std::get<1>(result) = "STRENGTH"; break;
		case 106: std::get<1>(result) = "SUICIDE"; break;
		case 107: std::get<1>(result) = "SUN"; break;
		case 108: std::get<1>(result) = "THEFT"; break;
		case 109: std::get<1>(result) = "THRALLDOM"; break;
		case 110: std::get<1>(result) = "THUNDER"; break;
		case 111: std::get<1>(result) = "TORTURE"; break;
		case 112: std::get<1>(result) = "TRADE"; break;
		case 113: std::get<1>(result) = "TRAVELERS"; break;
		case 114: std::get<1>(result) = "TREACHERY"; break;
		case 115: std::get<1>(result) = "TREES"; break;
		case 116: std::get<1>(result) = "TRICKERY"; break;
		case 117: std::get<1>(result) = "TRUTH"; break;
		case 118: std::get<1>(result) = "TWILIGHT"; break;
		case 119: std::get<1>(result) = "VALOR"; break;
		case 120: std::get<1>(result) = "VICTORY"; break;
		case 121: std::get<1>(result) = "VOLCANOS"; break;
		case 122: std::get<1>(result) = "WAR"; break;
		case 123: std::get<1>(result) = "WATER"; break;
		case 124: std::get<1>(result) = "WEALTH"; break;
		case 125: std::get<1>(result) = "WEATHER"; break;
		case 126: std::get<1>(result) = "WIND"; break;
		case 127: std::get<1>(result) = "WISDOM"; break;
		case 128: std::get<1>(result) = "WRITING"; break;
		case 129: std::get<1>(result) = "YOUTH"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_language_name_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Unit"; break;
		case 1: std::get<1>(result) = "Artifact"; break;
		case 2: std::get<1>(result) = "ArtifactEvil"; break;
		case 3: std::get<1>(result) = "Swamp"; break;
		case 4: std::get<1>(result) = "Desert"; break;
		case 5: std::get<1>(result) = "Forest"; break;
		case 6: std::get<1>(result) = "Mountains"; break;
		case 7: std::get<1>(result) = "Lake"; break;
		case 8: std::get<1>(result) = "Ocean"; break;
		case 9: std::get<1>(result) = "Glacier"; break;
		case 10: std::get<1>(result) = "Tundra"; break;
		case 11: std::get<1>(result) = "Grassland"; break;
		case 12: std::get<1>(result) = "Hills"; break;
		case 13: std::get<1>(result) = "Region"; break;
		case 14: std::get<1>(result) = "Cave"; break;
		case 15: std::get<1>(result) = "SwampEvil"; break;
		case 16: std::get<1>(result) = "DesertEvil"; break;
		case 17: std::get<1>(result) = "ForestEvil"; break;
		case 18: std::get<1>(result) = "MountainsEvil"; break;
		case 19: std::get<1>(result) = "LakeEvil"; break;
		case 20: std::get<1>(result) = "OceanEvil"; break;
		case 21: std::get<1>(result) = "GlacierEvil"; break;
		case 22: std::get<1>(result) = "TundraEvil"; break;
		case 23: std::get<1>(result) = "GrasslandEvil"; break;
		case 24: std::get<1>(result) = "HillsEvil"; break;
		case 25: std::get<1>(result) = "SwampGood"; break;
		case 26: std::get<1>(result) = "DesertGood"; break;
		case 27: std::get<1>(result) = "ForestGood"; break;
		case 28: std::get<1>(result) = "MountainsGood"; break;
		case 29: std::get<1>(result) = "LakeGood"; break;
		case 30: std::get<1>(result) = "OceanGood"; break;
		case 31: std::get<1>(result) = "GlacierGood"; break;
		case 32: std::get<1>(result) = "TundraGood"; break;
		case 33: std::get<1>(result) = "GrasslandGood"; break;
		case 34: std::get<1>(result) = "HillsGood"; break;
		case 35: std::get<1>(result) = "ArtImage"; break;
		case 36: std::get<1>(result) = "MountainPeak"; break;
		case 37: std::get<1>(result) = "Unknown1"; break;
		case 38: std::get<1>(result) = "Volcano"; break;
		case 39: std::get<1>(result) = "SmallIsland"; break;
		case 40: std::get<1>(result) = "Island"; break;
		case 41: std::get<1>(result) = "Continent"; break;
		case 42: std::get<1>(result) = "CommonReligion"; break;
		case 43: std::get<1>(result) = "Temple"; break;
		case 44: std::get<1>(result) = "Keep"; break;
		case 45: std::get<1>(result) = "Unknown2"; break;
		case 46: std::get<1>(result) = "SymbolArtifice"; break;
		case 47: std::get<1>(result) = "SymbolViolent"; break;
		case 48: std::get<1>(result) = "SymbolProtect"; break;
		case 49: std::get<1>(result) = "SymbolDomestic"; break;
		case 50: std::get<1>(result) = "SymbolFood"; break;
		case 51: std::get<1>(result) = "War"; break;
		case 52: std::get<1>(result) = "Battle"; break;
		case 53: std::get<1>(result) = "Siege"; break;
		case 54: std::get<1>(result) = "Road"; break;
		case 55: std::get<1>(result) = "Wall"; break;
		case 56: std::get<1>(result) = "Bridge"; break;
		case 57: std::get<1>(result) = "Tunnel"; break;
		case 58: std::get<1>(result) = "Tomb"; break;
		case 59: std::get<1>(result) = "SymbolProtect2"; break;
		case 60: std::get<1>(result) = "Library"; break;
		case 61: std::get<1>(result) = "Festival"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_nemesis_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ACTIVE_ADVENTURER"; std::get<2>(result) = "used when loading save"; break;
		case 1: std::get<1>(result) = "RETIRED_ADVENTURER"; std::get<2>(result) = "allows resuming play"; break;
		case 2: std::get<1>(result) = "ADVENTURER"; std::get<2>(result) = "blue color in legends"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_machine_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "standard"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_screw_pump_direction_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "FromNorth"; break;
		case 1: std::get<1>(result) = "FromEast"; break;
		case 2: std::get<1>(result) = "FromSouth"; break;
		case 3: std::get<1>(result) = "FromWest"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tile_traffic_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Normal"; break;
		case 1: std::get<1>(result) = "Low"; break;
		case 2: std::get<1>(result) = "High"; break;
		case 3: std::get<1>(result) = "Restricted"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tile_dig_designation_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "No"; std::get<2>(result) = "no designation"; break;
		case 1: std::get<1>(result) = "Default"; std::get<2>(result) = "dig walls, remove stairs and ramps, gather plants, fell trees"; break;
		case 2: std::get<1>(result) = "UpDownStair"; break;
		case 3: std::get<1>(result) = "Channel"; break;
		case 4: std::get<1>(result) = "Ramp"; break;
		case 5: std::get<1>(result) = "DownStair"; break;
		case 6: std::get<1>(result) = "UpStair"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tile_liquid_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Water"; break;
		case 1: std::get<1>(result) = "Magma"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tile_building_occ_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "None"; std::get<2>(result) = "no building"; break;
		case 1: std::get<1>(result) = "Planned"; std::get<2>(result) = "nothing built yet"; break;
		case 2: std::get<1>(result) = "Passable"; break;
		case 3: std::get<1>(result) = "Obstacle"; std::get<2>(result) = "workshop tile; ~fortification"; break;
		case 4: std::get<1>(result) = "Well"; break;
		case 5: std::get<1>(result) = "Floored"; std::get<2>(result) = "depot; lowered bridge"; break;
		case 6: std::get<1>(result) = "Impassable"; break;
		case 7: std::get<1>(result) = "Dynamic"; std::get<2>(result) = "doors, grates, etc"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tile_liquid_flow_dir_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "none"; break;
		case 1: std::get<1>(result) = "south"; break;
		case 2: std::get<1>(result) = "east"; break;
		case 3: std::get<1>(result) = "northeast"; break;
		case 4: std::get<1>(result) = "west"; break;
		case 5: std::get<1>(result) = "northwest"; break;
		case 6: std::get<1>(result) = "southeast"; break;
		case 7: std::get<1>(result) = "southwest"; break;
		case 8: std::get<1>(result) = "inv_8"; break;
		case 9: std::get<1>(result) = "inv_9"; break;
		case 10: std::get<1>(result) = "north"; break;
		case 11: std::get<1>(result) = "inv_b"; break;
		case 12: std::get<1>(result) = "inv_c"; break;
		case 13: std::get<1>(result) = "inv_d"; break;
		case 14: std::get<1>(result) = "inv_e"; break;
		case 15: std::get<1>(result) = "inv_f"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_block_square_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "mineral"; break;
		case 1: std::get<1>(result) = "frozen_liquid"; break;
		case 2: std::get<1>(result) = "world_construction"; break;
		case 3: std::get<1>(result) = "material_spatter"; break;
		case 4: std::get<1>(result) = "grass"; break;
		case 5: std::get<1>(result) = "spoor"; break;
		case 6: std::get<1>(result) = "item_spatter"; break;
		case 7: std::get<1>(result) = "designation_priority"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_feature_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "outdoor_river"; break;
		case 1: std::get<1>(result) = "cave"; break;
		case 2: std::get<1>(result) = "pit"; break;
		case 3: std::get<1>(result) = "magma_pool"; break;
		case 4: std::get<1>(result) = "volcano"; break;
		case 5: std::get<1>(result) = "deep_special_tube"; break;
		case 6: std::get<1>(result) = "deep_surface_portal"; break;
		case 7: std::get<1>(result) = "subterranean_from_layer"; break;
		case 8: std::get<1>(result) = "magma_core_from_layer"; break;
		case 9: std::get<1>(result) = "underworld_from_layer"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_feature_init_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "anon_1"; break;
		case 1: std::get<1>(result) = "anon_2"; break;
		case 2: std::get<1>(result) = "anon_3"; break;
		case 3: std::get<1>(result) = "Discovered"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_feature_alteration_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "new_pop_max"; break;
		case 1: std::get<1>(result) = "new_lava_fill_z"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_world_construction_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ROAD"; break;
		case 1: std::get<1>(result) = "TUNNEL"; break;
		case 2: std::get<1>(result) = "BRIDGE"; break;
		case 3: std::get<1>(result) = "WALL"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_biome_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MOUNTAIN"; break;
		case 1: std::get<1>(result) = "GLACIER"; break;
		case 2: std::get<1>(result) = "TUNDRA"; break;
		case 3: std::get<1>(result) = "SWAMP_TEMPERATE_FRESHWATER"; break;
		case 4: std::get<1>(result) = "SWAMP_TEMPERATE_SALTWATER"; break;
		case 5: std::get<1>(result) = "MARSH_TEMPERATE_FRESHWATER"; break;
		case 6: std::get<1>(result) = "MARSH_TEMPERATE_SALTWATER"; break;
		case 7: std::get<1>(result) = "SWAMP_TROPICAL_FRESHWATER"; break;
		case 8: std::get<1>(result) = "SWAMP_TROPICAL_SALTWATER"; break;
		case 9: std::get<1>(result) = "SWAMP_MANGROVE"; break;
		case 10: std::get<1>(result) = "MARSH_TROPICAL_FRESHWATER"; break;
		case 11: std::get<1>(result) = "MARSH_TROPICAL_SALTWATER"; break;
		case 12: std::get<1>(result) = "FOREST_TAIGA"; break;
		case 13: std::get<1>(result) = "FOREST_TEMPERATE_CONIFER"; break;
		case 14: std::get<1>(result) = "FOREST_TEMPERATE_BROADLEAF"; break;
		case 15: std::get<1>(result) = "FOREST_TROPICAL_CONIFER"; break;
		case 16: std::get<1>(result) = "FOREST_TROPICAL_DRY_BROADLEAF"; break;
		case 17: std::get<1>(result) = "FOREST_TROPICAL_MOIST_BROADLEAF"; break;
		case 18: std::get<1>(result) = "GRASSLAND_TEMPERATE"; break;
		case 19: std::get<1>(result) = "SAVANNA_TEMPERATE"; break;
		case 20: std::get<1>(result) = "SHRUBLAND_TEMPERATE"; break;
		case 21: std::get<1>(result) = "GRASSLAND_TROPICAL"; break;
		case 22: std::get<1>(result) = "SAVANNA_TROPICAL"; break;
		case 23: std::get<1>(result) = "SHRUBLAND_TROPICAL"; break;
		case 24: std::get<1>(result) = "DESERT_BADLAND"; break;
		case 25: std::get<1>(result) = "DESERT_ROCK"; break;
		case 26: std::get<1>(result) = "DESERT_SAND"; break;
		case 27: std::get<1>(result) = "OCEAN_TROPICAL"; break;
		case 28: std::get<1>(result) = "OCEAN_TEMPERATE"; break;
		case 29: std::get<1>(result) = "OCEAN_ARCTIC"; break;
		case 30: std::get<1>(result) = "POOL_TEMPERATE_FRESHWATER"; break;
		case 31: std::get<1>(result) = "POOL_TEMPERATE_BRACKISHWATER"; break;
		case 32: std::get<1>(result) = "POOL_TEMPERATE_SALTWATER"; break;
		case 33: std::get<1>(result) = "POOL_TROPICAL_FRESHWATER"; break;
		case 34: std::get<1>(result) = "POOL_TROPICAL_BRACKISHWATER"; break;
		case 35: std::get<1>(result) = "POOL_TROPICAL_SALTWATER"; break;
		case 36: std::get<1>(result) = "LAKE_TEMPERATE_FRESHWATER"; break;
		case 37: std::get<1>(result) = "LAKE_TEMPERATE_BRACKISHWATER"; break;
		case 38: std::get<1>(result) = "LAKE_TEMPERATE_SALTWATER"; break;
		case 39: std::get<1>(result) = "LAKE_TROPICAL_FRESHWATER"; break;
		case 40: std::get<1>(result) = "LAKE_TROPICAL_BRACKISHWATER"; break;
		case 41: std::get<1>(result) = "LAKE_TROPICAL_SALTWATER"; break;
		case 42: std::get<1>(result) = "RIVER_TEMPERATE_FRESHWATER"; break;
		case 43: std::get<1>(result) = "RIVER_TEMPERATE_BRACKISHWATER"; break;
		case 44: std::get<1>(result) = "RIVER_TEMPERATE_SALTWATER"; break;
		case 45: std::get<1>(result) = "RIVER_TROPICAL_FRESHWATER"; break;
		case 46: std::get<1>(result) = "RIVER_TROPICAL_BRACKISHWATER"; break;
		case 47: std::get<1>(result) = "RIVER_TROPICAL_SALTWATER"; break;
		case 48: std::get<1>(result) = "SUBTERRANEAN_WATER"; break;
		case 49: std::get<1>(result) = "SUBTERRANEAN_CHASM"; break;
		case 50: std::get<1>(result) = "SUBTERRANEAN_LAVA"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_flow_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Miasma"; break;
		case 1: std::get<1>(result) = "Steam"; std::get<2>(result) = "only if mat_type=1"; break;
		case 2: std::get<1>(result) = "Mist"; break;
		case 3: std::get<1>(result) = "MaterialDust"; break;
		case 4: std::get<1>(result) = "MagmaMist"; break;
		case 5: std::get<1>(result) = "Smoke"; break;
		case 6: std::get<1>(result) = "Dragonfire"; break;
		case 7: std::get<1>(result) = "Fire"; break;
		case 8: std::get<1>(result) = "Web"; break;
		case 9: std::get<1>(result) = "MaterialGas"; break;
		case 10: std::get<1>(result) = "MaterialVapor"; break;
		case 11: std::get<1>(result) = "OceanWave"; break;
		case 12: std::get<1>(result) = "SeaFoam"; break;
		case 13: std::get<1>(result) = "ItemCloud"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_flow_guide_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "TrailingFlow"; break;
		case 1: std::get<1>(result) = "ItemCloud"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_region_block_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SphereField"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_craft_material_class_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Metal"; break;
		case 1: std::get<1>(result) = "Wood"; break;
		case 2: std::get<1>(result) = "Gem"; break;
		case 3: std::get<1>(result) = "Glass"; break;
		case 4: std::get<1>(result) = "Stone"; break;
		case 5: std::get<1>(result) = "Bone"; break;
		case 6: std::get<1>(result) = "Ivory"; break;
		case 7: std::get<1>(result) = "Horn"; break;
		case 8: std::get<1>(result) = "Pearl"; break;
		case 9: std::get<1>(result) = "Shell"; break;
		case 10: std::get<1>(result) = "Leather"; break;
		case 11: std::get<1>(result) = "Cloth"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_builtin_mats_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "INORGANIC"; break;
		case 1: std::get<1>(result) = "AMBER"; break;
		case 2: std::get<1>(result) = "CORAL"; break;
		case 3: std::get<1>(result) = "GLASS_GREEN"; break;
		case 4: std::get<1>(result) = "GLASS_CLEAR"; break;
		case 5: std::get<1>(result) = "GLASS_CRYSTAL"; break;
		case 6: std::get<1>(result) = "WATER"; break;
		case 7: std::get<1>(result) = "COAL"; break;
		case 8: std::get<1>(result) = "POTASH"; break;
		case 9: std::get<1>(result) = "ASH"; break;
		case 10: std::get<1>(result) = "PEARLASH"; break;
		case 11: std::get<1>(result) = "LYE"; break;
		case 12: std::get<1>(result) = "MUD"; break;
		case 13: std::get<1>(result) = "VOMIT"; break;
		case 14: std::get<1>(result) = "SALT"; break;
		case 15: std::get<1>(result) = "FILTH_B"; break;
		case 16: std::get<1>(result) = "FILTH_Y"; break;
		case 17: std::get<1>(result) = "UNKNOWN_SUBSTANCE"; break;
		case 18: std::get<1>(result) = "GRIME"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_material_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "BONE"; break;
		case 1: std::get<1>(result) = "MEAT"; break;
		case 2: std::get<1>(result) = "EDIBLE_VERMIN"; break;
		case 3: std::get<1>(result) = "EDIBLE_RAW"; break;
		case 4: std::get<1>(result) = "EDIBLE_COOKED"; break;
		case 5: std::get<1>(result) = "ALCOHOL"; break;
		case 6: std::get<1>(result) = "ITEMS_METAL"; break;
		case 7: std::get<1>(result) = "ITEMS_BARRED"; break;
		case 8: std::get<1>(result) = "ITEMS_SCALED"; break;
		case 9: std::get<1>(result) = "ITEMS_LEATHER"; break;
		case 10: std::get<1>(result) = "ITEMS_SOFT"; break;
		case 11: std::get<1>(result) = "ITEMS_HARD"; break;
		case 12: std::get<1>(result) = "IMPLIES_ANIMAL_KILL"; break;
		case 13: std::get<1>(result) = "ALCOHOL_PLANT"; break;
		case 14: std::get<1>(result) = "ALCOHOL_CREATURE"; break;
		case 15: std::get<1>(result) = "CHEESE_PLANT"; break;
		case 16: std::get<1>(result) = "CHEESE_CREATURE"; break;
		case 17: std::get<1>(result) = "POWDER_MISC_PLANT"; break;
		case 18: std::get<1>(result) = "POWDER_MISC_CREATURE"; break;
		case 19: std::get<1>(result) = "STOCKPILE_GLOB"; break;
		case 20: std::get<1>(result) = "LIQUID_MISC_PLANT"; break;
		case 21: std::get<1>(result) = "LIQUID_MISC_CREATURE"; break;
		case 22: std::get<1>(result) = "LIQUID_MISC_OTHER"; break;
		case 23: std::get<1>(result) = "WOOD"; break;
		case 24: std::get<1>(result) = "THREAD_PLANT"; break;
		case 25: std::get<1>(result) = "TOOTH"; break;
		case 26: std::get<1>(result) = "HORN"; break;
		case 27: std::get<1>(result) = "PEARL"; break;
		case 28: std::get<1>(result) = "SHELL"; break;
		case 29: std::get<1>(result) = "LEATHER"; break;
		case 30: std::get<1>(result) = "SILK"; break;
		case 31: std::get<1>(result) = "SOAP"; break;
		case 32: std::get<1>(result) = "ROTS"; break;
		case 33: std::get<1>(result) = "IS_DYE"; break;
		case 34: std::get<1>(result) = "POWDER_MISC"; break;
		case 35: std::get<1>(result) = "LIQUID_MISC"; break;
		case 36: std::get<1>(result) = "STRUCTURAL_PLANT_MAT"; break;
		case 37: std::get<1>(result) = "SEED_MAT"; break;
		case 38: std::get<1>(result) = "LEAF_MAT"; break;
		case 39: std::get<1>(result) = "CHEESE"; break;
		case 40: std::get<1>(result) = "ENTERS_BLOOD"; break;
		case 41: std::get<1>(result) = "BLOOD_MAP_DESCRIPTOR"; break;
		case 42: std::get<1>(result) = "ICHOR_MAP_DESCRIPTOR"; break;
		case 43: std::get<1>(result) = "GOO_MAP_DESCRIPTOR"; break;
		case 44: std::get<1>(result) = "SLIME_MAP_DESCRIPTOR"; break;
		case 45: std::get<1>(result) = "PUS_MAP_DESCRIPTOR"; break;
		case 46: std::get<1>(result) = "GENERATES_MIASMA"; break;
		case 47: std::get<1>(result) = "IS_METAL"; break;
		case 48: std::get<1>(result) = "IS_GEM"; break;
		case 49: std::get<1>(result) = "IS_GLASS"; break;
		case 50: std::get<1>(result) = "CRYSTAL_GLASSABLE"; break;
		case 51: std::get<1>(result) = "ITEMS_WEAPON"; break;
		case 52: std::get<1>(result) = "ITEMS_WEAPON_RANGED"; break;
		case 53: std::get<1>(result) = "ITEMS_ANVIL"; break;
		case 54: std::get<1>(result) = "ITEMS_AMMO"; break;
		case 55: std::get<1>(result) = "ITEMS_DIGGER"; break;
		case 56: std::get<1>(result) = "ITEMS_ARMOR"; break;
		case 57: std::get<1>(result) = "ITEMS_DELICATE"; break;
		case 58: std::get<1>(result) = "ITEMS_SIEGE_ENGINE"; break;
		case 59: std::get<1>(result) = "ITEMS_QUERN"; break;
		case 60: std::get<1>(result) = "IS_STONE"; break;
		case 61: std::get<1>(result) = "UNDIGGABLE"; break;
		case 62: std::get<1>(result) = "YARN"; break;
		case 63: std::get<1>(result) = "STOCKPILE_GLOB_PASTE"; break;
		case 64: std::get<1>(result) = "STOCKPILE_GLOB_PRESSED"; break;
		case 65: std::get<1>(result) = "DISPLAY_UNGLAZED"; break;
		case 66: std::get<1>(result) = "DO_NOT_CLEAN_GLOB"; break;
		case 67: std::get<1>(result) = "NO_STONE_STOCKPILE"; break;
		case 68: std::get<1>(result) = "STOCKPILE_THREAD_METAL"; break;
		case 69: std::get<1>(result) = "SWEAT_MAP_DESCRIPTOR"; break;
		case 70: std::get<1>(result) = "TEARS_MAP_DESCRIPTOR"; break;
		case 71: std::get<1>(result) = "SPIT_MAP_DESCRIPTOR"; break;
		case 72: std::get<1>(result) = "EVAPORATES"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_matter_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Solid"; break;
		case 1: std::get<1>(result) = "Liquid"; break;
		case 2: std::get<1>(result) = "Gas"; break;
		case 3: std::get<1>(result) = "Powder"; break;
		case 4: std::get<1>(result) = "Paste"; break;
		case 5: std::get<1>(result) = "Pressed"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_strain_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "BENDING"; break;
		case 1: std::get<1>(result) = "SHEAR"; break;
		case 2: std::get<1>(result) = "TORSION"; break;
		case 3: std::get<1>(result) = "IMPACT"; break;
		case 4: std::get<1>(result) = "TENSILE"; break;
		case 5: std::get<1>(result) = "COMPRESSIVE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_inorganic_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "LAVA"; break;
		case 1: std::get<1>(result) = "GENERATED"; break;
		case 2: std::get<1>(result) = "ENVIRONMENT_NON_SOIL_OCEAN"; std::get<2>(result) = "is METAMORPHIC, or has ENVIRONMENT with anything but SOIL_OCEAN"; break;
		case 3: std::get<1>(result) = "SEDIMENTARY"; break;
		case 4: std::get<1>(result) = "SEDIMENTARY_OCEAN_SHALLOW"; break;
		case 5: std::get<1>(result) = "IGNEOUS_INTRUSIVE"; break;
		case 6: std::get<1>(result) = "IGNEOUS_EXTRUSIVE"; break;
		case 7: std::get<1>(result) = "METAMORPHIC"; break;
		case 8: std::get<1>(result) = "DEEP_SURFACE"; break;
		case 9: std::get<1>(result) = "METAL_ORE"; break;
		case 10: std::get<1>(result) = "AQUIFER"; break;
		case 11: std::get<1>(result) = "SOIL_ANY"; break;
		case 12: std::get<1>(result) = "SOIL_OCEAN"; break;
		case 13: std::get<1>(result) = "SOIL_SAND"; break;
		case 14: std::get<1>(result) = "SEDIMENTARY_OCEAN_DEEP"; break;
		case 15: std::get<1>(result) = "THREAD_METAL"; break;
		case 16: std::get<1>(result) = "SPECIAL"; std::get<2>(result) = "or any DEEP_*"; break;
		case 17: std::get<1>(result) = "SOIL"; break;
		case 18: std::get<1>(result) = "DEEP_SPECIAL"; break;
		case 19: std::get<1>(result) = "DIVINE"; break;
		case 20: std::get<1>(result) = "anon_1"; break;
		case 21: std::get<1>(result) = "anon_2"; break;
		case 22: std::get<1>(result) = "anon_3"; break;
		case 23: std::get<1>(result) = "anon_4"; break;
		case 24: std::get<1>(result) = "anon_5"; break;
		case 25: std::get<1>(result) = "WAFERS"; break;
		case 26: std::get<1>(result) = "anon_6"; break;
		case 27: std::get<1>(result) = "anon_7"; break;
		case 28: std::get<1>(result) = "anon_8"; break;
		case 29: std::get<1>(result) = "anon_9"; break;
		case 30: std::get<1>(result) = "anon_10"; break;
		case 31: std::get<1>(result) = "anon_11"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_environment_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SOIL"; break;
		case 1: std::get<1>(result) = "SOIL_OCEAN"; break;
		case 2: std::get<1>(result) = "SOIL_SAND"; break;
		case 3: std::get<1>(result) = "METAMORPHIC"; break;
		case 4: std::get<1>(result) = "SEDIMENTARY"; break;
		case 5: std::get<1>(result) = "IGNEOUS_INTRUSIVE"; break;
		case 6: std::get<1>(result) = "IGNEOUS_EXTRUSIVE"; break;
		case 7: std::get<1>(result) = "ALLUVIAL"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_inclusion_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "anon_1"; std::get<2>(result) = "unused"; break;
		case 1: std::get<1>(result) = "VEIN"; break;
		case 2: std::get<1>(result) = "CLUSTER"; break;
		case 3: std::get<1>(result) = "CLUSTER_SMALL"; break;
		case 4: std::get<1>(result) = "CLUSTER_ONE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_organic_mat_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Meat"; break;
		case 1: std::get<1>(result) = "Fish"; break;
		case 2: std::get<1>(result) = "UnpreparedFish"; break;
		case 3: std::get<1>(result) = "Eggs"; break;
		case 4: std::get<1>(result) = "Plants"; break;
		case 5: std::get<1>(result) = "PlantDrink"; break;
		case 6: std::get<1>(result) = "CreatureDrink"; break;
		case 7: std::get<1>(result) = "PlantCheese"; break;
		case 8: std::get<1>(result) = "CreatureCheese"; break;
		case 9: std::get<1>(result) = "Seed"; break;
		case 10: std::get<1>(result) = "Leaf"; break;
		case 11: std::get<1>(result) = "PlantPowder"; break;
		case 12: std::get<1>(result) = "CreaturePowder"; break;
		case 13: std::get<1>(result) = "Glob"; break;
		case 14: std::get<1>(result) = "PlantLiquid"; break;
		case 15: std::get<1>(result) = "CreatureLiquid"; break;
		case 16: std::get<1>(result) = "MiscLiquid"; break;
		case 17: std::get<1>(result) = "Leather"; break;
		case 18: std::get<1>(result) = "Silk"; break;
		case 19: std::get<1>(result) = "PlantFiber"; break;
		case 20: std::get<1>(result) = "Bone"; break;
		case 21: std::get<1>(result) = "Shell"; break;
		case 22: std::get<1>(result) = "Wood"; break;
		case 23: std::get<1>(result) = "Horn"; break;
		case 24: std::get<1>(result) = "Pearl"; break;
		case 25: std::get<1>(result) = "Tooth"; break;
		case 26: std::get<1>(result) = "EdibleCheese"; break;
		case 27: std::get<1>(result) = "AnyDrink"; break;
		case 28: std::get<1>(result) = "EdiblePlant"; break;
		case 29: std::get<1>(result) = "CookableLiquid"; break;
		case 30: std::get<1>(result) = "CookablePowder"; break;
		case 31: std::get<1>(result) = "CookableSeed"; break;
		case 32: std::get<1>(result) = "CookableLeaf"; break;
		case 33: std::get<1>(result) = "Paste"; break;
		case 34: std::get<1>(result) = "Pressed"; break;
		case 35: std::get<1>(result) = "Yarn"; break;
		case 36: std::get<1>(result) = "MetalThread"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_meeting_topic_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "DiscussCurrent"; break;
		case 1: std::get<1>(result) = "RequestPeace"; break;
		case 2: std::get<1>(result) = "TreeQuota"; break;
		case 3: std::get<1>(result) = "BecomeLandHolder"; break;
		case 4: std::get<1>(result) = "PromoteLandHolder"; break;
		case 5: std::get<1>(result) = "ExportAgreement"; break;
		case 6: std::get<1>(result) = "ImportAgreement"; break;
		case 7: std::get<1>(result) = "PleasantPlace"; break;
		case 8: std::get<1>(result) = "WorldStatus"; break;
		case 9: std::get<1>(result) = "TributeAgreement"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_meeting_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "AcceptAgreement"; break;
		case 1: std::get<1>(result) = "RejectAgreement"; break;
		case 2: std::get<1>(result) = "AcceptPeace"; break;
		case 3: std::get<1>(result) = "RejectPeace"; break;
		case 4: std::get<1>(result) = "ExportAgreement"; break;
		case 5: std::get<1>(result) = "ImportAgreement"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_activity_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "TrainingSession"; break;
		case 1: std::get<1>(result) = "CombatTraining"; break;
		case 2: std::get<1>(result) = "SkillDemonstration"; break;
		case 3: std::get<1>(result) = "IndividualSkillDrill"; break;
		case 4: std::get<1>(result) = "Sparring"; break;
		case 5: std::get<1>(result) = "RangedPractice"; break;
		case 6: std::get<1>(result) = "Harassment"; break;
		case 7: std::get<1>(result) = "Conversation"; break;
		case 8: std::get<1>(result) = "Conflict"; break;
		case 9: std::get<1>(result) = "Guard"; break;
		case 10: std::get<1>(result) = "Reunion"; break;
		case 11: std::get<1>(result) = "Prayer"; break;
		case 12: std::get<1>(result) = "Socialize"; break;
		case 13: std::get<1>(result) = "Worship"; break;
		case 14: std::get<1>(result) = "Performance"; break;
		case 15: std::get<1>(result) = "Research"; break;
		case 16: std::get<1>(result) = "PonderTopic"; break;
		case 17: std::get<1>(result) = "DiscussTopic"; break;
		case 18: std::get<1>(result) = "Read"; break;
		case 19: std::get<1>(result) = "FillServiceOrder"; break;
		case 20: std::get<1>(result) = "Write"; break;
		case 21: std::get<1>(result) = "CopyWrittenContent"; break;
		case 22: std::get<1>(result) = "TeachTopic"; break;
		case 23: std::get<1>(result) = "Play"; break;
		case 24: std::get<1>(result) = "MakeBelieve"; break;
		case 25: std::get<1>(result) = "PlayWithToy"; break;
		case 26: std::get<1>(result) = "Encounter"; break;
		case 27: std::get<1>(result) = "StoreObject"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_conversation_menu_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "RespondGreeting"; break;
		case 1: std::get<1>(result) = "MainMenu"; break;
		case 2: std::get<1>(result) = "anon_1"; break;
		case 3: std::get<1>(result) = "anon_2"; break;
		case 4: std::get<1>(result) = "anon_3"; break;
		case 5: std::get<1>(result) = "anon_4"; break;
		case 6: std::get<1>(result) = "anon_5"; break;
		case 7: std::get<1>(result) = "RespondGoodbye"; break;
		case 8: std::get<1>(result) = "anon_6"; break;
		case 9: std::get<1>(result) = "DenyPermissionSleep"; break;
		case 10: std::get<1>(result) = "AskJoin"; break;
		case 11: std::get<1>(result) = "RespondJoin"; break;
		case 12: std::get<1>(result) = "DiscussRescue"; break;
		case 13: std::get<1>(result) = "DiscussAgreement"; break;
		case 14: std::get<1>(result) = "DiscussTrade"; break;
		case 15: std::get<1>(result) = "DiscussSurroundingArea"; break;
		case 16: std::get<1>(result) = "RespondAccusation"; break;
		case 17: std::get<1>(result) = "DiscussFamily"; break;
		case 18: std::get<1>(result) = "RespondArmistice"; break;
		case 19: std::get<1>(result) = "RespondDemandYield"; break;
		case 20: std::get<1>(result) = "anon_7"; break;
		case 21: std::get<1>(result) = "anon_8"; break;
		case 22: std::get<1>(result) = "anon_9"; break;
		case 23: std::get<1>(result) = "AskDirections"; break;
		case 24: std::get<1>(result) = "anon_10"; break;
		case 25: std::get<1>(result) = "anon_11"; break;
		case 26: std::get<1>(result) = "anon_12"; break;
		case 27: std::get<1>(result) = "anon_13"; break;
		case 28: std::get<1>(result) = "anon_14"; break;
		case 29: std::get<1>(result) = "anon_15"; break;
		case 30: std::get<1>(result) = "Demand"; break;
		case 31: std::get<1>(result) = "anon_16"; break;
		case 32: std::get<1>(result) = "anon_17"; break;
		case 33: std::get<1>(result) = "anon_18"; break;
		case 34: std::get<1>(result) = "Barter"; break;
		case 35: std::get<1>(result) = "DiscussHearthpersonDuties"; break;
		case 36: std::get<1>(result) = "anon_19"; break;
		case 37: std::get<1>(result) = "DiscussJourney"; break;
		case 38: std::get<1>(result) = "DiscussGroup"; break;
		case 39: std::get<1>(result) = "DiscussConflict"; break;
		case 40: std::get<1>(result) = "DiscussSite"; break;
		case 41: std::get<1>(result) = "RespondDemand"; break;
		case 42: std::get<1>(result) = "anon_20"; break;
		case 43: std::get<1>(result) = "RespondTributeDemand"; break;
		case 44: std::get<1>(result) = "RespondTributeOffer"; break;
		case 45: std::get<1>(result) = "DiscussTradeCancellation"; break;
		case 46: std::get<1>(result) = "RespondPeaceOffer"; break;
		case 47: std::get<1>(result) = "DiscussAgreementConclusion"; break;
		case 48: std::get<1>(result) = "RespondAdoptionRequest"; break;
		case 49: std::get<1>(result) = "anon_21"; break;
		case 50: std::get<1>(result) = "anon_22"; break;
		case 51: std::get<1>(result) = "RespondPositionOffer"; break;
		case 52: std::get<1>(result) = "RespondInvocation"; break;
		case 53: std::get<1>(result) = "anon_23"; break;
		case 54: std::get<1>(result) = "AskAboutPerson"; break;
		case 55: std::get<1>(result) = "anon_24"; break;
		case 56: std::get<1>(result) = "DiscussFeelings"; break;
		case 57: std::get<1>(result) = "anon_25"; break;
		case 58: std::get<1>(result) = "anon_26"; break;
		case 59: std::get<1>(result) = "anon_27"; break;
		case 60: std::get<1>(result) = "anon_28"; break;
		case 61: std::get<1>(result) = "anon_29"; break;
		case 62: std::get<1>(result) = "anon_30"; break;
		case 63: std::get<1>(result) = "anon_31"; break;
		case 64: std::get<1>(result) = "anon_32"; break;
		case 65: std::get<1>(result) = "StateGeneralThoughts"; break;
		case 66: std::get<1>(result) = "DiscussValues"; break;
		case 67: std::get<1>(result) = "RespondValues"; break;
		case 68: std::get<1>(result) = "RespondPassiveReply"; break;
		case 69: std::get<1>(result) = "RespondFlattery"; break;
		case 70: std::get<1>(result) = "RespondDismissal"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_performance_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "STORY"; break;
		case 1: std::get<1>(result) = "POETRY"; break;
		case 2: std::get<1>(result) = "MUSIC"; break;
		case 3: std::get<1>(result) = "DANCE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_performance_participant_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "TELL_STORY"; break;
		case 1: std::get<1>(result) = "RECITE_POETRY"; break;
		case 2: std::get<1>(result) = "MAKE_MUSIC"; break;
		case 3: std::get<1>(result) = "PERFORM_DANCE"; break;
		case 4: std::get<1>(result) = "LISTEN"; break;
		case 5: std::get<1>(result) = "HEAR"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_uniform_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "body"; break;
		case 1: std::get<1>(result) = "head"; break;
		case 2: std::get<1>(result) = "pants"; break;
		case 3: std::get<1>(result) = "gloves"; break;
		case 4: std::get<1>(result) = "shoes"; break;
		case 5: std::get<1>(result) = "shield"; break;
		case 6: std::get<1>(result) = "weapon"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_barrack_preference_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Bed"; break;
		case 1: std::get<1>(result) = "Armorstand"; break;
		case 2: std::get<1>(result) = "Box"; break;
		case 3: std::get<1>(result) = "Cabinet"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_squad_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Unk0"; break;
		case 1: std::get<1>(result) = "Unk1"; break;
		case 2: std::get<1>(result) = "Unk2"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_squad_order_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MOVE"; break;
		case 1: std::get<1>(result) = "KILL_LIST"; break;
		case 2: std::get<1>(result) = "DEFEND_BURROWS"; break;
		case 3: std::get<1>(result) = "PATROL_ROUTE"; break;
		case 4: std::get<1>(result) = "TRAIN"; break;
		case 5: std::get<1>(result) = "DRIVE_ENTITY_OFF_SITE"; break;
		case 6: std::get<1>(result) = "CAUSE_TROUBLE_FOR_ENTITY"; break;
		case 7: std::get<1>(result) = "KILL_HF"; break;
		case 8: std::get<1>(result) = "DRIVE_ARMIES_FROM_SITE"; break;
		case 9: std::get<1>(result) = "RETRIEVE_ARTIFACT"; break;
		case 10: std::get<1>(result) = "RAID_SITE"; break;
		case 11: std::get<1>(result) = "RESCUE_HF"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_squad_order_cannot_reason_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "not_following_order"; break;
		case 1: std::get<1>(result) = "activity_cancelled"; break;
		case 2: std::get<1>(result) = "no_barracks"; break;
		case 3: std::get<1>(result) = "improper_barracks"; break;
		case 4: std::get<1>(result) = "no_activity"; break;
		case 5: std::get<1>(result) = "cannot_individually_drill"; break;
		case 6: std::get<1>(result) = "does_not_exist"; break;
		case 7: std::get<1>(result) = "no_archery_target"; break;
		case 8: std::get<1>(result) = "improper_building"; break;
		case 9: std::get<1>(result) = "unreachable_location"; break;
		case 10: std::get<1>(result) = "invalid_location"; break;
		case 11: std::get<1>(result) = "no_reachable_valid_target"; break;
		case 12: std::get<1>(result) = "no_burrow"; break;
		case 13: std::get<1>(result) = "not_in_squad"; break;
		case 14: std::get<1>(result) = "no_patrol_route"; break;
		case 15: std::get<1>(result) = "no_reachable_point_on_route"; break;
		case 16: std::get<1>(result) = "invalid_order"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_army_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "player"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_path_goal_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "ComeToJobBuilding"; break;
		case 1: std::get<1>(result) = "ValidPondDumpUnit"; break;
		case 2: std::get<1>(result) = "ValidPondDump"; break;
		case 3: std::get<1>(result) = "ConflictDefense"; break;
		case 4: std::get<1>(result) = "AdventureMove"; break;
		case 5: std::get<1>(result) = "MarauderMill"; break;
		case 6: std::get<1>(result) = "WildernessCuriousStealTarget"; break;
		case 7: std::get<1>(result) = "WildernessRoamer"; break;
		case 8: std::get<1>(result) = "ThiefTarget"; break;
		case 9: std::get<1>(result) = "Owner"; break;
		case 10: std::get<1>(result) = "CheckChest"; break;
		case 11: std::get<1>(result) = "SleepBed"; break;
		case 12: std::get<1>(result) = "SleepBarracks"; break;
		case 13: std::get<1>(result) = "SleepGround"; break;
		case 14: std::get<1>(result) = "LeaveWall"; break;
		case 15: std::get<1>(result) = "FleeTerrain"; break;
		case 16: std::get<1>(result) = "TaxRoom"; break;
		case 17: std::get<1>(result) = "GuardTaxes"; break;
		case 18: std::get<1>(result) = "RansackTaxes"; break;
		case 19: std::get<1>(result) = "GetEmptySandBag"; break;
		case 20: std::get<1>(result) = "SandZone"; break;
		case 21: std::get<1>(result) = "GrabCage"; break;
		case 22: std::get<1>(result) = "UncageAnimal"; break;
		case 23: std::get<1>(result) = "CaptureSmallPet"; break;
		case 24: std::get<1>(result) = "GrabCageUnit"; break;
		case 25: std::get<1>(result) = "GoToCage"; break;
		case 26: std::get<1>(result) = "GrabAnimalTrap"; break;
		case 27: std::get<1>(result) = "CageVermin"; break;
		case 28: std::get<1>(result) = "GrabUnfillBucket"; break;
		case 29: std::get<1>(result) = "SeekFillBucket"; break;
		case 30: std::get<1>(result) = "SeekPatientForCarry"; break;
		case 31: std::get<1>(result) = "SeekPatientForDiagnosis"; break;
		case 32: std::get<1>(result) = "SeekPatientForImmobilizeBreak"; break;
		case 33: std::get<1>(result) = "SeekPatientForCrutch"; break;
		case 34: std::get<1>(result) = "SeekPatientForSuturing"; break;
		case 35: std::get<1>(result) = "SeekSurgerySite"; break;
		case 36: std::get<1>(result) = "CarryPatientToBed"; break;
		case 37: std::get<1>(result) = "SeekGiveWaterBucket"; break;
		case 38: std::get<1>(result) = "SeekJobItem"; break;
		case 39: std::get<1>(result) = "SeekUnitForItemDrop"; break;
		case 40: std::get<1>(result) = "SeekUnitForJob"; break;
		case 41: std::get<1>(result) = "SeekSplint"; break;
		case 42: std::get<1>(result) = "SeekCrutch"; break;
		case 43: std::get<1>(result) = "SeekSutureThread"; break;
		case 44: std::get<1>(result) = "SeekDressingCloth"; break;
		case 45: std::get<1>(result) = "GoToGiveWaterTarget"; break;
		case 46: std::get<1>(result) = "SeekFoodForTarget"; break;
		case 47: std::get<1>(result) = "SeekTargetForFood"; break;
		case 48: std::get<1>(result) = "SeekAnimalForSlaughter"; break;
		case 49: std::get<1>(result) = "SeekSlaughterBuilding"; break;
		case 50: std::get<1>(result) = "SeekAnimalForChain"; break;
		case 51: std::get<1>(result) = "SeekChainForAnimal"; break;
		case 52: std::get<1>(result) = "SeekCageForUnchain"; break;
		case 53: std::get<1>(result) = "SeekAnimalForUnchain"; break;
		case 54: std::get<1>(result) = "GrabFoodForTaming"; break;
		case 55: std::get<1>(result) = "SeekAnimalForTaming"; break;
		case 56: std::get<1>(result) = "SeekDrinkItem"; break;
		case 57: std::get<1>(result) = "SeekFoodItem"; break;
		case 58: std::get<1>(result) = "SeekEatingChair"; break;
		case 59: std::get<1>(result) = "SeekEatingChair2"; break;
		case 60: std::get<1>(result) = "SeekBadMoodBuilding"; break;
		case 61: std::get<1>(result) = "SetGlassMoodBuilding"; break;
		case 62: std::get<1>(result) = "SetMoodBuilding"; break;
		case 63: std::get<1>(result) = "SeekFellVictim"; break;
		case 64: std::get<1>(result) = "CleanBuildingSite"; break;
		case 65: std::get<1>(result) = "ResetPriorityGoal"; break;
		case 66: std::get<1>(result) = "MainJobBuilding"; break;
		case 67: std::get<1>(result) = "DropOffJobItems"; break;
		case 68: std::get<1>(result) = "GrabJobResources"; break;
		case 69: std::get<1>(result) = "WorkAtBuilding"; break;
		case 70: std::get<1>(result) = "GrabUniform"; break;
		case 71: std::get<1>(result) = "GrabClothing"; break;
		case 72: std::get<1>(result) = "GrabWeapon"; break;
		case 73: std::get<1>(result) = "GrabAmmunition"; break;
		case 74: std::get<1>(result) = "GrabShield"; break;
		case 75: std::get<1>(result) = "GrabArmor"; break;
		case 76: std::get<1>(result) = "GrabHelm"; break;
		case 77: std::get<1>(result) = "GrabBoots"; break;
		case 78: std::get<1>(result) = "GrabGloves"; break;
		case 79: std::get<1>(result) = "GrabPants"; break;
		case 80: std::get<1>(result) = "GrabQuiver"; break;
		case 81: std::get<1>(result) = "GrabBackpack"; break;
		case 82: std::get<1>(result) = "GrabWaterskin"; break;
		case 83: std::get<1>(result) = "StartHunt"; break;
		case 84: std::get<1>(result) = "StartFish"; break;
		case 85: std::get<1>(result) = "Clean"; break;
		case 86: std::get<1>(result) = "HuntVermin"; break;
		case 87: std::get<1>(result) = "Patrol"; break;
		case 88: std::get<1>(result) = "SquadStation"; break;
		case 89: std::get<1>(result) = "SeekInfant"; break;
		case 90: std::get<1>(result) = "ShopSpecific"; break;
		case 91: std::get<1>(result) = "MillInShop"; break;
		case 92: std::get<1>(result) = "GoToShop"; break;
		case 93: std::get<1>(result) = "SeekTrainingAmmunition"; break;
		case 94: std::get<1>(result) = "ArcheryTrainingSite"; break;
		case 95: std::get<1>(result) = "SparringPartner"; break;
		case 96: std::get<1>(result) = "SparringSite"; break;
		case 97: std::get<1>(result) = "AttendParty"; break;
		case 98: std::get<1>(result) = "SeekArtifact"; break;
		case 99: std::get<1>(result) = "GrabAmmunitionForBuilding"; break;
		case 100: std::get<1>(result) = "SeekBuildingForAmmunition"; break;
		case 101: std::get<1>(result) = "SeekItemForStorage"; break;
		case 102: std::get<1>(result) = "StoreItem"; break;
		case 103: std::get<1>(result) = "GrabKill"; break;
		case 104: std::get<1>(result) = "DropKillAtButcher"; break;
		case 105: std::get<1>(result) = "DropKillOutFront"; break;
		case 106: std::get<1>(result) = "GoToBeatingTarget"; break;
		case 107: std::get<1>(result) = "SeekKidnapVictim"; break;
		case 108: std::get<1>(result) = "SeekHuntingTarget"; break;
		case 109: std::get<1>(result) = "SeekTargetMechanism"; break;
		case 110: std::get<1>(result) = "SeekTargetForMechanism"; break;
		case 111: std::get<1>(result) = "SeekMechanismForTrigger"; break;
		case 112: std::get<1>(result) = "SeekTriggerForMechanism"; break;
		case 113: std::get<1>(result) = "SeekTrapForVerminCatch"; break;
		case 114: std::get<1>(result) = "SeekVerminForCatching"; break;
		case 115: std::get<1>(result) = "SeekVerminCatchLocation"; break;
		case 116: std::get<1>(result) = "WanderVerminCatchLocation"; break;
		case 117: std::get<1>(result) = "SeekVerminForHunting"; break;
		case 118: std::get<1>(result) = "SeekVerminHuntingSpot"; break;
		case 119: std::get<1>(result) = "WanderVerminHuntingSpot"; break;
		case 120: std::get<1>(result) = "SeekFishTrap"; break;
		case 121: std::get<1>(result) = "SeekFishCatchLocation"; break;
		case 122: std::get<1>(result) = "SeekWellForWater"; break;
		case 123: std::get<1>(result) = "SeekDrinkAreaForWater"; break;
		case 124: std::get<1>(result) = "UpgradeSquadEquipment"; break;
		case 125: std::get<1>(result) = "PrepareEquipmentManifests"; break;
		case 126: std::get<1>(result) = "WanderDepot"; break;
		case 127: std::get<1>(result) = "SeekUpdateOffice"; break;
		case 128: std::get<1>(result) = "SeekManageOffice"; break;
		case 129: std::get<1>(result) = "AssignedBuildingJob"; break;
		case 130: std::get<1>(result) = "ChaseOpponent"; break;
		case 131: std::get<1>(result) = "FleeFromOpponent"; break;
		case 132: std::get<1>(result) = "AttackBuilding"; break;
		case 133: std::get<1>(result) = "StartBedCarry"; break;
		case 134: std::get<1>(result) = "StartGiveFoodWater"; break;
		case 135: std::get<1>(result) = "StartMedicalAid"; break;
		case 136: std::get<1>(result) = "SeekStationFlood"; break;
		case 137: std::get<1>(result) = "SeekStation"; break;
		case 138: std::get<1>(result) = "StartWaterJobWell"; break;
		case 139: std::get<1>(result) = "StartWaterJobDrinkArea"; break;
		case 140: std::get<1>(result) = "StartEatJob"; break;
		case 141: std::get<1>(result) = "ScheduledMeal"; break;
		case 142: std::get<1>(result) = "ScheduledSleepBed"; break;
		case 143: std::get<1>(result) = "ScheduledSleepGround"; break;
		case 144: std::get<1>(result) = "Rest"; break;
		case 145: std::get<1>(result) = "RemoveConstruction"; break;
		case 146: std::get<1>(result) = "Chop"; break;
		case 147: std::get<1>(result) = "Detail"; break;
		case 148: std::get<1>(result) = "GatherPlant"; break;
		case 149: std::get<1>(result) = "Dig"; break;
		case 150: std::get<1>(result) = "Mischief"; break;
		case 151: std::get<1>(result) = "ChaseOpponentSameSquare"; break;
		case 152: std::get<1>(result) = "RestRecovered"; break;
		case 153: std::get<1>(result) = "RestReset"; break;
		case 154: std::get<1>(result) = "CombatTraining"; break;
		case 155: std::get<1>(result) = "SkillDemonstration"; break;
		case 156: std::get<1>(result) = "IndividualSkillDrill"; break;
		case 157: std::get<1>(result) = "SeekBuildingForItemDrop"; break;
		case 158: std::get<1>(result) = "SeekBuildingForJob"; break;
		case 159: std::get<1>(result) = "GrabMilkUnit"; break;
		case 160: std::get<1>(result) = "GoToMilkStation"; break;
		case 161: std::get<1>(result) = "SeekPatientForDressWound"; break;
		case 162: std::get<1>(result) = "UndeadHunt"; break;
		case 163: std::get<1>(result) = "GrabShearUnit"; break;
		case 164: std::get<1>(result) = "GoToShearStation"; break;
		case 165: std::get<1>(result) = "LayEggNestBox"; break;
		case 166: std::get<1>(result) = "ClayZone"; break;
		case 167: std::get<1>(result) = "ColonyToInstall"; break;
		case 168: std::get<1>(result) = "ReturnColonyToInstall"; break;
		case 169: std::get<1>(result) = "Nonsense"; break;
		case 170: std::get<1>(result) = "SeekBloodSuckVictim"; break;
		case 171: std::get<1>(result) = "SeekSheriff"; break;
		case 172: std::get<1>(result) = "GrabExecutionWeapon"; break;
		case 173: std::get<1>(result) = "TrainAnimal"; break;
		case 174: std::get<1>(result) = "GuardPath"; break;
		case 175: std::get<1>(result) = "Harass"; break;
		case 176: std::get<1>(result) = "SiteWalk"; break;
		case 177: std::get<1>(result) = "SiteWalkToBuilding"; break;
		case 178: std::get<1>(result) = "Reunion"; break;
		case 179: std::get<1>(result) = "ArmyWalk"; break;
		case 180: std::get<1>(result) = "ChaseOpponentFlood"; break;
		case 181: std::get<1>(result) = "ChargeAttack"; break;
		case 182: std::get<1>(result) = "FleeFromOpponentClimb"; break;
		case 183: std::get<1>(result) = "SeekLadderToClimb"; break;
		case 184: std::get<1>(result) = "SeekLadderToMove"; break;
		case 185: std::get<1>(result) = "PlaceLadder"; break;
		case 186: std::get<1>(result) = "SeekAnimalForGelding"; break;
		case 187: std::get<1>(result) = "SeekGeldingBuilding"; break;
		case 188: std::get<1>(result) = "Prayer"; break;
		case 189: std::get<1>(result) = "Socialize"; break;
		case 190: std::get<1>(result) = "Performance"; break;
		case 191: std::get<1>(result) = "Research"; break;
		case 192: std::get<1>(result) = "PonderTopic"; break;
		case 193: std::get<1>(result) = "FillServiceOrder"; break;
		case 194: std::get<1>(result) = "GetWrittenContent"; break;
		case 195: std::get<1>(result) = "GoToReadingPlace"; break;
		case 196: std::get<1>(result) = "GetWritingMaterials"; break;
		case 197: std::get<1>(result) = "GoToWritingPlace"; break;
		case 198: std::get<1>(result) = "Worship"; break;
		case 199: std::get<1>(result) = "GrabInstrument"; break;
		case 200: std::get<1>(result) = "Play"; break;
		case 201: std::get<1>(result) = "MakeBelieve"; break;
		case 202: std::get<1>(result) = "PlayWithToy"; break;
		case 203: std::get<1>(result) = "GrabToy"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_station_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Nonsense"; break;
		case 1: std::get<1>(result) = "DungeonCommander"; break;
		case 2: std::get<1>(result) = "InsaneMood"; break;
		case 3: std::get<1>(result) = "UndeadHunt"; break;
		case 4: std::get<1>(result) = "SiegerPatrol"; break;
		case 5: std::get<1>(result) = "MaraudeTarget"; break;
		case 6: std::get<1>(result) = "SiegerBasepoint"; break;
		case 7: std::get<1>(result) = "SiegerMill"; break;
		case 8: std::get<1>(result) = "AmbushPatrol"; break;
		case 9: std::get<1>(result) = "MarauderMill"; break;
		case 10: std::get<1>(result) = "WildernessCuriousWander"; break;
		case 11: std::get<1>(result) = "WildernessCuriousStealTarget"; break;
		case 12: std::get<1>(result) = "WildernessRoamer"; break;
		case 13: std::get<1>(result) = "PatternPatrol"; break;
		case 14: std::get<1>(result) = "InactiveMarauder"; break;
		case 15: std::get<1>(result) = "Owner"; break;
		case 16: std::get<1>(result) = "Commander"; break;
		case 17: std::get<1>(result) = "ChainedAnimal"; break;
		case 18: std::get<1>(result) = "MeetingLocation"; break;
		case 19: std::get<1>(result) = "MeetingLocationBuilding"; break;
		case 20: std::get<1>(result) = "Depot"; break;
		case 21: std::get<1>(result) = "VerminHunting"; break;
		case 22: std::get<1>(result) = "SeekCommander"; break;
		case 23: std::get<1>(result) = "ReturnToBase"; break;
		case 24: std::get<1>(result) = "MillAnywhere"; break;
		case 25: std::get<1>(result) = "Wagon"; break;
		case 26: std::get<1>(result) = "MillBuilding"; break;
		case 27: std::get<1>(result) = "HeadForEdge"; break;
		case 28: std::get<1>(result) = "MillingFlood"; break;
		case 29: std::get<1>(result) = "MillingBurrow"; break;
		case 30: std::get<1>(result) = "SquadMove"; break;
		case 31: std::get<1>(result) = "SquadKillList"; break;
		case 32: std::get<1>(result) = "SquadPatrol"; break;
		case 33: std::get<1>(result) = "SquadDefendBurrow"; break;
		case 34: std::get<1>(result) = "SquadDefendBurrowFromTarget"; break;
		case 35: std::get<1>(result) = "LairHunter"; break;
		case 36: std::get<1>(result) = "Graze"; break;
		case 37: std::get<1>(result) = "Guard"; break;
		case 38: std::get<1>(result) = "Alarm"; break;
		case 39: std::get<1>(result) = "MoveToSite"; break;
		case 40: std::get<1>(result) = "ClaimSite"; break;
		case 41: std::get<1>(result) = "WaitOrder"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_plant_raw_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SPRING"; break;
		case 1: std::get<1>(result) = "SUMMER"; break;
		case 2: std::get<1>(result) = "AUTUMN"; break;
		case 3: std::get<1>(result) = "WINTER"; break;
		case 4: std::get<1>(result) = "anon_1"; break;
		case 5: std::get<1>(result) = "SEED"; break;
		case 6: std::get<1>(result) = "TREE_HAS_MUSHROOM_CAP"; break;
		case 7: std::get<1>(result) = "DRINK"; break;
		case 8: std::get<1>(result) = "EXTRACT_BARREL"; break;
		case 9: std::get<1>(result) = "EXTRACT_VIAL"; break;
		case 10: std::get<1>(result) = "EXTRACT_STILL_VIAL"; break;
		case 11: std::get<1>(result) = "GENERATED"; break;
		case 12: std::get<1>(result) = "THREAD"; break;
		case 13: std::get<1>(result) = "MILL"; break;
		case 14: std::get<1>(result) = "anon_2"; break;
		case 15: std::get<1>(result) = "anon_3"; break;
		case 16: std::get<1>(result) = "anon_4"; break;
		case 17: std::get<1>(result) = "anon_5"; break;
		case 18: std::get<1>(result) = "anon_6"; break;
		case 19: std::get<1>(result) = "anon_7"; break;
		case 20: std::get<1>(result) = "WET"; break;
		case 21: std::get<1>(result) = "DRY"; break;
		case 22: std::get<1>(result) = "BIOME_MOUNTAIN"; break;
		case 23: std::get<1>(result) = "BIOME_GLACIER"; break;
		case 24: std::get<1>(result) = "BIOME_TUNDRA"; break;
		case 25: std::get<1>(result) = "BIOME_SWAMP_TEMPERATE_FRESHWATER"; break;
		case 26: std::get<1>(result) = "BIOME_SWAMP_TEMPERATE_SALTWATER"; break;
		case 27: std::get<1>(result) = "BIOME_MARSH_TEMPERATE_FRESHWATER"; break;
		case 28: std::get<1>(result) = "BIOME_MARSH_TEMPERATE_SALTWATER"; break;
		case 29: std::get<1>(result) = "BIOME_SWAMP_TROPICAL_FRESHWATER"; break;
		case 30: std::get<1>(result) = "BIOME_SWAMP_TROPICAL_SALTWATER"; break;
		case 31: std::get<1>(result) = "BIOME_SWAMP_MANGROVE"; break;
		case 32: std::get<1>(result) = "BIOME_MARSH_TROPICAL_FRESHWATER"; break;
		case 33: std::get<1>(result) = "BIOME_MARSH_TROPICAL_SALTWATER"; break;
		case 34: std::get<1>(result) = "BIOME_FOREST_TAIGA"; break;
		case 35: std::get<1>(result) = "BIOME_FOREST_TEMPERATE_CONIFER"; break;
		case 36: std::get<1>(result) = "BIOME_FOREST_TEMPERATE_BROADLEAF"; break;
		case 37: std::get<1>(result) = "BIOME_FOREST_TROPICAL_CONIFER"; break;
		case 38: std::get<1>(result) = "BIOME_FOREST_TROPICAL_DRY_BROADLEAF"; break;
		case 39: std::get<1>(result) = "BIOME_FOREST_TROPICAL_MOIST_BROADLEAF"; break;
		case 40: std::get<1>(result) = "BIOME_GRASSLAND_TEMPERATE"; break;
		case 41: std::get<1>(result) = "BIOME_SAVANNA_TEMPERATE"; break;
		case 42: std::get<1>(result) = "BIOME_SHRUBLAND_TEMPERATE"; break;
		case 43: std::get<1>(result) = "BIOME_GRASSLAND_TROPICAL"; break;
		case 44: std::get<1>(result) = "BIOME_SAVANNA_TROPICAL"; break;
		case 45: std::get<1>(result) = "BIOME_SHRUBLAND_TROPICAL"; break;
		case 46: std::get<1>(result) = "BIOME_DESERT_BADLAND"; break;
		case 47: std::get<1>(result) = "BIOME_DESERT_ROCK"; break;
		case 48: std::get<1>(result) = "BIOME_DESERT_SAND"; break;
		case 49: std::get<1>(result) = "BIOME_OCEAN_TROPICAL"; break;
		case 50: std::get<1>(result) = "BIOME_OCEAN_TEMPERATE"; break;
		case 51: std::get<1>(result) = "BIOME_OCEAN_ARCTIC"; break;
		case 52: std::get<1>(result) = "BIOME_POOL_TEMPERATE_FRESHWATER"; break;
		case 53: std::get<1>(result) = "BIOME_SUBTERRANEAN_WATER"; break;
		case 54: std::get<1>(result) = "BIOME_SUBTERRANEAN_CHASM"; break;
		case 55: std::get<1>(result) = "BIOME_SUBTERRANEAN_LAVA"; break;
		case 56: std::get<1>(result) = "GOOD"; break;
		case 57: std::get<1>(result) = "EVIL"; break;
		case 58: std::get<1>(result) = "SAVAGE"; break;
		case 59: std::get<1>(result) = "BIOME_POOL_TEMPERATE_BRACKISHWATER"; break;
		case 60: std::get<1>(result) = "BIOME_POOL_TEMPERATE_SALTWATER"; break;
		case 61: std::get<1>(result) = "BIOME_POOL_TROPICAL_FRESHWATER"; break;
		case 62: std::get<1>(result) = "BIOME_POOL_TROPICAL_BRACKISHWATER"; break;
		case 63: std::get<1>(result) = "BIOME_POOL_TROPICAL_SALTWATER"; break;
		case 64: std::get<1>(result) = "BIOME_LAKE_TEMPERATE_FRESHWATER"; break;
		case 65: std::get<1>(result) = "BIOME_LAKE_TEMPERATE_BRACKISHWATER"; break;
		case 66: std::get<1>(result) = "BIOME_LAKE_TEMPERATE_SALTWATER"; break;
		case 67: std::get<1>(result) = "BIOME_LAKE_TROPICAL_FRESHWATER"; break;
		case 68: std::get<1>(result) = "BIOME_LAKE_TROPICAL_BRACKISHWATER"; break;
		case 69: std::get<1>(result) = "BIOME_LAKE_TROPICAL_SALTWATER"; break;
		case 70: std::get<1>(result) = "BIOME_RIVER_TEMPERATE_FRESHWATER"; break;
		case 71: std::get<1>(result) = "BIOME_RIVER_TEMPERATE_BRACKISHWATER"; break;
		case 72: std::get<1>(result) = "BIOME_RIVER_TEMPERATE_SALTWATER"; break;
		case 73: std::get<1>(result) = "BIOME_RIVER_TROPICAL_FRESHWATER"; break;
		case 74: std::get<1>(result) = "BIOME_RIVER_TROPICAL_BRACKISHWATER"; break;
		case 75: std::get<1>(result) = "BIOME_RIVER_TROPICAL_SALTWATER"; break;
		case 76: std::get<1>(result) = "TWIGS_SIDE_BRANCHES"; break;
		case 77: std::get<1>(result) = "SAPLING"; break;
		case 78: std::get<1>(result) = "TREE"; break;
		case 79: std::get<1>(result) = "GRASS"; break;
		case 80: std::get<1>(result) = "TWIGS_ABOVE_BRANCHES"; break;
		case 81: std::get<1>(result) = "TWIGS_BELOW_BRANCHES"; break;
		case 82: std::get<1>(result) = "TWIGS_SIDE_HEAVY_BRANCHES"; break;
		case 83: std::get<1>(result) = "TWIGS_ABOVE_HEAVY_BRANCHES"; break;
		case 84: std::get<1>(result) = "TWIGS_BELOW_HEAVY_BRANCHES"; break;
		case 85: std::get<1>(result) = "TWIGS_SIDE_TRUNK"; break;
		case 86: std::get<1>(result) = "TWIGS_ABOVE_TRUNK"; break;
		case 87: std::get<1>(result) = "TWIGS_BELOW_TRUNK"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_projectile_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Item"; break;
		case 1: std::get<1>(result) = "Unit"; break;
		case 2: std::get<1>(result) = "Magic"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_reaction_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "FUEL"; break;
		case 1: std::get<1>(result) = "AUTOMATIC"; break;
		case 2: std::get<1>(result) = "ADVENTURE_MODE_ENABLED"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_reaction_reagent_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "item"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_reaction_product_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "item"; break;
		case 1: std::get<1>(result) = "improvement"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_reaction_product_item_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "GET_MATERIAL_SAME"; break;
		case 1: std::get<1>(result) = "GET_MATERIAL_PRODUCT"; break;
		case 2: std::get<1>(result) = "FORCE_EDGE"; break;
		case 3: std::get<1>(result) = "PASTE"; break;
		case 4: std::get<1>(result) = "PRESSED"; break;
		case 5: std::get<1>(result) = "CRAFTS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_reaction_product_improvement_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "GET_MATERIAL_SAME"; break;
		case 1: std::get<1>(result) = "GET_MATERIAL_PRODUCT"; break;
		case 2: std::get<1>(result) = "GLAZED"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_general_ref_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ARTIFACT"; break;
		case 1: std::get<1>(result) = "IS_ARTIFACT"; break;
		case 2: std::get<1>(result) = "NEMESIS"; break;
		case 3: std::get<1>(result) = "IS_NEMESIS"; break;
		case 4: std::get<1>(result) = "ITEM"; break;
		case 5: std::get<1>(result) = "ITEM_TYPE"; break;
		case 6: std::get<1>(result) = "COINBATCH"; break;
		case 7: std::get<1>(result) = "MAPSQUARE"; break;
		case 8: std::get<1>(result) = "ENTITY_ART_IMAGE"; break;
		case 9: std::get<1>(result) = "CONTAINS_UNIT"; break;
		case 10: std::get<1>(result) = "CONTAINS_ITEM"; break;
		case 11: std::get<1>(result) = "CONTAINED_IN_ITEM"; break;
		case 12: std::get<1>(result) = "PROJECTILE"; break;
		case 13: std::get<1>(result) = "UNIT"; break;
		case 14: std::get<1>(result) = "UNIT_MILKEE"; break;
		case 15: std::get<1>(result) = "UNIT_TRAINEE"; break;
		case 16: std::get<1>(result) = "UNIT_ITEMOWNER"; break;
		case 17: std::get<1>(result) = "UNIT_TRADEBRINGER"; break;
		case 18: std::get<1>(result) = "UNIT_HOLDER"; break;
		case 19: std::get<1>(result) = "UNIT_WORKER"; break;
		case 20: std::get<1>(result) = "UNIT_CAGEE"; break;
		case 21: std::get<1>(result) = "UNIT_BEATEE"; break;
		case 22: std::get<1>(result) = "UNIT_FOODRECEIVER"; break;
		case 23: std::get<1>(result) = "UNIT_KIDNAPEE"; break;
		case 24: std::get<1>(result) = "UNIT_PATIENT"; break;
		case 25: std::get<1>(result) = "UNIT_INFANT"; break;
		case 26: std::get<1>(result) = "UNIT_SLAUGHTEREE"; break;
		case 27: std::get<1>(result) = "UNIT_SHEAREE"; break;
		case 28: std::get<1>(result) = "UNIT_SUCKEE"; break;
		case 29: std::get<1>(result) = "UNIT_REPORTEE"; break;
		case 30: std::get<1>(result) = "BUILDING"; break;
		case 31: std::get<1>(result) = "BUILDING_CIVZONE_ASSIGNED"; break;
		case 32: std::get<1>(result) = "BUILDING_TRIGGER"; break;
		case 33: std::get<1>(result) = "BUILDING_TRIGGERTARGET"; break;
		case 34: std::get<1>(result) = "BUILDING_CHAIN"; break;
		case 35: std::get<1>(result) = "BUILDING_CAGED"; break;
		case 36: std::get<1>(result) = "BUILDING_HOLDER"; break;
		case 37: std::get<1>(result) = "BUILDING_WELL_TAG"; break;
		case 38: std::get<1>(result) = "BUILDING_USE_TARGET_1"; break;
		case 39: std::get<1>(result) = "BUILDING_USE_TARGET_2"; break;
		case 40: std::get<1>(result) = "BUILDING_DESTINATION"; break;
		case 41: std::get<1>(result) = "BUILDING_NEST_BOX"; break;
		case 42: std::get<1>(result) = "ENTITY"; break;
		case 43: std::get<1>(result) = "ENTITY_STOLEN"; break;
		case 44: std::get<1>(result) = "ENTITY_OFFERED"; break;
		case 45: std::get<1>(result) = "ENTITY_ITEMOWNER"; break;
		case 46: std::get<1>(result) = "LOCATION"; break;
		case 47: std::get<1>(result) = "INTERACTION"; break;
		case 48: std::get<1>(result) = "ABSTRACT_BUILDING"; break;
		case 49: std::get<1>(result) = "HISTORICAL_EVENT"; break;
		case 50: std::get<1>(result) = "SPHERE"; break;
		case 51: std::get<1>(result) = "SITE"; break;
		case 52: std::get<1>(result) = "SUBREGION"; break;
		case 53: std::get<1>(result) = "FEATURE_LAYER"; break;
		case 54: std::get<1>(result) = "HISTORICAL_FIGURE"; break;
		case 55: std::get<1>(result) = "ENTITY_POP"; break;
		case 56: std::get<1>(result) = "CREATURE"; break;
		case 57: std::get<1>(result) = "UNIT_RIDER"; break;
		case 58: std::get<1>(result) = "UNIT_CLIMBER"; break;
		case 59: std::get<1>(result) = "UNIT_GELDEE"; break;
		case 60: std::get<1>(result) = "KNOWLEDGE_SCHOLAR_FLAG"; break;
		case 61: std::get<1>(result) = "ACTIVITY_EVENT"; break;
		case 62: std::get<1>(result) = "VALUE_LEVEL"; break;
		case 63: std::get<1>(result) = "LANGUAGE"; break;
		case 64: std::get<1>(result) = "WRITTEN_CONTENT"; break;
		case 65: std::get<1>(result) = "POETIC_FORM"; break;
		case 66: std::get<1>(result) = "MUSICAL_FORM"; break;
		case 67: std::get<1>(result) = "DANCE_FORM"; break;
		case 68: std::get<1>(result) = "BUILDING_DISPLAY_FURNITURE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_specific_ref_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "anon_1"; break;
		case 1: std::get<1>(result) = "UNIT_INVENTORY"; break;
		case 2: std::get<1>(result) = "JOB"; break;
		case 3: std::get<1>(result) = "BUILDING_PARTY"; break;
		case 4: std::get<1>(result) = "ACTIVITY"; break;
		case 5: std::get<1>(result) = "ITEM_GENERAL"; break;
		case 6: std::get<1>(result) = "EFFECT"; break;
		case 7: std::get<1>(result) = "PETINFO_PET"; std::get<2>(result) = "unused"; break;
		case 8: std::get<1>(result) = "PETINFO_OWNER"; std::get<2>(result) = "unused"; break;
		case 9: std::get<1>(result) = "VERMIN_EVENT"; break;
		case 10: std::get<1>(result) = "VERMIN_ESCAPED_PET"; break;
		case 11: std::get<1>(result) = "ENTITY"; break;
		case 12: std::get<1>(result) = "PLOT_INFO"; break;
		case 13: std::get<1>(result) = "VIEWSCREEN"; break;
		case 14: std::get<1>(result) = "UNIT_ITEM_WRESTLE"; break;
		case 15: std::get<1>(result) = "NULL_REF"; break;
		case 16: std::get<1>(result) = "HIST_FIG"; break;
		case 17: std::get<1>(result) = "SITE"; break;
		case 18: std::get<1>(result) = "ARTIFACT"; break;
		case 19: std::get<1>(result) = "ITEM_IMPROVEMENT"; break;
		case 20: std::get<1>(result) = "COIN_FRONT"; break;
		case 21: std::get<1>(result) = "COIN_BACK"; break;
		case 22: std::get<1>(result) = "DETAIL_EVENT"; break;
		case 23: std::get<1>(result) = "SUBREGION"; break;
		case 24: std::get<1>(result) = "FEATURE_LAYER"; break;
		case 25: std::get<1>(result) = "ART_IMAGE"; break;
		case 26: std::get<1>(result) = "CREATURE_DEF"; break;
		case 27: std::get<1>(result) = "anon_2"; break;
		case 28: std::get<1>(result) = "anon_3"; break;
		case 29: std::get<1>(result) = "ENTITY_POPULATION"; break;
		case 30: std::get<1>(result) = "BREED"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_histfig_entity_link_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MEMBER"; break;
		case 1: std::get<1>(result) = "FORMER_MEMBER"; break;
		case 2: std::get<1>(result) = "MERCENARY"; break;
		case 3: std::get<1>(result) = "FORMER_MERCENARY"; break;
		case 4: std::get<1>(result) = "SLAVE"; break;
		case 5: std::get<1>(result) = "FORMER_SLAVE"; break;
		case 6: std::get<1>(result) = "PRISONER"; break;
		case 7: std::get<1>(result) = "FORMER_PRISONER"; break;
		case 8: std::get<1>(result) = "ENEMY"; break;
		case 9: std::get<1>(result) = "CRIMINAL"; break;
		case 10: std::get<1>(result) = "POSITION"; break;
		case 11: std::get<1>(result) = "FORMER_POSITION"; break;
		case 12: std::get<1>(result) = "POSITION_CLAIM"; break;
		case 13: std::get<1>(result) = "SQUAD"; break;
		case 14: std::get<1>(result) = "FORMER_SQUAD"; break;
		case 15: std::get<1>(result) = "OCCUPATION"; break;
		case 16: std::get<1>(result) = "FORMER_OCCUPATION"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_histfig_site_link_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "OCCUPATION"; break;
		case 1: std::get<1>(result) = "SEAT_OF_POWER"; break;
		case 2: std::get<1>(result) = "HANGOUT"; break;
		case 3: std::get<1>(result) = "HOME_SITE_ABSTRACT_BUILDING"; break;
		case 4: std::get<1>(result) = "HOME_SITE_REALIZATION_BUILDING"; break;
		case 5: std::get<1>(result) = "LAIR"; break;
		case 6: std::get<1>(result) = "HOME_SITE_REALIZATION_SUL"; break;
		case 7: std::get<1>(result) = "HOME_SITE_SAVED_CIVZONE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_histfig_hf_link_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MOTHER"; break;
		case 1: std::get<1>(result) = "FATHER"; break;
		case 2: std::get<1>(result) = "SPOUSE"; break;
		case 3: std::get<1>(result) = "CHILD"; break;
		case 4: std::get<1>(result) = "DEITY"; break;
		case 5: std::get<1>(result) = "LOVER"; break;
		case 6: std::get<1>(result) = "PRISONER"; break;
		case 7: std::get<1>(result) = "IMPRISONER"; break;
		case 8: std::get<1>(result) = "MASTER"; break;
		case 9: std::get<1>(result) = "APPRENTICE"; break;
		case 10: std::get<1>(result) = "COMPANION"; break;
		case 11: std::get<1>(result) = "FORMER_MASTER"; break;
		case 12: std::get<1>(result) = "FORMER_APPRENTICE"; break;
		case 13: std::get<1>(result) = "PET_OWNER"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_entity_entity_link_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "PARENT"; break;
		case 1: std::get<1>(result) = "CHILD"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_resource_allotment_specifier_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "CROP"; break;
		case 1: std::get<1>(result) = "STONE"; break;
		case 2: std::get<1>(result) = "METAL"; break;
		case 3: std::get<1>(result) = "WOOD"; break;
		case 4: std::get<1>(result) = "ARMOR_BODY"; break;
		case 5: std::get<1>(result) = "ARMOR_PANTS"; break;
		case 6: std::get<1>(result) = "ARMOR_GLOVES"; break;
		case 7: std::get<1>(result) = "ARMOR_BOOTS"; break;
		case 8: std::get<1>(result) = "ARMOR_HELM"; break;
		case 9: std::get<1>(result) = "CLOTHING_BODY"; break;
		case 10: std::get<1>(result) = "CLOTHING_PANTS"; break;
		case 11: std::get<1>(result) = "CLOTHING_GLOVES"; break;
		case 12: std::get<1>(result) = "CLOTHING_BOOTS"; break;
		case 13: std::get<1>(result) = "CLOTHING_HELM"; break;
		case 14: std::get<1>(result) = "WEAPON_MELEE"; break;
		case 15: std::get<1>(result) = "WEAPON_RANGED"; break;
		case 16: std::get<1>(result) = "ANVIL"; break;
		case 17: std::get<1>(result) = "GEMS"; break;
		case 18: std::get<1>(result) = "THREAD"; break;
		case 19: std::get<1>(result) = "CLOTH"; break;
		case 20: std::get<1>(result) = "LEATHER"; break;
		case 21: std::get<1>(result) = "QUIVER"; break;
		case 22: std::get<1>(result) = "BACKPACK"; break;
		case 23: std::get<1>(result) = "FLASK"; break;
		case 24: std::get<1>(result) = "BAG"; break;
		case 25: std::get<1>(result) = "TABLE"; break;
		case 26: std::get<1>(result) = "CABINET"; break;
		case 27: std::get<1>(result) = "CHAIR"; break;
		case 28: std::get<1>(result) = "BOX"; break;
		case 29: std::get<1>(result) = "BED"; break;
		case 30: std::get<1>(result) = "CRAFTS"; break;
		case 31: std::get<1>(result) = "MEAT"; break;
		case 32: std::get<1>(result) = "BONE"; break;
		case 33: std::get<1>(result) = "HORN"; break;
		case 34: std::get<1>(result) = "SHELL"; break;
		case 35: std::get<1>(result) = "TALLOW"; break;
		case 36: std::get<1>(result) = "TOOTH"; break;
		case 37: std::get<1>(result) = "PEARL"; break;
		case 38: std::get<1>(result) = "SOAP"; break;
		case 39: std::get<1>(result) = "EXTRACT"; break;
		case 40: std::get<1>(result) = "CHEESE"; break;
		case 41: std::get<1>(result) = "SKIN"; break;
		case 42: std::get<1>(result) = "POWDER"; break;
		case 43: std::get<1>(result) = "AMMO"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_profession_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "MINER"; break;
		case 1: std::get<1>(result) = "WOODWORKER"; break;
		case 2: std::get<1>(result) = "CARPENTER"; break;
		case 3: std::get<1>(result) = "BOWYER"; break;
		case 4: std::get<1>(result) = "WOODCUTTER"; break;
		case 5: std::get<1>(result) = "STONEWORKER"; break;
		case 6: std::get<1>(result) = "ENGRAVER"; break;
		case 7: std::get<1>(result) = "MASON"; break;
		case 8: std::get<1>(result) = "RANGER"; break;
		case 9: std::get<1>(result) = "ANIMAL_CARETAKER"; break;
		case 10: std::get<1>(result) = "ANIMAL_TRAINER"; break;
		case 11: std::get<1>(result) = "HUNTER"; break;
		case 12: std::get<1>(result) = "TRAPPER"; break;
		case 13: std::get<1>(result) = "ANIMAL_DISSECTOR"; break;
		case 14: std::get<1>(result) = "METALSMITH"; break;
		case 15: std::get<1>(result) = "FURNACE_OPERATOR"; break;
		case 16: std::get<1>(result) = "WEAPONSMITH"; break;
		case 17: std::get<1>(result) = "ARMORER"; break;
		case 18: std::get<1>(result) = "BLACKSMITH"; break;
		case 19: std::get<1>(result) = "METALCRAFTER"; break;
		case 20: std::get<1>(result) = "JEWELER"; break;
		case 21: std::get<1>(result) = "GEM_CUTTER"; break;
		case 22: std::get<1>(result) = "GEM_SETTER"; break;
		case 23: std::get<1>(result) = "CRAFTSMAN"; break;
		case 24: std::get<1>(result) = "WOODCRAFTER"; break;
		case 25: std::get<1>(result) = "STONECRAFTER"; break;
		case 26: std::get<1>(result) = "LEATHERWORKER"; break;
		case 27: std::get<1>(result) = "BONE_CARVER"; break;
		case 28: std::get<1>(result) = "WEAVER"; break;
		case 29: std::get<1>(result) = "CLOTHIER"; break;
		case 30: std::get<1>(result) = "GLASSMAKER"; break;
		case 31: std::get<1>(result) = "POTTER"; break;
		case 32: std::get<1>(result) = "GLAZER"; break;
		case 33: std::get<1>(result) = "WAX_WORKER"; break;
		case 34: std::get<1>(result) = "STRAND_EXTRACTOR"; break;
		case 35: std::get<1>(result) = "FISHERY_WORKER"; break;
		case 36: std::get<1>(result) = "FISHERMAN"; break;
		case 37: std::get<1>(result) = "FISH_DISSECTOR"; break;
		case 38: std::get<1>(result) = "FISH_CLEANER"; break;
		case 39: std::get<1>(result) = "FARMER"; break;
		case 40: std::get<1>(result) = "CHEESE_MAKER"; break;
		case 41: std::get<1>(result) = "MILKER"; break;
		case 42: std::get<1>(result) = "COOK"; break;
		case 43: std::get<1>(result) = "THRESHER"; break;
		case 44: std::get<1>(result) = "MILLER"; break;
		case 45: std::get<1>(result) = "BUTCHER"; break;
		case 46: std::get<1>(result) = "TANNER"; break;
		case 47: std::get<1>(result) = "DYER"; break;
		case 48: std::get<1>(result) = "PLANTER"; break;
		case 49: std::get<1>(result) = "HERBALIST"; break;
		case 50: std::get<1>(result) = "BREWER"; break;
		case 51: std::get<1>(result) = "SOAP_MAKER"; break;
		case 52: std::get<1>(result) = "POTASH_MAKER"; break;
		case 53: std::get<1>(result) = "LYE_MAKER"; break;
		case 54: std::get<1>(result) = "WOOD_BURNER"; break;
		case 55: std::get<1>(result) = "SHEARER"; break;
		case 56: std::get<1>(result) = "SPINNER"; break;
		case 57: std::get<1>(result) = "PRESSER"; break;
		case 58: std::get<1>(result) = "BEEKEEPER"; break;
		case 59: std::get<1>(result) = "ENGINEER"; break;
		case 60: std::get<1>(result) = "MECHANIC"; break;
		case 61: std::get<1>(result) = "SIEGE_ENGINEER"; break;
		case 62: std::get<1>(result) = "SIEGE_OPERATOR"; break;
		case 63: std::get<1>(result) = "PUMP_OPERATOR"; break;
		case 64: std::get<1>(result) = "CLERK"; break;
		case 65: std::get<1>(result) = "ADMINISTRATOR"; break;
		case 66: std::get<1>(result) = "TRADER"; break;
		case 67: std::get<1>(result) = "ARCHITECT"; break;
		case 68: std::get<1>(result) = "ALCHEMIST"; break;
		case 69: std::get<1>(result) = "DOCTOR"; break;
		case 70: std::get<1>(result) = "DIAGNOSER"; break;
		case 71: std::get<1>(result) = "BONE_SETTER"; break;
		case 72: std::get<1>(result) = "SUTURER"; break;
		case 73: std::get<1>(result) = "SURGEON"; break;
		case 74: std::get<1>(result) = "MERCHANT"; break;
		case 75: std::get<1>(result) = "HAMMERMAN"; break;
		case 76: std::get<1>(result) = "MASTER_HAMMERMAN"; break;
		case 77: std::get<1>(result) = "SPEARMAN"; break;
		case 78: std::get<1>(result) = "MASTER_SPEARMAN"; break;
		case 79: std::get<1>(result) = "CROSSBOWMAN"; break;
		case 80: std::get<1>(result) = "MASTER_CROSSBOWMAN"; break;
		case 81: std::get<1>(result) = "WRESTLER"; break;
		case 82: std::get<1>(result) = "MASTER_WRESTLER"; break;
		case 83: std::get<1>(result) = "AXEMAN"; break;
		case 84: std::get<1>(result) = "MASTER_AXEMAN"; break;
		case 85: std::get<1>(result) = "SWORDSMAN"; break;
		case 86: std::get<1>(result) = "MASTER_SWORDSMAN"; break;
		case 87: std::get<1>(result) = "MACEMAN"; break;
		case 88: std::get<1>(result) = "MASTER_MACEMAN"; break;
		case 89: std::get<1>(result) = "PIKEMAN"; break;
		case 90: std::get<1>(result) = "MASTER_PIKEMAN"; break;
		case 91: std::get<1>(result) = "BOWMAN"; break;
		case 92: std::get<1>(result) = "MASTER_BOWMAN"; break;
		case 93: std::get<1>(result) = "BLOWGUNMAN"; break;
		case 94: std::get<1>(result) = "MASTER_BLOWGUNMAN"; break;
		case 95: std::get<1>(result) = "LASHER"; break;
		case 96: std::get<1>(result) = "MASTER_LASHER"; break;
		case 97: std::get<1>(result) = "RECRUIT"; break;
		case 98: std::get<1>(result) = "TRAINED_HUNTER"; break;
		case 99: std::get<1>(result) = "TRAINED_WAR"; break;
		case 100: std::get<1>(result) = "MASTER_THIEF"; break;
		case 101: std::get<1>(result) = "THIEF"; break;
		case 102: std::get<1>(result) = "STANDARD"; break;
		case 103: std::get<1>(result) = "CHILD"; break;
		case 104: std::get<1>(result) = "BABY"; break;
		case 105: std::get<1>(result) = "DRUNK"; break;
		case 106: std::get<1>(result) = "MONSTER_SLAYER"; break;
		case 107: std::get<1>(result) = "SCOUT"; break;
		case 108: std::get<1>(result) = "BEAST_HUNTER"; break;
		case 109: std::get<1>(result) = "SNATCHER"; break;
		case 110: std::get<1>(result) = "MERCENARY"; break;
		case 111: std::get<1>(result) = "GELDER"; break;
		case 112: std::get<1>(result) = "PERFORMER"; break;
		case 113: std::get<1>(result) = "POET"; break;
		case 114: std::get<1>(result) = "BARD"; break;
		case 115: std::get<1>(result) = "DANCER"; break;
		case 116: std::get<1>(result) = "SAGE"; break;
		case 117: std::get<1>(result) = "SCHOLAR"; break;
		case 118: std::get<1>(result) = "PHILOSOPHER"; break;
		case 119: std::get<1>(result) = "MATHEMATICIAN"; break;
		case 120: std::get<1>(result) = "HISTORIAN"; break;
		case 121: std::get<1>(result) = "ASTRONOMER"; break;
		case 122: std::get<1>(result) = "NATURALIST"; break;
		case 123: std::get<1>(result) = "CHEMIST"; break;
		case 124: std::get<1>(result) = "GEOGRAPHER"; break;
		case 125: std::get<1>(result) = "SCRIBE"; break;
		case 126: std::get<1>(result) = "PAPERMAKER"; break;
		case 127: std::get<1>(result) = "BOOKBINDER"; break;
		case 128: std::get<1>(result) = "TAVERN_KEEPER"; break;
		case 129: std::get<1>(result) = "CRIMINAL"; break;
		case 130: std::get<1>(result) = "PEDDLER"; break;
		case 131: std::get<1>(result) = "PROPHET"; break;
		case 132: std::get<1>(result) = "PILGRIM"; break;
		case 133: std::get<1>(result) = "MONK"; break;
		case 134: std::get<1>(result) = "MESSENGER"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_labor_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -13: std::get<1>(result) = "Other"; break;
		case -12: std::get<1>(result) = "Hauling"; break;
		case -11: std::get<1>(result) = "Engineering"; break;
		case -10: std::get<1>(result) = "Crafts"; break;
		case -9: std::get<1>(result) = "Jewelry"; break;
		case -8: std::get<1>(result) = "Metalsmithing"; break;
		case -7: std::get<1>(result) = "Fishing"; break;
		case -6: std::get<1>(result) = "Farming"; break;
		case -5: std::get<1>(result) = "Healthcare"; break;
		case -4: std::get<1>(result) = "Hunting"; break;
		case -3: std::get<1>(result) = "Stoneworking"; break;
		case -2: std::get<1>(result) = "Woodworking"; break;
		case -1: std::get<1>(result) = "None"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_labor_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "MINE"; break;
		case 1: std::get<1>(result) = "HAUL_STONE"; break;
		case 2: std::get<1>(result) = "HAUL_WOOD"; break;
		case 3: std::get<1>(result) = "HAUL_BODY"; break;
		case 4: std::get<1>(result) = "HAUL_FOOD"; break;
		case 5: std::get<1>(result) = "HAUL_REFUSE"; break;
		case 6: std::get<1>(result) = "HAUL_ITEM"; break;
		case 7: std::get<1>(result) = "HAUL_FURNITURE"; break;
		case 8: std::get<1>(result) = "HAUL_ANIMALS"; break;
		case 9: std::get<1>(result) = "CLEAN"; break;
		case 10: std::get<1>(result) = "CUTWOOD"; break;
		case 11: std::get<1>(result) = "CARPENTER"; break;
		case 12: std::get<1>(result) = "DETAIL"; break;
		case 13: std::get<1>(result) = "MASON"; break;
		case 14: std::get<1>(result) = "ARCHITECT"; break;
		case 15: std::get<1>(result) = "ANIMALTRAIN"; break;
		case 16: std::get<1>(result) = "ANIMALCARE"; break;
		case 17: std::get<1>(result) = "DIAGNOSE"; break;
		case 18: std::get<1>(result) = "SURGERY"; break;
		case 19: std::get<1>(result) = "BONE_SETTING"; break;
		case 20: std::get<1>(result) = "SUTURING"; break;
		case 21: std::get<1>(result) = "DRESSING_WOUNDS"; break;
		case 22: std::get<1>(result) = "FEED_WATER_CIVILIANS"; break;
		case 23: std::get<1>(result) = "RECOVER_WOUNDED"; break;
		case 24: std::get<1>(result) = "BUTCHER"; break;
		case 25: std::get<1>(result) = "TRAPPER"; break;
		case 26: std::get<1>(result) = "DISSECT_VERMIN"; break;
		case 27: std::get<1>(result) = "LEATHER"; break;
		case 28: std::get<1>(result) = "TANNER"; break;
		case 29: std::get<1>(result) = "BREWER"; break;
		case 30: std::get<1>(result) = "ALCHEMIST"; break;
		case 31: std::get<1>(result) = "SOAP_MAKER"; break;
		case 32: std::get<1>(result) = "WEAVER"; break;
		case 33: std::get<1>(result) = "CLOTHESMAKER"; break;
		case 34: std::get<1>(result) = "MILLER"; break;
		case 35: std::get<1>(result) = "PROCESS_PLANT"; break;
		case 36: std::get<1>(result) = "MAKE_CHEESE"; break;
		case 37: std::get<1>(result) = "MILK"; break;
		case 38: std::get<1>(result) = "COOK"; break;
		case 39: std::get<1>(result) = "PLANT"; break;
		case 40: std::get<1>(result) = "HERBALIST"; break;
		case 41: std::get<1>(result) = "FISH"; break;
		case 42: std::get<1>(result) = "CLEAN_FISH"; break;
		case 43: std::get<1>(result) = "DISSECT_FISH"; break;
		case 44: std::get<1>(result) = "HUNT"; break;
		case 45: std::get<1>(result) = "SMELT"; break;
		case 46: std::get<1>(result) = "FORGE_WEAPON"; break;
		case 47: std::get<1>(result) = "FORGE_ARMOR"; break;
		case 48: std::get<1>(result) = "FORGE_FURNITURE"; break;
		case 49: std::get<1>(result) = "METAL_CRAFT"; break;
		case 50: std::get<1>(result) = "CUT_GEM"; break;
		case 51: std::get<1>(result) = "ENCRUST_GEM"; break;
		case 52: std::get<1>(result) = "WOOD_CRAFT"; break;
		case 53: std::get<1>(result) = "STONE_CRAFT"; break;
		case 54: std::get<1>(result) = "BONE_CARVE"; break;
		case 55: std::get<1>(result) = "GLASSMAKER"; break;
		case 56: std::get<1>(result) = "EXTRACT_STRAND"; break;
		case 57: std::get<1>(result) = "SIEGECRAFT"; break;
		case 58: std::get<1>(result) = "SIEGEOPERATE"; break;
		case 59: std::get<1>(result) = "BOWYER"; break;
		case 60: std::get<1>(result) = "MECHANIC"; break;
		case 61: std::get<1>(result) = "POTASH_MAKING"; break;
		case 62: std::get<1>(result) = "LYE_MAKING"; break;
		case 63: std::get<1>(result) = "DYER"; break;
		case 64: std::get<1>(result) = "BURN_WOOD"; break;
		case 65: std::get<1>(result) = "OPERATE_PUMP"; break;
		case 66: std::get<1>(result) = "SHEARER"; break;
		case 67: std::get<1>(result) = "SPINNER"; break;
		case 68: std::get<1>(result) = "POTTERY"; break;
		case 69: std::get<1>(result) = "GLAZING"; break;
		case 70: std::get<1>(result) = "PRESSING"; break;
		case 71: std::get<1>(result) = "BEEKEEPING"; break;
		case 72: std::get<1>(result) = "WAX_WORKING"; break;
		case 73: std::get<1>(result) = "HANDLE_VEHICLES"; break;
		case 74: std::get<1>(result) = "HAUL_TRADE"; break;
		case 75: std::get<1>(result) = "PULL_LEVER"; break;
		case 76: std::get<1>(result) = "REMOVE_CONSTRUCTION"; break;
		case 77: std::get<1>(result) = "HAUL_WATER"; break;
		case 78: std::get<1>(result) = "GELD"; break;
		case 79: std::get<1>(result) = "BUILD_ROAD"; break;
		case 80: std::get<1>(result) = "BUILD_CONSTRUCTION"; break;
		case 81: std::get<1>(result) = "PAPERMAKING"; break;
		case 82: std::get<1>(result) = "BOOKBINDING"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_job_skill_class_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Normal"; break;
		case 1: std::get<1>(result) = "Medical"; break;
		case 2: std::get<1>(result) = "Personal"; break;
		case 3: std::get<1>(result) = "Social"; break;
		case 4: std::get<1>(result) = "Cultural"; break;
		case 5: std::get<1>(result) = "MilitaryWeapon"; break;
		case 6: std::get<1>(result) = "MilitaryUnarmed"; break;
		case 7: std::get<1>(result) = "MilitaryAttack"; break;
		case 8: std::get<1>(result) = "MilitaryDefense"; break;
		case 9: std::get<1>(result) = "MilitaryMisc"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_job_skill_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "MINING"; break;
		case 1: std::get<1>(result) = "WOODCUTTING"; break;
		case 2: std::get<1>(result) = "CARPENTRY"; break;
		case 3: std::get<1>(result) = "DETAILSTONE"; break;
		case 4: std::get<1>(result) = "MASONRY"; break;
		case 5: std::get<1>(result) = "ANIMALTRAIN"; break;
		case 6: std::get<1>(result) = "ANIMALCARE"; break;
		case 7: std::get<1>(result) = "DISSECT_FISH"; break;
		case 8: std::get<1>(result) = "DISSECT_VERMIN"; break;
		case 9: std::get<1>(result) = "PROCESSFISH"; break;
		case 10: std::get<1>(result) = "BUTCHER"; break;
		case 11: std::get<1>(result) = "TRAPPING"; break;
		case 12: std::get<1>(result) = "TANNER"; break;
		case 13: std::get<1>(result) = "WEAVING"; break;
		case 14: std::get<1>(result) = "BREWING"; break;
		case 15: std::get<1>(result) = "ALCHEMY"; break;
		case 16: std::get<1>(result) = "CLOTHESMAKING"; break;
		case 17: std::get<1>(result) = "MILLING"; break;
		case 18: std::get<1>(result) = "PROCESSPLANTS"; break;
		case 19: std::get<1>(result) = "CHEESEMAKING"; break;
		case 20: std::get<1>(result) = "MILK"; break;
		case 21: std::get<1>(result) = "COOK"; break;
		case 22: std::get<1>(result) = "PLANT"; break;
		case 23: std::get<1>(result) = "HERBALISM"; break;
		case 24: std::get<1>(result) = "FISH"; break;
		case 25: std::get<1>(result) = "SMELT"; break;
		case 26: std::get<1>(result) = "EXTRACT_STRAND"; break;
		case 27: std::get<1>(result) = "FORGE_WEAPON"; break;
		case 28: std::get<1>(result) = "FORGE_ARMOR"; break;
		case 29: std::get<1>(result) = "FORGE_FURNITURE"; break;
		case 30: std::get<1>(result) = "CUTGEM"; break;
		case 31: std::get<1>(result) = "ENCRUSTGEM"; break;
		case 32: std::get<1>(result) = "WOODCRAFT"; break;
		case 33: std::get<1>(result) = "STONECRAFT"; break;
		case 34: std::get<1>(result) = "METALCRAFT"; break;
		case 35: std::get<1>(result) = "GLASSMAKER"; break;
		case 36: std::get<1>(result) = "LEATHERWORK"; break;
		case 37: std::get<1>(result) = "BONECARVE"; break;
		case 38: std::get<1>(result) = "AXE"; break;
		case 39: std::get<1>(result) = "SWORD"; break;
		case 40: std::get<1>(result) = "DAGGER"; break;
		case 41: std::get<1>(result) = "MACE"; break;
		case 42: std::get<1>(result) = "HAMMER"; break;
		case 43: std::get<1>(result) = "SPEAR"; break;
		case 44: std::get<1>(result) = "CROSSBOW"; break;
		case 45: std::get<1>(result) = "SHIELD"; break;
		case 46: std::get<1>(result) = "ARMOR"; break;
		case 47: std::get<1>(result) = "SIEGECRAFT"; break;
		case 48: std::get<1>(result) = "SIEGEOPERATE"; break;
		case 49: std::get<1>(result) = "BOWYER"; break;
		case 50: std::get<1>(result) = "PIKE"; break;
		case 51: std::get<1>(result) = "WHIP"; break;
		case 52: std::get<1>(result) = "BOW"; break;
		case 53: std::get<1>(result) = "BLOWGUN"; break;
		case 54: std::get<1>(result) = "THROW"; break;
		case 55: std::get<1>(result) = "MECHANICS"; break;
		case 56: std::get<1>(result) = "MAGIC_NATURE"; break;
		case 57: std::get<1>(result) = "SNEAK"; break;
		case 58: std::get<1>(result) = "DESIGNBUILDING"; break;
		case 59: std::get<1>(result) = "DRESS_WOUNDS"; break;
		case 60: std::get<1>(result) = "DIAGNOSE"; break;
		case 61: std::get<1>(result) = "SURGERY"; break;
		case 62: std::get<1>(result) = "SET_BONE"; break;
		case 63: std::get<1>(result) = "SUTURE"; break;
		case 64: std::get<1>(result) = "CRUTCH_WALK"; break;
		case 65: std::get<1>(result) = "WOOD_BURNING"; break;
		case 66: std::get<1>(result) = "LYE_MAKING"; break;
		case 67: std::get<1>(result) = "SOAP_MAKING"; break;
		case 68: std::get<1>(result) = "POTASH_MAKING"; break;
		case 69: std::get<1>(result) = "DYER"; break;
		case 70: std::get<1>(result) = "OPERATE_PUMP"; break;
		case 71: std::get<1>(result) = "SWIMMING"; break;
		case 72: std::get<1>(result) = "PERSUASION"; break;
		case 73: std::get<1>(result) = "NEGOTIATION"; break;
		case 74: std::get<1>(result) = "JUDGING_INTENT"; break;
		case 75: std::get<1>(result) = "APPRAISAL"; break;
		case 76: std::get<1>(result) = "ORGANIZATION"; break;
		case 77: std::get<1>(result) = "RECORD_KEEPING"; break;
		case 78: std::get<1>(result) = "LYING"; break;
		case 79: std::get<1>(result) = "INTIMIDATION"; break;
		case 80: std::get<1>(result) = "CONVERSATION"; break;
		case 81: std::get<1>(result) = "COMEDY"; break;
		case 82: std::get<1>(result) = "FLATTERY"; break;
		case 83: std::get<1>(result) = "CONSOLE"; break;
		case 84: std::get<1>(result) = "PACIFY"; break;
		case 85: std::get<1>(result) = "TRACKING"; break;
		case 86: std::get<1>(result) = "KNOWLEDGE_ACQUISITION"; break;
		case 87: std::get<1>(result) = "CONCENTRATION"; break;
		case 88: std::get<1>(result) = "DISCIPLINE"; break;
		case 89: std::get<1>(result) = "SITUATIONAL_AWARENESS"; break;
		case 90: std::get<1>(result) = "WRITING"; break;
		case 91: std::get<1>(result) = "PROSE"; break;
		case 92: std::get<1>(result) = "POETRY"; break;
		case 93: std::get<1>(result) = "READING"; break;
		case 94: std::get<1>(result) = "SPEAKING"; break;
		case 95: std::get<1>(result) = "COORDINATION"; break;
		case 96: std::get<1>(result) = "BALANCE"; break;
		case 97: std::get<1>(result) = "LEADERSHIP"; break;
		case 98: std::get<1>(result) = "TEACHING"; break;
		case 99: std::get<1>(result) = "MELEE_COMBAT"; break;
		case 100: std::get<1>(result) = "RANGED_COMBAT"; break;
		case 101: std::get<1>(result) = "WRESTLING"; break;
		case 102: std::get<1>(result) = "BITE"; break;
		case 103: std::get<1>(result) = "GRASP_STRIKE"; break;
		case 104: std::get<1>(result) = "STANCE_STRIKE"; break;
		case 105: std::get<1>(result) = "DODGING"; break;
		case 106: std::get<1>(result) = "MISC_WEAPON"; break;
		case 107: std::get<1>(result) = "KNAPPING"; break;
		case 108: std::get<1>(result) = "MILITARY_TACTICS"; break;
		case 109: std::get<1>(result) = "SHEARING"; break;
		case 110: std::get<1>(result) = "SPINNING"; break;
		case 111: std::get<1>(result) = "POTTERY"; break;
		case 112: std::get<1>(result) = "GLAZING"; break;
		case 113: std::get<1>(result) = "PRESSING"; break;
		case 114: std::get<1>(result) = "BEEKEEPING"; break;
		case 115: std::get<1>(result) = "WAX_WORKING"; break;
		case 116: std::get<1>(result) = "CLIMBING"; break;
		case 117: std::get<1>(result) = "GELD"; break;
		case 118: std::get<1>(result) = "DANCE"; break;
		case 119: std::get<1>(result) = "MAKE_MUSIC"; break;
		case 120: std::get<1>(result) = "SING_MUSIC"; break;
		case 121: std::get<1>(result) = "PLAY_KEYBOARD_INSTRUMENT"; break;
		case 122: std::get<1>(result) = "PLAY_STRINGED_INSTRUMENT"; break;
		case 123: std::get<1>(result) = "PLAY_WIND_INSTRUMENT"; break;
		case 124: std::get<1>(result) = "PLAY_PERCUSSION_INSTRUMENT"; break;
		case 125: std::get<1>(result) = "CRITICAL_THINKING"; break;
		case 126: std::get<1>(result) = "LOGIC"; break;
		case 127: std::get<1>(result) = "MATHEMATICS"; break;
		case 128: std::get<1>(result) = "ASTRONOMY"; break;
		case 129: std::get<1>(result) = "CHEMISTRY"; break;
		case 130: std::get<1>(result) = "GEOGRAPHY"; break;
		case 131: std::get<1>(result) = "OPTICS_ENGINEER"; break;
		case 132: std::get<1>(result) = "FLUID_ENGINEER"; break;
		case 133: std::get<1>(result) = "PAPERMAKING"; break;
		case 134: std::get<1>(result) = "BOOKBINDING"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_hauler_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Any"; break;
		case 1: std::get<1>(result) = "Stone"; break;
		case 2: std::get<1>(result) = "Wood"; break;
		case 3: std::get<1>(result) = "Item"; break;
		case 4: std::get<1>(result) = "Bin"; break;
		case 5: std::get<1>(result) = "Body"; break;
		case 6: std::get<1>(result) = "Food"; break;
		case 7: std::get<1>(result) = "Refuse"; break;
		case 8: std::get<1>(result) = "Furniture"; break;
		case 9: std::get<1>(result) = "Animal"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_furniture_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "FLOODGATE"; break;
		case 1: std::get<1>(result) = "HATCH_COVER"; break;
		case 2: std::get<1>(result) = "GRATE"; break;
		case 3: std::get<1>(result) = "DOOR"; break;
		case 4: std::get<1>(result) = "CATAPULTPARTS"; break;
		case 5: std::get<1>(result) = "BALLISTAPARTS"; break;
		case 6: std::get<1>(result) = "TRAPPARTS"; break;
		case 7: std::get<1>(result) = "BED"; break;
		case 8: std::get<1>(result) = "TRACTION_BENCH"; break;
		case 9: std::get<1>(result) = "WINDOW"; break;
		case 10: std::get<1>(result) = "CHAIR"; break;
		case 11: std::get<1>(result) = "TABLE"; break;
		case 12: std::get<1>(result) = "COFFIN"; break;
		case 13: std::get<1>(result) = "STATUE"; break;
		case 14: std::get<1>(result) = "SLAB"; break;
		case 15: std::get<1>(result) = "QUERN"; break;
		case 16: std::get<1>(result) = "MILLSTONE"; break;
		case 17: std::get<1>(result) = "ARMORSTAND"; break;
		case 18: std::get<1>(result) = "WEAPONRACK"; break;
		case 19: std::get<1>(result) = "CABINET"; break;
		case 20: std::get<1>(result) = "ANVIL"; break;
		case 21: std::get<1>(result) = "BUCKET"; break;
		case 22: std::get<1>(result) = "BIN"; break;
		case 23: std::get<1>(result) = "BOX"; break;
		case 24: std::get<1>(result) = "SIEGEAMMO"; break;
		case 25: std::get<1>(result) = "BARREL"; break;
		case 26: std::get<1>(result) = "BALLISTAARROWHEAD"; break;
		case 27: std::get<1>(result) = "PIPE_SECTION"; break;
		case 28: std::get<1>(result) = "FOOD_STORAGE"; break;
		case 29: std::get<1>(result) = "MINECART"; break;
		case 30: std::get<1>(result) = "WHEELBARROW"; break;
		case 31: std::get<1>(result) = "OTHER_LARGE_TOOLS"; break;
		case 32: std::get<1>(result) = "SAND_BAG"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_stockpile_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "Remove"; break;
		case 0: std::get<1>(result) = "Animals"; break;
		case 1: std::get<1>(result) = "Food"; break;
		case 2: std::get<1>(result) = "Furniture"; break;
		case 3: std::get<1>(result) = "Corpses"; break;
		case 4: std::get<1>(result) = "Refuse"; break;
		case 5: std::get<1>(result) = "Stone"; break;
		case 6: std::get<1>(result) = "Ore"; break;
		case 7: std::get<1>(result) = "Ammo"; break;
		case 8: std::get<1>(result) = "Coins"; break;
		case 9: std::get<1>(result) = "Bars"; break;
		case 10: std::get<1>(result) = "Gems"; break;
		case 11: std::get<1>(result) = "Goods"; break;
		case 12: std::get<1>(result) = "Leather"; break;
		case 13: std::get<1>(result) = "Cloth"; break;
		case 14: std::get<1>(result) = "Wood"; break;
		case 15: std::get<1>(result) = "Weapons"; break;
		case 16: std::get<1>(result) = "Armor"; break;
		case 17: std::get<1>(result) = "Sheets"; break;
		case 18: std::get<1>(result) = "Custom"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_stockpile_list_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Animals"; break;
		case 1: std::get<1>(result) = "Food"; break;
		case 2: std::get<1>(result) = "FoodMeat"; break;
		case 3: std::get<1>(result) = "FoodFish"; break;
		case 4: std::get<1>(result) = "FoodUnpreparedFish"; break;
		case 5: std::get<1>(result) = "FoodEgg"; break;
		case 6: std::get<1>(result) = "FoodPlants"; break;
		case 7: std::get<1>(result) = "FoodDrinkPlant"; break;
		case 8: std::get<1>(result) = "FoodDrinkAnimal"; break;
		case 9: std::get<1>(result) = "FoodCheesePlant"; break;
		case 10: std::get<1>(result) = "FoodCheeseAnimal"; break;
		case 11: std::get<1>(result) = "FoodSeeds"; break;
		case 12: std::get<1>(result) = "FoodLeaves"; break;
		case 13: std::get<1>(result) = "FoodMilledPlant"; break;
		case 14: std::get<1>(result) = "FoodBoneMeal"; break;
		case 15: std::get<1>(result) = "FoodFat"; break;
		case 16: std::get<1>(result) = "FoodPaste"; break;
		case 17: std::get<1>(result) = "FoodPressedMaterial"; break;
		case 18: std::get<1>(result) = "FoodExtractPlant"; break;
		case 19: std::get<1>(result) = "FoodExtractAnimal"; break;
		case 20: std::get<1>(result) = "FoodMiscLiquid"; break;
		case 21: std::get<1>(result) = "Furniture"; break;
		case 22: std::get<1>(result) = "FurnitureType"; break;
		case 23: std::get<1>(result) = "FurnitureStoneClay"; break;
		case 24: std::get<1>(result) = "FurnitureMetal"; break;
		case 25: std::get<1>(result) = "FurnitureOtherMaterials"; break;
		case 26: std::get<1>(result) = "FurnitureCoreQuality"; break;
		case 27: std::get<1>(result) = "FurnitureTotalQuality"; break;
		case 28: std::get<1>(result) = "Corpses"; break;
		case 29: std::get<1>(result) = "Refuse"; break;
		case 30: std::get<1>(result) = "RefuseItems"; break;
		case 31: std::get<1>(result) = "RefuseCorpses"; break;
		case 32: std::get<1>(result) = "RefuseParts"; break;
		case 33: std::get<1>(result) = "RefuseSkulls"; break;
		case 34: std::get<1>(result) = "RefuseBones"; break;
		case 35: std::get<1>(result) = "RefuseShells"; break;
		case 36: std::get<1>(result) = "RefuseTeeth"; break;
		case 37: std::get<1>(result) = "RefuseHorns"; break;
		case 38: std::get<1>(result) = "RefuseHair"; break;
		case 39: std::get<1>(result) = "Stone"; break;
		case 40: std::get<1>(result) = "StoneOres"; break;
		case 41: std::get<1>(result) = "StoneEconomic"; break;
		case 42: std::get<1>(result) = "StoneOther"; break;
		case 43: std::get<1>(result) = "StoneClay"; break;
		case 44: std::get<1>(result) = "Ammo"; break;
		case 45: std::get<1>(result) = "AmmoType"; break;
		case 46: std::get<1>(result) = "AmmoMetal"; break;
		case 47: std::get<1>(result) = "AmmoOther"; break;
		case 48: std::get<1>(result) = "AmmoCoreQuality"; break;
		case 49: std::get<1>(result) = "AmmoTotalQuality"; break;
		case 50: std::get<1>(result) = "Coins"; break;
		case 51: std::get<1>(result) = "BarsBlocks"; break;
		case 52: std::get<1>(result) = "BarsMetal"; break;
		case 53: std::get<1>(result) = "BarsOther"; break;
		case 54: std::get<1>(result) = "BlocksStone"; break;
		case 55: std::get<1>(result) = "BlocksMetal"; break;
		case 56: std::get<1>(result) = "BlocksOther"; break;
		case 57: std::get<1>(result) = "Gems"; break;
		case 58: std::get<1>(result) = "RoughGem"; break;
		case 59: std::get<1>(result) = "RoughGlass"; break;
		case 60: std::get<1>(result) = "CutGem"; break;
		case 61: std::get<1>(result) = "CutGlass"; break;
		case 62: std::get<1>(result) = "CutStone"; break;
		case 63: std::get<1>(result) = "Goods"; break;
		case 64: std::get<1>(result) = "GoodsType"; break;
		case 65: std::get<1>(result) = "GoodsStone"; break;
		case 66: std::get<1>(result) = "GoodsMetal"; break;
		case 67: std::get<1>(result) = "GoodsGem"; break;
		case 68: std::get<1>(result) = "GoodsOther"; break;
		case 69: std::get<1>(result) = "GoodsCoreQuality"; break;
		case 70: std::get<1>(result) = "GoodsTotalQuality"; break;
		case 71: std::get<1>(result) = "Leather"; break;
		case 72: std::get<1>(result) = "Cloth"; break;
		case 73: std::get<1>(result) = "ThreadSilk"; break;
		case 74: std::get<1>(result) = "ThreadPlant"; break;
		case 75: std::get<1>(result) = "ThreadYarn"; break;
		case 76: std::get<1>(result) = "ThreadMetal"; break;
		case 77: std::get<1>(result) = "ClothSilk"; break;
		case 78: std::get<1>(result) = "ClothPlant"; break;
		case 79: std::get<1>(result) = "ClothYarn"; break;
		case 80: std::get<1>(result) = "ClothMetal"; break;
		case 81: std::get<1>(result) = "Wood"; break;
		case 82: std::get<1>(result) = "Weapons"; break;
		case 83: std::get<1>(result) = "WeaponsType"; break;
		case 84: std::get<1>(result) = "WeaponsTrapcomp"; break;
		case 85: std::get<1>(result) = "WeaponsMetal"; break;
		case 86: std::get<1>(result) = "WeaponsStone"; break;
		case 87: std::get<1>(result) = "WeaponsOther"; break;
		case 88: std::get<1>(result) = "WeaponsCoreQuality"; break;
		case 89: std::get<1>(result) = "WeaponsTotalQuality"; break;
		case 90: std::get<1>(result) = "Armor"; break;
		case 91: std::get<1>(result) = "ArmorBody"; break;
		case 92: std::get<1>(result) = "ArmorHead"; break;
		case 93: std::get<1>(result) = "ArmorFeet"; break;
		case 94: std::get<1>(result) = "ArmorHands"; break;
		case 95: std::get<1>(result) = "ArmorLegs"; break;
		case 96: std::get<1>(result) = "ArmorShield"; break;
		case 97: std::get<1>(result) = "ArmorMetal"; break;
		case 98: std::get<1>(result) = "ArmorOther"; break;
		case 99: std::get<1>(result) = "ArmorCoreQuality"; break;
		case 100: std::get<1>(result) = "ArmorTotalQuality"; break;
		case 101: std::get<1>(result) = "Sheet"; break;
		case 102: std::get<1>(result) = "SheetPaper"; break;
		case 103: std::get<1>(result) = "SheetParchment"; break;
		case 104: std::get<1>(result) = "AdditionalOptions"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_creature_interaction_effect_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "PAIN"; break;
		case 1: std::get<1>(result) = "SWELLING"; break;
		case 2: std::get<1>(result) = "OOZING"; break;
		case 3: std::get<1>(result) = "BRUISING"; break;
		case 4: std::get<1>(result) = "BLISTERS"; break;
		case 5: std::get<1>(result) = "NUMBNESS"; break;
		case 6: std::get<1>(result) = "PARALYSIS"; break;
		case 7: std::get<1>(result) = "FEVER"; break;
		case 8: std::get<1>(result) = "BLEEDING"; break;
		case 9: std::get<1>(result) = "COUGH_BLOOD"; break;
		case 10: std::get<1>(result) = "VOMIT_BLOOD"; break;
		case 11: std::get<1>(result) = "NAUSEA"; break;
		case 12: std::get<1>(result) = "UNCONSCIOUSNESS"; break;
		case 13: std::get<1>(result) = "NECROSIS"; break;
		case 14: std::get<1>(result) = "IMPAIR_FUNCTION"; break;
		case 15: std::get<1>(result) = "DROWSINESS"; break;
		case 16: std::get<1>(result) = "DIZZINESS"; break;
		case 17: std::get<1>(result) = "ADD_TAG"; break;
		case 18: std::get<1>(result) = "REMOVE_TAG"; break;
		case 19: std::get<1>(result) = "DISPLAY_TILE"; break;
		case 20: std::get<1>(result) = "FLASH_TILE"; break;
		case 21: std::get<1>(result) = "SPEED_CHANGE"; break;
		case 22: std::get<1>(result) = "CAN_DO_INTERACTION"; break;
		case 23: std::get<1>(result) = "SKILL_ROLL_ADJUST"; break;
		case 24: std::get<1>(result) = "BODY_TRANSFORMATION"; break;
		case 25: std::get<1>(result) = "PHYS_ATT_CHANGE"; break;
		case 26: std::get<1>(result) = "MENT_ATT_CHANGE"; break;
		case 27: std::get<1>(result) = "MATERIAL_FORCE_MULTIPLIER"; break;
		case 28: std::get<1>(result) = "BODY_MAT_INTERACTION"; break;
		case 29: std::get<1>(result) = "BODY_APPEARANCE_MODIFIER"; break;
		case 30: std::get<1>(result) = "BP_APPEARANCE_MODIFIER"; break;
		case 31: std::get<1>(result) = "DISPLAY_NAME"; break;
		case 32: std::get<1>(result) = "SENSE_CREATURE_CLASS"; break;
		case 33: std::get<1>(result) = "FEEL_EMOTION"; break;
		case 34: std::get<1>(result) = "CHANGE_PERSONALITY"; break;
		case 35: std::get<1>(result) = "ERRATIC_BEHAVIOR"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_creature_interaction_effect_target_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "BY_TYPE"; break;
		case 1: std::get<1>(result) = "BY_TOKEN"; break;
		case 2: std::get<1>(result) = "BY_CATEGORY"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tiletype_shape_basic_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Open"; break;
		case 1: std::get<1>(result) = "Floor"; break;
		case 2: std::get<1>(result) = "Ramp"; break;
		case 3: std::get<1>(result) = "Wall"; break;
		case 4: std::get<1>(result) = "Stair"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tiletype_shape_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "EMPTY"; break;
		case 1: std::get<1>(result) = "FLOOR"; break;
		case 2: std::get<1>(result) = "BOULDER"; break;
		case 3: std::get<1>(result) = "PEBBLES"; break;
		case 4: std::get<1>(result) = "WALL"; break;
		case 5: std::get<1>(result) = "FORTIFICATION"; break;
		case 6: std::get<1>(result) = "STAIR_UP"; break;
		case 7: std::get<1>(result) = "STAIR_DOWN"; break;
		case 8: std::get<1>(result) = "STAIR_UPDOWN"; break;
		case 9: std::get<1>(result) = "RAMP"; break;
		case 10: std::get<1>(result) = "RAMP_TOP"; break;
		case 11: std::get<1>(result) = "BROOK_BED"; break;
		case 12: std::get<1>(result) = "BROOK_TOP"; break;
		case 13: std::get<1>(result) = "BRANCH"; break;
		case 14: std::get<1>(result) = "TRUNK_BRANCH"; break;
		case 15: std::get<1>(result) = "TWIG"; break;
		case 16: std::get<1>(result) = "SAPLING"; break;
		case 17: std::get<1>(result) = "SHRUB"; break;
		case 18: std::get<1>(result) = "ENDLESS_PIT"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tiletype_material_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "AIR"; break;
		case 1: std::get<1>(result) = "SOIL"; break;
		case 2: std::get<1>(result) = "STONE"; break;
		case 3: std::get<1>(result) = "FEATURE"; break;
		case 4: std::get<1>(result) = "LAVA_STONE"; break;
		case 5: std::get<1>(result) = "MINERAL"; break;
		case 6: std::get<1>(result) = "FROZEN_LIQUID"; break;
		case 7: std::get<1>(result) = "CONSTRUCTION"; break;
		case 8: std::get<1>(result) = "GRASS_LIGHT"; break;
		case 9: std::get<1>(result) = "GRASS_DARK"; break;
		case 10: std::get<1>(result) = "GRASS_DRY"; break;
		case 11: std::get<1>(result) = "GRASS_DEAD"; break;
		case 12: std::get<1>(result) = "PLANT"; break;
		case 13: std::get<1>(result) = "HFS"; break;
		case 14: std::get<1>(result) = "CAMPFIRE"; break;
		case 15: std::get<1>(result) = "FIRE"; break;
		case 16: std::get<1>(result) = "ASHES"; break;
		case 17: std::get<1>(result) = "MAGMA"; break;
		case 18: std::get<1>(result) = "DRIFTWOOD"; break;
		case 19: std::get<1>(result) = "POOL"; break;
		case 20: std::get<1>(result) = "BROOK"; break;
		case 21: std::get<1>(result) = "RIVER"; break;
		case 22: std::get<1>(result) = "ROOT"; break;
		case 23: std::get<1>(result) = "TREE"; break;
		case 24: std::get<1>(result) = "MUSHROOM"; break;
		case 25: std::get<1>(result) = "UNDERWORLD_GATE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tiletype_variant_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "VAR_1"; break;
		case 1: std::get<1>(result) = "VAR_2"; break;
		case 2: std::get<1>(result) = "VAR_3"; break;
		case 3: std::get<1>(result) = "VAR_4"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tiletype_special_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "NORMAL"; break;
		case 1: std::get<1>(result) = "RIVER_SOURCE"; break;
		case 2: std::get<1>(result) = "WATERFALL"; break;
		case 3: std::get<1>(result) = "SMOOTH"; break;
		case 4: std::get<1>(result) = "FURROWED"; break;
		case 5: std::get<1>(result) = "WET"; break;
		case 6: std::get<1>(result) = "DEAD"; break;
		case 7: std::get<1>(result) = "WORN_1"; break;
		case 8: std::get<1>(result) = "WORN_2"; break;
		case 9: std::get<1>(result) = "WORN_3"; break;
		case 10: std::get<1>(result) = "TRACK"; break;
		case 11: std::get<1>(result) = "SMOOTH_DEAD"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tiletype_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Void"; break;
		case 1: std::get<1>(result) = "RampTop"; break;
		case 2: std::get<1>(result) = "MurkyPool"; break;
		case 3: std::get<1>(result) = "MurkyPoolRamp"; break;
		case 4: std::get<1>(result) = "UnderworldGateStairU"; break;
		case 5: std::get<1>(result) = "UnderworldGateStairD"; break;
		case 6: std::get<1>(result) = "UnderworldGateStairUD"; break;
		case 7: std::get<1>(result) = "anon_1"; break;
		case 8: std::get<1>(result) = "anon_2"; break;
		case 9: std::get<1>(result) = "anon_3"; break;
		case 10: std::get<1>(result) = "anon_4"; break;
		case 11: std::get<1>(result) = "anon_5"; break;
		case 12: std::get<1>(result) = "anon_6"; break;
		case 13: std::get<1>(result) = "anon_7"; break;
		case 14: std::get<1>(result) = "anon_8"; break;
		case 15: std::get<1>(result) = "anon_9"; break;
		case 16: std::get<1>(result) = "anon_10"; break;
		case 17: std::get<1>(result) = "anon_11"; break;
		case 18: std::get<1>(result) = "anon_12"; break;
		case 19: std::get<1>(result) = "Driftwood"; break;
		case 20: std::get<1>(result) = "anon_13"; break;
		case 21: std::get<1>(result) = "anon_14"; break;
		case 22: std::get<1>(result) = "anon_15"; break;
		case 23: std::get<1>(result) = "anon_16"; break;
		case 24: std::get<1>(result) = "anon_17"; break;
		case 25: std::get<1>(result) = "FrozenStairUD"; break;
		case 26: std::get<1>(result) = "FrozenStairD"; break;
		case 27: std::get<1>(result) = "FrozenStairU"; break;
		case 28: std::get<1>(result) = "anon_18"; break;
		case 29: std::get<1>(result) = "anon_19"; break;
		case 30: std::get<1>(result) = "anon_20"; break;
		case 31: std::get<1>(result) = "anon_21"; break;
		case 32: std::get<1>(result) = "OpenSpace"; break;
		case 33: std::get<1>(result) = "anon_22"; break;
		case 34: std::get<1>(result) = "Shrub"; break;
		case 35: std::get<1>(result) = "Chasm"; break;
		case 36: std::get<1>(result) = "LavaStairUD"; break;
		case 37: std::get<1>(result) = "LavaStairD"; break;
		case 38: std::get<1>(result) = "LavaStairU"; break;
		case 39: std::get<1>(result) = "SoilStairUD"; break;
		case 40: std::get<1>(result) = "SoilStairD"; break;
		case 41: std::get<1>(result) = "SoilStairU"; break;
		case 42: std::get<1>(result) = "EeriePit"; break;
		case 43: std::get<1>(result) = "StoneFloorSmooth"; break;
		case 44: std::get<1>(result) = "LavaFloorSmooth"; break;
		case 45: std::get<1>(result) = "FeatureFloorSmooth"; break;
		case 46: std::get<1>(result) = "MineralFloorSmooth"; break;
		case 47: std::get<1>(result) = "FrozenFloorSmooth"; break;
		case 48: std::get<1>(result) = "anon_23"; break;
		case 49: std::get<1>(result) = "Grass1StairUD"; break;
		case 50: std::get<1>(result) = "Grass1StairD"; break;
		case 51: std::get<1>(result) = "Grass1StairU"; break;
		case 52: std::get<1>(result) = "Grass2StairUD"; break;
		case 53: std::get<1>(result) = "Grass2StairD"; break;
		case 54: std::get<1>(result) = "Grass2StairU"; break;
		case 55: std::get<1>(result) = "StoneStairUD"; break;
		case 56: std::get<1>(result) = "StoneStairD"; break;
		case 57: std::get<1>(result) = "StoneStairU"; break;
		case 58: std::get<1>(result) = "MineralStairUD"; break;
		case 59: std::get<1>(result) = "MineralStairD"; break;
		case 60: std::get<1>(result) = "MineralStairU"; break;
		case 61: std::get<1>(result) = "FeatureStairUD"; break;
		case 62: std::get<1>(result) = "FeatureStairD"; break;
		case 63: std::get<1>(result) = "FeatureStairU"; break;
		case 64: std::get<1>(result) = "anon_24"; break;
		case 65: std::get<1>(result) = "StoneFortification"; break;
		case 66: std::get<1>(result) = "anon_25"; break;
		case 67: std::get<1>(result) = "Campfire"; break;
		case 68: std::get<1>(result) = "anon_26"; break;
		case 69: std::get<1>(result) = "anon_27"; break;
		case 70: std::get<1>(result) = "Fire"; break;
		case 71: std::get<1>(result) = "BurningTreeTrunk"; break;
		case 72: std::get<1>(result) = "BurningTreeBranches"; break;
		case 73: std::get<1>(result) = "BurningTreeTwigs"; break;
		case 74: std::get<1>(result) = "BurningTreeCapWall"; break;
		case 75: std::get<1>(result) = "BurningTreeCapRamp"; break;
		case 76: std::get<1>(result) = "BurningTreeCapFloor"; break;
		case 77: std::get<1>(result) = "anon_28"; break;
		case 78: std::get<1>(result) = "anon_29"; break;
		case 79: std::get<1>(result) = "StonePillar"; break;
		case 80: std::get<1>(result) = "LavaPillar"; break;
		case 81: std::get<1>(result) = "FeaturePillar"; break;
		case 82: std::get<1>(result) = "MineralPillar"; break;
		case 83: std::get<1>(result) = "FrozenPillar"; break;
		case 84: std::get<1>(result) = "anon_30"; break;
		case 85: std::get<1>(result) = "anon_31"; break;
		case 86: std::get<1>(result) = "anon_32"; break;
		case 87: std::get<1>(result) = "anon_33"; break;
		case 88: std::get<1>(result) = "anon_34"; break;
		case 89: std::get<1>(result) = "Waterfall"; break;
		case 90: std::get<1>(result) = "RiverSource"; break;
		case 91: std::get<1>(result) = "TreeRootSloping"; break;
		case 92: std::get<1>(result) = "TreeRoots"; break;
		case 93: std::get<1>(result) = "TreeTrunkPillar"; break;
		case 94: std::get<1>(result) = "TreeTrunkSloping"; break;
		case 95: std::get<1>(result) = "TreeTrunkN"; break;
		case 96: std::get<1>(result) = "TreeTrunkS"; break;
		case 97: std::get<1>(result) = "TreeTrunkE"; break;
		case 98: std::get<1>(result) = "TreeTrunkW"; break;
		case 99: std::get<1>(result) = "TreeTrunkNW"; break;
		case 100: std::get<1>(result) = "TreeTrunkNE"; break;
		case 101: std::get<1>(result) = "TreeTrunkSW"; break;
		case 102: std::get<1>(result) = "TreeTrunkSE"; break;
		case 103: std::get<1>(result) = "TreeTrunkBranchN"; break;
		case 104: std::get<1>(result) = "TreeTrunkBranchS"; break;
		case 105: std::get<1>(result) = "TreeTrunkBranchE"; break;
		case 106: std::get<1>(result) = "TreeTrunkBranchW"; break;
		case 107: std::get<1>(result) = "TreeBranchNS"; break;
		case 108: std::get<1>(result) = "TreeBranchEW"; break;
		case 109: std::get<1>(result) = "TreeBranchesSmooth"; break;
		case 110: std::get<1>(result) = "TreeDeadBranchesSmooth"; break;
		case 111: std::get<1>(result) = "TreeBranchNW"; break;
		case 112: std::get<1>(result) = "TreeBranchNE"; break;
		case 113: std::get<1>(result) = "TreeBranchSW"; break;
		case 114: std::get<1>(result) = "TreeBranchSE"; break;
		case 115: std::get<1>(result) = "TreeBranches"; break;
		case 116: std::get<1>(result) = "TreeTwigs"; break;
		case 117: std::get<1>(result) = "TreeCapRamp"; break;
		case 118: std::get<1>(result) = "TreeCapPillar"; break;
		case 119: std::get<1>(result) = "TreeCapWallN"; break;
		case 120: std::get<1>(result) = "TreeCapWallS"; break;
		case 121: std::get<1>(result) = "TreeCapWallE"; break;
		case 122: std::get<1>(result) = "TreeCapWallW"; break;
		case 123: std::get<1>(result) = "TreeCapWallNW"; break;
		case 124: std::get<1>(result) = "TreeCapWallNE"; break;
		case 125: std::get<1>(result) = "TreeCapWallSW"; break;
		case 126: std::get<1>(result) = "TreeCapWallSE"; break;
		case 127: std::get<1>(result) = "TreeCapFloor1"; break;
		case 128: std::get<1>(result) = "TreeCapFloor2"; break;
		case 129: std::get<1>(result) = "TreeCapFloor3"; break;
		case 130: std::get<1>(result) = "TreeCapFloor4"; break;
		case 131: std::get<1>(result) = "TreeDeadRootSloping"; break;
		case 132: std::get<1>(result) = "TreeDeadRoots"; break;
		case 133: std::get<1>(result) = "TreeDeadTrunkPillar"; break;
		case 134: std::get<1>(result) = "TreeDeadTrunkSloping"; break;
		case 135: std::get<1>(result) = "TreeDeadTrunkN"; break;
		case 136: std::get<1>(result) = "TreeDeadTrunkS"; break;
		case 137: std::get<1>(result) = "TreeDeadTrunkE"; break;
		case 138: std::get<1>(result) = "TreeDeadTrunkW"; break;
		case 139: std::get<1>(result) = "TreeDeadTrunkNW"; break;
		case 140: std::get<1>(result) = "TreeDeadTrunkNE"; break;
		case 141: std::get<1>(result) = "TreeDeadTrunkSW"; break;
		case 142: std::get<1>(result) = "TreeDeadTrunkSE"; break;
		case 143: std::get<1>(result) = "TreeDeadTrunkBranchN"; break;
		case 144: std::get<1>(result) = "TreeDeadTrunkBranchS"; break;
		case 145: std::get<1>(result) = "TreeDeadTrunkBranchE"; break;
		case 146: std::get<1>(result) = "TreeDeadTrunkBranchW"; break;
		case 147: std::get<1>(result) = "TreeDeadBranchNS"; break;
		case 148: std::get<1>(result) = "TreeDeadBranchEW"; break;
		case 149: std::get<1>(result) = "anon_35"; break;
		case 150: std::get<1>(result) = "anon_36"; break;
		case 151: std::get<1>(result) = "TreeDeadBranchNW"; break;
		case 152: std::get<1>(result) = "TreeDeadBranchNE"; break;
		case 153: std::get<1>(result) = "TreeDeadBranchSW"; break;
		case 154: std::get<1>(result) = "TreeDeadBranchSE"; break;
		case 155: std::get<1>(result) = "TreeDeadBranches"; break;
		case 156: std::get<1>(result) = "TreeDeadTwigs"; break;
		case 157: std::get<1>(result) = "TreeDeadCapRamp"; break;
		case 158: std::get<1>(result) = "TreeDeadCapPillar"; break;
		case 159: std::get<1>(result) = "TreeDeadCapWallN"; break;
		case 160: std::get<1>(result) = "TreeDeadCapWallS"; break;
		case 161: std::get<1>(result) = "TreeDeadCapWallE"; break;
		case 162: std::get<1>(result) = "TreeDeadCapWallW"; break;
		case 163: std::get<1>(result) = "TreeDeadCapWallNW"; break;
		case 164: std::get<1>(result) = "TreeDeadCapWallNE"; break;
		case 165: std::get<1>(result) = "TreeDeadCapWallSW"; break;
		case 166: std::get<1>(result) = "TreeDeadCapWallSE"; break;
		case 167: std::get<1>(result) = "TreeDeadCapFloor1"; break;
		case 168: std::get<1>(result) = "TreeDeadCapFloor2"; break;
		case 169: std::get<1>(result) = "TreeDeadCapFloor3"; break;
		case 170: std::get<1>(result) = "TreeDeadCapFloor4"; break;
		case 171: std::get<1>(result) = "anon_37"; break;
		case 172: std::get<1>(result) = "StoneWallWorn1"; break;
		case 173: std::get<1>(result) = "StoneWallWorn2"; break;
		case 174: std::get<1>(result) = "StoneWallWorn3"; break;
		case 175: std::get<1>(result) = "TreeBranchNSE"; break;
		case 176: std::get<1>(result) = "TreeBranchNSW"; break;
		case 177: std::get<1>(result) = "TreeBranchNEW"; break;
		case 178: std::get<1>(result) = "TreeBranchSEW"; break;
		case 179: std::get<1>(result) = "TreeBranchNSEW"; break;
		case 180: std::get<1>(result) = "TreeDeadBranchNSE"; break;
		case 181: std::get<1>(result) = "TreeDeadBranchNSW"; break;
		case 182: std::get<1>(result) = "TreeDeadBranchNEW"; break;
		case 183: std::get<1>(result) = "TreeDeadBranchSEW"; break;
		case 184: std::get<1>(result) = "TreeDeadBranchNSEW"; break;
		case 185: std::get<1>(result) = "TreeTrunkNSE"; break;
		case 186: std::get<1>(result) = "TreeTrunkNSW"; break;
		case 187: std::get<1>(result) = "TreeTrunkNEW"; break;
		case 188: std::get<1>(result) = "TreeTrunkSEW"; break;
		case 189: std::get<1>(result) = "TreeTrunkNS"; break;
		case 190: std::get<1>(result) = "TreeTrunkEW"; break;
		case 191: std::get<1>(result) = "TreeTrunkNSEW"; break;
		case 192: std::get<1>(result) = "TreeTrunkInterior"; break;
		case 193: std::get<1>(result) = "TreeDeadTrunkNSE"; break;
		case 194: std::get<1>(result) = "TreeDeadTrunkNSW"; break;
		case 195: std::get<1>(result) = "TreeDeadTrunkNEW"; break;
		case 196: std::get<1>(result) = "TreeDeadTrunkSEW"; break;
		case 197: std::get<1>(result) = "TreeDeadTrunkNS"; break;
		case 198: std::get<1>(result) = "TreeDeadTrunkEW"; break;
		case 199: std::get<1>(result) = "TreeDeadTrunkNSEW"; break;
		case 200: std::get<1>(result) = "TreeDeadTrunkInterior"; break;
		case 201: std::get<1>(result) = "anon_38"; break;
		case 202: std::get<1>(result) = "anon_39"; break;
		case 203: std::get<1>(result) = "anon_40"; break;
		case 204: std::get<1>(result) = "anon_41"; break;
		case 205: std::get<1>(result) = "anon_42"; break;
		case 206: std::get<1>(result) = "anon_43"; break;
		case 207: std::get<1>(result) = "anon_44"; break;
		case 208: std::get<1>(result) = "anon_45"; break;
		case 209: std::get<1>(result) = "anon_46"; break;
		case 210: std::get<1>(result) = "anon_47"; break;
		case 211: std::get<1>(result) = "anon_48"; break;
		case 212: std::get<1>(result) = "anon_49"; break;
		case 213: std::get<1>(result) = "anon_50"; break;
		case 214: std::get<1>(result) = "anon_51"; break;
		case 215: std::get<1>(result) = "StoneWall"; break;
		case 216: std::get<1>(result) = "anon_52"; break;
		case 217: std::get<1>(result) = "anon_53"; break;
		case 218: std::get<1>(result) = "anon_54"; break;
		case 219: std::get<1>(result) = "anon_55"; break;
		case 220: std::get<1>(result) = "anon_56"; break;
		case 221: std::get<1>(result) = "anon_57"; break;
		case 222: std::get<1>(result) = "anon_58"; break;
		case 223: std::get<1>(result) = "anon_59"; break;
		case 224: std::get<1>(result) = "anon_60"; break;
		case 225: std::get<1>(result) = "anon_61"; break;
		case 226: std::get<1>(result) = "anon_62"; break;
		case 227: std::get<1>(result) = "Sapling"; break;
		case 228: std::get<1>(result) = "anon_63"; break;
		case 229: std::get<1>(result) = "GrassDryRamp"; break;
		case 230: std::get<1>(result) = "GrassDeadRamp"; break;
		case 231: std::get<1>(result) = "GrassLightRamp"; break;
		case 232: std::get<1>(result) = "GrassDarkRamp"; break;
		case 233: std::get<1>(result) = "StoneRamp"; break;
		case 234: std::get<1>(result) = "LavaRamp"; break;
		case 235: std::get<1>(result) = "FeatureRamp"; break;
		case 236: std::get<1>(result) = "MineralRamp"; break;
		case 237: std::get<1>(result) = "SoilRamp"; break;
		case 238: std::get<1>(result) = "Ashes1"; break;
		case 239: std::get<1>(result) = "Ashes2"; break;
		case 240: std::get<1>(result) = "Ashes3"; break;
		case 241: std::get<1>(result) = "FrozenRamp"; break;
		case 242: std::get<1>(result) = "anon_64"; break;
		case 243: std::get<1>(result) = "anon_65"; break;
		case 244: std::get<1>(result) = "anon_66"; break;
		case 245: std::get<1>(result) = "anon_67"; break;
		case 246: std::get<1>(result) = "anon_68"; break;
		case 247: std::get<1>(result) = "anon_69"; break;
		case 248: std::get<1>(result) = "anon_70"; break;
		case 249: std::get<1>(result) = "anon_71"; break;
		case 250: std::get<1>(result) = "anon_72"; break;
		case 251: std::get<1>(result) = "anon_73"; break;
		case 252: std::get<1>(result) = "anon_74"; break;
		case 253: std::get<1>(result) = "anon_75"; break;
		case 254: std::get<1>(result) = "FrozenFloor2"; break;
		case 255: std::get<1>(result) = "FrozenFloor3"; break;
		case 256: std::get<1>(result) = "FrozenFloor4"; break;
		case 257: std::get<1>(result) = "FurrowedSoil"; break;
		case 258: std::get<1>(result) = "FrozenFloor1"; break;
		case 259: std::get<1>(result) = "SemiMoltenRock"; break;
		case 260: std::get<1>(result) = "MagmaFlow"; break;
		case 261: std::get<1>(result) = "SoilWall"; break;
		case 262: std::get<1>(result) = "GlowingBarrier"; break;
		case 263: std::get<1>(result) = "GlowingFloor"; break;
		case 264: std::get<1>(result) = "anon_76"; break;
		case 265: std::get<1>(result) = "LavaWallSmoothRD2"; break;
		case 266: std::get<1>(result) = "LavaWallSmoothR2D"; break;
		case 267: std::get<1>(result) = "LavaWallSmoothR2U"; break;
		case 268: std::get<1>(result) = "LavaWallSmoothRU2"; break;
		case 269: std::get<1>(result) = "LavaWallSmoothL2U"; break;
		case 270: std::get<1>(result) = "LavaWallSmoothLU2"; break;
		case 271: std::get<1>(result) = "LavaWallSmoothL2D"; break;
		case 272: std::get<1>(result) = "LavaWallSmoothLD2"; break;
		case 273: std::get<1>(result) = "LavaWallSmoothLRUD"; break;
		case 274: std::get<1>(result) = "LavaWallSmoothRUD"; break;
		case 275: std::get<1>(result) = "LavaWallSmoothLRD"; break;
		case 276: std::get<1>(result) = "LavaWallSmoothLRU"; break;
		case 277: std::get<1>(result) = "LavaWallSmoothLUD"; break;
		case 278: std::get<1>(result) = "LavaWallSmoothRD"; break;
		case 279: std::get<1>(result) = "LavaWallSmoothRU"; break;
		case 280: std::get<1>(result) = "LavaWallSmoothLU"; break;
		case 281: std::get<1>(result) = "LavaWallSmoothLD"; break;
		case 282: std::get<1>(result) = "LavaWallSmoothUD"; break;
		case 283: std::get<1>(result) = "LavaWallSmoothLR"; break;
		case 284: std::get<1>(result) = "FeatureWallSmoothRD2"; break;
		case 285: std::get<1>(result) = "FeatureWallSmoothR2D"; break;
		case 286: std::get<1>(result) = "FeatureWallSmoothR2U"; break;
		case 287: std::get<1>(result) = "FeatureWallSmoothRU2"; break;
		case 288: std::get<1>(result) = "FeatureWallSmoothL2U"; break;
		case 289: std::get<1>(result) = "FeatureWallSmoothLU2"; break;
		case 290: std::get<1>(result) = "FeatureWallSmoothL2D"; break;
		case 291: std::get<1>(result) = "FeatureWallSmoothLD2"; break;
		case 292: std::get<1>(result) = "FeatureWallSmoothLRUD"; break;
		case 293: std::get<1>(result) = "FeatureWallSmoothRUD"; break;
		case 294: std::get<1>(result) = "FeatureWallSmoothLRD"; break;
		case 295: std::get<1>(result) = "FeatureWallSmoothLRU"; break;
		case 296: std::get<1>(result) = "FeatureWallSmoothLUD"; break;
		case 297: std::get<1>(result) = "FeatureWallSmoothRD"; break;
		case 298: std::get<1>(result) = "FeatureWallSmoothRU"; break;
		case 299: std::get<1>(result) = "FeatureWallSmoothLU"; break;
		case 300: std::get<1>(result) = "FeatureWallSmoothLD"; break;
		case 301: std::get<1>(result) = "FeatureWallSmoothUD"; break;
		case 302: std::get<1>(result) = "FeatureWallSmoothLR"; break;
		case 303: std::get<1>(result) = "StoneWallSmoothRD2"; break;
		case 304: std::get<1>(result) = "StoneWallSmoothR2D"; break;
		case 305: std::get<1>(result) = "StoneWallSmoothR2U"; break;
		case 306: std::get<1>(result) = "StoneWallSmoothRU2"; break;
		case 307: std::get<1>(result) = "StoneWallSmoothL2U"; break;
		case 308: std::get<1>(result) = "StoneWallSmoothLU2"; break;
		case 309: std::get<1>(result) = "StoneWallSmoothL2D"; break;
		case 310: std::get<1>(result) = "StoneWallSmoothLD2"; break;
		case 311: std::get<1>(result) = "StoneWallSmoothLRUD"; break;
		case 312: std::get<1>(result) = "StoneWallSmoothRUD"; break;
		case 313: std::get<1>(result) = "StoneWallSmoothLRD"; break;
		case 314: std::get<1>(result) = "StoneWallSmoothLRU"; break;
		case 315: std::get<1>(result) = "StoneWallSmoothLUD"; break;
		case 316: std::get<1>(result) = "StoneWallSmoothRD"; break;
		case 317: std::get<1>(result) = "StoneWallSmoothRU"; break;
		case 318: std::get<1>(result) = "StoneWallSmoothLU"; break;
		case 319: std::get<1>(result) = "StoneWallSmoothLD"; break;
		case 320: std::get<1>(result) = "StoneWallSmoothUD"; break;
		case 321: std::get<1>(result) = "StoneWallSmoothLR"; break;
		case 322: std::get<1>(result) = "LavaFortification"; break;
		case 323: std::get<1>(result) = "FeatureFortification"; break;
		case 324: std::get<1>(result) = "LavaWallWorn1"; break;
		case 325: std::get<1>(result) = "LavaWallWorn2"; break;
		case 326: std::get<1>(result) = "LavaWallWorn3"; break;
		case 327: std::get<1>(result) = "LavaWall"; break;
		case 328: std::get<1>(result) = "FeatureWallWorn1"; break;
		case 329: std::get<1>(result) = "FeatureWallWorn2"; break;
		case 330: std::get<1>(result) = "FeatureWallWorn3"; break;
		case 331: std::get<1>(result) = "FeatureWall"; break;
		case 332: std::get<1>(result) = "StoneFloor1"; break;
		case 333: std::get<1>(result) = "StoneFloor2"; break;
		case 334: std::get<1>(result) = "StoneFloor3"; break;
		case 335: std::get<1>(result) = "StoneFloor4"; break;
		case 336: std::get<1>(result) = "LavaFloor1"; break;
		case 337: std::get<1>(result) = "LavaFloor2"; break;
		case 338: std::get<1>(result) = "LavaFloor3"; break;
		case 339: std::get<1>(result) = "LavaFloor4"; break;
		case 340: std::get<1>(result) = "FeatureFloor1"; break;
		case 341: std::get<1>(result) = "FeatureFloor2"; break;
		case 342: std::get<1>(result) = "FeatureFloor3"; break;
		case 343: std::get<1>(result) = "FeatureFloor4"; break;
		case 344: std::get<1>(result) = "GrassDarkFloor1"; break;
		case 345: std::get<1>(result) = "GrassDarkFloor2"; break;
		case 346: std::get<1>(result) = "GrassDarkFloor3"; break;
		case 347: std::get<1>(result) = "GrassDarkFloor4"; break;
		case 348: std::get<1>(result) = "SoilFloor1"; break;
		case 349: std::get<1>(result) = "SoilFloor2"; break;
		case 350: std::get<1>(result) = "SoilFloor3"; break;
		case 351: std::get<1>(result) = "SoilFloor4"; break;
		case 352: std::get<1>(result) = "SoilWetFloor1"; break;
		case 353: std::get<1>(result) = "SoilWetFloor2"; break;
		case 354: std::get<1>(result) = "SoilWetFloor3"; break;
		case 355: std::get<1>(result) = "SoilWetFloor4"; break;
		case 356: std::get<1>(result) = "FrozenFortification"; break;
		case 357: std::get<1>(result) = "FrozenWallWorn1"; break;
		case 358: std::get<1>(result) = "FrozenWallWorn2"; break;
		case 359: std::get<1>(result) = "FrozenWallWorn3"; break;
		case 360: std::get<1>(result) = "FrozenWall"; break;
		case 361: std::get<1>(result) = "RiverN"; break;
		case 362: std::get<1>(result) = "RiverS"; break;
		case 363: std::get<1>(result) = "RiverE"; break;
		case 364: std::get<1>(result) = "RiverW"; break;
		case 365: std::get<1>(result) = "RiverNW"; break;
		case 366: std::get<1>(result) = "RiverNE"; break;
		case 367: std::get<1>(result) = "RiverSW"; break;
		case 368: std::get<1>(result) = "RiverSE"; break;
		case 369: std::get<1>(result) = "BrookN"; break;
		case 370: std::get<1>(result) = "BrookS"; break;
		case 371: std::get<1>(result) = "BrookE"; break;
		case 372: std::get<1>(result) = "BrookW"; break;
		case 373: std::get<1>(result) = "BrookNW"; break;
		case 374: std::get<1>(result) = "BrookNE"; break;
		case 375: std::get<1>(result) = "BrookSW"; break;
		case 376: std::get<1>(result) = "BrookSE"; break;
		case 377: std::get<1>(result) = "BrookTop"; break;
		case 378: std::get<1>(result) = "anon_77"; break;
		case 379: std::get<1>(result) = "anon_78"; break;
		case 380: std::get<1>(result) = "anon_79"; break;
		case 381: std::get<1>(result) = "anon_80"; break;
		case 382: std::get<1>(result) = "anon_81"; break;
		case 383: std::get<1>(result) = "GrassDryFloor1"; break;
		case 384: std::get<1>(result) = "GrassDryFloor2"; break;
		case 385: std::get<1>(result) = "GrassDryFloor3"; break;
		case 386: std::get<1>(result) = "GrassDryFloor4"; break;
		case 387: std::get<1>(result) = "anon_82"; break;
		case 388: std::get<1>(result) = "SaplingDead"; break;
		case 389: std::get<1>(result) = "ShrubDead"; break;
		case 390: std::get<1>(result) = "GrassDeadFloor1"; break;
		case 391: std::get<1>(result) = "GrassDeadFloor2"; break;
		case 392: std::get<1>(result) = "GrassDeadFloor3"; break;
		case 393: std::get<1>(result) = "GrassDeadFloor4"; break;
		case 394: std::get<1>(result) = "GrassLightFloor1"; break;
		case 395: std::get<1>(result) = "GrassLightFloor2"; break;
		case 396: std::get<1>(result) = "GrassLightFloor3"; break;
		case 397: std::get<1>(result) = "GrassLightFloor4"; break;
		case 398: std::get<1>(result) = "StoneBoulder"; break;
		case 399: std::get<1>(result) = "LavaBoulder"; break;
		case 400: std::get<1>(result) = "FeatureBoulder"; break;
		case 401: std::get<1>(result) = "StonePebbles1"; break;
		case 402: std::get<1>(result) = "StonePebbles2"; break;
		case 403: std::get<1>(result) = "StonePebbles3"; break;
		case 404: std::get<1>(result) = "StonePebbles4"; break;
		case 405: std::get<1>(result) = "LavaPebbles1"; break;
		case 406: std::get<1>(result) = "LavaPebbles2"; break;
		case 407: std::get<1>(result) = "LavaPebbles3"; break;
		case 408: std::get<1>(result) = "LavaPebbles4"; break;
		case 409: std::get<1>(result) = "FeaturePebbles1"; break;
		case 410: std::get<1>(result) = "FeaturePebbles2"; break;
		case 411: std::get<1>(result) = "FeaturePebbles3"; break;
		case 412: std::get<1>(result) = "FeaturePebbles4"; break;
		case 413: std::get<1>(result) = "MineralWallSmoothRD2"; break;
		case 414: std::get<1>(result) = "MineralWallSmoothR2D"; break;
		case 415: std::get<1>(result) = "MineralWallSmoothR2U"; break;
		case 416: std::get<1>(result) = "MineralWallSmoothRU2"; break;
		case 417: std::get<1>(result) = "MineralWallSmoothL2U"; break;
		case 418: std::get<1>(result) = "MineralWallSmoothLU2"; break;
		case 419: std::get<1>(result) = "MineralWallSmoothL2D"; break;
		case 420: std::get<1>(result) = "MineralWallSmoothLD2"; break;
		case 421: std::get<1>(result) = "MineralWallSmoothLRUD"; break;
		case 422: std::get<1>(result) = "MineralWallSmoothRUD"; break;
		case 423: std::get<1>(result) = "MineralWallSmoothLRD"; break;
		case 424: std::get<1>(result) = "MineralWallSmoothLRU"; break;
		case 425: std::get<1>(result) = "MineralWallSmoothLUD"; break;
		case 426: std::get<1>(result) = "MineralWallSmoothRD"; break;
		case 427: std::get<1>(result) = "MineralWallSmoothRU"; break;
		case 428: std::get<1>(result) = "MineralWallSmoothLU"; break;
		case 429: std::get<1>(result) = "MineralWallSmoothLD"; break;
		case 430: std::get<1>(result) = "MineralWallSmoothUD"; break;
		case 431: std::get<1>(result) = "MineralWallSmoothLR"; break;
		case 432: std::get<1>(result) = "MineralFortification"; break;
		case 433: std::get<1>(result) = "MineralWallWorn1"; break;
		case 434: std::get<1>(result) = "MineralWallWorn2"; break;
		case 435: std::get<1>(result) = "MineralWallWorn3"; break;
		case 436: std::get<1>(result) = "MineralWall"; break;
		case 437: std::get<1>(result) = "MineralFloor1"; break;
		case 438: std::get<1>(result) = "MineralFloor2"; break;
		case 439: std::get<1>(result) = "MineralFloor3"; break;
		case 440: std::get<1>(result) = "MineralFloor4"; break;
		case 441: std::get<1>(result) = "MineralBoulder"; break;
		case 442: std::get<1>(result) = "MineralPebbles1"; break;
		case 443: std::get<1>(result) = "MineralPebbles2"; break;
		case 444: std::get<1>(result) = "MineralPebbles3"; break;
		case 445: std::get<1>(result) = "MineralPebbles4"; break;
		case 446: std::get<1>(result) = "FrozenWallSmoothRD2"; break;
		case 447: std::get<1>(result) = "FrozenWallSmoothR2D"; break;
		case 448: std::get<1>(result) = "FrozenWallSmoothR2U"; break;
		case 449: std::get<1>(result) = "FrozenWallSmoothRU2"; break;
		case 450: std::get<1>(result) = "FrozenWallSmoothL2U"; break;
		case 451: std::get<1>(result) = "FrozenWallSmoothLU2"; break;
		case 452: std::get<1>(result) = "FrozenWallSmoothL2D"; break;
		case 453: std::get<1>(result) = "FrozenWallSmoothLD2"; break;
		case 454: std::get<1>(result) = "FrozenWallSmoothLRUD"; break;
		case 455: std::get<1>(result) = "FrozenWallSmoothRUD"; break;
		case 456: std::get<1>(result) = "FrozenWallSmoothLRD"; break;
		case 457: std::get<1>(result) = "FrozenWallSmoothLRU"; break;
		case 458: std::get<1>(result) = "FrozenWallSmoothLUD"; break;
		case 459: std::get<1>(result) = "FrozenWallSmoothRD"; break;
		case 460: std::get<1>(result) = "FrozenWallSmoothRU"; break;
		case 461: std::get<1>(result) = "FrozenWallSmoothLU"; break;
		case 462: std::get<1>(result) = "FrozenWallSmoothLD"; break;
		case 463: std::get<1>(result) = "FrozenWallSmoothUD"; break;
		case 464: std::get<1>(result) = "FrozenWallSmoothLR"; break;
		case 465: std::get<1>(result) = "RiverRampN"; break;
		case 466: std::get<1>(result) = "RiverRampS"; break;
		case 467: std::get<1>(result) = "RiverRampE"; break;
		case 468: std::get<1>(result) = "RiverRampW"; break;
		case 469: std::get<1>(result) = "RiverRampNW"; break;
		case 470: std::get<1>(result) = "RiverRampNE"; break;
		case 471: std::get<1>(result) = "RiverRampSW"; break;
		case 472: std::get<1>(result) = "RiverRampSE"; break;
		case 473: std::get<1>(result) = "anon_83"; break;
		case 474: std::get<1>(result) = "anon_84"; break;
		case 475: std::get<1>(result) = "anon_85"; break;
		case 476: std::get<1>(result) = "anon_86"; break;
		case 477: std::get<1>(result) = "anon_87"; break;
		case 478: std::get<1>(result) = "anon_88"; break;
		case 479: std::get<1>(result) = "anon_89"; break;
		case 480: std::get<1>(result) = "anon_90"; break;
		case 481: std::get<1>(result) = "anon_91"; break;
		case 482: std::get<1>(result) = "anon_92"; break;
		case 483: std::get<1>(result) = "anon_93"; break;
		case 484: std::get<1>(result) = "anon_94"; break;
		case 485: std::get<1>(result) = "anon_95"; break;
		case 486: std::get<1>(result) = "anon_96"; break;
		case 487: std::get<1>(result) = "anon_97"; break;
		case 488: std::get<1>(result) = "anon_98"; break;
		case 489: std::get<1>(result) = "ConstructedFloor"; break;
		case 490: std::get<1>(result) = "ConstructedFortification"; break;
		case 491: std::get<1>(result) = "ConstructedPillar"; break;
		case 492: std::get<1>(result) = "ConstructedWallRD2"; break;
		case 493: std::get<1>(result) = "ConstructedWallR2D"; break;
		case 494: std::get<1>(result) = "ConstructedWallR2U"; break;
		case 495: std::get<1>(result) = "ConstructedWallRU2"; break;
		case 496: std::get<1>(result) = "ConstructedWallL2U"; break;
		case 497: std::get<1>(result) = "ConstructedWallLU2"; break;
		case 498: std::get<1>(result) = "ConstructedWallL2D"; break;
		case 499: std::get<1>(result) = "ConstructedWallLD2"; break;
		case 500: std::get<1>(result) = "ConstructedWallLRUD"; break;
		case 501: std::get<1>(result) = "ConstructedWallRUD"; break;
		case 502: std::get<1>(result) = "ConstructedWallLRD"; break;
		case 503: std::get<1>(result) = "ConstructedWallLRU"; break;
		case 504: std::get<1>(result) = "ConstructedWallLUD"; break;
		case 505: std::get<1>(result) = "ConstructedWallRD"; break;
		case 506: std::get<1>(result) = "ConstructedWallRU"; break;
		case 507: std::get<1>(result) = "ConstructedWallLU"; break;
		case 508: std::get<1>(result) = "ConstructedWallLD"; break;
		case 509: std::get<1>(result) = "ConstructedWallUD"; break;
		case 510: std::get<1>(result) = "ConstructedWallLR"; break;
		case 511: std::get<1>(result) = "ConstructedStairUD"; break;
		case 512: std::get<1>(result) = "ConstructedStairD"; break;
		case 513: std::get<1>(result) = "ConstructedStairU"; break;
		case 514: std::get<1>(result) = "ConstructedRamp"; break;
		case 515: std::get<1>(result) = "StoneFloorTrackN"; break;
		case 516: std::get<1>(result) = "StoneFloorTrackS"; break;
		case 517: std::get<1>(result) = "StoneFloorTrackE"; break;
		case 518: std::get<1>(result) = "StoneFloorTrackW"; break;
		case 519: std::get<1>(result) = "StoneFloorTrackNS"; break;
		case 520: std::get<1>(result) = "StoneFloorTrackNE"; break;
		case 521: std::get<1>(result) = "StoneFloorTrackNW"; break;
		case 522: std::get<1>(result) = "StoneFloorTrackSE"; break;
		case 523: std::get<1>(result) = "StoneFloorTrackSW"; break;
		case 524: std::get<1>(result) = "StoneFloorTrackEW"; break;
		case 525: std::get<1>(result) = "StoneFloorTrackNSE"; break;
		case 526: std::get<1>(result) = "StoneFloorTrackNSW"; break;
		case 527: std::get<1>(result) = "StoneFloorTrackNEW"; break;
		case 528: std::get<1>(result) = "StoneFloorTrackSEW"; break;
		case 529: std::get<1>(result) = "StoneFloorTrackNSEW"; break;
		case 530: std::get<1>(result) = "LavaFloorTrackN"; break;
		case 531: std::get<1>(result) = "LavaFloorTrackS"; break;
		case 532: std::get<1>(result) = "LavaFloorTrackE"; break;
		case 533: std::get<1>(result) = "LavaFloorTrackW"; break;
		case 534: std::get<1>(result) = "LavaFloorTrackNS"; break;
		case 535: std::get<1>(result) = "LavaFloorTrackNE"; break;
		case 536: std::get<1>(result) = "LavaFloorTrackNW"; break;
		case 537: std::get<1>(result) = "LavaFloorTrackSE"; break;
		case 538: std::get<1>(result) = "LavaFloorTrackSW"; break;
		case 539: std::get<1>(result) = "LavaFloorTrackEW"; break;
		case 540: std::get<1>(result) = "LavaFloorTrackNSE"; break;
		case 541: std::get<1>(result) = "LavaFloorTrackNSW"; break;
		case 542: std::get<1>(result) = "LavaFloorTrackNEW"; break;
		case 543: std::get<1>(result) = "LavaFloorTrackSEW"; break;
		case 544: std::get<1>(result) = "LavaFloorTrackNSEW"; break;
		case 545: std::get<1>(result) = "FeatureFloorTrackN"; break;
		case 546: std::get<1>(result) = "FeatureFloorTrackS"; break;
		case 547: std::get<1>(result) = "FeatureFloorTrackE"; break;
		case 548: std::get<1>(result) = "FeatureFloorTrackW"; break;
		case 549: std::get<1>(result) = "FeatureFloorTrackNS"; break;
		case 550: std::get<1>(result) = "FeatureFloorTrackNE"; break;
		case 551: std::get<1>(result) = "FeatureFloorTrackNW"; break;
		case 552: std::get<1>(result) = "FeatureFloorTrackSE"; break;
		case 553: std::get<1>(result) = "FeatureFloorTrackSW"; break;
		case 554: std::get<1>(result) = "FeatureFloorTrackEW"; break;
		case 555: std::get<1>(result) = "FeatureFloorTrackNSE"; break;
		case 556: std::get<1>(result) = "FeatureFloorTrackNSW"; break;
		case 557: std::get<1>(result) = "FeatureFloorTrackNEW"; break;
		case 558: std::get<1>(result) = "FeatureFloorTrackSEW"; break;
		case 559: std::get<1>(result) = "FeatureFloorTrackNSEW"; break;
		case 560: std::get<1>(result) = "MineralFloorTrackN"; break;
		case 561: std::get<1>(result) = "MineralFloorTrackS"; break;
		case 562: std::get<1>(result) = "MineralFloorTrackE"; break;
		case 563: std::get<1>(result) = "MineralFloorTrackW"; break;
		case 564: std::get<1>(result) = "MineralFloorTrackNS"; break;
		case 565: std::get<1>(result) = "MineralFloorTrackNE"; break;
		case 566: std::get<1>(result) = "MineralFloorTrackNW"; break;
		case 567: std::get<1>(result) = "MineralFloorTrackSE"; break;
		case 568: std::get<1>(result) = "MineralFloorTrackSW"; break;
		case 569: std::get<1>(result) = "MineralFloorTrackEW"; break;
		case 570: std::get<1>(result) = "MineralFloorTrackNSE"; break;
		case 571: std::get<1>(result) = "MineralFloorTrackNSW"; break;
		case 572: std::get<1>(result) = "MineralFloorTrackNEW"; break;
		case 573: std::get<1>(result) = "MineralFloorTrackSEW"; break;
		case 574: std::get<1>(result) = "MineralFloorTrackNSEW"; break;
		case 575: std::get<1>(result) = "FrozenFloorTrackN"; break;
		case 576: std::get<1>(result) = "FrozenFloorTrackS"; break;
		case 577: std::get<1>(result) = "FrozenFloorTrackE"; break;
		case 578: std::get<1>(result) = "FrozenFloorTrackW"; break;
		case 579: std::get<1>(result) = "FrozenFloorTrackNS"; break;
		case 580: std::get<1>(result) = "FrozenFloorTrackNE"; break;
		case 581: std::get<1>(result) = "FrozenFloorTrackNW"; break;
		case 582: std::get<1>(result) = "FrozenFloorTrackSE"; break;
		case 583: std::get<1>(result) = "FrozenFloorTrackSW"; break;
		case 584: std::get<1>(result) = "FrozenFloorTrackEW"; break;
		case 585: std::get<1>(result) = "FrozenFloorTrackNSE"; break;
		case 586: std::get<1>(result) = "FrozenFloorTrackNSW"; break;
		case 587: std::get<1>(result) = "FrozenFloorTrackNEW"; break;
		case 588: std::get<1>(result) = "FrozenFloorTrackSEW"; break;
		case 589: std::get<1>(result) = "FrozenFloorTrackNSEW"; break;
		case 590: std::get<1>(result) = "ConstructedFloorTrackN"; break;
		case 591: std::get<1>(result) = "ConstructedFloorTrackS"; break;
		case 592: std::get<1>(result) = "ConstructedFloorTrackE"; break;
		case 593: std::get<1>(result) = "ConstructedFloorTrackW"; break;
		case 594: std::get<1>(result) = "ConstructedFloorTrackNS"; break;
		case 595: std::get<1>(result) = "ConstructedFloorTrackNE"; break;
		case 596: std::get<1>(result) = "ConstructedFloorTrackNW"; break;
		case 597: std::get<1>(result) = "ConstructedFloorTrackSE"; break;
		case 598: std::get<1>(result) = "ConstructedFloorTrackSW"; break;
		case 599: std::get<1>(result) = "ConstructedFloorTrackEW"; break;
		case 600: std::get<1>(result) = "ConstructedFloorTrackNSE"; break;
		case 601: std::get<1>(result) = "ConstructedFloorTrackNSW"; break;
		case 602: std::get<1>(result) = "ConstructedFloorTrackNEW"; break;
		case 603: std::get<1>(result) = "ConstructedFloorTrackSEW"; break;
		case 604: std::get<1>(result) = "ConstructedFloorTrackNSEW"; break;
		case 605: std::get<1>(result) = "StoneRampTrackN"; break;
		case 606: std::get<1>(result) = "StoneRampTrackS"; break;
		case 607: std::get<1>(result) = "StoneRampTrackE"; break;
		case 608: std::get<1>(result) = "StoneRampTrackW"; break;
		case 609: std::get<1>(result) = "StoneRampTrackNS"; break;
		case 610: std::get<1>(result) = "StoneRampTrackNE"; break;
		case 611: std::get<1>(result) = "StoneRampTrackNW"; break;
		case 612: std::get<1>(result) = "StoneRampTrackSE"; break;
		case 613: std::get<1>(result) = "StoneRampTrackSW"; break;
		case 614: std::get<1>(result) = "StoneRampTrackEW"; break;
		case 615: std::get<1>(result) = "StoneRampTrackNSE"; break;
		case 616: std::get<1>(result) = "StoneRampTrackNSW"; break;
		case 617: std::get<1>(result) = "StoneRampTrackNEW"; break;
		case 618: std::get<1>(result) = "StoneRampTrackSEW"; break;
		case 619: std::get<1>(result) = "StoneRampTrackNSEW"; break;
		case 620: std::get<1>(result) = "LavaRampTrackN"; break;
		case 621: std::get<1>(result) = "LavaRampTrackS"; break;
		case 622: std::get<1>(result) = "LavaRampTrackE"; break;
		case 623: std::get<1>(result) = "LavaRampTrackW"; break;
		case 624: std::get<1>(result) = "LavaRampTrackNS"; break;
		case 625: std::get<1>(result) = "LavaRampTrackNE"; break;
		case 626: std::get<1>(result) = "LavaRampTrackNW"; break;
		case 627: std::get<1>(result) = "LavaRampTrackSE"; break;
		case 628: std::get<1>(result) = "LavaRampTrackSW"; break;
		case 629: std::get<1>(result) = "LavaRampTrackEW"; break;
		case 630: std::get<1>(result) = "LavaRampTrackNSE"; break;
		case 631: std::get<1>(result) = "LavaRampTrackNSW"; break;
		case 632: std::get<1>(result) = "LavaRampTrackNEW"; break;
		case 633: std::get<1>(result) = "LavaRampTrackSEW"; break;
		case 634: std::get<1>(result) = "LavaRampTrackNSEW"; break;
		case 635: std::get<1>(result) = "FeatureRampTrackN"; break;
		case 636: std::get<1>(result) = "FeatureRampTrackS"; break;
		case 637: std::get<1>(result) = "FeatureRampTrackE"; break;
		case 638: std::get<1>(result) = "FeatureRampTrackW"; break;
		case 639: std::get<1>(result) = "FeatureRampTrackNS"; break;
		case 640: std::get<1>(result) = "FeatureRampTrackNE"; break;
		case 641: std::get<1>(result) = "FeatureRampTrackNW"; break;
		case 642: std::get<1>(result) = "FeatureRampTrackSE"; break;
		case 643: std::get<1>(result) = "FeatureRampTrackSW"; break;
		case 644: std::get<1>(result) = "FeatureRampTrackEW"; break;
		case 645: std::get<1>(result) = "FeatureRampTrackNSE"; break;
		case 646: std::get<1>(result) = "FeatureRampTrackNSW"; break;
		case 647: std::get<1>(result) = "FeatureRampTrackNEW"; break;
		case 648: std::get<1>(result) = "FeatureRampTrackSEW"; break;
		case 649: std::get<1>(result) = "FeatureRampTrackNSEW"; break;
		case 650: std::get<1>(result) = "MineralRampTrackN"; break;
		case 651: std::get<1>(result) = "MineralRampTrackS"; break;
		case 652: std::get<1>(result) = "MineralRampTrackE"; break;
		case 653: std::get<1>(result) = "MineralRampTrackW"; break;
		case 654: std::get<1>(result) = "MineralRampTrackNS"; break;
		case 655: std::get<1>(result) = "MineralRampTrackNE"; break;
		case 656: std::get<1>(result) = "MineralRampTrackNW"; break;
		case 657: std::get<1>(result) = "MineralRampTrackSE"; break;
		case 658: std::get<1>(result) = "MineralRampTrackSW"; break;
		case 659: std::get<1>(result) = "MineralRampTrackEW"; break;
		case 660: std::get<1>(result) = "MineralRampTrackNSE"; break;
		case 661: std::get<1>(result) = "MineralRampTrackNSW"; break;
		case 662: std::get<1>(result) = "MineralRampTrackNEW"; break;
		case 663: std::get<1>(result) = "MineralRampTrackSEW"; break;
		case 664: std::get<1>(result) = "MineralRampTrackNSEW"; break;
		case 665: std::get<1>(result) = "FrozenRampTrackN"; break;
		case 666: std::get<1>(result) = "FrozenRampTrackS"; break;
		case 667: std::get<1>(result) = "FrozenRampTrackE"; break;
		case 668: std::get<1>(result) = "FrozenRampTrackW"; break;
		case 669: std::get<1>(result) = "FrozenRampTrackNS"; break;
		case 670: std::get<1>(result) = "FrozenRampTrackNE"; break;
		case 671: std::get<1>(result) = "FrozenRampTrackNW"; break;
		case 672: std::get<1>(result) = "FrozenRampTrackSE"; break;
		case 673: std::get<1>(result) = "FrozenRampTrackSW"; break;
		case 674: std::get<1>(result) = "FrozenRampTrackEW"; break;
		case 675: std::get<1>(result) = "FrozenRampTrackNSE"; break;
		case 676: std::get<1>(result) = "FrozenRampTrackNSW"; break;
		case 677: std::get<1>(result) = "FrozenRampTrackNEW"; break;
		case 678: std::get<1>(result) = "FrozenRampTrackSEW"; break;
		case 679: std::get<1>(result) = "FrozenRampTrackNSEW"; break;
		case 680: std::get<1>(result) = "ConstructedRampTrackN"; break;
		case 681: std::get<1>(result) = "ConstructedRampTrackS"; break;
		case 682: std::get<1>(result) = "ConstructedRampTrackE"; break;
		case 683: std::get<1>(result) = "ConstructedRampTrackW"; break;
		case 684: std::get<1>(result) = "ConstructedRampTrackNS"; break;
		case 685: std::get<1>(result) = "ConstructedRampTrackNE"; break;
		case 686: std::get<1>(result) = "ConstructedRampTrackNW"; break;
		case 687: std::get<1>(result) = "ConstructedRampTrackSE"; break;
		case 688: std::get<1>(result) = "ConstructedRampTrackSW"; break;
		case 689: std::get<1>(result) = "ConstructedRampTrackEW"; break;
		case 690: std::get<1>(result) = "ConstructedRampTrackNSE"; break;
		case 691: std::get<1>(result) = "ConstructedRampTrackNSW"; break;
		case 692: std::get<1>(result) = "ConstructedRampTrackNEW"; break;
		case 693: std::get<1>(result) = "ConstructedRampTrackSEW"; break;
		case 694: std::get<1>(result) = "ConstructedRampTrackNSEW"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_build_req_choice_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "General"; break;
		case 1: std::get<1>(result) = "Specific"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ui_hotkey__T_cmd_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Zoom"; break;
		case 1: std::get<1>(result) = "FollowUnit"; break;
		case 2: std::get<1>(result) = "FollowItem"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ui_sidebar_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Default"; break;
		case 1: std::get<1>(result) = "Squads"; break;
		case 2: std::get<1>(result) = "DesignateMine"; break;
		case 3: std::get<1>(result) = "DesignateRemoveRamps"; break;
		case 4: std::get<1>(result) = "DesignateUpStair"; break;
		case 5: std::get<1>(result) = "DesignateDownStair"; break;
		case 6: std::get<1>(result) = "DesignateUpDownStair"; break;
		case 7: std::get<1>(result) = "DesignateUpRamp"; break;
		case 8: std::get<1>(result) = "DesignateChannel"; break;
		case 9: std::get<1>(result) = "DesignateGatherPlants"; break;
		case 10: std::get<1>(result) = "DesignateRemoveDesignation"; break;
		case 11: std::get<1>(result) = "DesignateSmooth"; break;
		case 12: std::get<1>(result) = "DesignateCarveTrack"; break;
		case 13: std::get<1>(result) = "DesignateEngrave"; break;
		case 14: std::get<1>(result) = "DesignateCarveFortification"; break;
		case 15: std::get<1>(result) = "Stockpiles"; break;
		case 16: std::get<1>(result) = "Build"; break;
		case 17: std::get<1>(result) = "QueryBuilding"; break;
		case 18: std::get<1>(result) = "Orders"; break;
		case 19: std::get<1>(result) = "OrdersForbid"; break;
		case 20: std::get<1>(result) = "OrdersRefuse"; break;
		case 21: std::get<1>(result) = "OrdersWorkshop"; break;
		case 22: std::get<1>(result) = "OrdersZone"; break;
		case 23: std::get<1>(result) = "BuildingItems"; break;
		case 24: std::get<1>(result) = "ViewUnits"; break;
		case 25: std::get<1>(result) = "LookAround"; break;
		case 26: std::get<1>(result) = "DesignateItemsClaim"; break;
		case 27: std::get<1>(result) = "DesignateItemsForbid"; break;
		case 28: std::get<1>(result) = "DesignateItemsMelt"; break;
		case 29: std::get<1>(result) = "DesignateItemsUnmelt"; break;
		case 30: std::get<1>(result) = "DesignateItemsDump"; break;
		case 31: std::get<1>(result) = "DesignateItemsUndump"; break;
		case 32: std::get<1>(result) = "DesignateItemsHide"; break;
		case 33: std::get<1>(result) = "DesignateItemsUnhide"; break;
		case 34: std::get<1>(result) = "DesignateChopTrees"; break;
		case 35: std::get<1>(result) = "DesignateToggleEngravings"; break;
		case 36: std::get<1>(result) = "DesignateToggleMarker"; break;
		case 37: std::get<1>(result) = "Hotkeys"; break;
		case 38: std::get<1>(result) = "DesignateTrafficHigh"; break;
		case 39: std::get<1>(result) = "DesignateTrafficNormal"; break;
		case 40: std::get<1>(result) = "DesignateTrafficLow"; break;
		case 41: std::get<1>(result) = "DesignateTrafficRestricted"; break;
		case 42: std::get<1>(result) = "Zones"; break;
		case 43: std::get<1>(result) = "ZonesPenInfo"; break;
		case 44: std::get<1>(result) = "ZonesPitInfo"; break;
		case 45: std::get<1>(result) = "ZonesHospitalInfo"; break;
		case 46: std::get<1>(result) = "ZonesGatherInfo"; break;
		case 47: std::get<1>(result) = "DesignateRemoveConstruction"; break;
		case 48: std::get<1>(result) = "DepotAccess"; break;
		case 49: std::get<1>(result) = "NotesPoints"; break;
		case 50: std::get<1>(result) = "NotesRoutes"; break;
		case 51: std::get<1>(result) = "Burrows"; break;
		case 52: std::get<1>(result) = "Hauling"; break;
		case 53: std::get<1>(result) = "ArenaWeather"; break;
		case 54: std::get<1>(result) = "ArenaTrees"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_kitchen_exc_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 1: std::get<1>(result) = "Cook"; break;
		case 2: std::get<1>(result) = "Brew"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_timed_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Caravan"; break;
		case 1: std::get<1>(result) = "Migrants"; break;
		case 2: std::get<1>(result) = "Diplomat"; break;
		case 3: std::get<1>(result) = "FeatureAttack"; std::get<2>(result) = "unused, does nothing"; break;
		case 4: std::get<1>(result) = "Megabeast"; break;
		case 5: std::get<1>(result) = "WildlifeCurious"; break;
		case 6: std::get<1>(result) = "WildlifeMischievous"; break;
		case 7: std::get<1>(result) = "WildlifeFlier"; break;
		case 8: std::get<1>(result) = "NightCreature"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_emotion_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "ANYTHING"; break;
		case 0: std::get<1>(result) = "ACCEPTANCE"; break;
		case 1: std::get<1>(result) = "ADORATION"; break;
		case 2: std::get<1>(result) = "AFFECTION"; break;
		case 3: std::get<1>(result) = "AGITATION"; break;
		case 4: std::get<1>(result) = "AGGRAVATION"; break;
		case 5: std::get<1>(result) = "AGONY"; break;
		case 6: std::get<1>(result) = "ALARM"; break;
		case 7: std::get<1>(result) = "ALIENATION"; break;
		case 8: std::get<1>(result) = "AMAZEMENT"; break;
		case 9: std::get<1>(result) = "AMBIVALENCE"; break;
		case 10: std::get<1>(result) = "AMUSEMENT"; break;
		case 11: std::get<1>(result) = "ANGER"; break;
		case 12: std::get<1>(result) = "ANGST"; break;
		case 13: std::get<1>(result) = "ANGUISH"; break;
		case 14: std::get<1>(result) = "ANNOYANCE"; break;
		case 15: std::get<1>(result) = "anon_1"; break;
		case 16: std::get<1>(result) = "ANXIETY"; break;
		case 17: std::get<1>(result) = "APATHY"; break;
		case 18: std::get<1>(result) = "anon_2"; break;
		case 19: std::get<1>(result) = "AROUSAL"; break;
		case 20: std::get<1>(result) = "ASTONISHMENT"; break;
		case 21: std::get<1>(result) = "anon_3"; break;
		case 22: std::get<1>(result) = "AVERSION"; break;
		case 23: std::get<1>(result) = "AWE"; break;
		case 24: std::get<1>(result) = "BITTERNESS"; break;
		case 25: std::get<1>(result) = "BLISS"; break;
		case 26: std::get<1>(result) = "BOREDOM"; break;
		case 27: std::get<1>(result) = "CARING"; break;
		case 28: std::get<1>(result) = "anon_4"; break;
		case 29: std::get<1>(result) = "CONFUSION"; break;
		case 30: std::get<1>(result) = "CONTEMPT"; break;
		case 31: std::get<1>(result) = "CONTENTMENT"; break;
		case 32: std::get<1>(result) = "anon_5"; break;
		case 33: std::get<1>(result) = "anon_6"; break;
		case 34: std::get<1>(result) = "DEFEAT"; break;
		case 35: std::get<1>(result) = "DEJECTION"; break;
		case 36: std::get<1>(result) = "DELIGHT"; break;
		case 37: std::get<1>(result) = "anon_7"; break;
		case 38: std::get<1>(result) = "anon_8"; break;
		case 39: std::get<1>(result) = "DESPAIR"; break;
		case 40: std::get<1>(result) = "DISAPPOINTMENT"; break;
		case 41: std::get<1>(result) = "DISGUST"; break;
		case 42: std::get<1>(result) = "DISILLUSIONMENT"; break;
		case 43: std::get<1>(result) = "DISLIKE"; break;
		case 44: std::get<1>(result) = "DISMAY"; break;
		case 45: std::get<1>(result) = "DISPLEASURE"; break;
		case 46: std::get<1>(result) = "DISTRESS"; break;
		case 47: std::get<1>(result) = "DOUBT"; break;
		case 48: std::get<1>(result) = "anon_9"; break;
		case 49: std::get<1>(result) = "EAGERNESS"; break;
		case 50: std::get<1>(result) = "anon_10"; break;
		case 51: std::get<1>(result) = "ELATION"; break;
		case 52: std::get<1>(result) = "EMBARRASSMENT"; break;
		case 53: std::get<1>(result) = "EMPATHY"; break;
		case 54: std::get<1>(result) = "EMPTINESS"; break;
		case 55: std::get<1>(result) = "ENJOYMENT"; break;
		case 56: std::get<1>(result) = "anon_11"; break;
		case 57: std::get<1>(result) = "ENTHUSIASM"; break;
		case 58: std::get<1>(result) = "anon_12"; break;
		case 59: std::get<1>(result) = "EUPHORIA"; break;
		case 60: std::get<1>(result) = "EXASPERATION"; break;
		case 61: std::get<1>(result) = "EXCITEMENT"; break;
		case 62: std::get<1>(result) = "EXHILARATION"; break;
		case 63: std::get<1>(result) = "EXPECTANCY"; break;
		case 64: std::get<1>(result) = "FEAR"; break;
		case 65: std::get<1>(result) = "FEROCITY"; break;
		case 66: std::get<1>(result) = "FONDNESS"; break;
		case 67: std::get<1>(result) = "FREEDOM"; break;
		case 68: std::get<1>(result) = "FRIGHT"; break;
		case 69: std::get<1>(result) = "FRUSTRATION"; break;
		case 70: std::get<1>(result) = "anon_13"; break;
		case 71: std::get<1>(result) = "GAIETY"; break;
		case 72: std::get<1>(result) = "anon_14"; break;
		case 73: std::get<1>(result) = "GLEE"; break;
		case 74: std::get<1>(result) = "GLOOM"; break;
		case 75: std::get<1>(result) = "GLUMNESS"; break;
		case 76: std::get<1>(result) = "GRATITUDE"; break;
		case 77: std::get<1>(result) = "anon_15"; break;
		case 78: std::get<1>(result) = "GRIEF"; break;
		case 79: std::get<1>(result) = "GRIM_SATISFACTION"; break;
		case 80: std::get<1>(result) = "GROUCHINESS"; break;
		case 81: std::get<1>(result) = "GRUMPINESS"; break;
		case 82: std::get<1>(result) = "GUILT"; break;
		case 83: std::get<1>(result) = "HAPPINESS"; break;
		case 84: std::get<1>(result) = "HATRED"; break;
		case 85: std::get<1>(result) = "anon_16"; break;
		case 86: std::get<1>(result) = "HOPE"; break;
		case 87: std::get<1>(result) = "HOPELESSNESS"; break;
		case 88: std::get<1>(result) = "HORROR"; break;
		case 89: std::get<1>(result) = "anon_17"; break;
		case 90: std::get<1>(result) = "HUMILIATION"; break;
		case 91: std::get<1>(result) = "anon_18"; break;
		case 92: std::get<1>(result) = "anon_19"; break;
		case 93: std::get<1>(result) = "anon_20"; break;
		case 94: std::get<1>(result) = "anon_21"; break;
		case 95: std::get<1>(result) = "INSULT"; break;
		case 96: std::get<1>(result) = "INTEREST"; break;
		case 97: std::get<1>(result) = "IRRITATION"; break;
		case 98: std::get<1>(result) = "ISOLATION"; break;
		case 99: std::get<1>(result) = "anon_22"; break;
		case 100: std::get<1>(result) = "JOLLINESS"; break;
		case 101: std::get<1>(result) = "JOVIALITY"; break;
		case 102: std::get<1>(result) = "JOY"; break;
		case 103: std::get<1>(result) = "JUBILATION"; break;
		case 104: std::get<1>(result) = "anon_23"; break;
		case 105: std::get<1>(result) = "LOATHING"; break;
		case 106: std::get<1>(result) = "LONELINESS"; break;
		case 107: std::get<1>(result) = "anon_24"; break;
		case 108: std::get<1>(result) = "LOVE"; break;
		case 109: std::get<1>(result) = "anon_25"; break;
		case 110: std::get<1>(result) = "LUST"; break;
		case 111: std::get<1>(result) = "anon_26"; break;
		case 112: std::get<1>(result) = "MISERY"; break;
		case 113: std::get<1>(result) = "MORTIFICATION"; break;
		case 114: std::get<1>(result) = "anon_27"; break;
		case 115: std::get<1>(result) = "NERVOUSNESS"; break;
		case 116: std::get<1>(result) = "NOSTALGIA"; break;
		case 117: std::get<1>(result) = "OPTIMISM"; break;
		case 118: std::get<1>(result) = "OUTRAGE"; break;
		case 119: std::get<1>(result) = "PANIC"; break;
		case 120: std::get<1>(result) = "PATIENCE"; break;
		case 121: std::get<1>(result) = "PASSION"; break;
		case 122: std::get<1>(result) = "PESSIMISM"; break;
		case 123: std::get<1>(result) = "anon_28"; break;
		case 124: std::get<1>(result) = "PLEASURE"; break;
		case 125: std::get<1>(result) = "PRIDE"; break;
		case 126: std::get<1>(result) = "RAGE"; break;
		case 127: std::get<1>(result) = "RAPTURE"; break;
		case 128: std::get<1>(result) = "REJECTION"; break;
		case 129: std::get<1>(result) = "RELIEF"; break;
		case 130: std::get<1>(result) = "REGRET"; break;
		case 131: std::get<1>(result) = "REMORSE"; break;
		case 132: std::get<1>(result) = "REPENTANCE"; break;
		case 133: std::get<1>(result) = "RESENTMENT"; break;
		case 134: std::get<1>(result) = "anon_29"; break;
		case 135: std::get<1>(result) = "RIGHTEOUS_INDIGNATION"; break;
		case 136: std::get<1>(result) = "SADNESS"; break;
		case 137: std::get<1>(result) = "SATISFACTION"; break;
		case 138: std::get<1>(result) = "anon_30"; break;
		case 139: std::get<1>(result) = "SELF_PITY"; break;
		case 140: std::get<1>(result) = "anon_31"; break;
		case 141: std::get<1>(result) = "SERVILE"; break;
		case 142: std::get<1>(result) = "SHAKEN"; break;
		case 143: std::get<1>(result) = "SHAME"; break;
		case 144: std::get<1>(result) = "SHOCK"; break;
		case 145: std::get<1>(result) = "anon_32"; break;
		case 146: std::get<1>(result) = "anon_33"; break;
		case 147: std::get<1>(result) = "anon_34"; break;
		case 148: std::get<1>(result) = "anon_35"; break;
		case 149: std::get<1>(result) = "SUSPICION"; break;
		case 150: std::get<1>(result) = "SYMPATHY"; break;
		case 151: std::get<1>(result) = "TENDERNESS"; break;
		case 152: std::get<1>(result) = "anon_36"; break;
		case 153: std::get<1>(result) = "TERROR"; break;
		case 154: std::get<1>(result) = "THRILL"; break;
		case 155: std::get<1>(result) = "anon_37"; break;
		case 156: std::get<1>(result) = "TRIUMPH"; break;
		case 157: std::get<1>(result) = "UNEASINESS"; break;
		case 158: std::get<1>(result) = "UNHAPPINESS"; break;
		case 159: std::get<1>(result) = "VENGEFULNESS"; break;
		case 160: std::get<1>(result) = "anon_38"; break;
		case 161: std::get<1>(result) = "WONDER"; break;
		case 162: std::get<1>(result) = "WORRY"; break;
		case 163: std::get<1>(result) = "WRATH"; break;
		case 164: std::get<1>(result) = "ZEAL"; break;
		case 165: std::get<1>(result) = "anon_39"; break;
		case 166: std::get<1>(result) = "anon_40"; break;
		case 167: std::get<1>(result) = "anon_41"; break;
		case 168: std::get<1>(result) = "RESTLESS"; break;
		case 169: std::get<1>(result) = "ADMIRATION"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_thought_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Conflict"; break;
		case 1: std::get<1>(result) = "Trauma"; break;
		case 2: std::get<1>(result) = "WitnessDeath"; break;
		case 3: std::get<1>(result) = "UnexpectedDeath"; break;
		case 4: std::get<1>(result) = "Death"; break;
		case 5: std::get<1>(result) = "Kill"; break;
		case 6: std::get<1>(result) = "LoveSeparated"; break;
		case 7: std::get<1>(result) = "LoveReunited"; break;
		case 8: std::get<1>(result) = "JoinConflict"; break;
		case 9: std::get<1>(result) = "MakeMasterwork"; break;
		case 10: std::get<1>(result) = "MadeArtifact"; break;
		case 11: std::get<1>(result) = "MasterSkill"; break;
		case 12: std::get<1>(result) = "NewRomance"; break;
		case 13: std::get<1>(result) = "BecomeParent"; break;
		case 14: std::get<1>(result) = "NearConflict"; break;
		case 15: std::get<1>(result) = "CancelAgreement"; break;
		case 16: std::get<1>(result) = "JoinTravel"; break;
		case 17: std::get<1>(result) = "SiteControlled"; break;
		case 18: std::get<1>(result) = "TributeCancel"; break;
		case 19: std::get<1>(result) = "Incident"; break;
		case 20: std::get<1>(result) = "HearRumor"; break;
		case 21: std::get<1>(result) = "MilitaryRemoved"; break;
		case 22: std::get<1>(result) = "StrangerWeapon"; break;
		case 23: std::get<1>(result) = "StrangerSneaking"; break;
		case 24: std::get<1>(result) = "SawDrinkBlood"; break;
		case 25: std::get<1>(result) = "Complained"; break;
		case 26: std::get<1>(result) = "ReceivedComplaint"; break;
		case 27: std::get<1>(result) = "AdmireBuilding"; break;
		case 28: std::get<1>(result) = "AdmireOwnBuilding"; break;
		case 29: std::get<1>(result) = "AdmireArrangedBuilding"; break;
		case 30: std::get<1>(result) = "AdmireOwnArrangedBuilding"; break;
		case 31: std::get<1>(result) = "LostPet"; break;
		case 32: std::get<1>(result) = "ThrownStuff"; break;
		case 33: std::get<1>(result) = "JailReleased"; break;
		case 34: std::get<1>(result) = "Miscarriage"; break;
		case 35: std::get<1>(result) = "SpouseMiscarriage"; break;
		case 36: std::get<1>(result) = "OldClothing"; break;
		case 37: std::get<1>(result) = "TatteredClothing"; break;
		case 38: std::get<1>(result) = "RottedClothing"; break;
		case 39: std::get<1>(result) = "GhostNightmare"; break;
		case 40: std::get<1>(result) = "GhostHaunt"; break;
		case 41: std::get<1>(result) = "Spar"; break;
		case 42: std::get<1>(result) = "UnableComplain"; break;
		case 43: std::get<1>(result) = "LongPatrol"; break;
		case 44: std::get<1>(result) = "SunNausea"; break;
		case 45: std::get<1>(result) = "SunIrritated"; break;
		case 46: std::get<1>(result) = "Drowsy"; break;
		case 47: std::get<1>(result) = "VeryDrowsy"; break;
		case 48: std::get<1>(result) = "Thirsty"; break;
		case 49: std::get<1>(result) = "Dehydrated"; break;
		case 50: std::get<1>(result) = "Hungry"; break;
		case 51: std::get<1>(result) = "Starving"; break;
		case 52: std::get<1>(result) = "MajorInjuries"; break;
		case 53: std::get<1>(result) = "MinorInjuries"; break;
		case 54: std::get<1>(result) = "SleepNoise"; break;
		case 55: std::get<1>(result) = "Rest"; break;
		case 56: std::get<1>(result) = "FreakishWeather"; break;
		case 57: std::get<1>(result) = "Rain"; break;
		case 58: std::get<1>(result) = "SnowStorm"; break;
		case 59: std::get<1>(result) = "Miasma"; break;
		case 60: std::get<1>(result) = "Smoke"; break;
		case 61: std::get<1>(result) = "Waterfall"; break;
		case 62: std::get<1>(result) = "Dust"; break;
		case 63: std::get<1>(result) = "Demands"; break;
		case 64: std::get<1>(result) = "ImproperPunishment"; break;
		case 65: std::get<1>(result) = "PunishmentReduced"; break;
		case 66: std::get<1>(result) = "Elected"; break;
		case 67: std::get<1>(result) = "Reelected"; break;
		case 68: std::get<1>(result) = "RequestApproved"; break;
		case 69: std::get<1>(result) = "RequestIgnored"; break;
		case 70: std::get<1>(result) = "NoPunishment"; break;
		case 71: std::get<1>(result) = "PunishmentDelayed"; break;
		case 72: std::get<1>(result) = "DelayedPunishment"; break;
		case 73: std::get<1>(result) = "ScarceCageChain"; break;
		case 74: std::get<1>(result) = "MandateIgnored"; break;
		case 75: std::get<1>(result) = "MandateDeadlineMissed"; break;
		case 76: std::get<1>(result) = "LackWork"; break;
		case 77: std::get<1>(result) = "SmashedBuilding"; break;
		case 78: std::get<1>(result) = "ToppledStuff"; break;
		case 79: std::get<1>(result) = "NoblePromotion"; break;
		case 80: std::get<1>(result) = "BecomeNoble"; break;
		case 81: std::get<1>(result) = "Cavein"; break;
		case 82: std::get<1>(result) = "MandateDeadlineMet"; break;
		case 83: std::get<1>(result) = "Uncovered"; break;
		case 84: std::get<1>(result) = "NoShirt"; break;
		case 85: std::get<1>(result) = "NoShoes"; break;
		case 86: std::get<1>(result) = "EatPet"; break;
		case 87: std::get<1>(result) = "EatLikedCreature"; break;
		case 88: std::get<1>(result) = "EatVermin"; break;
		case 89: std::get<1>(result) = "FistFight"; break;
		case 90: std::get<1>(result) = "GaveBeating"; break;
		case 91: std::get<1>(result) = "GotBeaten"; break;
		case 92: std::get<1>(result) = "GaveHammering"; break;
		case 93: std::get<1>(result) = "GotHammered"; break;
		case 94: std::get<1>(result) = "NoHammer"; break;
		case 95: std::get<1>(result) = "SameFood"; break;
		case 96: std::get<1>(result) = "AteRotten"; break;
		case 97: std::get<1>(result) = "GoodMeal"; break;
		case 98: std::get<1>(result) = "GoodDrink"; break;
		case 99: std::get<1>(result) = "MoreChests"; break;
		case 100: std::get<1>(result) = "MoreCabinets"; break;
		case 101: std::get<1>(result) = "MoreWeaponRacks"; break;
		case 102: std::get<1>(result) = "MoreArmorStands"; break;
		case 103: std::get<1>(result) = "RoomPretension"; break;
		case 104: std::get<1>(result) = "LackTables"; break;
		case 105: std::get<1>(result) = "CrowdedTables"; break;
		case 106: std::get<1>(result) = "DiningQuality"; break;
		case 107: std::get<1>(result) = "NoDining"; break;
		case 108: std::get<1>(result) = "LackChairs"; break;
		case 109: std::get<1>(result) = "TrainingBond"; break;
		case 110: std::get<1>(result) = "Rescued"; break;
		case 111: std::get<1>(result) = "RescuedOther"; break;
		case 112: std::get<1>(result) = "SatisfiedAtWork"; break;
		case 113: std::get<1>(result) = "TaxedLostProperty"; break;
		case 114: std::get<1>(result) = "Taxed"; break;
		case 115: std::get<1>(result) = "LackProtection"; break;
		case 116: std::get<1>(result) = "TaxRoomUnreachable"; break;
		case 117: std::get<1>(result) = "TaxRoomMisinformed"; break;
		case 118: std::get<1>(result) = "PleasedNoble"; break;
		case 119: std::get<1>(result) = "TaxCollectionSmooth"; break;
		case 120: std::get<1>(result) = "DisappointedNoble"; break;
		case 121: std::get<1>(result) = "TaxCollectionRough"; break;
		case 122: std::get<1>(result) = "MadeFriend"; break;
		case 123: std::get<1>(result) = "FormedGrudge"; break;
		case 124: std::get<1>(result) = "AnnoyedVermin"; break;
		case 125: std::get<1>(result) = "NearVermin"; break;
		case 126: std::get<1>(result) = "PesteredVermin"; break;
		case 127: std::get<1>(result) = "AcquiredItem"; break;
		case 128: std::get<1>(result) = "AdoptedPet"; break;
		case 129: std::get<1>(result) = "Jailed"; break;
		case 130: std::get<1>(result) = "Bath"; break;
		case 131: std::get<1>(result) = "SoapyBath"; break;
		case 132: std::get<1>(result) = "SparringAccident"; break;
		case 133: std::get<1>(result) = "Attacked"; break;
		case 134: std::get<1>(result) = "AttackedByDead"; break;
		case 135: std::get<1>(result) = "SameBooze"; break;
		case 136: std::get<1>(result) = "DrinkBlood"; break;
		case 137: std::get<1>(result) = "DrinkSlime"; break;
		case 138: std::get<1>(result) = "DrinkVomit"; break;
		case 139: std::get<1>(result) = "DrinkGoo"; break;
		case 140: std::get<1>(result) = "DrinkIchor"; break;
		case 141: std::get<1>(result) = "DrinkPus"; break;
		case 142: std::get<1>(result) = "NastyWater"; break;
		case 143: std::get<1>(result) = "DrankSpoiled"; break;
		case 144: std::get<1>(result) = "LackWell"; break;
		case 145: std::get<1>(result) = "NearCaged"; break;
		case 146: std::get<1>(result) = "NearCagedHated"; break;
		case 147: std::get<1>(result) = "LackBedroom"; break;
		case 148: std::get<1>(result) = "BedroomQuality"; break;
		case 149: std::get<1>(result) = "SleptFloor"; break;
		case 150: std::get<1>(result) = "SleptMud"; break;
		case 151: std::get<1>(result) = "SleptGrass"; break;
		case 152: std::get<1>(result) = "SleptRoughFloor"; break;
		case 153: std::get<1>(result) = "SleptRocks"; break;
		case 154: std::get<1>(result) = "SleptIce"; break;
		case 155: std::get<1>(result) = "SleptDirt"; break;
		case 156: std::get<1>(result) = "SleptDriftwood"; break;
		case 157: std::get<1>(result) = "ArtDefacement"; break;
		case 158: std::get<1>(result) = "Evicted"; break;
		case 159: std::get<1>(result) = "GaveBirth"; break;
		case 160: std::get<1>(result) = "SpouseGaveBirth"; break;
		case 161: std::get<1>(result) = "ReceivedWater"; break;
		case 162: std::get<1>(result) = "GaveWater"; break;
		case 163: std::get<1>(result) = "ReceivedFood"; break;
		case 164: std::get<1>(result) = "GaveFood"; break;
		case 165: std::get<1>(result) = "Talked"; break;
		case 166: std::get<1>(result) = "OfficeQuality"; break;
		case 167: std::get<1>(result) = "MeetingInBedroom"; break;
		case 168: std::get<1>(result) = "MeetingInDiningRoom"; break;
		case 169: std::get<1>(result) = "NoRooms"; break;
		case 170: std::get<1>(result) = "TombQuality"; break;
		case 171: std::get<1>(result) = "TombLack"; break;
		case 172: std::get<1>(result) = "TalkToNoble"; break;
		case 173: std::get<1>(result) = "InteractPet"; break;
		case 174: std::get<1>(result) = "ConvictionCorpse"; break;
		case 175: std::get<1>(result) = "ConvictionAnimal"; break;
		case 176: std::get<1>(result) = "ConvictionVictim"; break;
		case 177: std::get<1>(result) = "ConvictionJusticeSelf"; break;
		case 178: std::get<1>(result) = "ConvictionJusticeFamily"; break;
		case 179: std::get<1>(result) = "Decay"; break;
		case 180: std::get<1>(result) = "NeedsUnfulfilled"; break;
		case 181: std::get<1>(result) = "Prayer"; break;
		case 182: std::get<1>(result) = "DrinkWithoutCup"; break;
		case 183: std::get<1>(result) = "ResearchBreakthrough"; break;
		case 184: std::get<1>(result) = "ResearchStalled"; break;
		case 185: std::get<1>(result) = "PonderTopic"; break;
		case 186: std::get<1>(result) = "DiscussTopic"; break;
		case 187: std::get<1>(result) = "Syndrome"; break;
		case 188: std::get<1>(result) = "Perform"; break;
		case 189: std::get<1>(result) = "WatchPerform"; break;
		case 190: std::get<1>(result) = "RemoveTroupe"; break;
		case 191: std::get<1>(result) = "LearnTopic"; break;
		case 192: std::get<1>(result) = "LearnSkill"; break;
		case 193: std::get<1>(result) = "LearnBook"; break;
		case 194: std::get<1>(result) = "LearnInteraction"; break;
		case 195: std::get<1>(result) = "LearnPoetry"; break;
		case 196: std::get<1>(result) = "LearnMusic"; break;
		case 197: std::get<1>(result) = "LearnDance"; break;
		case 198: std::get<1>(result) = "TeachTopic"; break;
		case 199: std::get<1>(result) = "TeachSkill"; break;
		case 200: std::get<1>(result) = "ReadBook"; break;
		case 201: std::get<1>(result) = "WriteBook"; break;
		case 202: std::get<1>(result) = "BecomeResident"; break;
		case 203: std::get<1>(result) = "BecomeCitizen"; break;
		case 204: std::get<1>(result) = "DenyResident"; break;
		case 205: std::get<1>(result) = "DenyCitizen"; break;
		case 206: std::get<1>(result) = "LeaveTroupe"; break;
		case 207: std::get<1>(result) = "MakeBelieve"; break;
		case 208: std::get<1>(result) = "PlayToy"; break;
		case 209: std::get<1>(result) = "DreamAbout"; break;
		case 210: std::get<1>(result) = "Dream"; break;
		case 211: std::get<1>(result) = "Nightmare"; break;
		case 212: std::get<1>(result) = "Argument"; break;
		case 213: std::get<1>(result) = "CombatDrills"; break;
		case 214: std::get<1>(result) = "ArcheryPractice"; break;
		case 215: std::get<1>(result) = "ImproveSkill"; break;
		case 216: std::get<1>(result) = "WearItem"; break;
		case 217: std::get<1>(result) = "RealizeValue"; break;
		case 218: std::get<1>(result) = "OpinionStoryteller"; break;
		case 219: std::get<1>(result) = "OpinionRecitation"; break;
		case 220: std::get<1>(result) = "OpinionInstrumentSimulation"; break;
		case 221: std::get<1>(result) = "OpinionInstrumentPlayer"; break;
		case 222: std::get<1>(result) = "OpinionSinger"; break;
		case 223: std::get<1>(result) = "OpinionChanter"; break;
		case 224: std::get<1>(result) = "OpinionDancer"; break;
		case 225: std::get<1>(result) = "OpinionStory"; break;
		case 226: std::get<1>(result) = "OpinionPoetry"; break;
		case 227: std::get<1>(result) = "OpinionMusic"; break;
		case 228: std::get<1>(result) = "OpinionDance"; break;
		case 229: std::get<1>(result) = "Defeated"; break;
		case 230: std::get<1>(result) = "FavoritePossession"; break;
		case 231: std::get<1>(result) = "PreserveBody"; break;
		case 232: std::get<1>(result) = "Murdered"; break;
		case 233: std::get<1>(result) = "HistEventCollection"; break;
		case 234: std::get<1>(result) = "ViewOwnDisplay"; break;
		case 235: std::get<1>(result) = "ViewDisplay"; break;
		case 236: std::get<1>(result) = "AcquireArtifact"; break;
		case 237: std::get<1>(result) = "DenySanctuary"; break;
		case 238: std::get<1>(result) = "CaughtSneaking"; break;
		case 239: std::get<1>(result) = "GaveArtifact"; break;
		case 240: std::get<1>(result) = "SawDeadBody"; break;
		case 241: std::get<1>(result) = "Expelled"; break;
		case 242: std::get<1>(result) = "RelativeExpelled"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_value_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "LAW"; break;
		case 1: std::get<1>(result) = "LOYALTY"; break;
		case 2: std::get<1>(result) = "FAMILY"; break;
		case 3: std::get<1>(result) = "FRIENDSHIP"; break;
		case 4: std::get<1>(result) = "POWER"; break;
		case 5: std::get<1>(result) = "TRUTH"; break;
		case 6: std::get<1>(result) = "CUNNING"; break;
		case 7: std::get<1>(result) = "ELOQUENCE"; break;
		case 8: std::get<1>(result) = "FAIRNESS"; break;
		case 9: std::get<1>(result) = "DECORUM"; break;
		case 10: std::get<1>(result) = "TRADITION"; break;
		case 11: std::get<1>(result) = "ARTWORK"; break;
		case 12: std::get<1>(result) = "COOPERATION"; break;
		case 13: std::get<1>(result) = "INDEPENDENCE"; break;
		case 14: std::get<1>(result) = "STOICISM"; break;
		case 15: std::get<1>(result) = "INTROSPECTION"; break;
		case 16: std::get<1>(result) = "SELF_CONTROL"; break;
		case 17: std::get<1>(result) = "TRANQUILITY"; break;
		case 18: std::get<1>(result) = "HARMONY"; break;
		case 19: std::get<1>(result) = "MERRIMENT"; break;
		case 20: std::get<1>(result) = "CRAFTSMANSHIP"; break;
		case 21: std::get<1>(result) = "MARTIAL_PROWESS"; break;
		case 22: std::get<1>(result) = "SKILL"; break;
		case 23: std::get<1>(result) = "HARD_WORK"; break;
		case 24: std::get<1>(result) = "SACRIFICE"; break;
		case 25: std::get<1>(result) = "COMPETITION"; break;
		case 26: std::get<1>(result) = "PERSEVERENCE"; break;
		case 27: std::get<1>(result) = "LEISURE_TIME"; break;
		case 28: std::get<1>(result) = "COMMERCE"; break;
		case 29: std::get<1>(result) = "ROMANCE"; break;
		case 30: std::get<1>(result) = "NATURE"; break;
		case 31: std::get<1>(result) = "PEACE"; break;
		case 32: std::get<1>(result) = "KNOWLEDGE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_goal_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "STAY_ALIVE"; break;
		case 1: std::get<1>(result) = "MAINTAIN_ENTITY_STATUS"; break;
		case 2: std::get<1>(result) = "START_A_FAMILY"; break;
		case 3: std::get<1>(result) = "RULE_THE_WORLD"; break;
		case 4: std::get<1>(result) = "CREATE_A_GREAT_WORK_OF_ART"; break;
		case 5: std::get<1>(result) = "CRAFT_A_MASTERWORK"; break;
		case 6: std::get<1>(result) = "BRING_PEACE_TO_THE_WORLD"; break;
		case 7: std::get<1>(result) = "BECOME_A_LEGENDARY_WARRIOR"; break;
		case 8: std::get<1>(result) = "MASTER_A_SKILL"; break;
		case 9: std::get<1>(result) = "FALL_IN_LOVE"; break;
		case 10: std::get<1>(result) = "SEE_THE_GREAT_NATURAL_SITES"; break;
		case 11: std::get<1>(result) = "IMMORTALITY"; break;
		case 12: std::get<1>(result) = "MAKE_A_GREAT_DISCOVERY"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_personality_facet_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "LOVE_PROPENSITY"; break;
		case 1: std::get<1>(result) = "HATE_PROPENSITY"; break;
		case 2: std::get<1>(result) = "ENVY_PROPENSITY"; break;
		case 3: std::get<1>(result) = "CHEER_PROPENSITY"; break;
		case 4: std::get<1>(result) = "DEPRESSION_PROPENSITY"; break;
		case 5: std::get<1>(result) = "ANGER_PROPENSITY"; break;
		case 6: std::get<1>(result) = "ANXIETY_PROPENSITY"; break;
		case 7: std::get<1>(result) = "LUST_PROPENSITY"; break;
		case 8: std::get<1>(result) = "STRESS_VULNERABILITY"; break;
		case 9: std::get<1>(result) = "GREED"; break;
		case 10: std::get<1>(result) = "IMMODERATION"; break;
		case 11: std::get<1>(result) = "VIOLENT"; break;
		case 12: std::get<1>(result) = "PERSEVERENCE"; break;
		case 13: std::get<1>(result) = "WASTEFULNESS"; break;
		case 14: std::get<1>(result) = "DISCORD"; break;
		case 15: std::get<1>(result) = "FRIENDLINESS"; break;
		case 16: std::get<1>(result) = "POLITENESS"; break;
		case 17: std::get<1>(result) = "DISDAIN_ADVICE"; break;
		case 18: std::get<1>(result) = "BRAVERY"; break;
		case 19: std::get<1>(result) = "CONFIDENCE"; break;
		case 20: std::get<1>(result) = "VANITY"; break;
		case 21: std::get<1>(result) = "AMBITION"; break;
		case 22: std::get<1>(result) = "GRATITUDE"; break;
		case 23: std::get<1>(result) = "IMMODESTY"; break;
		case 24: std::get<1>(result) = "HUMOR"; break;
		case 25: std::get<1>(result) = "VENGEFUL"; break;
		case 26: std::get<1>(result) = "PRIDE"; break;
		case 27: std::get<1>(result) = "CRUELTY"; break;
		case 28: std::get<1>(result) = "SINGLEMINDED"; break;
		case 29: std::get<1>(result) = "HOPEFUL"; break;
		case 30: std::get<1>(result) = "CURIOUS"; break;
		case 31: std::get<1>(result) = "BASHFUL"; break;
		case 32: std::get<1>(result) = "PRIVACY"; break;
		case 33: std::get<1>(result) = "PERFECTIONIST"; break;
		case 34: std::get<1>(result) = "CLOSEMINDED"; break;
		case 35: std::get<1>(result) = "TOLERANT"; break;
		case 36: std::get<1>(result) = "EMOTIONALLY_OBSESSIVE"; break;
		case 37: std::get<1>(result) = "SWAYED_BY_EMOTIONS"; break;
		case 38: std::get<1>(result) = "ALTRUISM"; break;
		case 39: std::get<1>(result) = "DUTIFULNESS"; break;
		case 40: std::get<1>(result) = "THOUGHTLESSNESS"; break;
		case 41: std::get<1>(result) = "ORDERLINESS"; break;
		case 42: std::get<1>(result) = "TRUST"; break;
		case 43: std::get<1>(result) = "GREGARIOUSNESS"; break;
		case 44: std::get<1>(result) = "ASSERTIVENESS"; break;
		case 45: std::get<1>(result) = "ACTIVITY_LEVEL"; break;
		case 46: std::get<1>(result) = "EXCITEMENT_SEEKING"; break;
		case 47: std::get<1>(result) = "IMAGINATION"; break;
		case 48: std::get<1>(result) = "ABSTRACT_INCLINED"; break;
		case 49: std::get<1>(result) = "ART_INCLINED"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_physical_attribute_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "STRENGTH"; break;
		case 1: std::get<1>(result) = "AGILITY"; break;
		case 2: std::get<1>(result) = "TOUGHNESS"; break;
		case 3: std::get<1>(result) = "ENDURANCE"; break;
		case 4: std::get<1>(result) = "RECUPERATION"; break;
		case 5: std::get<1>(result) = "DISEASE_RESISTANCE"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_mental_attribute_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ANALYTICAL_ABILITY"; break;
		case 1: std::get<1>(result) = "FOCUS"; break;
		case 2: std::get<1>(result) = "WILLPOWER"; break;
		case 3: std::get<1>(result) = "CREATIVITY"; break;
		case 4: std::get<1>(result) = "INTUITION"; break;
		case 5: std::get<1>(result) = "PATIENCE"; break;
		case 6: std::get<1>(result) = "MEMORY"; break;
		case 7: std::get<1>(result) = "LINGUISTIC_ABILITY"; break;
		case 8: std::get<1>(result) = "SPATIAL_SENSE"; break;
		case 9: std::get<1>(result) = "MUSICALITY"; break;
		case 10: std::get<1>(result) = "KINESTHETIC_SENSE"; break;
		case 11: std::get<1>(result) = "EMPATHY"; break;
		case 12: std::get<1>(result) = "SOCIAL_AWARENESS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_mood_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Fey"; break;
		case 1: std::get<1>(result) = "Secretive"; break;
		case 2: std::get<1>(result) = "Possessed"; break;
		case 3: std::get<1>(result) = "Macabre"; break;
		case 4: std::get<1>(result) = "Fell"; break;
		case 5: std::get<1>(result) = "Melancholy"; break;
		case 6: std::get<1>(result) = "Raving"; break;
		case 7: std::get<1>(result) = "Berserk"; break;
		case 8: std::get<1>(result) = "Baby"; break;
		case 9: std::get<1>(result) = "Traumatized"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ghost_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MurderousGhost"; break;
		case 1: std::get<1>(result) = "SadisticGhost"; break;
		case 2: std::get<1>(result) = "SecretivePoltergeist"; break;
		case 3: std::get<1>(result) = "EnergeticPoltergeist"; break;
		case 4: std::get<1>(result) = "AngryGhost"; break;
		case 5: std::get<1>(result) = "ViolentGhost"; break;
		case 6: std::get<1>(result) = "MoaningSpirit"; break;
		case 7: std::get<1>(result) = "HowlingSpirit"; break;
		case 8: std::get<1>(result) = "TroublesomePoltergeist"; break;
		case 9: std::get<1>(result) = "RestlessHaunt"; break;
		case 10: std::get<1>(result) = "ForlornHaunt"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_animal_training_level_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SemiWild"; break;
		case 1: std::get<1>(result) = "Trained"; break;
		case 2: std::get<1>(result) = "WellTrained"; break;
		case 3: std::get<1>(result) = "SkilfullyTrained"; break;
		case 4: std::get<1>(result) = "ExpertlyTrained"; break;
		case 5: std::get<1>(result) = "ExceptionallyTrained"; break;
		case 6: std::get<1>(result) = "MasterfullyTrained"; break;
		case 7: std::get<1>(result) = "Domesticated"; break;
		case 8: std::get<1>(result) = "Unk8"; break;
		case 9: std::get<1>(result) = "WildUntamed"; std::get<2>(result) = "Seems to be used as default when not flags1.tame"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_report_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Combat"; break;
		case 1: std::get<1>(result) = "Sparring"; break;
		case 2: std::get<1>(result) = "Hunting"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_skill_rating_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Dabbling"; break;
		case 1: std::get<1>(result) = "Novice"; break;
		case 2: std::get<1>(result) = "Adequate"; break;
		case 3: std::get<1>(result) = "Competent"; break;
		case 4: std::get<1>(result) = "Skilled"; break;
		case 5: std::get<1>(result) = "Proficient"; break;
		case 6: std::get<1>(result) = "Talented"; break;
		case 7: std::get<1>(result) = "Adept"; break;
		case 8: std::get<1>(result) = "Expert"; break;
		case 9: std::get<1>(result) = "Professional"; break;
		case 10: std::get<1>(result) = "Accomplished"; break;
		case 11: std::get<1>(result) = "Great"; break;
		case 12: std::get<1>(result) = "Master"; break;
		case 13: std::get<1>(result) = "HighMaster"; break;
		case 14: std::get<1>(result) = "GrandMaster"; break;
		case 15: std::get<1>(result) = "Legendary"; break;
		case 16: std::get<1>(result) = "Legendary1"; break;
		case 17: std::get<1>(result) = "Legendary2"; break;
		case 18: std::get<1>(result) = "Legendary3"; break;
		case 19: std::get<1>(result) = "Legendary4"; break;
		case 20: std::get<1>(result) = "Legendary5"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_relationship_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Pet"; break;
		case 1: std::get<1>(result) = "Spouse"; break;
		case 2: std::get<1>(result) = "Mother"; break;
		case 3: std::get<1>(result) = "Father"; break;
		case 4: std::get<1>(result) = "LastAttacker"; break;
		case 5: std::get<1>(result) = "GroupLeader"; break;
		case 6: std::get<1>(result) = "Draggee"; break;
		case 7: std::get<1>(result) = "Dragger"; break;
		case 8: std::get<1>(result) = "RiderMount"; break;
		case 9: std::get<1>(result) = "Lover"; break;
		case 10: std::get<1>(result) = "unk10"; break;
		case 11: std::get<1>(result) = "Sibling"; break;
		case 12: std::get<1>(result) = "Child"; break;
		case 13: std::get<1>(result) = "Friend"; break;
		case 14: std::get<1>(result) = "Grudge"; break;
		case 15: std::get<1>(result) = "Worship"; break;
		case 16: std::get<1>(result) = "AcquaintanceLong"; break;
		case 17: std::get<1>(result) = "AcquaintancePassing"; break;
		case 18: std::get<1>(result) = "Bonded"; break;
		case 19: std::get<1>(result) = "Hero"; break;
		case 20: std::get<1>(result) = "ConsidersViolent"; break;
		case 21: std::get<1>(result) = "ConsidersPsychotic"; break;
		case 22: std::get<1>(result) = "GoodForBusiness"; break;
		case 23: std::get<1>(result) = "FriendlyTerms"; break;
		case 24: std::get<1>(result) = "ConsidersKiller"; break;
		case 25: std::get<1>(result) = "ConsidersMurderer"; break;
		case 26: std::get<1>(result) = "Comrade"; break;
		case 27: std::get<1>(result) = "MemberOfRespectedGroup"; break;
		case 28: std::get<1>(result) = "MemberOfHatedGroup"; break;
		case 29: std::get<1>(result) = "EnemyFighter"; break;
		case 30: std::get<1>(result) = "FriendlyFighter"; break;
		case 31: std::get<1>(result) = "ConsidersBully"; break;
		case 32: std::get<1>(result) = "ConsidersBrigand"; break;
		case 33: std::get<1>(result) = "LoyalSoldier"; break;
		case 34: std::get<1>(result) = "ConsidersMonster"; break;
		case 35: std::get<1>(result) = "ConsidersStoryteller"; break;
		case 36: std::get<1>(result) = "ConsidersPoet"; break;
		case 37: std::get<1>(result) = "ConsidersBard"; break;
		case 38: std::get<1>(result) = "ConsidersDancer"; break;
		case 39: std::get<1>(result) = "Master"; break;
		case 40: std::get<1>(result) = "Apprentice"; break;
		case 41: std::get<1>(result) = "Companion"; break;
		case 42: std::get<1>(result) = "FormerMaster"; break;
		case 43: std::get<1>(result) = "FormerApprentice"; break;
		case 44: std::get<1>(result) = "ConsidersQuarreler"; break;
		case 45: std::get<1>(result) = "ConsidersFlatterer"; break;
		case 46: std::get<1>(result) = "Hunter"; break;
		case 47: std::get<1>(result) = "ProtectorOfTheWeak"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_need_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Socialize"; break;
		case 1: std::get<1>(result) = "DrinkAlcohol"; break;
		case 2: std::get<1>(result) = "PrayOrMedidate"; break;
		case 3: std::get<1>(result) = "StayOccupied"; break;
		case 4: std::get<1>(result) = "BeCreative"; break;
		case 5: std::get<1>(result) = "Excitement"; break;
		case 6: std::get<1>(result) = "LearnSomething"; break;
		case 7: std::get<1>(result) = "BeWithFamily"; break;
		case 8: std::get<1>(result) = "BeWithFriends"; break;
		case 9: std::get<1>(result) = "HearEloquence"; break;
		case 10: std::get<1>(result) = "UpholdTradition"; break;
		case 11: std::get<1>(result) = "SelfExamination"; break;
		case 12: std::get<1>(result) = "MakeMerry"; break;
		case 13: std::get<1>(result) = "CraftObject"; break;
		case 14: std::get<1>(result) = "MartialTraining"; break;
		case 15: std::get<1>(result) = "PracticeSkill"; break;
		case 16: std::get<1>(result) = "TakeItEasy"; break;
		case 17: std::get<1>(result) = "MakeRomance"; break;
		case 18: std::get<1>(result) = "SeeAnimal"; break;
		case 19: std::get<1>(result) = "SeeGreatBeast"; break;
		case 20: std::get<1>(result) = "AcquireObject"; break;
		case 21: std::get<1>(result) = "EatGoodMeal"; break;
		case 22: std::get<1>(result) = "Fight"; break;
		case 23: std::get<1>(result) = "CauseTrouble"; break;
		case 24: std::get<1>(result) = "Argue"; break;
		case 25: std::get<1>(result) = "BeExtravagant"; break;
		case 26: std::get<1>(result) = "Wander"; break;
		case 27: std::get<1>(result) = "HelpSomebody"; break;
		case 28: std::get<1>(result) = "ThinkAbstractly"; break;
		case 29: std::get<1>(result) = "AdmireArt"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ghost_goal_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "ScareToDeath"; break;
		case 1: std::get<1>(result) = "Stun"; break;
		case 2: std::get<1>(result) = "Batter"; break;
		case 3: std::get<1>(result) = "Possess"; break;
		case 4: std::get<1>(result) = "MisplaceItem"; break;
		case 5: std::get<1>(result) = "Haunt"; break;
		case 6: std::get<1>(result) = "Torment"; break;
		case 7: std::get<1>(result) = "ToppleBuilding"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_wound_effect_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Bruise"; break;
		case 1: std::get<1>(result) = "Burn"; break;
		case 2: std::get<1>(result) = "Frostbite"; break;
		case 3: std::get<1>(result) = "Burn2"; break;
		case 4: std::get<1>(result) = "Melting"; break;
		case 5: std::get<1>(result) = "Boiling"; break;
		case 6: std::get<1>(result) = "Freezing"; break;
		case 7: std::get<1>(result) = "Condensation"; break;
		case 8: std::get<1>(result) = "Necrosis"; break;
		case 9: std::get<1>(result) = "Blister"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_misc_trait_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "RequestWaterCooldown"; break;
		case 1: std::get<1>(result) = "RequestFoodCooldown"; break;
		case 2: std::get<1>(result) = "RequestRescueCooldown"; break;
		case 3: std::get<1>(result) = "RequestHealthcareCooldown"; break;
		case 4: std::get<1>(result) = "GetDrinkCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 5: std::get<1>(result) = "GetFoodCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 6: std::get<1>(result) = "CleanSelfCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 7: std::get<1>(result) = "Migrant"; std::get<2>(result) = "auto-decrement"; break;
		case 8: std::get<1>(result) = "RoomComplaint"; std::get<2>(result) = "auto-decrement"; break;
		case 9: std::get<1>(result) = "UnnamedResident"; std::get<2>(result) = "upon reaching zero, resident creature gets named"; break;
		case 10: std::get<1>(result) = "RentBedroomCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 11: std::get<1>(result) = "ClaimTrinketCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 12: std::get<1>(result) = "ClaimClothingCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 13: std::get<1>(result) = "WantsDrink"; std::get<2>(result) = "auto-increment to 403200"; break;
		case 14: std::get<1>(result) = "anon_1"; std::get<2>(result) = "formerly LikesOutdoors"; break;
		case 15: std::get<1>(result) = "anon_2"; std::get<2>(result) = "formerly Hardened"; break;
		case 16: std::get<1>(result) = "anon_3"; std::get<2>(result) = "formerly TimeSinceBreak"; break;
		case 17: std::get<1>(result) = "anon_4"; std::get<2>(result) = "formerly OnBreak"; break;
		case 18: std::get<1>(result) = "PrepareToDie"; std::get<2>(result) = "auto-decrement"; break;
		case 19: std::get<1>(result) = "CaveAdapt"; break;
		case 20: std::get<1>(result) = "anon_5"; std::get<2>(result) = "auto-decrement"; break;
		case 21: std::get<1>(result) = "anon_6"; std::get<2>(result) = "auto-decrement"; break;
		case 22: std::get<1>(result) = "anon_7"; break;
		case 23: std::get<1>(result) = "anon_8"; std::get<2>(result) = "auto-decrement"; break;
		case 24: std::get<1>(result) = "FollowUnitCooldown"; std::get<2>(result) = "0-20, 200 on failed path, auto-decrement"; break;
		case 25: std::get<1>(result) = "anon_9"; std::get<2>(result) = "auto-decrement"; break;
		case 26: std::get<1>(result) = "anon_10"; std::get<2>(result) = "auto-decrement"; break;
		case 27: std::get<1>(result) = "anon_11"; break;
		case 28: std::get<1>(result) = "DangerousTerrainCooldown"; std::get<2>(result) = "created at 200, blocks repath?, auto-decrement"; break;
		case 29: std::get<1>(result) = "Beaching"; std::get<2>(result) = "triggered by BEACH_FREQUENCY, auto-decrement"; break;
		case 30: std::get<1>(result) = "IdleAreaCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 31: std::get<1>(result) = "anon_12"; std::get<2>(result) = "auto-decrement"; break;
		case 32: std::get<1>(result) = "PartiedOut"; std::get<2>(result) = "auto-decrement"; break;
		case 33: std::get<1>(result) = "DiagnosePatientCooldown"; std::get<2>(result) = "0-2000, auto-decrement"; break;
		case 34: std::get<1>(result) = "DressWoundCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 35: std::get<1>(result) = "CleanPatientCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 36: std::get<1>(result) = "SurgeryCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 37: std::get<1>(result) = "SutureCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 38: std::get<1>(result) = "SetBoneCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 39: std::get<1>(result) = "PlaceInTractionCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 40: std::get<1>(result) = "ApplyCastCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 41: std::get<1>(result) = "ImmobilizeBreakCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 42: std::get<1>(result) = "BringCrutchCooldown"; std::get<2>(result) = "auto-decrement"; break;
		case 43: std::get<1>(result) = "anon_13"; std::get<2>(result) = "auto-decrement, set military pickup flag upon reaching zero"; break;
		case 44: std::get<1>(result) = "MilkCounter"; std::get<2>(result) = "auto-decrement"; break;
		case 45: std::get<1>(result) = "HadDrill"; std::get<2>(result) = "auto-decrement"; break;
		case 46: std::get<1>(result) = "CompletedDrill"; std::get<2>(result) = "auto-decrement"; break;
		case 47: std::get<1>(result) = "EggSpent"; std::get<2>(result) = "auto-decrement"; break;
		case 48: std::get<1>(result) = "GroundedAnimalAnger"; std::get<2>(result) = "auto-decrement"; break;
		case 49: std::get<1>(result) = "anon_14"; std::get<2>(result) = "auto-decrement"; break;
		case 50: std::get<1>(result) = "TimeSinceSuckedBlood"; break;
		case 51: std::get<1>(result) = "DrinkingBlood"; std::get<2>(result) = "auto-decrement"; break;
		case 52: std::get<1>(result) = "anon_15"; std::get<2>(result) = "auto-decrement"; break;
		case 53: std::get<1>(result) = "anon_16"; std::get<2>(result) = "auto-decrement"; break;
		case 54: std::get<1>(result) = "RevertWildTimer"; std::get<2>(result) = "one trigger => --training_level, auto-decrement"; break;
		case 55: std::get<1>(result) = "anon_17"; std::get<2>(result) = "auto-decrement"; break;
		case 56: std::get<1>(result) = "NoPantsAnger"; std::get<2>(result) = "auto-decrement"; break;
		case 57: std::get<1>(result) = "NoShirtAnger"; std::get<2>(result) = "auto-decrement"; break;
		case 58: std::get<1>(result) = "NoShoesAnger"; std::get<2>(result) = "auto-decrement"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_action_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Move"; break;
		case 1: std::get<1>(result) = "Attack"; break;
		case 2: std::get<1>(result) = "Jump"; break;
		case 3: std::get<1>(result) = "HoldTerrain"; break;
		case 4: std::get<1>(result) = "ReleaseTerrain"; break;
		case 5: std::get<1>(result) = "Climb"; break;
		case 6: std::get<1>(result) = "Job"; break;
		case 7: std::get<1>(result) = "Talk"; break;
		case 8: std::get<1>(result) = "Unsteady"; break;
		case 9: std::get<1>(result) = "Parry"; break;
		case 10: std::get<1>(result) = "Block"; break;
		case 11: std::get<1>(result) = "Dodge"; break;
		case 12: std::get<1>(result) = "Recover"; break;
		case 13: std::get<1>(result) = "StandUp"; break;
		case 14: std::get<1>(result) = "LieDown"; break;
		case 15: std::get<1>(result) = "Job2"; break;
		case 16: std::get<1>(result) = "PushObject"; break;
		case 17: std::get<1>(result) = "SuckBlood"; break;
		case 18: std::get<1>(result) = "HoldItem"; break;
		case 19: std::get<1>(result) = "ReleaseItem"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_interface_breakdown_types_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "NONE"; break;
		case 1: std::get<1>(result) = "QUIT"; break;
		case 2: std::get<1>(result) = "STOPSCREEN"; break;
		case 3: std::get<1>(result) = "TOFIRST"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_embark_finder_option_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "DimensionX"; break;
		case 1: std::get<1>(result) = "DimensionY"; break;
		case 2: std::get<1>(result) = "Savagery"; break;
		case 3: std::get<1>(result) = "Evil"; break;
		case 4: std::get<1>(result) = "Elevation"; break;
		case 5: std::get<1>(result) = "Temperature"; break;
		case 6: std::get<1>(result) = "Rain"; break;
		case 7: std::get<1>(result) = "Drainage"; break;
		case 8: std::get<1>(result) = "FluxStone"; break;
		case 9: std::get<1>(result) = "Aquifer"; break;
		case 10: std::get<1>(result) = "River"; break;
		case 11: std::get<1>(result) = "UndergroundRiver"; break;
		case 12: std::get<1>(result) = "UndergroundPool"; break;
		case 13: std::get<1>(result) = "MagmaPool"; break;
		case 14: std::get<1>(result) = "MagmaPipe"; break;
		case 15: std::get<1>(result) = "Chasm"; break;
		case 16: std::get<1>(result) = "BottomlessPit"; break;
		case 17: std::get<1>(result) = "OtherFeatures"; break;
		case 18: std::get<1>(result) = "ShallowMetal"; break;
		case 19: std::get<1>(result) = "DeepMetal"; break;
		case 20: std::get<1>(result) = "Soil"; break;
		case 21: std::get<1>(result) = "Clay"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_image_creator_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "ArtistToChoose"; break;
		case 1: std::get<1>(result) = "Histfig"; break;
		case 2: std::get<1>(result) = "Site"; break;
		case 3: std::get<1>(result) = "Entity"; break;
		case 4: std::get<1>(result) = "HistoryEvent"; break;
		case 5: std::get<1>(result) = "ExistingImage"; break;
		case 6: std::get<1>(result) = "NewImage"; break;
		case 7: std::get<1>(result) = "AddCreature"; break;
		case 8: std::get<1>(result) = "AddHistfig"; break;
		case 9: std::get<1>(result) = "AddPlant"; break;
		case 10: std::get<1>(result) = "AddTree"; break;
		case 11: std::get<1>(result) = "AddShape"; break;
		case 12: std::get<1>(result) = "AddObject"; break;
		case 13: std::get<1>(result) = "AddArtifact"; break;
		case 14: std::get<1>(result) = "AddRelationship"; break;
		case 15: std::get<1>(result) = "ChooseRelationshipX"; break;
		case 16: std::get<1>(result) = "ChooseRelationshipY"; break;
		case 17: std::get<1>(result) = "EnterNumber"; break;
		case 18: std::get<1>(result) = "DeleteElement"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_kitchenpref_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "VegetablesFruitLeaves"; break;
		case 1: std::get<1>(result) = "Seeds"; break;
		case 2: std::get<1>(result) = "Drinks"; break;
		case 3: std::get<1>(result) = "MeatFishOther"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_adventurer_attribute_level_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "VeryLow"; break;
		case 1: std::get<1>(result) = "Low"; break;
		case 2: std::get<1>(result) = "BelowAverage"; break;
		case 3: std::get<1>(result) = "Average"; break;
		case 4: std::get<1>(result) = "AboveAverage"; break;
		case 5: std::get<1>(result) = "High"; break;
		case 6: std::get<1>(result) = "Superior"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_unitlist_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Citizens"; break;
		case 1: std::get<1>(result) = "Livestock"; break;
		case 2: std::get<1>(result) = "Others"; break;
		case 3: std::get<1>(result) = "Dead"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_world_population_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Animal"; break;
		case 1: std::get<1>(result) = "Vermin"; break;
		case 2: std::get<1>(result) = "Unk2"; break;
		case 3: std::get<1>(result) = "VerminInnumerable"; break;
		case 4: std::get<1>(result) = "ColonyInsect"; break;
		case 5: std::get<1>(result) = "Tree"; break;
		case 6: std::get<1>(result) = "Grass"; break;
		case 7: std::get<1>(result) = "Bush"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_world_region_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Swamp"; break;
		case 1: std::get<1>(result) = "Desert"; break;
		case 2: std::get<1>(result) = "Jungle"; break;
		case 3: std::get<1>(result) = "Mountains"; break;
		case 4: std::get<1>(result) = "Ocean"; break;
		case 5: std::get<1>(result) = "Lake"; break;
		case 6: std::get<1>(result) = "Glacier"; break;
		case 7: std::get<1>(result) = "Tundra"; break;
		case 8: std::get<1>(result) = "Steppe"; break;
		case 9: std::get<1>(result) = "Hills"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_geo_layer_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SOIL"; break;
		case 1: std::get<1>(result) = "SEDIMENTARY"; break;
		case 2: std::get<1>(result) = "METAMORPHIC"; break;
		case 3: std::get<1>(result) = "IGNEOUS_EXTRUSIVE"; break;
		case 4: std::get<1>(result) = "IGNEOUS_INTRUSIVE"; break;
		case 5: std::get<1>(result) = "SOIL_OCEAN"; break;
		case 6: std::get<1>(result) = "SOIL_SAND"; break;
		case 7: std::get<1>(result) = "SEDIMENTARY_OCEAN_SHALLOW"; break;
		case 8: std::get<1>(result) = "SEDIMENTARY_OCEAN_DEEP"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_region_map_entry_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "has_river"; break;
		case 1: std::get<1>(result) = "tile_variant"; break;
		case 2: std::get<1>(result) = "anon_1"; break;
		case 3: std::get<1>(result) = "has_site"; break;
		case 4: std::get<1>(result) = "anon_2"; break;
		case 5: std::get<1>(result) = "river_up"; break;
		case 6: std::get<1>(result) = "river_down"; break;
		case 7: std::get<1>(result) = "river_right"; break;
		case 8: std::get<1>(result) = "river_left"; break;
		case 9: std::get<1>(result) = "discovered"; break;
		case 10: std::get<1>(result) = "anon_3"; break;
		case 11: std::get<1>(result) = "anon_4"; break;
		case 12: std::get<1>(result) = "anon_5"; break;
		case 13: std::get<1>(result) = "is_peak"; break;
		case 14: std::get<1>(result) = "is_lake"; break;
		case 15: std::get<1>(result) = "is_brook"; break;
		case 16: std::get<1>(result) = "has_road"; break;
		case 17: std::get<1>(result) = "anon_6"; break;
		case 18: std::get<1>(result) = "anon_7"; break;
		case 19: std::get<1>(result) = "anon_8"; break;
		case 20: std::get<1>(result) = "anon_9"; break;
		case 21: std::get<1>(result) = "anon_10"; break;
		case 22: std::get<1>(result) = "anon_11"; break;
		case 23: std::get<1>(result) = "anon_12"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_front_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "front_none"; break;
		case 1: std::get<1>(result) = "front_warm"; break;
		case 2: std::get<1>(result) = "front_cold"; break;
		case 3: std::get<1>(result) = "front_occluded"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_cumulus_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "cumulus_none"; break;
		case 1: std::get<1>(result) = "cumulus_medium"; break;
		case 2: std::get<1>(result) = "cumulus_multi"; break;
		case 3: std::get<1>(result) = "cumulus_nimbus"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_stratus_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "stratus_none"; break;
		case 1: std::get<1>(result) = "stratus_alto"; break;
		case 2: std::get<1>(result) = "stratus_proper"; break;
		case 3: std::get<1>(result) = "stratus_nimbus"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_fog_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "fog_none"; break;
		case 1: std::get<1>(result) = "fog_mist"; break;
		case 2: std::get<1>(result) = "fog_normal"; break;
		case 3: std::get<1>(result) = "fog_thick"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_mountain_peak_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "is_volcano"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_abstract_building_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MEAD_HALL"; break;
		case 1: std::get<1>(result) = "KEEP"; break;
		case 2: std::get<1>(result) = "TEMPLE"; break;
		case 3: std::get<1>(result) = "DARK_TOWER"; break;
		case 4: std::get<1>(result) = "MARKET"; break;
		case 5: std::get<1>(result) = "TOMB"; break;
		case 6: std::get<1>(result) = "DUNGEON"; break;
		case 7: std::get<1>(result) = "UNDERWORLD_SPIRE"; break;
		case 8: std::get<1>(result) = "INN_TAVERN"; break;
		case 9: std::get<1>(result) = "LIBRARY"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_abstract_building_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Unk0"; break;
		case 1: std::get<1>(result) = "Unk1"; break;
		case 2: std::get<1>(result) = "Unk2"; break;
		case 3: std::get<1>(result) = "Unk3"; break;
		case 4: std::get<1>(result) = "AllowVisitors"; break;
		case 5: std::get<1>(result) = "AllowResidents"; break;
		case 6: std::get<1>(result) = "Unk6"; break;
		case 7: std::get<1>(result) = "Unk7"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_world_site_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "PlayerFortress"; break;
		case 1: std::get<1>(result) = "DarkFortress"; break;
		case 2: std::get<1>(result) = "Cave"; break;
		case 3: std::get<1>(result) = "MountainHalls"; break;
		case 4: std::get<1>(result) = "ForestRetreat"; break;
		case 5: std::get<1>(result) = "Town"; break;
		case 6: std::get<1>(result) = "ImportantLocation"; break;
		case 7: std::get<1>(result) = "LairShrine"; break;
		case 8: std::get<1>(result) = "Fortress"; break;
		case 9: std::get<1>(result) = "Camp"; break;
		case 10: std::get<1>(result) = "Monument"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_world_site_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Undiscovered"; break;
		case 1: std::get<1>(result) = "anon_1"; break;
		case 2: std::get<1>(result) = "anon_2"; break;
		case 3: std::get<1>(result) = "Town"; std::get<2>(result) = "not hamlet"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_site_realization_building_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "cottage_plot"; break;
		case 1: std::get<1>(result) = "castle_wall"; break;
		case 2: std::get<1>(result) = "castle_tower"; break;
		case 3: std::get<1>(result) = "castle_courtyard"; break;
		case 4: std::get<1>(result) = "house"; break;
		case 5: std::get<1>(result) = "temple"; break;
		case 6: std::get<1>(result) = "tomb"; break;
		case 7: std::get<1>(result) = "shop_house"; break;
		case 8: std::get<1>(result) = "warehouse"; break;
		case 9: std::get<1>(result) = "market_square"; break;
		case 10: std::get<1>(result) = "pasture"; break;
		case 11: std::get<1>(result) = "waste"; break;
		case 12: std::get<1>(result) = "courtyard"; break;
		case 13: std::get<1>(result) = "well"; break;
		case 14: std::get<1>(result) = "vault"; break;
		case 15: std::get<1>(result) = "great_tower"; break;
		case 16: std::get<1>(result) = "trenches"; break;
		case 17: std::get<1>(result) = "tree_house"; break;
		case 18: std::get<1>(result) = "hillock_house"; break;
		case 19: std::get<1>(result) = "mead_hall"; break;
		case 20: std::get<1>(result) = "fortress_entrance"; break;
		case 21: std::get<1>(result) = "library"; break;
		case 22: std::get<1>(result) = "tavern"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_site_shop_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "GeneralImports"; break;
		case 1: std::get<1>(result) = "FoodImports"; break;
		case 2: std::get<1>(result) = "ClothingImports"; break;
		case 3: std::get<1>(result) = "Cloth"; break;
		case 4: std::get<1>(result) = "Leather"; break;
		case 5: std::get<1>(result) = "WovenClothing"; break;
		case 6: std::get<1>(result) = "LeatherClothing"; break;
		case 7: std::get<1>(result) = "BoneCarver"; break;
		case 8: std::get<1>(result) = "GemCutter"; break;
		case 9: std::get<1>(result) = "Weaponsmith"; break;
		case 10: std::get<1>(result) = "Bowyer"; break;
		case 11: std::get<1>(result) = "Blacksmith"; break;
		case 12: std::get<1>(result) = "Armorsmith"; break;
		case 13: std::get<1>(result) = "MetalCraft"; break;
		case 14: std::get<1>(result) = "LeatherGoods"; break;
		case 15: std::get<1>(result) = "Carpenter"; break;
		case 16: std::get<1>(result) = "StoneFurniture"; break;
		case 17: std::get<1>(result) = "MetalFurniture"; break;
		case 18: std::get<1>(result) = "ImportedGoodsMarket"; break;
		case 19: std::get<1>(result) = "ImportedFoodMarket"; break;
		case 20: std::get<1>(result) = "ImportedClothingMarket"; break;
		case 21: std::get<1>(result) = "MeatMarket"; break;
		case 22: std::get<1>(result) = "FruitAndVegetableMarket"; break;
		case 23: std::get<1>(result) = "CheeseMarket"; break;
		case 24: std::get<1>(result) = "ProcessedGoodsMarket"; break;
		case 25: std::get<1>(result) = "Tavern"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_tree_house_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "TreeHouse"; break;
		case 1: std::get<1>(result) = "HomeTree"; break;
		case 2: std::get<1>(result) = "ShapingTree"; break;
		case 3: std::get<1>(result) = "MarketTree"; break;
		case 4: std::get<1>(result) = "Unknown1"; break;
		case 5: std::get<1>(result) = "Unknown2"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_hillock_house_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "anon_1"; break;
		case 1: std::get<1>(result) = "CivicMound"; break;
		case 2: std::get<1>(result) = "CastleMound"; break;
		case 3: std::get<1>(result) = "DrinkingMound"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_creation_zone_pwg_alteration_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "location_death"; break;
		case 1: std::get<1>(result) = "camp"; break;
		case 2: std::get<1>(result) = "srb_ruined"; break;
		case 3: std::get<1>(result) = "srp_ruined"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_worldgen_region_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SWAMP"; break;
		case 1: std::get<1>(result) = "DESERT"; break;
		case 2: std::get<1>(result) = "FOREST"; break;
		case 3: std::get<1>(result) = "MOUNTAINS"; break;
		case 4: std::get<1>(result) = "OCEAN"; break;
		case 5: std::get<1>(result) = "LAKE"; break;
		case 6: std::get<1>(result) = "GLACIER"; break;
		case 7: std::get<1>(result) = "TUNDRA"; break;
		case 8: std::get<1>(result) = "GRASSLAND"; break;
		case 9: std::get<1>(result) = "HILLS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_worldgen_range_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ELEVATION"; break;
		case 1: std::get<1>(result) = "RAINFALL"; break;
		case 2: std::get<1>(result) = "anon_1"; break;
		case 3: std::get<1>(result) = "TEMPERATURE"; break;
		case 4: std::get<1>(result) = "anon_2"; break;
		case 5: std::get<1>(result) = "DRAINAGE"; break;
		case 6: std::get<1>(result) = "VOLCANISM"; break;
		case 7: std::get<1>(result) = "SAVAGERY"; break;
		case 8: std::get<1>(result) = "anon_3"; break;
		case 9: std::get<1>(result) = "anon_4"; break;
		case 10: std::get<1>(result) = "anon_5"; break;
		case 11: std::get<1>(result) = "anon_6"; break;
		case 12: std::get<1>(result) = "anon_7"; break;
		case 13: std::get<1>(result) = "anon_8"; break;
		case 14: std::get<1>(result) = "anon_9"; break;
		case 15: std::get<1>(result) = "anon_10"; break;
		case 16: std::get<1>(result) = "anon_11"; break;
		case 17: std::get<1>(result) = "anon_12"; break;
		case 18: std::get<1>(result) = "anon_13"; break;
		case 19: std::get<1>(result) = "anon_14"; break;
		case 20: std::get<1>(result) = "anon_15"; break;
		case 21: std::get<1>(result) = "anon_16"; break;
		case 22: std::get<1>(result) = "anon_17"; break;
		case 23: std::get<1>(result) = "anon_18"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_units_other_id_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ANY_RIDER"; break;
		case 1: std::get<1>(result) = "ANY_BABY2"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_conflict_level_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "Encounter"; break;
		case 1: std::get<1>(result) = "Horseplay"; break;
		case 2: std::get<1>(result) = "Training"; break;
		case 3: std::get<1>(result) = "Brawl"; break;
		case 4: std::get<1>(result) = "Nonlethal"; break;
		case 5: std::get<1>(result) = "Lethal"; break;
		case 6: std::get<1>(result) = "NoQuarter"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_combat_report_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "anon_1"; break;
		case 1: std::get<1>(result) = "Deflected"; break;
		case 2: std::get<1>(result) = "anon_2"; break;
		case 3: std::get<1>(result) = "anon_3"; break;
		case 4: std::get<1>(result) = "anon_4"; break;
		case 5: std::get<1>(result) = "anon_5"; break;
		case 6: std::get<1>(result) = "Unconscious"; break;
		case 7: std::get<1>(result) = "Stunned"; break;
		case 8: std::get<1>(result) = "MoreStunned"; break;
		case 9: std::get<1>(result) = "Winded"; break;
		case 10: std::get<1>(result) = "MoreWinded"; break;
		case 11: std::get<1>(result) = "Nausea"; break;
		case 12: std::get<1>(result) = "MoreNausea"; break;
		case 13: std::get<1>(result) = "anon_6"; break;
		case 14: std::get<1>(result) = "anon_7"; break;
		case 15: std::get<1>(result) = "ExtractInjected"; break;
		case 16: std::get<1>(result) = "ExtractSprayed"; break;
		case 17: std::get<1>(result) = "BloodSucked"; break;
		case 18: std::get<1>(result) = "SeveredPart"; break;
		case 19: std::get<1>(result) = "anon_8"; break;
		case 20: std::get<1>(result) = "KnockedBack"; break;
		case 21: std::get<1>(result) = "StuckIn"; break;
		case 22: std::get<1>(result) = "LatchOnPart"; break;
		case 23: std::get<1>(result) = "LatchOn"; break;
		case 24: std::get<1>(result) = "Enraged"; break;
		case 25: std::get<1>(result) = "PassThrough"; break;
		case 26: std::get<1>(result) = "GlancesAway"; break;
		case 27: std::get<1>(result) = "anon_9"; break;
		case 28: std::get<1>(result) = "anon_10"; break;
		case 29: std::get<1>(result) = "MajorArtery"; break;
		case 30: std::get<1>(result) = "Artery"; break;
		case 31: std::get<1>(result) = "MotorNerve"; break;
		case 32: std::get<1>(result) = "SensoryNerve"; break;
		case 33: std::get<1>(result) = "NoForce"; break;
		case 34: std::get<1>(result) = "Interrupted"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_conversation__T_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "started"; break;
		case 1: std::get<1>(result) = "active"; break;
		case 2: std::get<1>(result) = "finished"; break;
		case 3: std::get<1>(result) = "quit"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_building_archerytargetst__T_archery_direction_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "TopToBottom"; break;
		case 1: std::get<1>(result) = "BottomToTop"; break;
		case 2: std::get<1>(result) = "LeftToRight"; break;
		case 3: std::get<1>(result) = "RightToLeft"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_building_bridgest__T_direction_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "Retracting"; break;
		case 0: std::get<1>(result) = "Left"; break;
		case 1: std::get<1>(result) = "Right"; break;
		case 2: std::get<1>(result) = "Up"; break;
		case 3: std::get<1>(result) = "Down"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_building_siegeenginest__T_facing_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Left"; break;
		case 1: std::get<1>(result) = "Up"; break;
		case 2: std::get<1>(result) = "Right"; break;
		case 3: std::get<1>(result) = "Down"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_building_siegeenginest__T_action_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "NotInUse"; break;
		case 1: std::get<1>(result) = "PrepareToFire"; break;
		case 2: std::get<1>(result) = "FireAtWill"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_caste_body_info__T_interactions__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "RETRACT_INTO_BP"; break;
		case 1: std::get<1>(result) = "CAN_DO_INTERACTION"; break;
		case 2: std::get<1>(result) = "ROOT_AROUND"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_caravan_state__T_trade_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "None"; break;
		case 1: std::get<1>(result) = "Approaching"; break;
		case 2: std::get<1>(result) = "AtDepot"; break;
		case 3: std::get<1>(result) = "Leaving"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_entity_event__T_data__T_insurrection_end__T_result_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Overthrow"; break;
		case 1: std::get<1>(result) = "Failure"; break;
		case 2: std::get<1>(result) = "Crushing"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_history_event_change_hf_statest__T_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Wandering"; break;
		case 1: std::get<1>(result) = "Settled"; break;
		case 2: std::get<1>(result) = "Refugee"; break;
		case 3: std::get<1>(result) = "anon_1"; break;
		case 4: std::get<1>(result) = "anon_2"; break;
		case 5: std::get<1>(result) = "Visiting"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_history_event_body_abusedst__T_props__T_pile_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "GrislyMound"; break;
		case 1: std::get<1>(result) = "GrotesquePillar"; break;
		case 2: std::get<1>(result) = "GruesomeSculpture"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_history_event_body_abusedst__T_abuse_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Impaled"; std::get<2>(result) = "props.item"; break;
		case 1: std::get<1>(result) = "Piled"; std::get<2>(result) = "props.pile_type"; break;
		case 2: std::get<1>(result) = "Flayed"; std::get<2>(result) = "props.structure"; break;
		case 3: std::get<1>(result) = "Hung"; std::get<2>(result) = "props.hung"; break;
		case 4: std::get<1>(result) = "Mutilated"; std::get<2>(result) = "no props"; break;
		case 5: std::get<1>(result) = "Animated"; std::get<2>(result) = "no props"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_history_event_hist_figure_travelst__T_reason_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Journey"; std::get<2>(result) = "made a journey to"; break;
		case 1: std::get<1>(result) = "Return"; std::get<2>(result) = "returned to"; break;
		case 2: std::get<1>(result) = "Escape"; std::get<2>(result) = "escaped from"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_history_event_artifact_claim_formedst__T_claim_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Symbol"; break;
		case 1: std::get<1>(result) = "Heirloom"; break;
		case 2: std::get<1>(result) = "Treasure"; break;
		case 3: std::get<1>(result) = "HolyRelic"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_init_display__T_windowed_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "True"; break;
		case 1: std::get<1>(result) = "False"; break;
		case 2: std::get<1>(result) = "Prompt"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_init_font__T_use_ttf_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "TTF_OFF"; break;
		case 1: std::get<1>(result) = "TTF_ON"; break;
		case 2: std::get<1>(result) = "TTF_AUTO"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_job_item_ref__T_role_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "anon_1"; break;
		case 1: std::get<1>(result) = "Reagent"; break;
		case 2: std::get<1>(result) = "Hauled"; break;
		case 3: std::get<1>(result) = "LinkToTarget"; break;
		case 4: std::get<1>(result) = "LinkToTrigger"; break;
		case 5: std::get<1>(result) = "anon_2"; break;
		case 6: std::get<1>(result) = "TargetContainer"; break;
		case 7: std::get<1>(result) = "QueuedContainer"; break;
		case 8: std::get<1>(result) = "PushHaulVehicle"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_manager_order__T_frequency_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "OneTime"; break;
		case 1: std::get<1>(result) = "Daily"; break;
		case 2: std::get<1>(result) = "Monthly"; break;
		case 3: std::get<1>(result) = "Seasonally"; break;
		case 4: std::get<1>(result) = "Yearly"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_manager_order_condition_item__T_compare_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "AtLeast"; break;
		case 1: std::get<1>(result) = "AtMost"; break;
		case 2: std::get<1>(result) = "GreaterThan"; break;
		case 3: std::get<1>(result) = "LessThan"; break;
		case 4: std::get<1>(result) = "Exactly"; break;
		case 5: std::get<1>(result) = "Not"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_mandate__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Export"; break;
		case 1: std::get<1>(result) = "Make"; break;
		case 2: std::get<1>(result) = "Guild"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_demand__T_place_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Office"; break;
		case 1: std::get<1>(result) = "Bedroom"; break;
		case 2: std::get<1>(result) = "DiningRoom"; break;
		case 3: std::get<1>(result) = "Tomb"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ui_advmode__T_conversation__T_targets__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Talk"; break;
		case 1: std::get<1>(result) = "anon_1"; break;
		case 2: std::get<1>(result) = "anon_2"; break;
		case 3: std::get<1>(result) = "Shout"; break;
		case 4: std::get<1>(result) = "Perform"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ui_advmode__T_travel_right_map_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "MapNone"; break;
		case 1: std::get<1>(result) = "MapSite"; break;
		case 2: std::get<1>(result) = "MapWorld"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ui_advmode__T_show_menu_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "TwoBlankRows"; break;
		case 0: std::get<1>(result) = "Hidden"; break;
		case 1: std::get<1>(result) = "TwoRowsWithKeybindingHints"; break;
		case 2: std::get<1>(result) = "TwoRows"; break;
		case 3: std::get<1>(result) = "OneRow"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_stop_depart_condition__T_direction_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "North"; break;
		case 1: std::get<1>(result) = "South"; break;
		case 2: std::get<1>(result) = "East"; break;
		case 3: std::get<1>(result) = "West"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_stop_depart_condition__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Push"; break;
		case 1: std::get<1>(result) = "Ride"; break;
		case 2: std::get<1>(result) = "Guide"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_interface_button_construction_category_selectorst__T_category_id_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 1: std::get<1>(result) = "SiegeEngines"; break;
		case 2: std::get<1>(result) = "Traps"; break;
		case 3: std::get<1>(result) = "Workshops"; break;
		case 4: std::get<1>(result) = "Furnaces"; break;
		case 5: std::get<1>(result) = "Constructions"; break;
		case 6: std::get<1>(result) = "MachineComponents"; break;
		case 7: std::get<1>(result) = "Track"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ui_sidebar_menus__T_designation__T_mine_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "All"; break;
		case 1: std::get<1>(result) = "AutoMine"; break;
		case 2: std::get<1>(result) = "Economic"; break;
		case 3: std::get<1>(result) = "Gems"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ui_sidebar_menus__T_zone__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Rectangle"; break;
		case 1: std::get<1>(result) = "Flow"; break;
		case 2: std::get<1>(result) = "FloorFlow"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ui_sidebar_menus__T_unit__T_expel_error_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "NONE"; break;
		case 0: std::get<1>(result) = "NOBILITY"; break;
		case 1: std::get<1>(result) = "HOLDS_OFFICE"; break;
		case 2: std::get<1>(result) = "DOES_EXPELLING"; break;
		case 3: std::get<1>(result) = "SPOUSE_IS_NOT_PRESENT"; break;
		case 4: std::get<1>(result) = "SPOUSE_IS_NOBILITY"; break;
		case 5: std::get<1>(result) = "SPOUSE_IS_ELECTED"; break;
		case 6: std::get<1>(result) = "SPOUSE_DOES_EXPELLING"; break;
		case 7: std::get<1>(result) = "CHILD_IS_NOT_PRESENT"; break;
		case 8: std::get<1>(result) = "CHILD_IS_NOBILITY"; break;
		case 9: std::get<1>(result) = "CHILD_IS_ELECTED"; break;
		case 10: std::get<1>(result) = "CHILD_DOES_EXPELLING"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ui_look_list__T_items__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Item"; break;
		case 1: std::get<1>(result) = "Floor"; break;
		case 2: std::get<1>(result) = "Unit"; break;
		case 3: std::get<1>(result) = "Building"; break;
		case 4: std::get<1>(result) = "Vermin"; break;
		case 5: std::get<1>(result) = "Flow"; break;
		case 6: std::get<1>(result) = "Campfire"; break;
		case 7: std::get<1>(result) = "Spatter"; break;
		case 8: std::get<1>(result) = "BuildingItem"; break;
		case 9: std::get<1>(result) = "Fire"; break;
		case 10: std::get<1>(result) = "Water"; break;
		case 11: std::get<1>(result) = "Magma"; break;
		case 12: std::get<1>(result) = "Spoor"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_ui_unit_view_mode__T_value_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "General"; break;
		case 1: std::get<1>(result) = "Inventory"; break;
		case 2: std::get<1>(result) = "Preferences"; break;
		case 3: std::get<1>(result) = "Wounds"; break;
		case 4: std::get<1>(result) = "PrefLabor"; break;
		case 5: std::get<1>(result) = "PrefDogs"; break;
		case 6: std::get<1>(result) = "PrefOccupation"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit__T_meeting__T_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SelectNoble"; break;
		case 1: std::get<1>(result) = "FollowNoble"; break;
		case 2: std::get<1>(result) = "DoMeeting"; break;
		case 3: std::get<1>(result) = "LeaveMap"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit__T_counters__T_soldier_mood_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "MartialTrance"; break;
		case 1: std::get<1>(result) = "Enraged"; break;
		case 2: std::get<1>(result) = "Tantrum"; break;
		case 3: std::get<1>(result) = "Depressed"; break;
		case 4: std::get<1>(result) = "Oblivious"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_inventory_item__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Hauled"; break;
		case 1: std::get<1>(result) = "Weapon"; std::get<2>(result) = "also shield, crutch"; break;
		case 2: std::get<1>(result) = "Worn"; std::get<2>(result) = "quiver"; break;
		case 3: std::get<1>(result) = "Piercing"; break;
		case 4: std::get<1>(result) = "Flask"; std::get<2>(result) = "attached to clothing"; break;
		case 5: std::get<1>(result) = "WrappedAround"; std::get<2>(result) = "e.g. bandage"; break;
		case 6: std::get<1>(result) = "StuckIn"; break;
		case 7: std::get<1>(result) = "InMouth"; std::get<2>(result) = "string descr like Worn"; break;
		case 8: std::get<1>(result) = "Pet"; std::get<2>(result) = "Left shoulder, right shoulder, or head, selected randomly using pet_seed"; break;
		case 9: std::get<1>(result) = "SewnInto"; break;
		case 10: std::get<1>(result) = "Strapped"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_preference__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "LikeMaterial"; break;
		case 1: std::get<1>(result) = "LikeCreature"; break;
		case 2: std::get<1>(result) = "LikeFood"; break;
		case 3: std::get<1>(result) = "HateCreature"; break;
		case 4: std::get<1>(result) = "LikeItem"; break;
		case 5: std::get<1>(result) = "LikePlant"; break;
		case 6: std::get<1>(result) = "LikeTree"; std::get<2>(result) = "holdover from 40d and earlier"; break;
		case 7: std::get<1>(result) = "LikeColor"; break;
		case 8: std::get<1>(result) = "LikeShape"; break;
		case 9: std::get<1>(result) = "LikePoeticForm"; break;
		case 10: std::get<1>(result) = "LikeMusicalForm"; break;
		case 11: std::get<1>(result) = "LikeDanceForm"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_complaint__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 25: std::get<1>(result) = "SelfUnemployed"; break;
		case 26: std::get<1>(result) = "GuildUnemployed"; break;
		case 27: std::get<1>(result) = "NeedWeapons"; std::get<2>(result) = "no longer used"; break;
		case 28: std::get<1>(result) = "IsAngry"; break;
		case 29: std::get<1>(result) = "IsSad"; break;
		case 30: std::get<1>(result) = "anon_1"; break;
		case 31: std::get<1>(result) = "anon_2"; break;
		case 32: std::get<1>(result) = "anon_3"; break;
		case 33: std::get<1>(result) = "anon_4"; break;
		case 34: std::get<1>(result) = "anon_5"; break;
		case 35: std::get<1>(result) = "anon_6"; break;
		case 36: std::get<1>(result) = "anon_7"; break;
		case 37: std::get<1>(result) = "anon_8"; break;
		case 38: std::get<1>(result) = "anon_9"; break;
		case 39: std::get<1>(result) = "anon_10"; break;
		case 40: std::get<1>(result) = "anon_11"; break;
		case 41: std::get<1>(result) = "anon_12"; break;
		case 42: std::get<1>(result) = "anon_13"; break;
		case 43: std::get<1>(result) = "anon_14"; break;
		case 44: std::get<1>(result) = "anon_15"; break;
		case 45: std::get<1>(result) = "anon_16"; break;
		case 46: std::get<1>(result) = "anon_17"; break;
		case 47: std::get<1>(result) = "anon_18"; break;
		case 48: std::get<1>(result) = "Petition"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_unit_request__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "DoGuildJobs"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_KeybindingScreen__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Main"; break;
		case 1: std::get<1>(result) = "KeyL"; break;
		case 2: std::get<1>(result) = "KeyR"; break;
		case 3: std::get<1>(result) = "Macro"; break;
		case 4: std::get<1>(result) = "Register"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_adventure_logst__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Info"; break;
		case 1: std::get<1>(result) = "Map"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_adventure_logst__T_info_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Events"; break;
		case 1: std::get<1>(result) = "Agreements"; break;
		case 2: std::get<1>(result) = "People"; break;
		case 3: std::get<1>(result) = "Sites"; break;
		case 4: std::get<1>(result) = "Groups"; break;
		case 5: std::get<1>(result) = "Regions"; break;
		case 6: std::get<1>(result) = "Bestiary"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_assign_display_itemst__T_sel_column_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ItemTypes"; break;
		case 1: std::get<1>(result) = "Items"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_choose_start_sitest__T_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Biome"; break;
		case 1: std::get<1>(result) = "Neighbors"; break;
		case 2: std::get<1>(result) = "Civilization"; break;
		case 3: std::get<1>(result) = "Elevation"; break;
		case 4: std::get<1>(result) = "Cliffs"; break;
		case 5: std::get<1>(result) = "Reclaim"; break;
		case 6: std::get<1>(result) = "Reclaim2"; break;
		case 7: std::get<1>(result) = "Find"; break;
		case 8: std::get<1>(result) = "Notes"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_mission__T_details__T_raid__T_raid_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Raze"; break;
		case 1: std::get<1>(result) = "TakeOver"; break;
		case 2: std::get<1>(result) = "Occupy"; break;
		case 3: std::get<1>(result) = "DemandTribute"; break;
		case 4: std::get<1>(result) = "Raid"; break;
		case 5: std::get<1>(result) = "Explore"; break;
		case 6: std::get<1>(result) = "Pillage"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_mission__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 2: std::get<1>(result) = "Raid"; break;
		case 17: std::get<1>(result) = "RecoverArtifact"; break;
		case 18: std::get<1>(result) = "RescuePerson"; break;
		case 19: std::get<1>(result) = "RequestWorkers"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_civlistst__T_rumors__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ArmyMarched"; break;
		case 1: std::get<1>(result) = "Kidnapped"; break;
		case 3: std::get<1>(result) = "Unknown3"; break;
		case 7: std::get<1>(result) = "RefugeesFled"; break;
		case 8: std::get<1>(result) = "MovedOn"; break;
		case 9: std::get<1>(result) = "Reclaimed"; break;
		case 10: std::get<1>(result) = "Founded"; break;
		case 13: std::get<1>(result) = "GaveUpOccupation"; break;
		case 16: std::get<1>(result) = "BecameRuler"; break;
		case 17: std::get<1>(result) = "Claimed"; break;
		case 25: std::get<1>(result) = "ArtifactLocation"; break;
		case 28: std::get<1>(result) = "Unknown28"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_civlistst__T_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Civilizations"; break;
		case 1: std::get<1>(result) = "News"; break;
		case 2: std::get<1>(result) = "World"; break;
		case 3: std::get<1>(result) = "Missions"; break;
		case 4: std::get<1>(result) = "MissionSquads"; break;
		case 5: std::get<1>(result) = "MissionMessengers"; break;
		case 6: std::get<1>(result) = "MissionDetails"; break;
		case 7: std::get<1>(result) = "People"; break;
		case 8: std::get<1>(result) = "Artifacts"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_game_cleanerst__T_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "CleaningGameObjects"; break;
		case 1: std::get<1>(result) = "CleaningStrandedObjects"; break;
		case 2: std::get<1>(result) = "CleaningPlayObjects"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_justicest__T_cur_column_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Crimes"; break;
		case 1: std::get<1>(result) = "Suspects"; break;
		case 2: std::get<1>(result) = "ConvictChoices"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_assign_trade_status__T_status_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -2: std::get<1>(result) = "RemoveTrading"; break;
		case -1: std::get<1>(result) = "RemovePending"; break;
		case 0: std::get<1>(result) = "None"; break;
		case 1: std::get<1>(result) = "AddPending"; break;
		case 2: std::get<1>(result) = "Pending"; break;
		case 3: std::get<1>(result) = "Trading"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_layer_choose_language_namest__T_current_component_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "FrontCompound"; break;
		case 1: std::get<1>(result) = "RearCompound"; break;
		case 2: std::get<1>(result) = "FirstAdjective"; break;
		case 3: std::get<1>(result) = "SecondAdjective"; break;
		case 4: std::get<1>(result) = "HyphenCompound"; break;
		case 5: std::get<1>(result) = "TheX"; break;
		case 6: std::get<1>(result) = "OfX"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_layer_militaryst__T_equip__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Customize"; break;
		case 1: std::get<1>(result) = "Uniform"; break;
		case 2: std::get<1>(result) = "Priority"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_layer_militaryst__T_equip__T_edit_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Armor"; break;
		case 1: std::get<1>(result) = "Helm"; break;
		case 2: std::get<1>(result) = "Legs"; break;
		case 3: std::get<1>(result) = "Gloves"; break;
		case 4: std::get<1>(result) = "Boots"; break;
		case 5: std::get<1>(result) = "Shield"; break;
		case 6: std::get<1>(result) = "Weapon"; break;
		case 7: std::get<1>(result) = "Material"; break;
		case 8: std::get<1>(result) = "Color"; break;
		case 9: std::get<1>(result) = "SpecificArmor"; break;
		case 10: std::get<1>(result) = "SpecificHelm"; break;
		case 11: std::get<1>(result) = "SpecificLegs"; break;
		case 12: std::get<1>(result) = "SpecificGloves"; break;
		case 13: std::get<1>(result) = "SpecificBoots"; break;
		case 14: std::get<1>(result) = "SpecificShield"; break;
		case 15: std::get<1>(result) = "SpecificWeapon"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_layer_militaryst__T_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Positions"; break;
		case 1: std::get<1>(result) = "Alerts"; break;
		case 2: std::get<1>(result) = "Equip"; break;
		case 3: std::get<1>(result) = "Uniforms"; break;
		case 4: std::get<1>(result) = "Supplies"; break;
		case 5: std::get<1>(result) = "Ammunition"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_layer_noblelistst__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "List"; break;
		case 1: std::get<1>(result) = "Appoint"; break;
		case 2: std::get<1>(result) = "Settings"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_legendsst__T_cur_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Main"; break;
		case 1: std::get<1>(result) = "HistoricalFigures"; break;
		case 2: std::get<1>(result) = "Sites"; break;
		case 3: std::get<1>(result) = "Artifacts"; break;
		case 4: std::get<1>(result) = "Regions"; break;
		case 5: std::get<1>(result) = "Civilizations"; break;
		case 6: std::get<1>(result) = "Art"; break;
		case 7: std::get<1>(result) = "Structures"; break;
		case 8: std::get<1>(result) = "Age"; break;
		case 9: std::get<1>(result) = "HistoricalMaps"; break;
		case 10: std::get<1>(result) = "UndergroundRegions"; break;
		case 11: std::get<1>(result) = "Populations"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_locationsst__T_in_edit_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "None"; break;
		case 1: std::get<1>(result) = "Goblets"; break;
		case 2: std::get<1>(result) = "Instruments"; break;
		case 3: std::get<1>(result) = "WritingCopies"; break;
		case 4: std::get<1>(result) = "WritingMaterial"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_locationsst__T_menu_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Locations"; break;
		case 1: std::get<1>(result) = "Occupations"; break;
		case 2: std::get<1>(result) = "AssignOccupation"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_petst__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "List"; break;
		case 1: std::get<1>(result) = "TrainingKnowledge"; break;
		case 2: std::get<1>(result) = "SelectTrainer"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_setup_character_info__T_status_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Peasant"; break;
		case 1: std::get<1>(result) = "Hero"; break;
		case 2: std::get<1>(result) = "Demigod"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_setupadventurest__T_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ChooseRace"; break;
		case 1: std::get<1>(result) = "ChooseAnimalRace"; break;
		case 2: std::get<1>(result) = "ChooseHistfig"; break;
		case 3: std::get<1>(result) = "ChooseCiv"; break;
		case 4: std::get<1>(result) = "Skills"; break;
		case 5: std::get<1>(result) = "PhysicalTraits"; break;
		case 6: std::get<1>(result) = "MentalTraits"; break;
		case 7: std::get<1>(result) = "Background"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_setupadventurest__T_sel_trait_column_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "SkillsColumn"; break;
		case 1: std::get<1>(result) = "AttributesColumn"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_setupdwarfgamest__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Dwarves"; break;
		case 1: std::get<1>(result) = "Items"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_titlest__T_sel_subpage_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "None"; break;
		case 1: std::get<1>(result) = "StartSelectWorld"; break;
		case 2: std::get<1>(result) = "StartSelectMode"; break;
		case 3: std::get<1>(result) = "Arena"; break;
		case 4: std::get<1>(result) = "About"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_workquota_conditionst__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "List"; break;
		case 0: std::get<1>(result) = "ItemType"; break;
		case 1: std::get<1>(result) = "Material"; break;
		case 2: std::get<1>(result) = "Traits"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_viewscreen_workshop_profilest__T_tab_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Workers"; break;
		case 1: std::get<1>(result) = "Orders"; break;
		case 2: std::get<1>(result) = "Restrictions"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_world_underground_region__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Cavern"; break;
		case 1: std::get<1>(result) = "MagmaSea"; break;
		case 2: std::get<1>(result) = "Underworld"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_world_data__T_flip_latitude_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case -1: std::get<1>(result) = "None"; break;
		case 0: std::get<1>(result) = "North"; break;
		case 1: std::get<1>(result) = "South"; break;
		case 2: std::get<1>(result) = "Both"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_abstract_building_dungeonst__T_dungeon_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "DUNGEON"; break;
		case 1: std::get<1>(result) = "SEWERS"; break;
		case 2: std::get<1>(result) = "CATACOMBS"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_cultural_identity__T_group_log__T_join_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Peaceful"; break;
		case 1: std::get<1>(result) = "CompleteTakeOver"; std::get<2>(result) = "The previous group left the culture."; break;
		case 2: std::get<1>(result) = "TakeOver"; std::get<2>(result) = "The previous group's end_year is still -1."; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_world_site_realization__T_areas__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "Crops1"; break;
		case 1: std::get<1>(result) = "Crops2"; break;
		case 2: std::get<1>(result) = "Crops3"; break;
		case 3: std::get<1>(result) = "Meadow"; break;
		case 4: std::get<1>(result) = "Pasture"; break;
		case 5: std::get<1>(result) = "Orchard"; break;
		case 6: std::get<1>(result) = "Woodland"; break;
		case 7: std::get<1>(result) = "Waste"; break;
		case 8: std::get<1>(result) = "Unknown1"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_crime__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::tuple<int64_t, std::string, std::string> result = std::make_tuple(cast(p_base_type, p_address), "UNKNOWN-VALUE", "");
	switch (std::get<0>(result))
	{
		case 0: std::get<1>(result) = "ProductionOrderViolation"; break;
		case 1: std::get<1>(result) = "ExportViolation"; break;
		case 2: std::get<1>(result) = "JobOrderViolation"; break;
		case 3: std::get<1>(result) = "ConspiracyToSlowLabor"; break;
		case 4: std::get<1>(result) = "Murder"; break;
		case 5: std::get<1>(result) = "DisorderlyBehavior"; break;
		case 6: std::get<1>(result) = "BuildingDestruction"; break;
		case 7: std::get<1>(result) = "Vandalism"; break;
		case 8: std::get<1>(result) = "Theft"; break;
		case 9: std::get<1>(result) = "Robbery"; break;
		case 10: std::get<1>(result) = "BloodDrinking"; break;
		default: break;
	}
	return result;
}

std::tuple<int64_t, std::string, std::string> get_enum_decoded(const NodeEnum* p_node)
{
	switch(p_node->m_df_type)
	{
		case DF_Type::ui_advmode_menu: return get_ui_advmode_menu_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::talk_choice_type: return get_talk_choice_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::announcement_type: return get_announcement_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::art_image_element_type: return get_art_image_element_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::art_image_property_type: return get_art_image_property_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::art_image_property_verb: return get_art_image_property_verb_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::art_facet_type: return get_art_facet_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_action: return get_poetic_form_action_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_pattern: return get_poetic_form_pattern_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_caesura_position: return get_poetic_form_caesura_position_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_mood: return get_poetic_form_mood_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_subject: return get_poetic_form_subject_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_additional_feature: return get_poetic_form_additional_feature_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_perspective__T_type: return get_poetic_form_perspective__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::occupation_type: return get_occupation_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::buildings_other_id: return get_buildings_other_id_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::building_type: return get_building_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::civzone_type: return get_civzone_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::furnace_type: return get_furnace_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::workshop_type: return get_workshop_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::construction_type: return get_construction_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::shop_type: return get_shop_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::siegeengine_type: return get_siegeengine_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::trap_type: return get_trap_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::dfhack_room_quality_level: return get_dfhack_room_quality_level_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::creature_raw_flags: return get_creature_raw_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::caste_raw_flags: return get_caste_raw_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::body_part_raw_flags: return get_body_part_raw_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::appearance_modifier_type: return get_appearance_modifier_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::body_part_layer_flags: return get_body_part_layer_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::appearance_modifier_growth_interval: return get_appearance_modifier_growth_interval_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::gait_type: return get_gait_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::creature_graphics_role: return get_creature_graphics_role_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tissue_style_type: return get_tissue_style_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::body_part_template_flags: return get_body_part_template_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::body_part_template_contype: return get_body_part_template_contype_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tissue_flags: return get_tissue_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_nickname: return get_d_init_nickname_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_z_view: return get_d_init_z_view_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_embark_confirm: return get_d_init_embark_confirm_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_idlers: return get_d_init_idlers_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_tunnel: return get_d_init_tunnel_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_flags1: return get_d_init_flags1_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_flags2: return get_d_init_flags2_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_flags3: return get_d_init_flags3_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_flags4: return get_d_init_flags4_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::pattern_type: return get_pattern_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::occasion_schedule_type: return get_occasion_schedule_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::occasion_schedule_feature: return get_occasion_schedule_feature_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_sell_category: return get_entity_sell_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::historical_entity_type: return get_historical_entity_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::training_knowledge_level: return get_training_knowledge_level_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_position_flags: return get_entity_position_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_material_category: return get_entity_material_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_event_type: return get_entity_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_raw_flags: return get_entity_raw_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::site_type: return get_site_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ethic_type: return get_ethic_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ethic_response: return get_ethic_response_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_name_type: return get_entity_name_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_position_raw_flags: return get_entity_position_raw_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_position_responsibility: return get_entity_position_responsibility_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::weather_type: return get_weather_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::game_mode: return get_game_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::game_type: return get_game_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::lever_target_type: return get_lever_target_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::zoom_commands: return get_zoom_commands_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::reputation_type: return get_reputation_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::histfig_flags: return get_histfig_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::histfig_relationship_type: return get_histfig_relationship_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mental_picture_property_type: return get_mental_picture_property_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mental_picture_element_type: return get_mental_picture_element_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_type: return get_history_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_reason: return get_history_event_reason_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::death_type: return get_death_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_action_type: return get_entity_action_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::masterpiece_loss_type: return get_masterpiece_loss_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_hist_figure_woundedst__T_injury_type: return get_history_event_hist_figure_woundedst__T_injury_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_simple_battle_subtype: return get_history_event_simple_battle_subtype_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::histfig_body_state: return get_histfig_body_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_hf_act_on_buildingst__T_action: return get_history_event_hf_act_on_buildingst__T_action_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::site_dispute_type: return get_site_dispute_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::insurrection_outcome: return get_insurrection_outcome_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_hf_act_on_artifactst__T_action: return get_history_event_hf_act_on_artifactst__T_action_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tactical_situation: return get_tactical_situation_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_collection_type: return get_history_event_collection_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::era_type: return get_era_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::init_display_flags: return get_init_display_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::init_media_flags: return get_init_media_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::init_input_flags: return get_init_input_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::init_window_flags: return get_init_window_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interaction_effect_type: return get_interaction_effect_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interaction_effect_location_hint: return get_interaction_effect_location_hint_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interaction_source_type: return get_interaction_source_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interaction_source_usage_hint: return get_interaction_source_usage_hint_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interaction_target_type: return get_interaction_target_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interaction_target_location_type: return get_interaction_target_location_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::breath_attack_type: return get_breath_attack_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::item_type: return get_item_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ammo_flags: return get_ammo_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::armor_general_flags: return get_armor_general_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::armor_flags: return get_armor_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::gloves_flags: return get_gloves_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::helm_flags: return get_helm_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::instrument_flags: return get_instrument_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::sound_production_type: return get_sound_production_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::pitch_choice_type: return get_pitch_choice_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tuning_type: return get_tuning_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::timbre_type: return get_timbre_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::pants_flags: return get_pants_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::shoes_flags: return get_shoes_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tool_flags: return get_tool_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tool_uses: return get_tool_uses_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::toy_flags: return get_toy_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::trapcomp_flags: return get_trapcomp_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::weapon_flags: return get_weapon_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::items_other_id: return get_items_other_id_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_item_vector_id: return get_job_item_vector_id_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::improvement_type: return get_improvement_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::itemimprovement_specific_type: return get_itemimprovement_specific_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::written_content_type: return get_written_content_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::written_content_style: return get_written_content_style_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::item_magicness_type: return get_item_magicness_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::item_quality: return get_item_quality_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::slab_engraving_type: return get_slab_engraving_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::corpse_material_type: return get_corpse_material_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_type_class: return get_job_type_class_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_type: return get_job_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_subtype_surgery: return get_job_subtype_surgery_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_art_specification__T_type: return get_job_art_specification__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::manager_order_condition_order__T_condition: return get_manager_order_condition_order__T_condition_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::guild_id: return get_guild_id_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interface_key: return get_interface_key_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::dfhack_knowledge_scholar_flag: return get_dfhack_knowledge_scholar_flag_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::part_of_speech: return get_part_of_speech_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::sphere_type: return get_sphere_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::language_name_category: return get_language_name_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::nemesis_flags: return get_nemesis_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::machine_type: return get_machine_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::screw_pump_direction: return get_screw_pump_direction_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tile_traffic: return get_tile_traffic_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tile_dig_designation: return get_tile_dig_designation_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tile_liquid: return get_tile_liquid_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tile_building_occ: return get_tile_building_occ_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tile_liquid_flow_dir: return get_tile_liquid_flow_dir_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::block_square_event_type: return get_block_square_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::feature_type: return get_feature_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::feature_init_flags: return get_feature_init_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::feature_alteration_type: return get_feature_alteration_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_construction_type: return get_world_construction_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::biome_type: return get_biome_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::flow_type: return get_flow_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::flow_guide_type: return get_flow_guide_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::region_block_event_type: return get_region_block_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::craft_material_class: return get_craft_material_class_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::builtin_mats: return get_builtin_mats_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::material_flags: return get_material_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::matter_state: return get_matter_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::strain_type: return get_strain_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::inorganic_flags: return get_inorganic_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::environment_type: return get_environment_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::inclusion_type: return get_inclusion_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::organic_mat_category: return get_organic_mat_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::meeting_topic: return get_meeting_topic_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::meeting_event_type: return get_meeting_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::activity_event_type: return get_activity_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::conversation_menu: return get_conversation_menu_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::performance_event_type: return get_performance_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::performance_participant_type: return get_performance_participant_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::uniform_category: return get_uniform_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::barrack_preference_category: return get_barrack_preference_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::squad_event_type: return get_squad_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::squad_order_type: return get_squad_order_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::squad_order_cannot_reason: return get_squad_order_cannot_reason_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::army_flags: return get_army_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_path_goal: return get_unit_path_goal_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_station_type: return get_unit_station_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::plant_raw_flags: return get_plant_raw_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::projectile_type: return get_projectile_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::reaction_flags: return get_reaction_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::reaction_reagent_type: return get_reaction_reagent_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::reaction_product_type: return get_reaction_product_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::reaction_product_item_flags: return get_reaction_product_item_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::reaction_product_improvement_flags: return get_reaction_product_improvement_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::general_ref_type: return get_general_ref_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::specific_ref_type: return get_specific_ref_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::histfig_entity_link_type: return get_histfig_entity_link_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::histfig_site_link_type: return get_histfig_site_link_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::histfig_hf_link_type: return get_histfig_hf_link_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_entity_link_type: return get_entity_entity_link_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::resource_allotment_specifier_type: return get_resource_allotment_specifier_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::profession: return get_profession_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_labor_category: return get_unit_labor_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_labor: return get_unit_labor_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_skill_class: return get_job_skill_class_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_skill: return get_job_skill_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::hauler_type: return get_hauler_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::furniture_type: return get_furniture_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::stockpile_category: return get_stockpile_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::stockpile_list: return get_stockpile_list_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::creature_interaction_effect_type: return get_creature_interaction_effect_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::creature_interaction_effect_target_mode: return get_creature_interaction_effect_target_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tiletype_shape_basic: return get_tiletype_shape_basic_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tiletype_shape: return get_tiletype_shape_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tiletype_material: return get_tiletype_material_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tiletype_variant: return get_tiletype_variant_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tiletype_special: return get_tiletype_special_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tiletype: return get_tiletype_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::build_req_choice_type: return get_build_req_choice_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_hotkey__T_cmd: return get_ui_hotkey__T_cmd_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_sidebar_mode: return get_ui_sidebar_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::kitchen_exc_type: return get_kitchen_exc_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::timed_event_type: return get_timed_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::emotion_type: return get_emotion_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_thought_type: return get_unit_thought_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::value_type: return get_value_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::goal_type: return get_goal_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::personality_facet_type: return get_personality_facet_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::physical_attribute_type: return get_physical_attribute_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mental_attribute_type: return get_mental_attribute_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mood_type: return get_mood_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ghost_type: return get_ghost_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::animal_training_level: return get_animal_training_level_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_report_type: return get_unit_report_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::skill_rating: return get_skill_rating_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_relationship_type: return get_unit_relationship_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::need_type: return get_need_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ghost_goal: return get_ghost_goal_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::wound_effect_type: return get_wound_effect_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::misc_trait_type: return get_misc_trait_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_action_type: return get_unit_action_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interface_breakdown_types: return get_interface_breakdown_types_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::embark_finder_option: return get_embark_finder_option_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_image_creator_mode: return get_viewscreen_image_creator_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_kitchenpref_page: return get_viewscreen_kitchenpref_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::adventurer_attribute_level: return get_adventurer_attribute_level_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_unitlist_page: return get_viewscreen_unitlist_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_population_type: return get_world_population_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_region_type: return get_world_region_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::geo_layer_type: return get_geo_layer_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::region_map_entry_flags: return get_region_map_entry_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::front_type: return get_front_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::cumulus_type: return get_cumulus_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::stratus_type: return get_stratus_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::fog_type: return get_fog_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mountain_peak_flags: return get_mountain_peak_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::abstract_building_type: return get_abstract_building_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::abstract_building_flags: return get_abstract_building_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_site_type: return get_world_site_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_site_flags: return get_world_site_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::site_realization_building_type: return get_site_realization_building_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::site_shop_type: return get_site_shop_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tree_house_type: return get_tree_house_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::hillock_house_type: return get_hillock_house_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::creation_zone_pwg_alteration_type: return get_creation_zone_pwg_alteration_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::worldgen_region_type: return get_worldgen_region_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::worldgen_range_type: return get_worldgen_range_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::units_other_id: return get_units_other_id_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::conflict_level: return get_conflict_level_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::combat_report_event_type: return get_combat_report_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::conversation__T_state: return get_conversation__T_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::building_archerytargetst__T_archery_direction: return get_building_archerytargetst__T_archery_direction_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::building_bridgest__T_direction: return get_building_bridgest__T_direction_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::building_siegeenginest__T_facing: return get_building_siegeenginest__T_facing_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::building_siegeenginest__T_action: return get_building_siegeenginest__T_action_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::caste_body_info__T_interactions__T_type: return get_caste_body_info__T_interactions__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::caravan_state__T_trade_state: return get_caravan_state__T_trade_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_event__T_data__T_insurrection_end__T_result: return get_entity_event__T_data__T_insurrection_end__T_result_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_change_hf_statest__T_state: return get_history_event_change_hf_statest__T_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_body_abusedst__T_props__T_pile_type: return get_history_event_body_abusedst__T_props__T_pile_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_body_abusedst__T_abuse_type: return get_history_event_body_abusedst__T_abuse_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_hist_figure_travelst__T_reason: return get_history_event_hist_figure_travelst__T_reason_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_artifact_claim_formedst__T_claim_type: return get_history_event_artifact_claim_formedst__T_claim_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::init_display__T_windowed: return get_init_display__T_windowed_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::init_font__T_use_ttf: return get_init_font__T_use_ttf_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_item_ref__T_role: return get_job_item_ref__T_role_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::manager_order__T_frequency: return get_manager_order__T_frequency_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::manager_order_condition_item__T_compare_type: return get_manager_order_condition_item__T_compare_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mandate__T_mode: return get_mandate__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_demand__T_place: return get_unit_demand__T_place_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_advmode__T_conversation__T_targets__T_type: return get_ui_advmode__T_conversation__T_targets__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_advmode__T_travel_right_map: return get_ui_advmode__T_travel_right_map_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_advmode__T_show_menu: return get_ui_advmode__T_show_menu_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::stop_depart_condition__T_direction: return get_stop_depart_condition__T_direction_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::stop_depart_condition__T_mode: return get_stop_depart_condition__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interface_button_construction_category_selectorst__T_category_id: return get_interface_button_construction_category_selectorst__T_category_id_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_sidebar_menus__T_designation__T_mine_mode: return get_ui_sidebar_menus__T_designation__T_mine_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_sidebar_menus__T_zone__T_mode: return get_ui_sidebar_menus__T_zone__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_sidebar_menus__T_unit__T_expel_error: return get_ui_sidebar_menus__T_unit__T_expel_error_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_look_list__T_items__T_type: return get_ui_look_list__T_items__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_unit_view_mode__T_value: return get_ui_unit_view_mode__T_value_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit__T_meeting__T_state: return get_unit__T_meeting__T_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit__T_counters__T_soldier_mood: return get_unit__T_counters__T_soldier_mood_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_inventory_item__T_mode: return get_unit_inventory_item__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_preference__T_type: return get_unit_preference__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_complaint__T_type: return get_unit_complaint__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_request__T_type: return get_unit_request__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::KeybindingScreen__T_mode: return get_KeybindingScreen__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_adventure_logst__T_mode: return get_viewscreen_adventure_logst__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_adventure_logst__T_info_mode: return get_viewscreen_adventure_logst__T_info_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_assign_display_itemst__T_sel_column: return get_viewscreen_assign_display_itemst__T_sel_column_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_choose_start_sitest__T_page: return get_viewscreen_choose_start_sitest__T_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mission__T_details__T_raid__T_raid_type: return get_mission__T_details__T_raid__T_raid_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mission__T_type: return get_mission__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_civlistst__T_rumors__T_type: return get_viewscreen_civlistst__T_rumors__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_civlistst__T_page: return get_viewscreen_civlistst__T_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_game_cleanerst__T_state: return get_viewscreen_game_cleanerst__T_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_justicest__T_cur_column: return get_viewscreen_justicest__T_cur_column_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::assign_trade_status__T_status: return get_assign_trade_status__T_status_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_layer_choose_language_namest__T_current_component: return get_viewscreen_layer_choose_language_namest__T_current_component_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_mode: return get_viewscreen_layer_militaryst__T_equip__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode: return get_viewscreen_layer_militaryst__T_equip__T_edit_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_layer_militaryst__T_page: return get_viewscreen_layer_militaryst__T_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_layer_noblelistst__T_mode: return get_viewscreen_layer_noblelistst__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_legendsst__T_cur_page: return get_viewscreen_legendsst__T_cur_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_locationsst__T_in_edit: return get_viewscreen_locationsst__T_in_edit_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_locationsst__T_menu: return get_viewscreen_locationsst__T_menu_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_petst__T_mode: return get_viewscreen_petst__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::setup_character_info__T_status: return get_setup_character_info__T_status_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_setupadventurest__T_page: return get_viewscreen_setupadventurest__T_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_setupadventurest__T_sel_trait_column: return get_viewscreen_setupadventurest__T_sel_trait_column_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_setupdwarfgamest__T_mode: return get_viewscreen_setupdwarfgamest__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_titlest__T_sel_subpage: return get_viewscreen_titlest__T_sel_subpage_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_workquota_conditionst__T_mode: return get_viewscreen_workquota_conditionst__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_workshop_profilest__T_tab: return get_viewscreen_workshop_profilest__T_tab_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_underground_region__T_type: return get_world_underground_region__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_data__T_flip_latitude: return get_world_data__T_flip_latitude_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::abstract_building_dungeonst__T_dungeon_type: return get_abstract_building_dungeonst__T_dungeon_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::cultural_identity__T_group_log__T_join_type: return get_cultural_identity__T_group_log__T_join_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_site_realization__T_areas__T_type: return get_world_site_realization__T_areas__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::crime__T_mode: return get_crime__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		default: break;
	}
	return std::tuple<int64_t, std::string, std::string>(-1111,"UNKNOWN DF_TYPE", "");
}

