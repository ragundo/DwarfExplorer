#include <cstdint>
#include <DataDefs.h>
#include <Core.h>
#include <Console.h>
#include <Export.h>
#include <PluginManager.h>
#include <RemoteServer.h>
#include <RemoteClient.h>
#include <VersionInfo.h>
#include "df_all.h"
#include "node.h"
#include "offsets_cache.h"
#include "DF_Types.h"


using namespace rdf;


extern DF_Type get_df_subtype(DF_Type, uint64_t);
extern DF_Type get_real_subtype(uint64_t p_address, DF_Type p_df_type);
extern DF_Type enum_base_type(DF_Type p_enum);
extern DF_Type enum_size(DF_Type p_enum);


extern rdf::NodeDummy* dummy();


void fill_globals(Node* p_node_parent)
{
	std::string field_name;

	field_name = "activity_next_id";
	auto n_activity_next_id          = new NodeSimple<int32_t>;
	n_activity_next_id->m_field_name = field_name;
	n_activity_next_id->m_df_type    = DF_Type::int32_t;
	n_activity_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_activity_next_id->m_node_type  = NodeType::Simple;
	n_activity_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::activity_next_id);
	n_activity_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_activity_next_id);

	field_name = "agreement_next_id";
	auto n_agreement_next_id          = new NodeSimple<int32_t>;
	n_agreement_next_id->m_field_name = field_name;
	n_agreement_next_id->m_df_type    = DF_Type::int32_t;
	n_agreement_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_agreement_next_id->m_node_type  = NodeType::Simple;
	n_agreement_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::agreement_next_id);
	n_agreement_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_agreement_next_id);

	field_name = "army_controller_next_id";
	auto n_army_controller_next_id          = new NodeSimple<int32_t>;
	n_army_controller_next_id->m_field_name = field_name;
	n_army_controller_next_id->m_df_type    = DF_Type::int32_t;
	n_army_controller_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_army_controller_next_id->m_node_type  = NodeType::Simple;
	n_army_controller_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::army_controller_next_id);
	n_army_controller_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_army_controller_next_id);

	field_name = "army_next_id";
	auto n_army_next_id          = new NodeSimple<int32_t>;
	n_army_next_id->m_field_name = field_name;
	n_army_next_id->m_df_type    = DF_Type::int32_t;
	n_army_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_army_next_id->m_node_type  = NodeType::Simple;
	n_army_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::army_next_id);
	n_army_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_army_next_id);

	field_name = "army_tracking_info_next_id";
	auto n_army_tracking_info_next_id          = new NodeSimple<int32_t>;
	n_army_tracking_info_next_id->m_field_name = field_name;
	n_army_tracking_info_next_id->m_df_type    = DF_Type::int32_t;
	n_army_tracking_info_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_army_tracking_info_next_id->m_node_type  = NodeType::Simple;
	n_army_tracking_info_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::army_tracking_info_next_id);
	n_army_tracking_info_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_army_tracking_info_next_id);

	field_name = "art_image_chunk_next_id";
	auto n_art_image_chunk_next_id          = new NodeSimple<int32_t>;
	n_art_image_chunk_next_id->m_field_name = field_name;
	n_art_image_chunk_next_id->m_df_type    = DF_Type::int32_t;
	n_art_image_chunk_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_art_image_chunk_next_id->m_node_type  = NodeType::Simple;
	n_art_image_chunk_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::art_image_chunk_next_id);
	n_art_image_chunk_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_art_image_chunk_next_id);

	field_name = "artifact_next_id";
	auto n_artifact_next_id          = new NodeSimple<int32_t>;
	n_artifact_next_id->m_field_name = field_name;
	n_artifact_next_id->m_df_type    = DF_Type::int32_t;
	n_artifact_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_artifact_next_id->m_node_type  = NodeType::Simple;
	n_artifact_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::artifact_next_id);
	n_artifact_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_artifact_next_id);

	field_name = "basic_seed";
	auto n_basic_seed          = new NodeSimple<int32_t>;
	n_basic_seed->m_field_name = field_name;
	n_basic_seed->m_df_type    = DF_Type::int32_t;
	n_basic_seed->m_rdf_type   = RDF_Type::int32_t;
	n_basic_seed->m_node_type  = NodeType::Simple;
	n_basic_seed->m_address    = reinterpret_cast<uint64_t>(df::global::basic_seed);
	n_basic_seed->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_basic_seed);

	field_name = "belief_system_next_id";
	auto n_belief_system_next_id          = new NodeSimple<int32_t>;
	n_belief_system_next_id->m_field_name = field_name;
	n_belief_system_next_id->m_df_type    = DF_Type::int32_t;
	n_belief_system_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_belief_system_next_id->m_node_type  = NodeType::Simple;
	n_belief_system_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::belief_system_next_id);
	n_belief_system_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_belief_system_next_id);

	field_name = "building_next_id";
	auto n_building_next_id          = new NodeSimple<int32_t>;
	n_building_next_id->m_field_name = field_name;
	n_building_next_id->m_df_type    = DF_Type::int32_t;
	n_building_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_building_next_id->m_node_type  = NodeType::Simple;
	n_building_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::building_next_id);
	n_building_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_building_next_id);

	field_name = "created_item_count";
	auto n_created_item_count            = new NodeVector;
	n_created_item_count->m_field_name   = field_name;
	n_created_item_count->m_df_type      = DF_Type::int32_t;
	n_created_item_count->m_rdf_type     = RDF_Type::Vector;
	n_created_item_count->m_node_type    = NodeType::Vector;
	n_created_item_count->m_addornements = "v";
	n_created_item_count->m_address      = reinterpret_cast<uint64_t>(df::global::created_item_count);
	n_created_item_count->m_parent       = p_node_parent;
	n_created_item_count->m_children.push_back(rdf::dummy());
	p_node_parent->m_children.push_back(n_created_item_count);

	field_name = "created_item_matindex";
	auto n_created_item_matindex            = new NodeVector;
	n_created_item_matindex->m_field_name   = field_name;
	n_created_item_matindex->m_df_type      = DF_Type::int16_t;
	n_created_item_matindex->m_rdf_type     = RDF_Type::Vector;
	n_created_item_matindex->m_node_type    = NodeType::Vector;
	n_created_item_matindex->m_addornements = "v";
	n_created_item_matindex->m_address      = reinterpret_cast<uint64_t>(df::global::created_item_matindex);
	n_created_item_matindex->m_parent       = p_node_parent;
	n_created_item_matindex->m_children.push_back(rdf::dummy());
	p_node_parent->m_children.push_back(n_created_item_matindex);

	field_name = "created_item_mattype";
	auto n_created_item_mattype            = new NodeVector;
	n_created_item_mattype->m_field_name   = field_name;
	n_created_item_mattype->m_df_type      = DF_Type::int16_t;
	n_created_item_mattype->m_rdf_type     = RDF_Type::Vector;
	n_created_item_mattype->m_node_type    = NodeType::Vector;
	n_created_item_mattype->m_addornements = "v";
	n_created_item_mattype->m_address      = reinterpret_cast<uint64_t>(df::global::created_item_mattype);
	n_created_item_mattype->m_parent       = p_node_parent;
	n_created_item_mattype->m_children.push_back(rdf::dummy());
	p_node_parent->m_children.push_back(n_created_item_mattype);

	field_name = "created_item_subtype";
	auto n_created_item_subtype            = new NodeVector;
	n_created_item_subtype->m_field_name   = field_name;
	n_created_item_subtype->m_df_type      = DF_Type::int16_t;
	n_created_item_subtype->m_rdf_type     = RDF_Type::Vector;
	n_created_item_subtype->m_node_type    = NodeType::Vector;
	n_created_item_subtype->m_addornements = "v";
	n_created_item_subtype->m_address      = reinterpret_cast<uint64_t>(df::global::created_item_subtype);
	n_created_item_subtype->m_parent       = p_node_parent;
	n_created_item_subtype->m_children.push_back(rdf::dummy());
	p_node_parent->m_children.push_back(n_created_item_subtype);

	field_name = "created_item_type";
	auto n_created_item_type            = new NodeVector;
	n_created_item_type->m_field_name   = field_name;
	n_created_item_type->m_df_type      = DF_Type::item_type;
	n_created_item_type->m_rdf_type     = RDF_Type::Vector;
	n_created_item_type->m_node_type    = NodeType::Vector;
	n_created_item_type->m_enum_base    = DF_Type::int16_t;
	n_created_item_type->m_defined_in   = "df.item-raws.xml";
	n_created_item_type->m_addornements = "v";
	n_created_item_type->m_address      = reinterpret_cast<uint64_t>(df::global::created_item_type);
	n_created_item_type->m_parent       = p_node_parent;
	n_created_item_type->m_children.push_back(rdf::dummy());
	p_node_parent->m_children.push_back(n_created_item_type);

	field_name = "crime_next_id";
	auto n_crime_next_id          = new NodeSimple<int32_t>;
	n_crime_next_id->m_field_name = field_name;
	n_crime_next_id->m_df_type    = DF_Type::int32_t;
	n_crime_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_crime_next_id->m_node_type  = NodeType::Simple;
	n_crime_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::crime_next_id);
	n_crime_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_crime_next_id);

	field_name = "cultural_identity_next_id";
	auto n_cultural_identity_next_id          = new NodeSimple<int32_t>;
	n_cultural_identity_next_id->m_field_name = field_name;
	n_cultural_identity_next_id->m_df_type    = DF_Type::int32_t;
	n_cultural_identity_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_cultural_identity_next_id->m_node_type  = NodeType::Simple;
	n_cultural_identity_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::cultural_identity_next_id);
	n_cultural_identity_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_cultural_identity_next_id);

	field_name = "cur_season";
	auto n_cur_season          = new NodeSimple<int8_t>;
	n_cur_season->m_field_name = field_name;
	n_cur_season->m_df_type    = DF_Type::int8_t;
	n_cur_season->m_rdf_type   = RDF_Type::int8_t;
	n_cur_season->m_node_type  = NodeType::Simple;
	n_cur_season->m_address    = reinterpret_cast<uint64_t>(df::global::cur_season);
	n_cur_season->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_cur_season);

	field_name = "cur_season_tick";
	auto n_cur_season_tick          = new NodeSimple<int32_t>;
	n_cur_season_tick->m_field_name = field_name;
	n_cur_season_tick->m_df_type    = DF_Type::int32_t;
	n_cur_season_tick->m_rdf_type   = RDF_Type::int32_t;
	n_cur_season_tick->m_node_type  = NodeType::Simple;
	n_cur_season_tick->m_address    = reinterpret_cast<uint64_t>(df::global::cur_season_tick);
	n_cur_season_tick->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_cur_season_tick);

	field_name = "cur_year";
	auto n_cur_year          = new NodeSimple<int32_t>;
	n_cur_year->m_field_name = field_name;
	n_cur_year->m_df_type    = DF_Type::int32_t;
	n_cur_year->m_rdf_type   = RDF_Type::int32_t;
	n_cur_year->m_node_type  = NodeType::Simple;
	n_cur_year->m_address    = reinterpret_cast<uint64_t>(df::global::cur_year);
	n_cur_year->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_cur_year);

	field_name = "cur_year_tick";
	auto n_cur_year_tick          = new NodeSimple<int32_t>;
	n_cur_year_tick->m_field_name = field_name;
	n_cur_year_tick->m_df_type    = DF_Type::int32_t;
	n_cur_year_tick->m_rdf_type   = RDF_Type::int32_t;
	n_cur_year_tick->m_node_type  = NodeType::Simple;
	n_cur_year_tick->m_address    = reinterpret_cast<uint64_t>(df::global::cur_year_tick);
	n_cur_year_tick->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_cur_year_tick);

	field_name = "cur_year_tick_advmode";
	auto n_cur_year_tick_advmode          = new NodeSimple<int32_t>;
	n_cur_year_tick_advmode->m_field_name = field_name;
	n_cur_year_tick_advmode->m_df_type    = DF_Type::int32_t;
	n_cur_year_tick_advmode->m_rdf_type   = RDF_Type::int32_t;
	n_cur_year_tick_advmode->m_node_type  = NodeType::Simple;
	n_cur_year_tick_advmode->m_address    = reinterpret_cast<uint64_t>(df::global::cur_year_tick_advmode);
	n_cur_year_tick_advmode->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_cur_year_tick_advmode);

	field_name = "current_weather";
	auto n_current_weather            = new NodeArray;
	n_current_weather->m_address      = reinterpret_cast<uint64_t>(df::global::current_weather);
	n_current_weather->m_field_name   = field_name;
	n_current_weather->m_df_type      = DF_Type::weather_type;
	n_current_weather->m_rdf_type     = RDF_Type::Array;
	n_current_weather->m_node_type    = NodeType::Array;
	n_current_weather->m_enum_base    = DF_Type::int8_t;
	n_current_weather->m_defined_in   = "df.globals.xml";
	n_current_weather->m_addornements = "[5[5";
	n_current_weather->m_array_size   = 5;
	n_current_weather->m_address      = reinterpret_cast<uint64_t>(df::global::current_weather);
	n_current_weather->m_parent       = p_node_parent;
	p_node_parent->m_children.push_back(n_current_weather);

	field_name = "cursor";
	auto n_cursor = new NodeCompound;
	n_cursor->m_field_name = field_name;
	n_cursor->m_df_type    = DF_Type::T_cursor;
	n_cursor->m_rdf_type   = RDF_Type::Compound;
	n_cursor->m_node_type  = NodeType::Compound;
	n_cursor->m_address      = reinterpret_cast<uint64_t>(df::global::cursor);
	n_cursor->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_cursor);

	field_name = "d_init";
	auto n_d_init = new NodeCompound;
	n_d_init->m_field_name = field_name;
	n_d_init->m_df_type    = DF_Type::d_init;
	n_d_init->m_rdf_type   = RDF_Type::Compound;
	n_d_init->m_node_type  = NodeType::Compound;
	n_d_init->m_address      = reinterpret_cast<uint64_t>(df::global::d_init);
	n_d_init->m_defined_in = "df.globals.xml";
	n_d_init->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_d_init);

	field_name = "dance_form_next_id";
	auto n_dance_form_next_id          = new NodeSimple<int32_t>;
	n_dance_form_next_id->m_field_name = field_name;
	n_dance_form_next_id->m_df_type    = DF_Type::int32_t;
	n_dance_form_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_dance_form_next_id->m_node_type  = NodeType::Simple;
	n_dance_form_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::dance_form_next_id);
	n_dance_form_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_dance_form_next_id);

	field_name = "debug_combat";
	auto n_debug_combat          = new NodeSimple<bool>;
	n_debug_combat->m_field_name = field_name;
	n_debug_combat->m_df_type    = DF_Type::Bool;
	n_debug_combat->m_rdf_type   = RDF_Type::Bool;
	n_debug_combat->m_node_type  = NodeType::Simple;
	n_debug_combat->m_address    = reinterpret_cast<uint64_t>(df::global::debug_combat);
	n_debug_combat->m_comment    = "Functionality unknown, combat-related";
	n_debug_combat->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_debug_combat);

	field_name = "debug_fastmining";
	auto n_debug_fastmining          = new NodeSimple<bool>;
	n_debug_fastmining->m_field_name = field_name;
	n_debug_fastmining->m_df_type    = DF_Type::Bool;
	n_debug_fastmining->m_rdf_type   = RDF_Type::Bool;
	n_debug_fastmining->m_node_type  = NodeType::Simple;
	n_debug_fastmining->m_address    = reinterpret_cast<uint64_t>(df::global::debug_fastmining);
	n_debug_fastmining->m_comment    = "All dwarves mine as fast as a Legendary Miner";
	n_debug_fastmining->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_debug_fastmining);

	field_name = "debug_noberserk";
	auto n_debug_noberserk          = new NodeSimple<bool>;
	n_debug_noberserk->m_field_name = field_name;
	n_debug_noberserk->m_df_type    = DF_Type::Bool;
	n_debug_noberserk->m_rdf_type   = RDF_Type::Bool;
	n_debug_noberserk->m_node_type  = NodeType::Simple;
	n_debug_noberserk->m_address    = reinterpret_cast<uint64_t>(df::global::debug_noberserk);
	n_debug_noberserk->m_comment    = "Insanity can only result in Crazed or Melancholy, never Berserk";
	n_debug_noberserk->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_debug_noberserk);

	field_name = "debug_nodrink";
	auto n_debug_nodrink          = new NodeSimple<bool>;
	n_debug_nodrink->m_field_name = field_name;
	n_debug_nodrink->m_df_type    = DF_Type::Bool;
	n_debug_nodrink->m_rdf_type   = RDF_Type::Bool;
	n_debug_nodrink->m_node_type  = NodeType::Simple;
	n_debug_nodrink->m_address    = reinterpret_cast<uint64_t>(df::global::debug_nodrink);
	n_debug_nodrink->m_comment    = "Disables thirst on everything";
	n_debug_nodrink->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_debug_nodrink);

	field_name = "debug_noeat";
	auto n_debug_noeat          = new NodeSimple<bool>;
	n_debug_noeat->m_field_name = field_name;
	n_debug_noeat->m_df_type    = DF_Type::Bool;
	n_debug_noeat->m_rdf_type   = RDF_Type::Bool;
	n_debug_noeat->m_node_type  = NodeType::Simple;
	n_debug_noeat->m_address    = reinterpret_cast<uint64_t>(df::global::debug_noeat);
	n_debug_noeat->m_comment    = "Disables hunger on everything";
	n_debug_noeat->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_debug_noeat);

	field_name = "debug_nomoods";
	auto n_debug_nomoods          = new NodeSimple<bool>;
	n_debug_nomoods->m_field_name = field_name;
	n_debug_nomoods->m_df_type    = DF_Type::Bool;
	n_debug_nomoods->m_rdf_type   = RDF_Type::Bool;
	n_debug_nomoods->m_node_type  = NodeType::Simple;
	n_debug_nomoods->m_address    = reinterpret_cast<uint64_t>(df::global::debug_nomoods);
	n_debug_nomoods->m_comment    = "Same as ARTIFACTS:NO";
	n_debug_nomoods->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_debug_nomoods);

	field_name = "debug_nopause";
	auto n_debug_nopause          = new NodeSimple<bool>;
	n_debug_nopause->m_field_name = field_name;
	n_debug_nopause->m_df_type    = DF_Type::Bool;
	n_debug_nopause->m_rdf_type   = RDF_Type::Bool;
	n_debug_nopause->m_node_type  = NodeType::Simple;
	n_debug_nopause->m_address    = reinterpret_cast<uint64_t>(df::global::debug_nopause);
	n_debug_nopause->m_comment    = "Prevents the game from being paused";
	n_debug_nopause->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_debug_nopause);

	field_name = "debug_nosleep";
	auto n_debug_nosleep          = new NodeSimple<bool>;
	n_debug_nosleep->m_field_name = field_name;
	n_debug_nosleep->m_df_type    = DF_Type::Bool;
	n_debug_nosleep->m_rdf_type   = RDF_Type::Bool;
	n_debug_nosleep->m_node_type  = NodeType::Simple;
	n_debug_nosleep->m_address    = reinterpret_cast<uint64_t>(df::global::debug_nosleep);
	n_debug_nosleep->m_comment    = "Disables drowsiness on everything";
	n_debug_nosleep->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_debug_nosleep);

	field_name = "debug_showambush";
	auto n_debug_showambush          = new NodeSimple<bool>;
	n_debug_showambush->m_field_name = field_name;
	n_debug_showambush->m_df_type    = DF_Type::Bool;
	n_debug_showambush->m_rdf_type   = RDF_Type::Bool;
	n_debug_showambush->m_node_type  = NodeType::Simple;
	n_debug_showambush->m_address    = reinterpret_cast<uint64_t>(df::global::debug_showambush);
	n_debug_showambush->m_comment    = "Makes hidden ambushers visible on-screen and in the units list (but not to your citizens)";
	n_debug_showambush->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_debug_showambush);

	field_name = "debug_turbospeed";
	auto n_debug_turbospeed          = new NodeSimple<bool>;
	n_debug_turbospeed->m_field_name = field_name;
	n_debug_turbospeed->m_df_type    = DF_Type::Bool;
	n_debug_turbospeed->m_rdf_type   = RDF_Type::Bool;
	n_debug_turbospeed->m_node_type  = NodeType::Simple;
	n_debug_turbospeed->m_address    = reinterpret_cast<uint64_t>(df::global::debug_turbospeed);
	n_debug_turbospeed->m_comment    = "All units move and work at maximum speed";
	n_debug_turbospeed->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_debug_turbospeed);

	field_name = "debug_wildlife";
	auto n_debug_wildlife          = new NodeSimple<bool>;
	n_debug_wildlife->m_field_name = field_name;
	n_debug_wildlife->m_df_type    = DF_Type::Bool;
	n_debug_wildlife->m_rdf_type   = RDF_Type::Bool;
	n_debug_wildlife->m_node_type  = NodeType::Simple;
	n_debug_wildlife->m_address    = reinterpret_cast<uint64_t>(df::global::debug_wildlife);
	n_debug_wildlife->m_comment    = "Functionality unknown, wildlife-related";
	n_debug_wildlife->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_debug_wildlife);

	field_name = "entity_next_id";
	auto n_entity_next_id          = new NodeSimple<int32_t>;
	n_entity_next_id->m_field_name = field_name;
	n_entity_next_id->m_df_type    = DF_Type::int32_t;
	n_entity_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_entity_next_id->m_node_type  = NodeType::Simple;
	n_entity_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::entity_next_id);
	n_entity_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_entity_next_id);

	field_name = "flow_guide_next_id";
	auto n_flow_guide_next_id          = new NodeSimple<int32_t>;
	n_flow_guide_next_id->m_field_name = field_name;
	n_flow_guide_next_id->m_df_type    = DF_Type::int32_t;
	n_flow_guide_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_flow_guide_next_id->m_node_type  = NodeType::Simple;
	n_flow_guide_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::flow_guide_next_id);
	n_flow_guide_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_flow_guide_next_id);

	field_name = "flows";
	auto n_flows            = new NodeVector;
	n_flows->m_field_name   = field_name;
	n_flows->m_df_type      = DF_Type::flow_info;
	n_flows->m_rdf_type     = RDF_Type::Vector;
	n_flows->m_node_type    = NodeType::Vector;
	n_flows->m_defined_in   = "df.map.xml";
	n_flows->m_addornements = "v*";
	n_flows->m_address      = reinterpret_cast<uint64_t>(df::global::flows);
	n_flows->m_parent       = p_node_parent;
	n_flows->m_children.push_back(rdf::dummy());
	p_node_parent->m_children.push_back(n_flows);

	field_name = "formation_next_id";
	auto n_formation_next_id          = new NodeSimple<int32_t>;
	n_formation_next_id->m_field_name = field_name;
	n_formation_next_id->m_df_type    = DF_Type::int32_t;
	n_formation_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_formation_next_id->m_node_type  = NodeType::Simple;
	n_formation_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::formation_next_id);
	n_formation_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_formation_next_id);

	field_name = "gamemode";
	auto n_gamemode = new NodeEnum;
	n_gamemode->m_field_name = field_name;
	n_gamemode->m_df_type    = DF_Type::game_mode;
	n_gamemode->m_rdf_type   = RDF_Type::Enum;
	n_gamemode->m_node_type  = NodeType::Enum;
	n_gamemode->m_base_type  = DF_Type::int32_t;
	n_gamemode->m_enum_type  = "game_mode";
	n_gamemode->m_address    = reinterpret_cast<uint64_t>(df::global::gamemode);
	n_gamemode->m_defined_in = "df.globals.xml";
	n_gamemode->m_first_value = 0;
	n_gamemode->m_last_value  = 3;
	n_gamemode->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_gamemode);

	field_name = "gametype";
	auto n_gametype = new NodeEnum;
	n_gametype->m_field_name = field_name;
	n_gametype->m_df_type    = DF_Type::game_type;
	n_gametype->m_rdf_type   = RDF_Type::Enum;
	n_gametype->m_node_type  = NodeType::Enum;
	n_gametype->m_base_type  = DF_Type::int32_t;
	n_gametype->m_enum_type  = "game_type";
	n_gametype->m_address    = reinterpret_cast<uint64_t>(df::global::gametype);
	n_gametype->m_defined_in = "df.globals.xml";
	n_gametype->m_first_value = 0;
	n_gametype->m_last_value  = 11;
	n_gametype->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_gametype);

	field_name = "gps";
	auto n_gps = new NodeCompound;
	n_gps->m_field_name = field_name;
	n_gps->m_df_type    = DF_Type::graphic;
	n_gps->m_rdf_type   = RDF_Type::Compound;
	n_gps->m_node_type  = NodeType::Compound;
	n_gps->m_address      = reinterpret_cast<uint64_t>(df::global::gps);
	n_gps->m_defined_in = "df.graphics.xml";
	n_gps->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_gps);

	field_name = "gview";
	auto n_gview = new NodeCompound;
	n_gview->m_field_name = field_name;
	n_gview->m_df_type    = DF_Type::interfacest;
	n_gview->m_rdf_type   = RDF_Type::Compound;
	n_gview->m_node_type  = NodeType::Compound;
	n_gview->m_address      = reinterpret_cast<uint64_t>(df::global::gview);
	n_gview->m_defined_in = "df.viewscreen.xml";
	n_gview->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_gview);

	field_name = "hist_event_collection_next_id";
	auto n_hist_event_collection_next_id          = new NodeSimple<int32_t>;
	n_hist_event_collection_next_id->m_field_name = field_name;
	n_hist_event_collection_next_id->m_df_type    = DF_Type::int32_t;
	n_hist_event_collection_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_hist_event_collection_next_id->m_node_type  = NodeType::Simple;
	n_hist_event_collection_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::hist_event_collection_next_id);
	n_hist_event_collection_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_hist_event_collection_next_id);

	field_name = "hist_event_next_id";
	auto n_hist_event_next_id          = new NodeSimple<int32_t>;
	n_hist_event_next_id->m_field_name = field_name;
	n_hist_event_next_id->m_df_type    = DF_Type::int32_t;
	n_hist_event_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_hist_event_next_id->m_node_type  = NodeType::Simple;
	n_hist_event_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::hist_event_next_id);
	n_hist_event_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_hist_event_next_id);

	field_name = "hist_figure_next_id";
	auto n_hist_figure_next_id          = new NodeSimple<int32_t>;
	n_hist_figure_next_id->m_field_name = field_name;
	n_hist_figure_next_id->m_df_type    = DF_Type::int32_t;
	n_hist_figure_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_hist_figure_next_id->m_node_type  = NodeType::Simple;
	n_hist_figure_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::hist_figure_next_id);
	n_hist_figure_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_hist_figure_next_id);

	field_name = "identity_next_id";
	auto n_identity_next_id          = new NodeSimple<int32_t>;
	n_identity_next_id->m_field_name = field_name;
	n_identity_next_id->m_df_type    = DF_Type::int32_t;
	n_identity_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_identity_next_id->m_node_type  = NodeType::Simple;
	n_identity_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::identity_next_id);
	n_identity_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_identity_next_id);

	field_name = "incident_next_id";
	auto n_incident_next_id          = new NodeSimple<int32_t>;
	n_incident_next_id->m_field_name = field_name;
	n_incident_next_id->m_df_type    = DF_Type::int32_t;
	n_incident_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_incident_next_id->m_node_type  = NodeType::Simple;
	n_incident_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::incident_next_id);
	n_incident_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_incident_next_id);

	field_name = "init";
	auto n_init = new NodeCompound;
	n_init->m_field_name = field_name;
	n_init->m_df_type    = DF_Type::init;
	n_init->m_rdf_type   = RDF_Type::Compound;
	n_init->m_node_type  = NodeType::Compound;
	n_init->m_address      = reinterpret_cast<uint64_t>(df::global::init);
	n_init->m_defined_in = "df.init.xml";
	n_init->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_init);

	field_name = "interaction_instance_next_id";
	auto n_interaction_instance_next_id          = new NodeSimple<int32_t>;
	n_interaction_instance_next_id->m_field_name = field_name;
	n_interaction_instance_next_id->m_df_type    = DF_Type::int32_t;
	n_interaction_instance_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_interaction_instance_next_id->m_node_type  = NodeType::Simple;
	n_interaction_instance_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::interaction_instance_next_id);
	n_interaction_instance_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_interaction_instance_next_id);

	field_name = "item_next_id";
	auto n_item_next_id          = new NodeSimple<int32_t>;
	n_item_next_id->m_field_name = field_name;
	n_item_next_id->m_df_type    = DF_Type::int32_t;
	n_item_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_item_next_id->m_node_type  = NodeType::Simple;
	n_item_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::item_next_id);
	n_item_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_item_next_id);

	field_name = "job_next_id";
	auto n_job_next_id          = new NodeSimple<int32_t>;
	n_job_next_id->m_field_name = field_name;
	n_job_next_id->m_df_type    = DF_Type::int32_t;
	n_job_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_job_next_id->m_node_type  = NodeType::Simple;
	n_job_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::job_next_id);
	n_job_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_job_next_id);

	field_name = "machine_next_id";
	auto n_machine_next_id          = new NodeSimple<int32_t>;
	n_machine_next_id->m_field_name = field_name;
	n_machine_next_id->m_df_type    = DF_Type::int32_t;
	n_machine_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_machine_next_id->m_node_type  = NodeType::Simple;
	n_machine_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::machine_next_id);
	n_machine_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_machine_next_id);

	field_name = "map_renderer";
	auto n_map_renderer = new NodeCompound;
	n_map_renderer->m_field_name = field_name;
	n_map_renderer->m_df_type    = DF_Type::map_renderer;
	n_map_renderer->m_rdf_type   = RDF_Type::Compound;
	n_map_renderer->m_node_type  = NodeType::Compound;
	n_map_renderer->m_address      = reinterpret_cast<uint64_t>(df::global::map_renderer);
	n_map_renderer->m_defined_in = "df.ui.xml";
	n_map_renderer->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_map_renderer);

	field_name = "min_load_version";
	auto n_min_load_version          = new NodeSimple<int32_t>;
	n_min_load_version->m_field_name = field_name;
	n_min_load_version->m_df_type    = DF_Type::int32_t;
	n_min_load_version->m_rdf_type   = RDF_Type::int32_t;
	n_min_load_version->m_node_type  = NodeType::Simple;
	n_min_load_version->m_address    = reinterpret_cast<uint64_t>(df::global::min_load_version);
	n_min_load_version->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_min_load_version);

	field_name = "movie_version";
	auto n_movie_version          = new NodeSimple<int32_t>;
	n_movie_version->m_field_name = field_name;
	n_movie_version->m_df_type    = DF_Type::int32_t;
	n_movie_version->m_rdf_type   = RDF_Type::int32_t;
	n_movie_version->m_node_type  = NodeType::Simple;
	n_movie_version->m_address    = reinterpret_cast<uint64_t>(df::global::movie_version);
	n_movie_version->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_movie_version);

	field_name = "musical_form_next_id";
	auto n_musical_form_next_id          = new NodeSimple<int32_t>;
	n_musical_form_next_id->m_field_name = field_name;
	n_musical_form_next_id->m_df_type    = DF_Type::int32_t;
	n_musical_form_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_musical_form_next_id->m_node_type  = NodeType::Simple;
	n_musical_form_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::musical_form_next_id);
	n_musical_form_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_musical_form_next_id);

	field_name = "nemesis_next_id";
	auto n_nemesis_next_id          = new NodeSimple<int32_t>;
	n_nemesis_next_id->m_field_name = field_name;
	n_nemesis_next_id->m_df_type    = DF_Type::int32_t;
	n_nemesis_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_nemesis_next_id->m_node_type  = NodeType::Simple;
	n_nemesis_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::nemesis_next_id);
	n_nemesis_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_nemesis_next_id);

	field_name = "occupation_next_id";
	auto n_occupation_next_id          = new NodeSimple<int32_t>;
	n_occupation_next_id->m_field_name = field_name;
	n_occupation_next_id->m_df_type    = DF_Type::int32_t;
	n_occupation_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_occupation_next_id->m_node_type  = NodeType::Simple;
	n_occupation_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::occupation_next_id);
	n_occupation_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_occupation_next_id);

	field_name = "pause_state";
	auto n_pause_state          = new NodeSimple<bool>;
	n_pause_state->m_field_name = field_name;
	n_pause_state->m_df_type    = DF_Type::Bool;
	n_pause_state->m_rdf_type   = RDF_Type::Bool;
	n_pause_state->m_node_type  = NodeType::Simple;
	n_pause_state->m_address    = reinterpret_cast<uint64_t>(df::global::pause_state);
	n_pause_state->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_pause_state);

	field_name = "poetic_form_next_id";
	auto n_poetic_form_next_id          = new NodeSimple<int32_t>;
	n_poetic_form_next_id->m_field_name = field_name;
	n_poetic_form_next_id->m_df_type    = DF_Type::int32_t;
	n_poetic_form_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_poetic_form_next_id->m_node_type  = NodeType::Simple;
	n_poetic_form_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::poetic_form_next_id);
	n_poetic_form_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_poetic_form_next_id);

	field_name = "process_dig";
	auto n_process_dig          = new NodeSimple<bool>;
	n_process_dig->m_field_name = field_name;
	n_process_dig->m_df_type    = DF_Type::Bool;
	n_process_dig->m_rdf_type   = RDF_Type::Bool;
	n_process_dig->m_node_type  = NodeType::Simple;
	n_process_dig->m_address    = reinterpret_cast<uint64_t>(df::global::process_dig);
	n_process_dig->m_comment    = "Requests dig designations to be processed next frame.";
	n_process_dig->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_process_dig);

	field_name = "process_jobs";
	auto n_process_jobs          = new NodeSimple<bool>;
	n_process_jobs->m_field_name = field_name;
	n_process_jobs->m_df_type    = DF_Type::Bool;
	n_process_jobs->m_rdf_type   = RDF_Type::Bool;
	n_process_jobs->m_node_type  = NodeType::Simple;
	n_process_jobs->m_address    = reinterpret_cast<uint64_t>(df::global::process_jobs);
	n_process_jobs->m_comment    = "Requests building jobs to be processed next frame.";
	n_process_jobs->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_process_jobs);

	field_name = "proj_next_id";
	auto n_proj_next_id          = new NodeSimple<int32_t>;
	n_proj_next_id->m_field_name = field_name;
	n_proj_next_id->m_df_type    = DF_Type::int32_t;
	n_proj_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_proj_next_id->m_node_type  = NodeType::Simple;
	n_proj_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::proj_next_id);
	n_proj_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_proj_next_id);

	field_name = "rhythm_next_id";
	auto n_rhythm_next_id          = new NodeSimple<int32_t>;
	n_rhythm_next_id->m_field_name = field_name;
	n_rhythm_next_id->m_df_type    = DF_Type::int32_t;
	n_rhythm_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_rhythm_next_id->m_node_type  = NodeType::Simple;
	n_rhythm_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::rhythm_next_id);
	n_rhythm_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_rhythm_next_id);

	field_name = "save_on_exit";
	auto n_save_on_exit          = new NodeSimple<bool>;
	n_save_on_exit->m_field_name = field_name;
	n_save_on_exit->m_df_type    = DF_Type::Bool;
	n_save_on_exit->m_rdf_type   = RDF_Type::Bool;
	n_save_on_exit->m_node_type  = NodeType::Simple;
	n_save_on_exit->m_address    = reinterpret_cast<uint64_t>(df::global::save_on_exit);
	n_save_on_exit->m_comment    = "Ending the game saves its state back to world.dat or world.sav";
	n_save_on_exit->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_save_on_exit);

	field_name = "scale_next_id";
	auto n_scale_next_id          = new NodeSimple<int32_t>;
	n_scale_next_id->m_field_name = field_name;
	n_scale_next_id->m_df_type    = DF_Type::int32_t;
	n_scale_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_scale_next_id->m_node_type  = NodeType::Simple;
	n_scale_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::scale_next_id);
	n_scale_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_scale_next_id);

	field_name = "schedule_next_id";
	auto n_schedule_next_id          = new NodeSimple<int32_t>;
	n_schedule_next_id->m_field_name = field_name;
	n_schedule_next_id->m_df_type    = DF_Type::int32_t;
	n_schedule_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_schedule_next_id->m_node_type  = NodeType::Simple;
	n_schedule_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::schedule_next_id);
	n_schedule_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_schedule_next_id);

	field_name = "selection_rect";
	auto n_selection_rect = new NodeCompound;
	n_selection_rect->m_field_name = field_name;
	n_selection_rect->m_df_type    = DF_Type::T_selection_rect;
	n_selection_rect->m_rdf_type   = RDF_Type::Compound;
	n_selection_rect->m_node_type  = NodeType::Compound;
	n_selection_rect->m_address      = reinterpret_cast<uint64_t>(df::global::selection_rect);
	n_selection_rect->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_selection_rect);

	field_name = "soul_next_id";
	auto n_soul_next_id          = new NodeSimple<int32_t>;
	n_soul_next_id->m_field_name = field_name;
	n_soul_next_id->m_df_type    = DF_Type::int32_t;
	n_soul_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_soul_next_id->m_node_type  = NodeType::Simple;
	n_soul_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::soul_next_id);
	n_soul_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_soul_next_id);

	field_name = "squad_next_id";
	auto n_squad_next_id          = new NodeSimple<int32_t>;
	n_squad_next_id->m_field_name = field_name;
	n_squad_next_id->m_df_type    = DF_Type::int32_t;
	n_squad_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_squad_next_id->m_node_type  = NodeType::Simple;
	n_squad_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::squad_next_id);
	n_squad_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_squad_next_id);

	field_name = "standing_orders_auto_butcher";
	auto n_standing_orders_auto_butcher          = new NodeSimple<uint8_t>;
	n_standing_orders_auto_butcher->m_field_name = field_name;
	n_standing_orders_auto_butcher->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_auto_butcher->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_auto_butcher->m_node_type  = NodeType::Simple;
	n_standing_orders_auto_butcher->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_auto_butcher);
	n_standing_orders_auto_butcher->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_auto_butcher);

	field_name = "standing_orders_auto_collect_webs";
	auto n_standing_orders_auto_collect_webs          = new NodeSimple<uint8_t>;
	n_standing_orders_auto_collect_webs->m_field_name = field_name;
	n_standing_orders_auto_collect_webs->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_auto_collect_webs->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_auto_collect_webs->m_node_type  = NodeType::Simple;
	n_standing_orders_auto_collect_webs->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_auto_collect_webs);
	n_standing_orders_auto_collect_webs->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_auto_collect_webs);

	field_name = "standing_orders_auto_fishery";
	auto n_standing_orders_auto_fishery          = new NodeSimple<uint8_t>;
	n_standing_orders_auto_fishery->m_field_name = field_name;
	n_standing_orders_auto_fishery->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_auto_fishery->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_auto_fishery->m_node_type  = NodeType::Simple;
	n_standing_orders_auto_fishery->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_auto_fishery);
	n_standing_orders_auto_fishery->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_auto_fishery);

	field_name = "standing_orders_auto_kiln";
	auto n_standing_orders_auto_kiln          = new NodeSimple<uint8_t>;
	n_standing_orders_auto_kiln->m_field_name = field_name;
	n_standing_orders_auto_kiln->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_auto_kiln->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_auto_kiln->m_node_type  = NodeType::Simple;
	n_standing_orders_auto_kiln->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_auto_kiln);
	n_standing_orders_auto_kiln->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_auto_kiln);

	field_name = "standing_orders_auto_kitchen";
	auto n_standing_orders_auto_kitchen          = new NodeSimple<uint8_t>;
	n_standing_orders_auto_kitchen->m_field_name = field_name;
	n_standing_orders_auto_kitchen->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_auto_kitchen->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_auto_kitchen->m_node_type  = NodeType::Simple;
	n_standing_orders_auto_kitchen->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_auto_kitchen);
	n_standing_orders_auto_kitchen->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_auto_kitchen);

	field_name = "standing_orders_auto_loom";
	auto n_standing_orders_auto_loom          = new NodeSimple<uint8_t>;
	n_standing_orders_auto_loom->m_field_name = field_name;
	n_standing_orders_auto_loom->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_auto_loom->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_auto_loom->m_node_type  = NodeType::Simple;
	n_standing_orders_auto_loom->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_auto_loom);
	n_standing_orders_auto_loom->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_auto_loom);

	field_name = "standing_orders_auto_other";
	auto n_standing_orders_auto_other          = new NodeSimple<uint8_t>;
	n_standing_orders_auto_other->m_field_name = field_name;
	n_standing_orders_auto_other->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_auto_other->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_auto_other->m_node_type  = NodeType::Simple;
	n_standing_orders_auto_other->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_auto_other);
	n_standing_orders_auto_other->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_auto_other);

	field_name = "standing_orders_auto_slaughter";
	auto n_standing_orders_auto_slaughter          = new NodeSimple<uint8_t>;
	n_standing_orders_auto_slaughter->m_field_name = field_name;
	n_standing_orders_auto_slaughter->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_auto_slaughter->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_auto_slaughter->m_node_type  = NodeType::Simple;
	n_standing_orders_auto_slaughter->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_auto_slaughter);
	n_standing_orders_auto_slaughter->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_auto_slaughter);

	field_name = "standing_orders_auto_smelter";
	auto n_standing_orders_auto_smelter          = new NodeSimple<uint8_t>;
	n_standing_orders_auto_smelter->m_field_name = field_name;
	n_standing_orders_auto_smelter->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_auto_smelter->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_auto_smelter->m_node_type  = NodeType::Simple;
	n_standing_orders_auto_smelter->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_auto_smelter);
	n_standing_orders_auto_smelter->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_auto_smelter);

	field_name = "standing_orders_auto_tan";
	auto n_standing_orders_auto_tan          = new NodeSimple<uint8_t>;
	n_standing_orders_auto_tan->m_field_name = field_name;
	n_standing_orders_auto_tan->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_auto_tan->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_auto_tan->m_node_type  = NodeType::Simple;
	n_standing_orders_auto_tan->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_auto_tan);
	n_standing_orders_auto_tan->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_auto_tan);

	field_name = "standing_orders_dump_bones";
	auto n_standing_orders_dump_bones          = new NodeSimple<uint8_t>;
	n_standing_orders_dump_bones->m_field_name = field_name;
	n_standing_orders_dump_bones->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_dump_bones->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_dump_bones->m_node_type  = NodeType::Simple;
	n_standing_orders_dump_bones->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_dump_bones);
	n_standing_orders_dump_bones->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_dump_bones);

	field_name = "standing_orders_dump_corpses";
	auto n_standing_orders_dump_corpses          = new NodeSimple<uint8_t>;
	n_standing_orders_dump_corpses->m_field_name = field_name;
	n_standing_orders_dump_corpses->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_dump_corpses->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_dump_corpses->m_node_type  = NodeType::Simple;
	n_standing_orders_dump_corpses->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_dump_corpses);
	n_standing_orders_dump_corpses->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_dump_corpses);

	field_name = "standing_orders_dump_hair";
	auto n_standing_orders_dump_hair          = new NodeSimple<uint8_t>;
	n_standing_orders_dump_hair->m_field_name = field_name;
	n_standing_orders_dump_hair->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_dump_hair->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_dump_hair->m_node_type  = NodeType::Simple;
	n_standing_orders_dump_hair->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_dump_hair);
	n_standing_orders_dump_hair->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_dump_hair);

	field_name = "standing_orders_dump_other";
	auto n_standing_orders_dump_other          = new NodeSimple<uint8_t>;
	n_standing_orders_dump_other->m_field_name = field_name;
	n_standing_orders_dump_other->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_dump_other->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_dump_other->m_node_type  = NodeType::Simple;
	n_standing_orders_dump_other->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_dump_other);
	n_standing_orders_dump_other->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_dump_other);

	field_name = "standing_orders_dump_shells";
	auto n_standing_orders_dump_shells          = new NodeSimple<uint8_t>;
	n_standing_orders_dump_shells->m_field_name = field_name;
	n_standing_orders_dump_shells->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_dump_shells->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_dump_shells->m_node_type  = NodeType::Simple;
	n_standing_orders_dump_shells->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_dump_shells);
	n_standing_orders_dump_shells->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_dump_shells);

	field_name = "standing_orders_dump_skins";
	auto n_standing_orders_dump_skins          = new NodeSimple<uint8_t>;
	n_standing_orders_dump_skins->m_field_name = field_name;
	n_standing_orders_dump_skins->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_dump_skins->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_dump_skins->m_node_type  = NodeType::Simple;
	n_standing_orders_dump_skins->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_dump_skins);
	n_standing_orders_dump_skins->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_dump_skins);

	field_name = "standing_orders_dump_skulls";
	auto n_standing_orders_dump_skulls          = new NodeSimple<uint8_t>;
	n_standing_orders_dump_skulls->m_field_name = field_name;
	n_standing_orders_dump_skulls->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_dump_skulls->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_dump_skulls->m_node_type  = NodeType::Simple;
	n_standing_orders_dump_skulls->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_dump_skulls);
	n_standing_orders_dump_skulls->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_dump_skulls);

	field_name = "standing_orders_farmer_harvest";
	auto n_standing_orders_farmer_harvest          = new NodeSimple<uint8_t>;
	n_standing_orders_farmer_harvest->m_field_name = field_name;
	n_standing_orders_farmer_harvest->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_farmer_harvest->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_farmer_harvest->m_node_type  = NodeType::Simple;
	n_standing_orders_farmer_harvest->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_farmer_harvest);
	n_standing_orders_farmer_harvest->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_farmer_harvest);

	field_name = "standing_orders_forbid_other_dead_items";
	auto n_standing_orders_forbid_other_dead_items          = new NodeSimple<uint8_t>;
	n_standing_orders_forbid_other_dead_items->m_field_name = field_name;
	n_standing_orders_forbid_other_dead_items->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_forbid_other_dead_items->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_forbid_other_dead_items->m_node_type  = NodeType::Simple;
	n_standing_orders_forbid_other_dead_items->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_forbid_other_dead_items);
	n_standing_orders_forbid_other_dead_items->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_forbid_other_dead_items);

	field_name = "standing_orders_forbid_other_nohunt";
	auto n_standing_orders_forbid_other_nohunt          = new NodeSimple<uint8_t>;
	n_standing_orders_forbid_other_nohunt->m_field_name = field_name;
	n_standing_orders_forbid_other_nohunt->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_forbid_other_nohunt->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_forbid_other_nohunt->m_node_type  = NodeType::Simple;
	n_standing_orders_forbid_other_nohunt->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_forbid_other_nohunt);
	n_standing_orders_forbid_other_nohunt->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_forbid_other_nohunt);

	field_name = "standing_orders_forbid_own_dead";
	auto n_standing_orders_forbid_own_dead          = new NodeSimple<uint8_t>;
	n_standing_orders_forbid_own_dead->m_field_name = field_name;
	n_standing_orders_forbid_own_dead->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_forbid_own_dead->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_forbid_own_dead->m_node_type  = NodeType::Simple;
	n_standing_orders_forbid_own_dead->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_forbid_own_dead);
	n_standing_orders_forbid_own_dead->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_forbid_own_dead);

	field_name = "standing_orders_forbid_own_dead_items";
	auto n_standing_orders_forbid_own_dead_items          = new NodeSimple<uint8_t>;
	n_standing_orders_forbid_own_dead_items->m_field_name = field_name;
	n_standing_orders_forbid_own_dead_items->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_forbid_own_dead_items->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_forbid_own_dead_items->m_node_type  = NodeType::Simple;
	n_standing_orders_forbid_own_dead_items->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_forbid_own_dead_items);
	n_standing_orders_forbid_own_dead_items->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_forbid_own_dead_items);

	field_name = "standing_orders_forbid_used_ammo";
	auto n_standing_orders_forbid_used_ammo          = new NodeSimple<uint8_t>;
	n_standing_orders_forbid_used_ammo->m_field_name = field_name;
	n_standing_orders_forbid_used_ammo->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_forbid_used_ammo->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_forbid_used_ammo->m_node_type  = NodeType::Simple;
	n_standing_orders_forbid_used_ammo->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_forbid_used_ammo);
	n_standing_orders_forbid_used_ammo->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_forbid_used_ammo);

	field_name = "standing_orders_gather_animals";
	auto n_standing_orders_gather_animals          = new NodeSimple<uint8_t>;
	n_standing_orders_gather_animals->m_field_name = field_name;
	n_standing_orders_gather_animals->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_gather_animals->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_gather_animals->m_node_type  = NodeType::Simple;
	n_standing_orders_gather_animals->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_gather_animals);
	n_standing_orders_gather_animals->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_gather_animals);

	field_name = "standing_orders_gather_bodies";
	auto n_standing_orders_gather_bodies          = new NodeSimple<uint8_t>;
	n_standing_orders_gather_bodies->m_field_name = field_name;
	n_standing_orders_gather_bodies->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_gather_bodies->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_gather_bodies->m_node_type  = NodeType::Simple;
	n_standing_orders_gather_bodies->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_gather_bodies);
	n_standing_orders_gather_bodies->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_gather_bodies);

	field_name = "standing_orders_gather_food";
	auto n_standing_orders_gather_food          = new NodeSimple<uint8_t>;
	n_standing_orders_gather_food->m_field_name = field_name;
	n_standing_orders_gather_food->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_gather_food->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_gather_food->m_node_type  = NodeType::Simple;
	n_standing_orders_gather_food->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_gather_food);
	n_standing_orders_gather_food->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_gather_food);

	field_name = "standing_orders_gather_furniture";
	auto n_standing_orders_gather_furniture          = new NodeSimple<uint8_t>;
	n_standing_orders_gather_furniture->m_field_name = field_name;
	n_standing_orders_gather_furniture->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_gather_furniture->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_gather_furniture->m_node_type  = NodeType::Simple;
	n_standing_orders_gather_furniture->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_gather_furniture);
	n_standing_orders_gather_furniture->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_gather_furniture);

	field_name = "standing_orders_gather_minerals";
	auto n_standing_orders_gather_minerals          = new NodeSimple<uint8_t>;
	n_standing_orders_gather_minerals->m_field_name = field_name;
	n_standing_orders_gather_minerals->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_gather_minerals->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_gather_minerals->m_node_type  = NodeType::Simple;
	n_standing_orders_gather_minerals->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_gather_minerals);
	n_standing_orders_gather_minerals->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_gather_minerals);

	field_name = "standing_orders_gather_refuse";
	auto n_standing_orders_gather_refuse          = new NodeSimple<uint8_t>;
	n_standing_orders_gather_refuse->m_field_name = field_name;
	n_standing_orders_gather_refuse->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_gather_refuse->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_gather_refuse->m_node_type  = NodeType::Simple;
	n_standing_orders_gather_refuse->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_gather_refuse);
	n_standing_orders_gather_refuse->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_gather_refuse);

	field_name = "standing_orders_gather_refuse_outside";
	auto n_standing_orders_gather_refuse_outside          = new NodeSimple<uint8_t>;
	n_standing_orders_gather_refuse_outside->m_field_name = field_name;
	n_standing_orders_gather_refuse_outside->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_gather_refuse_outside->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_gather_refuse_outside->m_node_type  = NodeType::Simple;
	n_standing_orders_gather_refuse_outside->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_gather_refuse_outside);
	n_standing_orders_gather_refuse_outside->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_gather_refuse_outside);

	field_name = "standing_orders_gather_vermin_remains";
	auto n_standing_orders_gather_vermin_remains          = new NodeSimple<uint8_t>;
	n_standing_orders_gather_vermin_remains->m_field_name = field_name;
	n_standing_orders_gather_vermin_remains->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_gather_vermin_remains->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_gather_vermin_remains->m_node_type  = NodeType::Simple;
	n_standing_orders_gather_vermin_remains->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_gather_vermin_remains);
	n_standing_orders_gather_vermin_remains->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_gather_vermin_remains);

	field_name = "standing_orders_gather_wood";
	auto n_standing_orders_gather_wood          = new NodeSimple<uint8_t>;
	n_standing_orders_gather_wood->m_field_name = field_name;
	n_standing_orders_gather_wood->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_gather_wood->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_gather_wood->m_node_type  = NodeType::Simple;
	n_standing_orders_gather_wood->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_gather_wood);
	n_standing_orders_gather_wood->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_gather_wood);

	field_name = "standing_orders_job_cancel_announce";
	auto n_standing_orders_job_cancel_announce          = new NodeSimple<uint8_t>;
	n_standing_orders_job_cancel_announce->m_field_name = field_name;
	n_standing_orders_job_cancel_announce->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_job_cancel_announce->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_job_cancel_announce->m_node_type  = NodeType::Simple;
	n_standing_orders_job_cancel_announce->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_job_cancel_announce);
	n_standing_orders_job_cancel_announce->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_job_cancel_announce);

	field_name = "standing_orders_mix_food";
	auto n_standing_orders_mix_food          = new NodeSimple<uint8_t>;
	n_standing_orders_mix_food->m_field_name = field_name;
	n_standing_orders_mix_food->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_mix_food->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_mix_food->m_node_type  = NodeType::Simple;
	n_standing_orders_mix_food->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_mix_food);
	n_standing_orders_mix_food->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_mix_food);

	field_name = "standing_orders_use_dyed_cloth";
	auto n_standing_orders_use_dyed_cloth          = new NodeSimple<uint8_t>;
	n_standing_orders_use_dyed_cloth->m_field_name = field_name;
	n_standing_orders_use_dyed_cloth->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_use_dyed_cloth->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_use_dyed_cloth->m_node_type  = NodeType::Simple;
	n_standing_orders_use_dyed_cloth->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_use_dyed_cloth);
	n_standing_orders_use_dyed_cloth->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_use_dyed_cloth);

	field_name = "standing_orders_zoneonly_drink";
	auto n_standing_orders_zoneonly_drink          = new NodeSimple<uint8_t>;
	n_standing_orders_zoneonly_drink->m_field_name = field_name;
	n_standing_orders_zoneonly_drink->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_zoneonly_drink->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_zoneonly_drink->m_node_type  = NodeType::Simple;
	n_standing_orders_zoneonly_drink->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_zoneonly_drink);
	n_standing_orders_zoneonly_drink->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_zoneonly_drink);

	field_name = "standing_orders_zoneonly_fish";
	auto n_standing_orders_zoneonly_fish          = new NodeSimple<uint8_t>;
	n_standing_orders_zoneonly_fish->m_field_name = field_name;
	n_standing_orders_zoneonly_fish->m_df_type    = DF_Type::uint8_t;
	n_standing_orders_zoneonly_fish->m_rdf_type   = RDF_Type::uint8_t;
	n_standing_orders_zoneonly_fish->m_node_type  = NodeType::Simple;
	n_standing_orders_zoneonly_fish->m_address    = reinterpret_cast<uint64_t>(df::global::standing_orders_zoneonly_fish);
	n_standing_orders_zoneonly_fish->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_standing_orders_zoneonly_fish);

	field_name = "task_next_id";
	auto n_task_next_id          = new NodeSimple<int32_t>;
	n_task_next_id->m_field_name = field_name;
	n_task_next_id->m_df_type    = DF_Type::int32_t;
	n_task_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_task_next_id->m_node_type  = NodeType::Simple;
	n_task_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::task_next_id);
	n_task_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_task_next_id);

	field_name = "texture";
	auto n_texture = new NodeCompound;
	n_texture->m_field_name = field_name;
	n_texture->m_df_type    = DF_Type::texture_handler;
	n_texture->m_rdf_type   = RDF_Type::Compound;
	n_texture->m_node_type  = NodeType::Compound;
	n_texture->m_address      = reinterpret_cast<uint64_t>(df::global::texture);
	n_texture->m_defined_in = "df.init.xml";
	n_texture->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_texture);

	field_name = "timed_events";
	auto n_timed_events            = new NodeVector;
	n_timed_events->m_field_name   = field_name;
	n_timed_events->m_df_type      = DF_Type::timed_event;
	n_timed_events->m_rdf_type     = RDF_Type::Vector;
	n_timed_events->m_node_type    = NodeType::Vector;
	n_timed_events->m_defined_in   = "df.ui.xml";
	n_timed_events->m_addornements = "v*";
	n_timed_events->m_address      = reinterpret_cast<uint64_t>(df::global::timed_events);
	n_timed_events->m_parent       = p_node_parent;
	n_timed_events->m_children.push_back(rdf::dummy());
	p_node_parent->m_children.push_back(n_timed_events);

	field_name = "ui";
	auto n_ui = new NodeCompound;
	n_ui->m_field_name = field_name;
	n_ui->m_df_type    = DF_Type::ui;
	n_ui->m_rdf_type   = RDF_Type::Compound;
	n_ui->m_node_type  = NodeType::Compound;
	n_ui->m_address      = reinterpret_cast<uint64_t>(df::global::ui);
	n_ui->m_defined_in = "df.ui.xml";
	n_ui->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui);

	field_name = "ui_advmode";
	auto n_ui_advmode = new NodeCompound;
	n_ui_advmode->m_field_name = field_name;
	n_ui_advmode->m_df_type    = DF_Type::ui_advmode;
	n_ui_advmode->m_rdf_type   = RDF_Type::Compound;
	n_ui_advmode->m_node_type  = NodeType::Compound;
	n_ui_advmode->m_address      = reinterpret_cast<uint64_t>(df::global::ui_advmode);
	n_ui_advmode->m_defined_in = "df.globals.xml";
	n_ui_advmode->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_advmode);

	field_name = "ui_build_selector";
	auto n_ui_build_selector = new NodeCompound;
	n_ui_build_selector->m_field_name = field_name;
	n_ui_build_selector->m_df_type    = DF_Type::ui_build_selector;
	n_ui_build_selector->m_rdf_type   = RDF_Type::Compound;
	n_ui_build_selector->m_node_type  = NodeType::Compound;
	n_ui_build_selector->m_address      = reinterpret_cast<uint64_t>(df::global::ui_build_selector);
	n_ui_build_selector->m_defined_in = "df.ui-menus.xml";
	n_ui_build_selector->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_build_selector);

	field_name = "ui_building_assign_is_marked";
	auto n_ui_building_assign_is_marked            = new NodeVector;
	n_ui_building_assign_is_marked->m_field_name   = field_name;
	n_ui_building_assign_is_marked->m_df_type      = DF_Type::Bool;
	n_ui_building_assign_is_marked->m_rdf_type     = RDF_Type::Vector;
	n_ui_building_assign_is_marked->m_node_type    = NodeType::Vector;
	n_ui_building_assign_is_marked->m_addornements = "v";
	n_ui_building_assign_is_marked->m_address      = reinterpret_cast<uint64_t>(df::global::ui_building_assign_is_marked);
	n_ui_building_assign_is_marked->m_parent       = p_node_parent;
	n_ui_building_assign_is_marked->m_children.push_back(rdf::dummy());
	p_node_parent->m_children.push_back(n_ui_building_assign_is_marked);

	field_name = "ui_building_assign_items";
	auto n_ui_building_assign_items            = new NodeVector;
	n_ui_building_assign_items->m_field_name   = field_name;
	n_ui_building_assign_items->m_df_type      = DF_Type::item;
	n_ui_building_assign_items->m_rdf_type     = RDF_Type::Vector;
	n_ui_building_assign_items->m_node_type    = NodeType::Vector;
	n_ui_building_assign_items->m_defined_in   = "df.items.xml";
	n_ui_building_assign_items->m_addornements = "v*";
	n_ui_building_assign_items->m_address      = reinterpret_cast<uint64_t>(df::global::ui_building_assign_items);
	n_ui_building_assign_items->m_parent       = p_node_parent;
	n_ui_building_assign_items->m_children.push_back(rdf::dummy());
	p_node_parent->m_children.push_back(n_ui_building_assign_items);

	field_name = "ui_building_assign_type";
	auto n_ui_building_assign_type            = new NodeVector;
	n_ui_building_assign_type->m_field_name   = field_name;
	n_ui_building_assign_type->m_df_type      = DF_Type::int8_t;
	n_ui_building_assign_type->m_rdf_type     = RDF_Type::Vector;
	n_ui_building_assign_type->m_node_type    = NodeType::Vector;
	n_ui_building_assign_type->m_addornements = "v";
	n_ui_building_assign_type->m_address      = reinterpret_cast<uint64_t>(df::global::ui_building_assign_type);
	n_ui_building_assign_type->m_parent       = p_node_parent;
	n_ui_building_assign_type->m_children.push_back(rdf::dummy());
	p_node_parent->m_children.push_back(n_ui_building_assign_type);

	field_name = "ui_building_assign_units";
	auto n_ui_building_assign_units            = new NodeVector;
	n_ui_building_assign_units->m_field_name   = field_name;
	n_ui_building_assign_units->m_df_type      = DF_Type::unit;
	n_ui_building_assign_units->m_rdf_type     = RDF_Type::Vector;
	n_ui_building_assign_units->m_node_type    = NodeType::Vector;
	n_ui_building_assign_units->m_defined_in   = "df.units.xml";
	n_ui_building_assign_units->m_addornements = "v*";
	n_ui_building_assign_units->m_address      = reinterpret_cast<uint64_t>(df::global::ui_building_assign_units);
	n_ui_building_assign_units->m_parent       = p_node_parent;
	n_ui_building_assign_units->m_children.push_back(rdf::dummy());
	p_node_parent->m_children.push_back(n_ui_building_assign_units);

	field_name = "ui_building_in_assign";
	auto n_ui_building_in_assign          = new NodeSimple<bool>;
	n_ui_building_in_assign->m_field_name = field_name;
	n_ui_building_in_assign->m_df_type    = DF_Type::Bool;
	n_ui_building_in_assign->m_rdf_type   = RDF_Type::Bool;
	n_ui_building_in_assign->m_node_type  = NodeType::Simple;
	n_ui_building_in_assign->m_address    = reinterpret_cast<uint64_t>(df::global::ui_building_in_assign);
	n_ui_building_in_assign->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_building_in_assign);

	field_name = "ui_building_in_resize";
	auto n_ui_building_in_resize          = new NodeSimple<bool>;
	n_ui_building_in_resize->m_field_name = field_name;
	n_ui_building_in_resize->m_df_type    = DF_Type::Bool;
	n_ui_building_in_resize->m_rdf_type   = RDF_Type::Bool;
	n_ui_building_in_resize->m_node_type  = NodeType::Simple;
	n_ui_building_in_resize->m_address    = reinterpret_cast<uint64_t>(df::global::ui_building_in_resize);
	n_ui_building_in_resize->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_building_in_resize);

	field_name = "ui_building_item_cursor";
	auto n_ui_building_item_cursor          = new NodeSimple<int32_t>;
	n_ui_building_item_cursor->m_field_name = field_name;
	n_ui_building_item_cursor->m_df_type    = DF_Type::int32_t;
	n_ui_building_item_cursor->m_rdf_type   = RDF_Type::int32_t;
	n_ui_building_item_cursor->m_node_type  = NodeType::Simple;
	n_ui_building_item_cursor->m_address    = reinterpret_cast<uint64_t>(df::global::ui_building_item_cursor);
	n_ui_building_item_cursor->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_building_item_cursor);

	field_name = "ui_building_resize_radius";
	auto n_ui_building_resize_radius          = new NodeSimple<int16_t>;
	n_ui_building_resize_radius->m_field_name = field_name;
	n_ui_building_resize_radius->m_df_type    = DF_Type::int16_t;
	n_ui_building_resize_radius->m_rdf_type   = RDF_Type::int16_t;
	n_ui_building_resize_radius->m_node_type  = NodeType::Simple;
	n_ui_building_resize_radius->m_address    = reinterpret_cast<uint64_t>(df::global::ui_building_resize_radius);
	n_ui_building_resize_radius->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_building_resize_radius);

	field_name = "ui_lever_target_type";
	auto n_ui_lever_target_type = new NodeEnum;
	n_ui_lever_target_type->m_field_name = field_name;
	n_ui_lever_target_type->m_df_type    = DF_Type::lever_target_type;
	n_ui_lever_target_type->m_rdf_type   = RDF_Type::Enum;
	n_ui_lever_target_type->m_node_type  = NodeType::Enum;
	n_ui_lever_target_type->m_base_type  = DF_Type::int8_t;
	n_ui_lever_target_type->m_enum_type  = "lever_target_type";
	n_ui_lever_target_type->m_address    = reinterpret_cast<uint64_t>(df::global::ui_lever_target_type);
	n_ui_lever_target_type->m_defined_in = "df.globals.xml";
	n_ui_lever_target_type->m_first_value = -1;
	n_ui_lever_target_type->m_last_value  = 119;
	n_ui_lever_target_type->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_lever_target_type);

	field_name = "ui_look_cursor";
	auto n_ui_look_cursor          = new NodeSimple<int32_t>;
	n_ui_look_cursor->m_field_name = field_name;
	n_ui_look_cursor->m_df_type    = DF_Type::int32_t;
	n_ui_look_cursor->m_rdf_type   = RDF_Type::int32_t;
	n_ui_look_cursor->m_node_type  = NodeType::Simple;
	n_ui_look_cursor->m_address    = reinterpret_cast<uint64_t>(df::global::ui_look_cursor);
	n_ui_look_cursor->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_look_cursor);

	field_name = "ui_look_list";
	auto n_ui_look_list = new NodeCompound;
	n_ui_look_list->m_field_name = field_name;
	n_ui_look_list->m_df_type    = DF_Type::ui_look_list;
	n_ui_look_list->m_rdf_type   = RDF_Type::Compound;
	n_ui_look_list->m_node_type  = NodeType::Compound;
	n_ui_look_list->m_address      = reinterpret_cast<uint64_t>(df::global::ui_look_list);
	n_ui_look_list->m_defined_in = "df.ui-menus.xml";
	n_ui_look_list->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_look_list);

	field_name = "ui_menu_width";
	auto n_ui_menu_width            = new NodeArray;
	n_ui_menu_width->m_address      = reinterpret_cast<uint64_t>(df::global::ui_menu_width);
	n_ui_menu_width->m_field_name   = field_name;
	n_ui_menu_width->m_df_type      = DF_Type::int8_t;
	n_ui_menu_width->m_rdf_type     = RDF_Type::Array;
	n_ui_menu_width->m_node_type    = NodeType::Array;
	n_ui_menu_width->m_addornements = "[2";
	n_ui_menu_width->m_array_size   = 2;
	n_ui_menu_width->m_address      = reinterpret_cast<uint64_t>(df::global::ui_menu_width);
	n_ui_menu_width->m_parent       = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_menu_width);

	field_name = "ui_selected_unit";
	auto n_ui_selected_unit          = new NodeSimple<int32_t>;
	n_ui_selected_unit->m_field_name = field_name;
	n_ui_selected_unit->m_df_type    = DF_Type::int32_t;
	n_ui_selected_unit->m_rdf_type   = RDF_Type::int32_t;
	n_ui_selected_unit->m_node_type  = NodeType::Simple;
	n_ui_selected_unit->m_address    = reinterpret_cast<uint64_t>(df::global::ui_selected_unit);
	n_ui_selected_unit->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_selected_unit);

	field_name = "ui_sidebar_menus";
	auto n_ui_sidebar_menus = new NodeCompound;
	n_ui_sidebar_menus->m_field_name = field_name;
	n_ui_sidebar_menus->m_df_type    = DF_Type::ui_sidebar_menus;
	n_ui_sidebar_menus->m_rdf_type   = RDF_Type::Compound;
	n_ui_sidebar_menus->m_node_type  = NodeType::Compound;
	n_ui_sidebar_menus->m_address      = reinterpret_cast<uint64_t>(df::global::ui_sidebar_menus);
	n_ui_sidebar_menus->m_defined_in = "df.ui-menus.xml";
	n_ui_sidebar_menus->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_sidebar_menus);

	field_name = "ui_unit_view_mode";
	auto n_ui_unit_view_mode = new NodeCompound;
	n_ui_unit_view_mode->m_field_name = field_name;
	n_ui_unit_view_mode->m_df_type    = DF_Type::ui_unit_view_mode;
	n_ui_unit_view_mode->m_rdf_type   = RDF_Type::Compound;
	n_ui_unit_view_mode->m_node_type  = NodeType::Compound;
	n_ui_unit_view_mode->m_address      = reinterpret_cast<uint64_t>(df::global::ui_unit_view_mode);
	n_ui_unit_view_mode->m_defined_in = "df.ui-menus.xml";
	n_ui_unit_view_mode->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_unit_view_mode);

	field_name = "ui_workshop_in_add";
	auto n_ui_workshop_in_add          = new NodeSimple<bool>;
	n_ui_workshop_in_add->m_field_name = field_name;
	n_ui_workshop_in_add->m_df_type    = DF_Type::Bool;
	n_ui_workshop_in_add->m_rdf_type   = RDF_Type::Bool;
	n_ui_workshop_in_add->m_node_type  = NodeType::Simple;
	n_ui_workshop_in_add->m_address    = reinterpret_cast<uint64_t>(df::global::ui_workshop_in_add);
	n_ui_workshop_in_add->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_workshop_in_add);

	field_name = "ui_workshop_job_cursor";
	auto n_ui_workshop_job_cursor          = new NodeSimple<int32_t>;
	n_ui_workshop_job_cursor->m_field_name = field_name;
	n_ui_workshop_job_cursor->m_df_type    = DF_Type::int32_t;
	n_ui_workshop_job_cursor->m_rdf_type   = RDF_Type::int32_t;
	n_ui_workshop_job_cursor->m_node_type  = NodeType::Simple;
	n_ui_workshop_job_cursor->m_address    = reinterpret_cast<uint64_t>(df::global::ui_workshop_job_cursor);
	n_ui_workshop_job_cursor->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_ui_workshop_job_cursor);

	field_name = "unit_chunk_next_id";
	auto n_unit_chunk_next_id          = new NodeSimple<int32_t>;
	n_unit_chunk_next_id->m_field_name = field_name;
	n_unit_chunk_next_id->m_df_type    = DF_Type::int32_t;
	n_unit_chunk_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_unit_chunk_next_id->m_node_type  = NodeType::Simple;
	n_unit_chunk_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::unit_chunk_next_id);
	n_unit_chunk_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_unit_chunk_next_id);

	field_name = "unit_next_id";
	auto n_unit_next_id          = new NodeSimple<int32_t>;
	n_unit_next_id->m_field_name = field_name;
	n_unit_next_id->m_df_type    = DF_Type::int32_t;
	n_unit_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_unit_next_id->m_node_type  = NodeType::Simple;
	n_unit_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::unit_next_id);
	n_unit_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_unit_next_id);

	field_name = "vehicle_next_id";
	auto n_vehicle_next_id          = new NodeSimple<int32_t>;
	n_vehicle_next_id->m_field_name = field_name;
	n_vehicle_next_id->m_df_type    = DF_Type::int32_t;
	n_vehicle_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_vehicle_next_id->m_node_type  = NodeType::Simple;
	n_vehicle_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::vehicle_next_id);
	n_vehicle_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_vehicle_next_id);

	field_name = "version";
	auto n_version          = new NodeSimple<int32_t>;
	n_version->m_field_name = field_name;
	n_version->m_df_type    = DF_Type::int32_t;
	n_version->m_rdf_type   = RDF_Type::int32_t;
	n_version->m_node_type  = NodeType::Simple;
	n_version->m_address    = reinterpret_cast<uint64_t>(df::global::version);
	n_version->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_version);

	field_name = "window_x";
	auto n_window_x          = new NodeSimple<int32_t>;
	n_window_x->m_field_name = field_name;
	n_window_x->m_df_type    = DF_Type::int32_t;
	n_window_x->m_rdf_type   = RDF_Type::int32_t;
	n_window_x->m_node_type  = NodeType::Simple;
	n_window_x->m_address    = reinterpret_cast<uint64_t>(df::global::window_x);
	n_window_x->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_window_x);

	field_name = "window_y";
	auto n_window_y          = new NodeSimple<int32_t>;
	n_window_y->m_field_name = field_name;
	n_window_y->m_df_type    = DF_Type::int32_t;
	n_window_y->m_rdf_type   = RDF_Type::int32_t;
	n_window_y->m_node_type  = NodeType::Simple;
	n_window_y->m_address    = reinterpret_cast<uint64_t>(df::global::window_y);
	n_window_y->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_window_y);

	field_name = "window_z";
	auto n_window_z          = new NodeSimple<int32_t>;
	n_window_z->m_field_name = field_name;
	n_window_z->m_df_type    = DF_Type::int32_t;
	n_window_z->m_rdf_type   = RDF_Type::int32_t;
	n_window_z->m_node_type  = NodeType::Simple;
	n_window_z->m_address    = reinterpret_cast<uint64_t>(df::global::window_z);
	n_window_z->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_window_z);

	field_name = "world";
	auto n_world = new NodeCompound;
	n_world->m_field_name = field_name;
	n_world->m_df_type    = DF_Type::world;
	n_world->m_rdf_type   = RDF_Type::Compound;
	n_world->m_node_type  = NodeType::Compound;
	n_world->m_address      = reinterpret_cast<uint64_t>(df::global::world);
	n_world->m_defined_in = "df.world.xml";
	n_world->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_world);

	field_name = "written_content_next_id";
	auto n_written_content_next_id          = new NodeSimple<int32_t>;
	n_written_content_next_id->m_field_name = field_name;
	n_written_content_next_id->m_df_type    = DF_Type::int32_t;
	n_written_content_next_id->m_rdf_type   = RDF_Type::int32_t;
	n_written_content_next_id->m_node_type  = NodeType::Simple;
	n_written_content_next_id->m_address    = reinterpret_cast<uint64_t>(df::global::written_content_next_id);
	n_written_content_next_id->m_parent     = p_node_parent;
	p_node_parent->m_children.push_back(n_written_content_next_id);

}

