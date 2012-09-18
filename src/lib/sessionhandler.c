/* sessionhandler.c generated by valac 0.16.0, the Vala compiler
 * generated from sessionhandler.vala, do not modify */

/*
 * Copyright (C) 2011-2012 Simon Busch <morphis@gravedo.de>
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
#include <fsobasics.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <freesmartphone.h>


#define FSO_AUDIO_TYPE_SESSION_HANDLER (fso_audio_session_handler_get_type ())
#define FSO_AUDIO_SESSION_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_SESSION_HANDLER, FsoAudioSessionHandler))
#define FSO_AUDIO_SESSION_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_TYPE_SESSION_HANDLER, FsoAudioSessionHandlerClass))
#define FSO_AUDIO_IS_SESSION_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_SESSION_HANDLER))
#define FSO_AUDIO_IS_SESSION_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_TYPE_SESSION_HANDLER))
#define FSO_AUDIO_SESSION_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_TYPE_SESSION_HANDLER, FsoAudioSessionHandlerClass))

typedef struct _FsoAudioSessionHandler FsoAudioSessionHandler;
typedef struct _FsoAudioSessionHandlerClass FsoAudioSessionHandlerClass;
typedef struct _FsoAudioSessionHandlerPrivate FsoAudioSessionHandlerPrivate;

#define FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY (fso_audio_abstract_session_policy_get_type ())
#define FSO_AUDIO_ABSTRACT_SESSION_POLICY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY, FsoAudioAbstractSessionPolicy))
#define FSO_AUDIO_ABSTRACT_SESSION_POLICY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY, FsoAudioAbstractSessionPolicyClass))
#define FSO_AUDIO_IS_ABSTRACT_SESSION_POLICY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY))
#define FSO_AUDIO_IS_ABSTRACT_SESSION_POLICY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY))
#define FSO_AUDIO_ABSTRACT_SESSION_POLICY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY, FsoAudioAbstractSessionPolicyClass))

typedef struct _FsoAudioAbstractSessionPolicy FsoAudioAbstractSessionPolicy;
typedef struct _FsoAudioAbstractSessionPolicyClass FsoAudioAbstractSessionPolicyClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _FsoAudioSessionHandler {
	FsoFrameworkAbstractObject parent_instance;
	FsoAudioSessionHandlerPrivate * priv;
};

struct _FsoAudioSessionHandlerClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _FsoAudioSessionHandlerPrivate {
	GeeHashMap* sessions;
	FsoAudioAbstractSessionPolicy* policy;
};


extern guint16 fso_audio_token_counter;
guint16 fso_audio_token_counter = (guint16) 0x0;
static gpointer fso_audio_session_handler_parent_class = NULL;

#define FSO_AUDIO_TOKEN_BASE ((guint16) 0x2300)
GType fso_audio_session_handler_get_type (void) G_GNUC_CONST;
GType fso_audio_abstract_session_policy_get_type (void) G_GNUC_CONST;
#define FSO_AUDIO_SESSION_HANDLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FSO_AUDIO_TYPE_SESSION_HANDLER, FsoAudioSessionHandlerPrivate))
enum  {
	FSO_AUDIO_SESSION_HANDLER_DUMMY_PROPERTY
};
FsoAudioSessionHandler* fso_audio_session_handler_new (FsoAudioAbstractSessionPolicy* policy);
FsoAudioSessionHandler* fso_audio_session_handler_construct (GType object_type, FsoAudioAbstractSessionPolicy* policy);
static gchar* fso_audio_session_handler_real_repr (FsoFrameworkAbstractObject* base);
FreeSmartphoneAudioStream fso_audio_session_handler_streamTypeForToken (FsoAudioSessionHandler* self, const gchar* token);
gchar* fso_audio_session_handler_register_session (FsoAudioSessionHandler* self, FreeSmartphoneAudioStream stream, GError** error);
static gchar* fso_audio_session_handler_new_token (FsoAudioSessionHandler* self);
const gchar* free_smartphone_audio_stream_to_string (FreeSmartphoneAudioStream self);
void fso_audio_session_handler_release_session (FsoAudioSessionHandler* self, const gchar* token, GError** error);
static GObject * fso_audio_session_handler_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void fso_audio_session_handler_finalize (GObject* obj);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


FsoAudioSessionHandler* fso_audio_session_handler_construct (GType object_type, FsoAudioAbstractSessionPolicy* policy) {
	FsoAudioSessionHandler * self = NULL;
	FsoAudioAbstractSessionPolicy* _tmp0_;
	FsoAudioAbstractSessionPolicy* _tmp1_;
	g_return_val_if_fail (policy != NULL, NULL);
	self = (FsoAudioSessionHandler*) fso_framework_abstract_object_construct (object_type);
	_tmp0_ = policy;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->policy);
	self->priv->policy = _tmp1_;
	return self;
}


FsoAudioSessionHandler* fso_audio_session_handler_new (FsoAudioAbstractSessionPolicy* policy) {
	return fso_audio_session_handler_construct (FSO_AUDIO_TYPE_SESSION_HANDLER, policy);
}


static gchar* fso_audio_session_handler_real_repr (FsoFrameworkAbstractObject* base) {
	FsoAudioSessionHandler * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (FsoAudioSessionHandler*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


FreeSmartphoneAudioStream fso_audio_session_handler_streamTypeForToken (FsoAudioSessionHandler* self, const gchar* token) {
	FreeSmartphoneAudioStream result = 0;
	GeeHashMap* _tmp0_;
	const gchar* _tmp1_;
	gboolean _tmp2_ = FALSE;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (token != NULL, 0);
	_tmp0_ = self->priv->sessions;
	_tmp1_ = token;
	_tmp2_ = gee_abstract_map_has_key ((GeeAbstractMap*) _tmp0_, _tmp1_);
	if (_tmp2_) {
		GeeHashMap* _tmp3_;
		const gchar* _tmp4_;
		gpointer _tmp5_ = NULL;
		_tmp3_ = self->priv->sessions;
		_tmp4_ = token;
		_tmp5_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp3_, _tmp4_);
		result = GPOINTER_TO_INT (_tmp5_);
		return result;
	}
	result = FREE_SMARTPHONE_AUDIO_STREAM_INVALID;
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


gchar* fso_audio_session_handler_register_session (FsoAudioSessionHandler* self, FreeSmartphoneAudioStream stream, GError** error) {
	gchar* result = NULL;
	gchar* _tmp0_;
	gchar* token;
	gchar* _tmp1_ = NULL;
	GeeHashMap* _tmp2_;
	GeeSet* _tmp3_;
	GeeSet* _tmp4_;
	GeeSet* _tmp5_;
	const gchar* _tmp6_;
	gboolean _tmp7_ = FALSE;
	gboolean _tmp8_;
	GeeHashMap* _tmp10_;
	const gchar* _tmp11_;
	FreeSmartphoneAudioStream _tmp12_;
	FsoFrameworkLogger* _tmp13_;
	const gchar* _tmp14_;
	const gchar* _tmp15_ = NULL;
	FreeSmartphoneAudioStream _tmp16_;
	GEnumValue* _tmp17_;
	gchar* _tmp18_ = NULL;
	gchar* _tmp19_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup ("");
	token = _tmp0_;
	_tmp1_ = fso_audio_session_handler_new_token (self);
	_g_free0 (token);
	token = _tmp1_;
	_tmp2_ = self->priv->sessions;
	_tmp3_ = gee_abstract_map_get_keys ((GeeMap*) _tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = _tmp4_;
	_tmp6_ = token;
	_tmp7_ = gee_collection_contains ((GeeCollection*) _tmp5_, _tmp6_);
	_tmp8_ = _tmp7_;
	_g_object_unref0 (_tmp5_);
	if (_tmp8_) {
		GError* _tmp9_;
		_tmp9_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INTERNAL_ERROR, "We have two session with exactly the same key! WTF!?");
		_inner_error_ = _tmp9_;
		if (_inner_error_->domain == FREE_SMARTPHONE_ERROR) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (token);
			return NULL;
		} else {
			_g_free0 (token);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_tmp10_ = self->priv->sessions;
	_tmp11_ = token;
	_tmp12_ = stream;
	gee_abstract_map_set ((GeeAbstractMap*) _tmp10_, _tmp11_, GINT_TO_POINTER (_tmp12_));
	_tmp13_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp14_ = token;
	_tmp15_ = string_to_string (_tmp14_);
	_tmp16_ = stream;
	_tmp17_ = g_enum_get_value (g_type_class_ref (FREE_SMARTPHONE_AUDIO_TYPE_STREAM), _tmp16_);
	_tmp18_ = g_strconcat ("Successfully registered a new audio session: token = ", _tmp15_, ", stream = ", (_tmp17_ != NULL) ? _tmp17_->value_name : NULL, NULL);
	_tmp19_ = _tmp18_;
	fso_framework_logger_debug (_tmp13_, _tmp19_);
	_g_free0 (_tmp19_);
	result = token;
	return result;
}


void fso_audio_session_handler_release_session (FsoAudioSessionHandler* self, const gchar* token, GError** error) {
	GeeHashMap* _tmp0_;
	GeeSet* _tmp1_;
	GeeSet* _tmp2_;
	GeeSet* _tmp3_;
	const gchar* _tmp4_;
	gboolean _tmp5_ = FALSE;
	gboolean _tmp6_;
	GeeHashMap* _tmp8_;
	const gchar* _tmp9_;
	gpointer _tmp10_ = NULL;
	FreeSmartphoneAudioStream stream;
	GeeHashMap* _tmp11_;
	const gchar* _tmp12_;
	FsoFrameworkLogger* _tmp13_;
	const gchar* _tmp14_;
	const gchar* _tmp15_ = NULL;
	GEnumValue* _tmp16_;
	gchar* _tmp17_ = NULL;
	gchar* _tmp18_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (token != NULL);
	_tmp0_ = self->priv->sessions;
	_tmp1_ = gee_abstract_map_get_keys ((GeeMap*) _tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = _tmp2_;
	_tmp4_ = token;
	_tmp5_ = gee_collection_contains ((GeeCollection*) _tmp3_, _tmp4_);
	_tmp6_ = !_tmp5_;
	_g_object_unref0 (_tmp3_);
	if (_tmp6_) {
		GError* _tmp7_;
		_tmp7_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INVALID_PARAMETER, "Supplied unknown token for audio session");
		_inner_error_ = _tmp7_;
		if (_inner_error_->domain == FREE_SMARTPHONE_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_tmp8_ = self->priv->sessions;
	_tmp9_ = token;
	_tmp10_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp8_, _tmp9_);
	stream = GPOINTER_TO_INT (_tmp10_);
	_tmp11_ = self->priv->sessions;
	_tmp12_ = token;
	gee_abstract_map_unset ((GeeAbstractMap*) _tmp11_, _tmp12_, NULL);
	_tmp13_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp14_ = token;
	_tmp15_ = string_to_string (_tmp14_);
	_tmp16_ = g_enum_get_value (g_type_class_ref (FREE_SMARTPHONE_AUDIO_TYPE_STREAM), stream);
	_tmp17_ = g_strconcat ("Successfully release a audio session: token = ", _tmp15_, ", stream = ", (_tmp16_ != NULL) ? _tmp16_->value_name : NULL, NULL);
	_tmp18_ = _tmp17_;
	fso_framework_logger_debug (_tmp13_, _tmp18_);
	_g_free0 (_tmp18_);
}


static gchar* fso_audio_session_handler_new_token (FsoAudioSessionHandler* self) {
	gchar* result = NULL;
	guint16 _tmp0_;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = fso_audio_token_counter;
	fso_audio_token_counter = _tmp0_ + 1;
	_tmp1_ = g_strdup_printf ("%x", (guint) (FSO_AUDIO_TOKEN_BASE + _tmp0_));
	result = _tmp1_;
	return result;
}


static GObject * fso_audio_session_handler_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	FsoAudioSessionHandler * self;
	GeeHashMap* _tmp0_;
	parent_class = G_OBJECT_CLASS (fso_audio_session_handler_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = FSO_AUDIO_SESSION_HANDLER (obj);
	_tmp0_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, FREE_SMARTPHONE_AUDIO_TYPE_STREAM, NULL, NULL, NULL, NULL, NULL);
	_g_object_unref0 (self->priv->sessions);
	self->priv->sessions = _tmp0_;
	return obj;
}


static void fso_audio_session_handler_class_init (FsoAudioSessionHandlerClass * klass) {
	fso_audio_session_handler_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FsoAudioSessionHandlerPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = fso_audio_session_handler_real_repr;
	G_OBJECT_CLASS (klass)->constructor = fso_audio_session_handler_constructor;
	G_OBJECT_CLASS (klass)->finalize = fso_audio_session_handler_finalize;
}


static void fso_audio_session_handler_instance_init (FsoAudioSessionHandler * self) {
	self->priv = FSO_AUDIO_SESSION_HANDLER_GET_PRIVATE (self);
}


static void fso_audio_session_handler_finalize (GObject* obj) {
	FsoAudioSessionHandler * self;
	self = FSO_AUDIO_SESSION_HANDLER (obj);
	_g_object_unref0 (self->priv->sessions);
	_g_object_unref0 (self->priv->policy);
	G_OBJECT_CLASS (fso_audio_session_handler_parent_class)->finalize (obj);
}


GType fso_audio_session_handler_get_type (void) {
	static volatile gsize fso_audio_session_handler_type_id__volatile = 0;
	if (g_once_init_enter (&fso_audio_session_handler_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoAudioSessionHandlerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_audio_session_handler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoAudioSessionHandler), 0, (GInstanceInitFunc) fso_audio_session_handler_instance_init, NULL };
		GType fso_audio_session_handler_type_id;
		fso_audio_session_handler_type_id = g_type_register_static (FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "FsoAudioSessionHandler", &g_define_type_info, 0);
		g_once_init_leave (&fso_audio_session_handler_type_id__volatile, fso_audio_session_handler_type_id);
	}
	return fso_audio_session_handler_type_id__volatile;
}


