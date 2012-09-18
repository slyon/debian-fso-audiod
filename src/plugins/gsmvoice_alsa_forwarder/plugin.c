/* plugin.c generated by valac 0.16.0, the Vala compiler
 * generated from plugin.vala, do not modify */

/*
 * Copyright (C) 2011-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 * Copyright (C) 2012 Denis 'GNUtoo' Carikli <GNUtoo@no-log.org>

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
#include <fsobasics.h>
#include <stdlib.h>
#include <string.h>
#include <fsoframework.h>
#include <freesmartphone.h>
#include <gio/gio.h>


#define TYPE_ALSALOOP_FORWARDER (alsaloop_forwarder_get_type ())
#define ALSALOOP_FORWARDER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ALSALOOP_FORWARDER, AlsaloopForwarder))
#define ALSALOOP_FORWARDER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ALSALOOP_FORWARDER, AlsaloopForwarderClass))
#define IS_ALSALOOP_FORWARDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ALSALOOP_FORWARDER))
#define IS_ALSALOOP_FORWARDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ALSALOOP_FORWARDER))
#define ALSALOOP_FORWARDER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ALSALOOP_FORWARDER, AlsaloopForwarderClass))

typedef struct _AlsaloopForwarder AlsaloopForwarder;
typedef struct _AlsaloopForwarderClass AlsaloopForwarderClass;
typedef struct _AlsaloopForwarderPrivate AlsaloopForwarderPrivate;
#define _g_mutex_free0(var) ((var == NULL) ? NULL : (var = (g_mutex_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define FSO_AUDIO_GSM_VOICE_FORWARDER_TYPE_PLUGIN (fso_audio_gsm_voice_forwarder_plugin_get_type ())
#define FSO_AUDIO_GSM_VOICE_FORWARDER_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_GSM_VOICE_FORWARDER_TYPE_PLUGIN, FsoAudioGsmVoiceForwarderPlugin))
#define FSO_AUDIO_GSM_VOICE_FORWARDER_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_GSM_VOICE_FORWARDER_TYPE_PLUGIN, FsoAudioGsmVoiceForwarderPluginClass))
#define FSO_AUDIO_GSM_VOICE_FORWARDER_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_GSM_VOICE_FORWARDER_TYPE_PLUGIN))
#define FSO_AUDIO_GSM_VOICE_FORWARDER_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_GSM_VOICE_FORWARDER_TYPE_PLUGIN))
#define FSO_AUDIO_GSM_VOICE_FORWARDER_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_GSM_VOICE_FORWARDER_TYPE_PLUGIN, FsoAudioGsmVoiceForwarderPluginClass))

typedef struct _FsoAudioGsmVoiceForwarderPlugin FsoAudioGsmVoiceForwarderPlugin;
typedef struct _FsoAudioGsmVoiceForwarderPluginClass FsoAudioGsmVoiceForwarderPluginClass;
typedef struct _FsoAudioGsmVoiceForwarderPluginPrivate FsoAudioGsmVoiceForwarderPluginPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _AlsaloopForwarder {
	FsoFrameworkAbstractObject parent_instance;
	AlsaloopForwarderPrivate * priv;
};

struct _AlsaloopForwarderClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _AlsaloopForwarderPrivate {
	gchar* configFilePath;
	GThread* alsaloopThread;
	GMutex* mutex;
};

struct _FsoAudioGsmVoiceForwarderPlugin {
	FsoFrameworkAbstractObject parent_instance;
	FsoAudioGsmVoiceForwarderPluginPrivate * priv;
};

struct _FsoAudioGsmVoiceForwarderPluginClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _FsoAudioGsmVoiceForwarderPluginPrivate {
	FsoFrameworkSubsystem* subsystem;
	FreeSmartphoneGSMCall* gsmcallproxy;
	AlsaloopForwarder* forwarder;
};


static gpointer alsaloop_forwarder_parent_class = NULL;
static GType alsaloop_forwarder_type_id = 0;
static gpointer fso_audio_gsm_voice_forwarder_plugin_parent_class = NULL;
static GType fso_audio_gsm_voice_forwarder_plugin_type_id = 0;
extern FsoAudioGsmVoiceForwarderPlugin* instance;
FsoAudioGsmVoiceForwarderPlugin* instance = NULL;

gint forwarder_start (gchar* conf_path);
void forwarder_stop (void);
#define FSO_AUDIO_GSM_VOICE_FORWARDER_MODULE_NAME "fsoaudio.gsmvoice_alsa_forwarder"
GType alsaloop_forwarder_get_type (void) G_GNUC_CONST;
GType alsaloop_forwarder_register_type (GTypeModule * module);
#define ALSALOOP_FORWARDER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_ALSALOOP_FORWARDER, AlsaloopForwarderPrivate))
enum  {
	ALSALOOP_FORWARDER_DUMMY_PROPERTY
};
AlsaloopForwarder* alsaloop_forwarder_new (gchar* path);
AlsaloopForwarder* alsaloop_forwarder_construct (GType object_type, gchar* path);
static void* alsaloop_forwarder_startWrapper (AlsaloopForwarder* self);
void alsaloop_forwarder_start (AlsaloopForwarder* self);
static gpointer _alsaloop_forwarder_startWrapper_gthread_func (gpointer self);
void alsaloop_forwarder_stop (AlsaloopForwarder* self);
static gchar* alsaloop_forwarder_real_repr (FsoFrameworkAbstractObject* base);
static void alsaloop_forwarder_finalize (GObject* obj);
GType fso_audio_gsm_voice_forwarder_plugin_get_type (void) G_GNUC_CONST;
GType fso_audio_gsm_voice_forwarder_plugin_register_type (GTypeModule * module);
#define FSO_AUDIO_GSM_VOICE_FORWARDER_PLUGIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FSO_AUDIO_GSM_VOICE_FORWARDER_TYPE_PLUGIN, FsoAudioGsmVoiceForwarderPluginPrivate))
enum  {
	FSO_AUDIO_GSM_VOICE_FORWARDER_PLUGIN_DUMMY_PROPERTY
};
static void fso_audio_gsm_voice_forwarder_plugin_onCallStatusSignal (FsoAudioGsmVoiceForwarderPlugin* self, gint id, FreeSmartphoneGSMCallStatus status, GHashTable* properties);
const gchar* free_smartphone_gsm_call_status_to_string (FreeSmartphoneGSMCallStatus self);
FsoAudioGsmVoiceForwarderPlugin* fso_audio_gsm_voice_forwarder_plugin_new (FsoFrameworkSubsystem* subsystem);
FsoAudioGsmVoiceForwarderPlugin* fso_audio_gsm_voice_forwarder_plugin_construct (GType object_type, FsoFrameworkSubsystem* subsystem);
static void _fso_audio_gsm_voice_forwarder_plugin_onCallStatusSignal_free_smartphone_gsm_call_call_status (FreeSmartphoneGSMCall* _sender, gint id, FreeSmartphoneGSMCallStatus status, GHashTable* properties, gpointer self);
static gchar* fso_audio_gsm_voice_forwarder_plugin_real_repr (FsoFrameworkAbstractObject* base);
static void fso_audio_gsm_voice_forwarder_plugin_finalize (GObject* obj);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


AlsaloopForwarder* alsaloop_forwarder_construct (GType object_type, gchar* path) {
	AlsaloopForwarder * self = NULL;
	gchar* _tmp0_;
	self = (AlsaloopForwarder*) fso_framework_abstract_object_construct (object_type);
	_tmp0_ = path;
	self->priv->configFilePath = _tmp0_;
	return self;
}


AlsaloopForwarder* alsaloop_forwarder_new (gchar* path) {
	return alsaloop_forwarder_construct (TYPE_ALSALOOP_FORWARDER, path);
}


static void* alsaloop_forwarder_startWrapper (AlsaloopForwarder* self) {
	void* result = NULL;
	gint ret;
	FsoFrameworkLogger* _tmp0_;
	gboolean _tmp1_ = FALSE;
	gchar* _tmp2_;
	gint _tmp3_ = 0;
	FsoFrameworkLogger* _tmp4_;
	gint _tmp5_;
	gchar* _tmp6_ = NULL;
	gchar* _tmp7_;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_;
	gboolean _tmp10_ = FALSE;
	g_return_val_if_fail (self != NULL, NULL);
	ret = 0;
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp1_ = fso_framework_logger_info (_tmp0_, "Alsaloop started");
	g_assert (_tmp1_);
	_tmp2_ = self->priv->configFilePath;
	_tmp3_ = forwarder_start (_tmp2_);
	ret = _tmp3_;
	self->priv->alsaloopThread = NULL;
	_tmp4_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp5_ = ret;
	_tmp6_ = g_strdup_printf ("%i", _tmp5_);
	_tmp7_ = _tmp6_;
	_tmp8_ = g_strconcat ("Alsaloop exited with status ", _tmp7_, NULL);
	_tmp9_ = _tmp8_;
	_tmp10_ = fso_framework_logger_info (_tmp4_, _tmp9_);
	g_assert (_tmp10_);
	_g_free0 (_tmp9_);
	_g_free0 (_tmp7_);
	result = NULL;
	return result;
}


static gpointer _alsaloop_forwarder_startWrapper_gthread_func (gpointer self) {
	gpointer result;
	result = alsaloop_forwarder_startWrapper (self);
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


void alsaloop_forwarder_start (AlsaloopForwarder* self) {
	GMutex* _tmp0_;
	GMutex* _tmp13_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->mutex;
	g_mutex_lock (_tmp0_);
	{
		GThread* _tmp1_;
		_tmp1_ = self->priv->alsaloopThread;
		if (_tmp1_ == NULL) {
			GThread* _tmp2_ = NULL;
			GThread* _tmp3_;
			_tmp2_ = g_thread_create (_alsaloop_forwarder_startWrapper_gthread_func, self, FALSE, &_inner_error_);
			_tmp3_ = _tmp2_;
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_THREAD_ERROR) {
					goto __catch0_g_thread_error;
				}
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
			self->priv->alsaloopThread = _tmp3_;
		} else {
			FsoFrameworkLogger* _tmp4_;
			gboolean _tmp5_ = FALSE;
			_tmp4_ = ((FsoFrameworkAbstractObject*) self)->logger;
			_tmp5_ = fso_framework_logger_error (_tmp4_, "FIXME: Are multiple calls at the same time supported by the modem driv" \
"er?");
			g_assert (_tmp5_);
		}
	}
	goto __finally0;
	__catch0_g_thread_error:
	{
		GError* e = NULL;
		FsoFrameworkLogger* _tmp6_;
		GError* _tmp7_;
		const gchar* _tmp8_;
		const gchar* _tmp9_ = NULL;
		gchar* _tmp10_ = NULL;
		gchar* _tmp11_;
		gboolean _tmp12_ = FALSE;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp6_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp7_ = e;
		_tmp8_ = _tmp7_->message;
		_tmp9_ = string_to_string (_tmp8_);
		_tmp10_ = g_strconcat ("Error: ", _tmp9_, NULL);
		_tmp11_ = _tmp10_;
		_tmp12_ = fso_framework_logger_error (_tmp6_, _tmp11_);
		g_assert (_tmp12_);
		_g_free0 (_tmp11_);
		_g_error_free0 (e);
		return;
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp13_ = self->priv->mutex;
	g_mutex_unlock (_tmp13_);
}


void alsaloop_forwarder_stop (AlsaloopForwarder* self) {
	g_return_if_fail (self != NULL);
	forwarder_stop ();
}


static gchar* alsaloop_forwarder_real_repr (FsoFrameworkAbstractObject* base) {
	AlsaloopForwarder * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (AlsaloopForwarder*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static void alsaloop_forwarder_class_init (AlsaloopForwarderClass * klass) {
	alsaloop_forwarder_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (AlsaloopForwarderPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = alsaloop_forwarder_real_repr;
	G_OBJECT_CLASS (klass)->finalize = alsaloop_forwarder_finalize;
}


static void alsaloop_forwarder_instance_init (AlsaloopForwarder * self) {
	GMutex* _tmp0_;
	self->priv = ALSALOOP_FORWARDER_GET_PRIVATE (self);
	self->priv->alsaloopThread = NULL;
	_tmp0_ = g_mutex_new ();
	self->priv->mutex = _tmp0_;
}


static void alsaloop_forwarder_finalize (GObject* obj) {
	AlsaloopForwarder * self;
	self = ALSALOOP_FORWARDER (obj);
	_g_mutex_free0 (self->priv->mutex);
	G_OBJECT_CLASS (alsaloop_forwarder_parent_class)->finalize (obj);
}


GType alsaloop_forwarder_get_type (void) {
	return alsaloop_forwarder_type_id;
}


GType alsaloop_forwarder_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (AlsaloopForwarderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) alsaloop_forwarder_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (AlsaloopForwarder), 0, (GInstanceInitFunc) alsaloop_forwarder_instance_init, NULL };
	alsaloop_forwarder_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "AlsaloopForwarder", &g_define_type_info, 0);
	return alsaloop_forwarder_type_id;
}


static void fso_audio_gsm_voice_forwarder_plugin_onCallStatusSignal (FsoAudioGsmVoiceForwarderPlugin* self, gint id, FreeSmartphoneGSMCallStatus status, GHashTable* properties) {
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
		case FREE_SMARTPHONE_GSM_CALL_STATUS_ACTIVE:
		{
			AlsaloopForwarder* _tmp10_;
			_tmp10_ = self->priv->forwarder;
			alsaloop_forwarder_start (_tmp10_);
			break;
		}
		case FREE_SMARTPHONE_GSM_CALL_STATUS_RELEASE:
		{
			AlsaloopForwarder* _tmp11_;
			_tmp11_ = self->priv->forwarder;
			alsaloop_forwarder_stop (_tmp11_);
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


static void _fso_audio_gsm_voice_forwarder_plugin_onCallStatusSignal_free_smartphone_gsm_call_call_status (FreeSmartphoneGSMCall* _sender, gint id, FreeSmartphoneGSMCallStatus status, GHashTable* properties, gpointer self) {
	fso_audio_gsm_voice_forwarder_plugin_onCallStatusSignal (self, id, status, properties);
}


FsoAudioGsmVoiceForwarderPlugin* fso_audio_gsm_voice_forwarder_plugin_construct (GType object_type, FsoFrameworkSubsystem* subsystem) {
	FsoAudioGsmVoiceForwarderPlugin * self = NULL;
	gchar* _tmp0_ = NULL;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* configurationPath;
	FsoFrameworkSubsystem* _tmp4_;
	FsoFrameworkSubsystem* _tmp5_;
	AlsaloopForwarder* _tmp6_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (subsystem != NULL, NULL);
	self = (FsoAudioGsmVoiceForwarderPlugin*) fso_framework_abstract_object_construct (object_type);
	_tmp0_ = fso_framework_utility_machineConfigurationDir ();
	_tmp1_ = _tmp0_;
	_tmp2_ = g_strconcat (_tmp1_, "/alsaloop.conf", NULL);
	_tmp3_ = _tmp2_;
	_g_free0 (_tmp1_);
	configurationPath = _tmp3_;
	_tmp4_ = subsystem;
	_tmp5_ = _g_object_ref0 (_tmp4_);
	_g_object_unref0 (self->priv->subsystem);
	self->priv->subsystem = _tmp5_;
	_tmp6_ = alsaloop_forwarder_new (configurationPath);
	_g_object_unref0 (self->priv->forwarder);
	self->priv->forwarder = _tmp6_;
	{
		FreeSmartphoneGSMCall* _tmp7_ = NULL;
		FreeSmartphoneGSMCall* _tmp8_;
		FreeSmartphoneGSMCall* _tmp9_;
		_tmp7_ = g_initable_new (FREE_SMARTPHONE_GSM_TYPE_CALL_PROXY, NULL, &_inner_error_, "g-flags", G_DBUS_PROXY_FLAGS_DO_NOT_AUTO_START, "g-name", "org.freesmartphone.ogsmd", "g-bus-type", G_BUS_TYPE_SYSTEM, "g-object-path", "/org/freesmartphone/GSM/Device", "g-interface-name", "org.freesmartphone.GSM.Call", NULL);
		_tmp8_ = (FreeSmartphoneGSMCall*) _tmp7_;
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
		}
		_g_object_unref0 (self->priv->gsmcallproxy);
		self->priv->gsmcallproxy = _tmp8_;
		_tmp9_ = self->priv->gsmcallproxy;
		g_signal_connect_object (_tmp9_, "call-status", (GCallback) _fso_audio_gsm_voice_forwarder_plugin_onCallStatusSignal_free_smartphone_gsm_call_call_status, self, 0);
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError* e = NULL;
		FsoFrameworkLogger* _tmp10_;
		GError* _tmp11_;
		const gchar* _tmp12_;
		const gchar* _tmp13_ = NULL;
		gchar* _tmp14_ = NULL;
		gchar* _tmp15_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp10_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp11_ = e;
		_tmp12_ = _tmp11_->message;
		_tmp13_ = string_to_string (_tmp12_);
		_tmp14_ = g_strconcat ("Could not hook to fsogsmd: ", _tmp13_, NULL);
		_tmp15_ = _tmp14_;
		fso_framework_logger_error (_tmp10_, _tmp15_);
		_g_free0 (_tmp15_);
		_g_error_free0 (e);
	}
	__finally1:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


FsoAudioGsmVoiceForwarderPlugin* fso_audio_gsm_voice_forwarder_plugin_new (FsoFrameworkSubsystem* subsystem) {
	return fso_audio_gsm_voice_forwarder_plugin_construct (FSO_AUDIO_GSM_VOICE_FORWARDER_TYPE_PLUGIN, subsystem);
}


static gchar* fso_audio_gsm_voice_forwarder_plugin_real_repr (FsoFrameworkAbstractObject* base) {
	FsoAudioGsmVoiceForwarderPlugin * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (FsoAudioGsmVoiceForwarderPlugin*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static void fso_audio_gsm_voice_forwarder_plugin_class_init (FsoAudioGsmVoiceForwarderPluginClass * klass) {
	fso_audio_gsm_voice_forwarder_plugin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FsoAudioGsmVoiceForwarderPluginPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = fso_audio_gsm_voice_forwarder_plugin_real_repr;
	G_OBJECT_CLASS (klass)->finalize = fso_audio_gsm_voice_forwarder_plugin_finalize;
}


static void fso_audio_gsm_voice_forwarder_plugin_instance_init (FsoAudioGsmVoiceForwarderPlugin * self) {
	self->priv = FSO_AUDIO_GSM_VOICE_FORWARDER_PLUGIN_GET_PRIVATE (self);
}


static void fso_audio_gsm_voice_forwarder_plugin_finalize (GObject* obj) {
	FsoAudioGsmVoiceForwarderPlugin * self;
	self = FSO_AUDIO_GSM_VOICE_FORWARDER_PLUGIN (obj);
	_g_object_unref0 (self->priv->subsystem);
	_g_object_unref0 (self->priv->gsmcallproxy);
	_g_object_unref0 (self->priv->forwarder);
	G_OBJECT_CLASS (fso_audio_gsm_voice_forwarder_plugin_parent_class)->finalize (obj);
}


GType fso_audio_gsm_voice_forwarder_plugin_get_type (void) {
	return fso_audio_gsm_voice_forwarder_plugin_type_id;
}


GType fso_audio_gsm_voice_forwarder_plugin_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (FsoAudioGsmVoiceForwarderPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_audio_gsm_voice_forwarder_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoAudioGsmVoiceForwarderPlugin), 0, (GInstanceInitFunc) fso_audio_gsm_voice_forwarder_plugin_instance_init, NULL };
	fso_audio_gsm_voice_forwarder_plugin_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "FsoAudioGsmVoiceForwarderPlugin", &g_define_type_info, 0);
	return fso_audio_gsm_voice_forwarder_plugin_type_id;
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
	FsoAudioGsmVoiceForwarderPlugin* _tmp1_;
	gchar* _tmp2_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = subsystem;
	_tmp1_ = fso_audio_gsm_voice_forwarder_plugin_new (_tmp0_);
	_g_object_unref0 (instance);
	instance = _tmp1_;
	_tmp2_ = g_strdup (FSO_AUDIO_GSM_VOICE_FORWARDER_MODULE_NAME);
	result = _tmp2_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	FsoFrameworkLogger* _tmp0_;
	g_return_if_fail (module != NULL);
	fso_audio_gsm_voice_forwarder_plugin_register_type (module);
	alsaloop_forwarder_register_type (module);
	_tmp0_ = fso_framework_theLogger;
	fso_framework_logger_debug (_tmp0_, "fsoaudio.gsmvoice_alsa_forwarder fso_register_function");
}


