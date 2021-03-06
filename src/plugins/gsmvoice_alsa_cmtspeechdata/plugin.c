/* plugin.c generated by valac 0.16.1, the Vala compiler
 * generated from plugin.vala, do not modify */

/*
 * Copyright (C) 2011-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <fsobasics.h>
#include <fsoframework.h>
#include <freesmartphone.h>
#include <gio/gio.h>


#define FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_TYPE_PLUGIN (fso_audio_gsm_voice_cmtspeechdata_plugin_get_type ())
#define FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_TYPE_PLUGIN, FsoAudioGsmVoiceCmtspeechdataPlugin))
#define FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_TYPE_PLUGIN, FsoAudioGsmVoiceCmtspeechdataPluginClass))
#define FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_TYPE_PLUGIN))
#define FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_TYPE_PLUGIN))
#define FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_TYPE_PLUGIN, FsoAudioGsmVoiceCmtspeechdataPluginClass))

typedef struct _FsoAudioGsmVoiceCmtspeechdataPlugin FsoAudioGsmVoiceCmtspeechdataPlugin;
typedef struct _FsoAudioGsmVoiceCmtspeechdataPluginClass FsoAudioGsmVoiceCmtspeechdataPluginClass;
typedef struct _FsoAudioGsmVoiceCmtspeechdataPluginPrivate FsoAudioGsmVoiceCmtspeechdataPluginPrivate;

#define TYPE_CMT_HANDLER (cmt_handler_get_type ())
#define CMT_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CMT_HANDLER, CmtHandler))
#define CMT_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CMT_HANDLER, CmtHandlerClass))
#define IS_CMT_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CMT_HANDLER))
#define IS_CMT_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CMT_HANDLER))
#define CMT_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CMT_HANDLER, CmtHandlerClass))

typedef struct _CmtHandler CmtHandler;
typedef struct _CmtHandlerClass CmtHandlerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _FsoAudioGsmVoiceCmtspeechdataPlugin {
	FsoFrameworkAbstractObject parent_instance;
	FsoAudioGsmVoiceCmtspeechdataPluginPrivate * priv;
};

struct _FsoAudioGsmVoiceCmtspeechdataPluginClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _FsoAudioGsmVoiceCmtspeechdataPluginPrivate {
	FsoFrameworkSubsystem* subsystem;
	CmtHandler* cmthandler;
	FreeSmartphoneGSMCall* gsmcallproxy;
};


static gpointer fso_audio_gsm_voice_cmtspeechdata_plugin_parent_class = NULL;
static GType fso_audio_gsm_voice_cmtspeechdata_plugin_type_id = 0;
extern FsoAudioGsmVoiceCmtspeechdataPlugin* instance;
FsoAudioGsmVoiceCmtspeechdataPlugin* instance = NULL;

#define FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_MODULE_NAME "fsoaudio.gsmvoice_alsa_cmtspeechdata"
GType fso_audio_gsm_voice_cmtspeechdata_plugin_get_type (void) G_GNUC_CONST;
GType fso_audio_gsm_voice_cmtspeechdata_plugin_register_type (GTypeModule * module);
GType cmt_handler_get_type (void) G_GNUC_CONST;
GType cmt_handler_register_type (GTypeModule * module);
#define FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_PLUGIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_TYPE_PLUGIN, FsoAudioGsmVoiceCmtspeechdataPluginPrivate))
enum  {
	FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_PLUGIN_DUMMY_PROPERTY
};
static void fso_audio_gsm_voice_cmtspeechdata_plugin_onCallStatusSignal (FsoAudioGsmVoiceCmtspeechdataPlugin* self, gint id, FreeSmartphoneGSMCallStatus status, GHashTable* properties);
const gchar* free_smartphone_gsm_call_status_to_string (FreeSmartphoneGSMCallStatus self);
void cmt_handler_setAudioStatus (CmtHandler* self, gboolean enabled);
FsoAudioGsmVoiceCmtspeechdataPlugin* fso_audio_gsm_voice_cmtspeechdata_plugin_new (FsoFrameworkSubsystem* subsystem);
FsoAudioGsmVoiceCmtspeechdataPlugin* fso_audio_gsm_voice_cmtspeechdata_plugin_construct (GType object_type, FsoFrameworkSubsystem* subsystem);
CmtHandler* cmt_handler_new (void);
CmtHandler* cmt_handler_construct (GType object_type);
static void _fso_audio_gsm_voice_cmtspeechdata_plugin_onCallStatusSignal_free_smartphone_gsm_call_call_status (FreeSmartphoneGSMCall* _sender, gint id, FreeSmartphoneGSMCallStatus status, GHashTable* properties, gpointer self);
static gchar* fso_audio_gsm_voice_cmtspeechdata_plugin_real_repr (FsoFrameworkAbstractObject* base);
static void fso_audio_gsm_voice_cmtspeechdata_plugin_finalize (GObject* obj);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


static void fso_audio_gsm_voice_cmtspeechdata_plugin_onCallStatusSignal (FsoAudioGsmVoiceCmtspeechdataPlugin* self, gint id, FreeSmartphoneGSMCallStatus status, GHashTable* properties) {
	FsoFrameworkLogger* _tmp0_;
	gint _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_;
	FreeSmartphoneGSMCallStatus _tmp4_;
	GEnumValue* _tmp5_;
	gchar* _tmp6_ = NULL;
	gchar* _tmp7_;
	gboolean _tmp8_ = FALSE;
	FreeSmartphoneGSMCallStatus _tmp9_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (properties != NULL);
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp1_ = id;
	_tmp2_ = g_strdup_printf ("%i", _tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = status;
	_tmp5_ = g_enum_get_value (g_type_class_ref (FREE_SMARTPHONE_GSM_TYPE_CALL_STATUS), _tmp4_);
	_tmp6_ = g_strconcat ("onCallStatusSignal ", _tmp3_, " w/ status ", (_tmp5_ != NULL) ? _tmp5_->value_name : NULL, NULL);
	_tmp7_ = _tmp6_;
	_tmp8_ = fso_framework_logger_debug (_tmp0_, _tmp7_);
	g_assert (_tmp8_);
	_g_free0 (_tmp7_);
	_g_free0 (_tmp3_);
	_tmp9_ = status;
	switch (_tmp9_) {
		case FREE_SMARTPHONE_GSM_CALL_STATUS_INCOMING:
		case FREE_SMARTPHONE_GSM_CALL_STATUS_OUTGOING:
		{
			CmtHandler* _tmp10_;
			_tmp10_ = self->priv->cmthandler;
			cmt_handler_setAudioStatus (_tmp10_, TRUE);
			break;
		}
		case FREE_SMARTPHONE_GSM_CALL_STATUS_RELEASE:
		{
			CmtHandler* _tmp11_;
			_tmp11_ = self->priv->cmthandler;
			cmt_handler_setAudioStatus (_tmp11_, FALSE);
			break;
		}
		default:
		{
			FsoFrameworkLogger* _tmp12_;
			FreeSmartphoneGSMCallStatus _tmp13_;
			GEnumValue* _tmp14_;
			gchar* _tmp15_ = NULL;
			gchar* _tmp16_;
			gboolean _tmp17_ = FALSE;
			_tmp12_ = ((FsoFrameworkAbstractObject*) self)->logger;
			_tmp13_ = status;
			_tmp14_ = g_enum_get_value (g_type_class_ref (FREE_SMARTPHONE_GSM_TYPE_CALL_STATUS), _tmp13_);
			_tmp15_ = g_strconcat ("Unhandled call status ", (_tmp14_ != NULL) ? _tmp14_->value_name : NULL, NULL);
			_tmp16_ = _tmp15_;
			_tmp17_ = fso_framework_logger_debug (_tmp12_, _tmp16_);
			g_assert (_tmp17_);
			_g_free0 (_tmp16_);
			break;
		}
	}
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _fso_audio_gsm_voice_cmtspeechdata_plugin_onCallStatusSignal_free_smartphone_gsm_call_call_status (FreeSmartphoneGSMCall* _sender, gint id, FreeSmartphoneGSMCallStatus status, GHashTable* properties, gpointer self) {
	fso_audio_gsm_voice_cmtspeechdata_plugin_onCallStatusSignal (self, id, status, properties);
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


FsoAudioGsmVoiceCmtspeechdataPlugin* fso_audio_gsm_voice_cmtspeechdata_plugin_construct (GType object_type, FsoFrameworkSubsystem* subsystem) {
	FsoAudioGsmVoiceCmtspeechdataPlugin * self = NULL;
	FsoFrameworkSubsystem* _tmp0_;
	FsoFrameworkSubsystem* _tmp1_;
	CmtHandler* _tmp2_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (subsystem != NULL, NULL);
	self = (FsoAudioGsmVoiceCmtspeechdataPlugin*) fso_framework_abstract_object_construct (object_type);
	_tmp0_ = subsystem;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->subsystem);
	self->priv->subsystem = _tmp1_;
	_tmp2_ = cmt_handler_new ();
	_g_object_unref0 (self->priv->cmthandler);
	self->priv->cmthandler = _tmp2_;
	{
		FreeSmartphoneGSMCall* _tmp3_ = NULL;
		FreeSmartphoneGSMCall* _tmp4_;
		FreeSmartphoneGSMCall* _tmp5_;
		_tmp3_ = g_initable_new (FREE_SMARTPHONE_GSM_TYPE_CALL_PROXY, NULL, &_inner_error_, "g-flags", G_DBUS_PROXY_FLAGS_DO_NOT_AUTO_START, "g-name", "org.freesmartphone.ogsmd", "g-bus-type", G_BUS_TYPE_SYSTEM, "g-object-path", "/org/freesmartphone/GSM/Device", "g-interface-name", "org.freesmartphone.GSM.Call", NULL);
		_tmp4_ = (FreeSmartphoneGSMCall*) _tmp3_;
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
		_g_object_unref0 (self->priv->gsmcallproxy);
		self->priv->gsmcallproxy = _tmp4_;
		_tmp5_ = self->priv->gsmcallproxy;
		g_signal_connect_object (_tmp5_, "call-status", (GCallback) _fso_audio_gsm_voice_cmtspeechdata_plugin_onCallStatusSignal_free_smartphone_gsm_call_call_status, self, 0);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		FsoFrameworkLogger* _tmp6_;
		GError* _tmp7_;
		const gchar* _tmp8_;
		const gchar* _tmp9_ = NULL;
		gchar* _tmp10_ = NULL;
		gchar* _tmp11_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp6_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp7_ = e;
		_tmp8_ = _tmp7_->message;
		_tmp9_ = string_to_string (_tmp8_);
		_tmp10_ = g_strconcat ("Could not hook to fsogsmd: ", _tmp9_, NULL);
		_tmp11_ = _tmp10_;
		fso_framework_logger_error (_tmp6_, _tmp11_);
		_g_free0 (_tmp11_);
		_g_error_free0 (e);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


FsoAudioGsmVoiceCmtspeechdataPlugin* fso_audio_gsm_voice_cmtspeechdata_plugin_new (FsoFrameworkSubsystem* subsystem) {
	return fso_audio_gsm_voice_cmtspeechdata_plugin_construct (FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_TYPE_PLUGIN, subsystem);
}


static gchar* fso_audio_gsm_voice_cmtspeechdata_plugin_real_repr (FsoFrameworkAbstractObject* base) {
	FsoAudioGsmVoiceCmtspeechdataPlugin * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (FsoAudioGsmVoiceCmtspeechdataPlugin*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static void fso_audio_gsm_voice_cmtspeechdata_plugin_class_init (FsoAudioGsmVoiceCmtspeechdataPluginClass * klass) {
	fso_audio_gsm_voice_cmtspeechdata_plugin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FsoAudioGsmVoiceCmtspeechdataPluginPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = fso_audio_gsm_voice_cmtspeechdata_plugin_real_repr;
	G_OBJECT_CLASS (klass)->finalize = fso_audio_gsm_voice_cmtspeechdata_plugin_finalize;
}


static void fso_audio_gsm_voice_cmtspeechdata_plugin_instance_init (FsoAudioGsmVoiceCmtspeechdataPlugin * self) {
	self->priv = FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_PLUGIN_GET_PRIVATE (self);
}


static void fso_audio_gsm_voice_cmtspeechdata_plugin_finalize (GObject* obj) {
	FsoAudioGsmVoiceCmtspeechdataPlugin * self;
	self = FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_PLUGIN (obj);
	_g_object_unref0 (self->priv->subsystem);
	_g_object_unref0 (self->priv->cmthandler);
	_g_object_unref0 (self->priv->gsmcallproxy);
	G_OBJECT_CLASS (fso_audio_gsm_voice_cmtspeechdata_plugin_parent_class)->finalize (obj);
}


GType fso_audio_gsm_voice_cmtspeechdata_plugin_get_type (void) {
	return fso_audio_gsm_voice_cmtspeechdata_plugin_type_id;
}


GType fso_audio_gsm_voice_cmtspeechdata_plugin_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (FsoAudioGsmVoiceCmtspeechdataPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_audio_gsm_voice_cmtspeechdata_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoAudioGsmVoiceCmtspeechdataPlugin), 0, (GInstanceInitFunc) fso_audio_gsm_voice_cmtspeechdata_plugin_instance_init, NULL };
	fso_audio_gsm_voice_cmtspeechdata_plugin_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "FsoAudioGsmVoiceCmtspeechdataPlugin", &g_define_type_info, 0);
	return fso_audio_gsm_voice_cmtspeechdata_plugin_type_id;
}


/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error) {
	gchar* result = NULL;
	FsoFrameworkSubsystem* _tmp0_;
	FsoAudioGsmVoiceCmtspeechdataPlugin* _tmp1_;
	gchar* _tmp2_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = subsystem;
	_tmp1_ = fso_audio_gsm_voice_cmtspeechdata_plugin_new (_tmp0_);
	_g_object_unref0 (instance);
	instance = _tmp1_;
	_tmp2_ = g_strdup (FSO_AUDIO_GSM_VOICE_CMTSPEECHDATA_MODULE_NAME);
	result = _tmp2_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	FsoFrameworkLogger* _tmp0_;
	g_return_if_fail (module != NULL);
	fso_audio_gsm_voice_cmtspeechdata_plugin_register_type (module);
	ring_buffer_register_type (module);
	cmt_handler_register_type (module);
	_tmp0_ = fso_framework_theLogger;
	fso_framework_logger_debug (_tmp0_, "fsoaudio.gsmvoice_alsa_cmtspeechdata fso_register_function");
}



