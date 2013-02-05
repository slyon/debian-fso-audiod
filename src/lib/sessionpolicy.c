/* sessionpolicy.c generated by valac 0.16.1, the Vala compiler
 * generated from sessionpolicy.vala, do not modify */

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
#include <freesmartphone.h>
#include <stdlib.h>
#include <string.h>


#define FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY (fso_audio_abstract_session_policy_get_type ())
#define FSO_AUDIO_ABSTRACT_SESSION_POLICY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY, FsoAudioAbstractSessionPolicy))
#define FSO_AUDIO_ABSTRACT_SESSION_POLICY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY, FsoAudioAbstractSessionPolicyClass))
#define FSO_AUDIO_IS_ABSTRACT_SESSION_POLICY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY))
#define FSO_AUDIO_IS_ABSTRACT_SESSION_POLICY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY))
#define FSO_AUDIO_ABSTRACT_SESSION_POLICY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY, FsoAudioAbstractSessionPolicyClass))

typedef struct _FsoAudioAbstractSessionPolicy FsoAudioAbstractSessionPolicy;
typedef struct _FsoAudioAbstractSessionPolicyClass FsoAudioAbstractSessionPolicyClass;
typedef struct _FsoAudioAbstractSessionPolicyPrivate FsoAudioAbstractSessionPolicyPrivate;

#define FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL (fso_audio_abstract_stream_control_get_type ())
#define FSO_AUDIO_ABSTRACT_STREAM_CONTROL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL, FsoAudioAbstractStreamControl))
#define FSO_AUDIO_ABSTRACT_STREAM_CONTROL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL, FsoAudioAbstractStreamControlClass))
#define FSO_AUDIO_IS_ABSTRACT_STREAM_CONTROL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL))
#define FSO_AUDIO_IS_ABSTRACT_STREAM_CONTROL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL))
#define FSO_AUDIO_ABSTRACT_STREAM_CONTROL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_TYPE_ABSTRACT_STREAM_CONTROL, FsoAudioAbstractStreamControlClass))

typedef struct _FsoAudioAbstractStreamControl FsoAudioAbstractStreamControl;
typedef struct _FsoAudioAbstractStreamControlClass FsoAudioAbstractStreamControlClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define FSO_AUDIO_TYPE_NULL_SESSION_POLICY (fso_audio_null_session_policy_get_type ())
#define FSO_AUDIO_NULL_SESSION_POLICY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_AUDIO_TYPE_NULL_SESSION_POLICY, FsoAudioNullSessionPolicy))
#define FSO_AUDIO_NULL_SESSION_POLICY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_AUDIO_TYPE_NULL_SESSION_POLICY, FsoAudioNullSessionPolicyClass))
#define FSO_AUDIO_IS_NULL_SESSION_POLICY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_AUDIO_TYPE_NULL_SESSION_POLICY))
#define FSO_AUDIO_IS_NULL_SESSION_POLICY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_AUDIO_TYPE_NULL_SESSION_POLICY))
#define FSO_AUDIO_NULL_SESSION_POLICY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_AUDIO_TYPE_NULL_SESSION_POLICY, FsoAudioNullSessionPolicyClass))

typedef struct _FsoAudioNullSessionPolicy FsoAudioNullSessionPolicy;
typedef struct _FsoAudioNullSessionPolicyClass FsoAudioNullSessionPolicyClass;
typedef struct _FsoAudioNullSessionPolicyPrivate FsoAudioNullSessionPolicyPrivate;

struct _FsoAudioAbstractSessionPolicy {
	FsoFrameworkAbstractObject parent_instance;
	FsoAudioAbstractSessionPolicyPrivate * priv;
	FsoAudioAbstractStreamControl* stream_control;
};

struct _FsoAudioAbstractSessionPolicyClass {
	FsoFrameworkAbstractObjectClass parent_class;
	void (*handleConnectingStream) (FsoAudioAbstractSessionPolicy* self, FreeSmartphoneAudioStream stream);
	void (*handleDisconnectingStream) (FsoAudioAbstractSessionPolicy* self, FreeSmartphoneAudioStream stream);
};

struct _FsoAudioNullSessionPolicy {
	FsoAudioAbstractSessionPolicy parent_instance;
	FsoAudioNullSessionPolicyPrivate * priv;
};

struct _FsoAudioNullSessionPolicyClass {
	FsoAudioAbstractSessionPolicyClass parent_class;
};


static gpointer fso_audio_abstract_session_policy_parent_class = NULL;
static gpointer fso_audio_null_session_policy_parent_class = NULL;

GType fso_audio_abstract_session_policy_get_type (void) G_GNUC_CONST;
GType fso_audio_abstract_stream_control_get_type (void) G_GNUC_CONST;
enum  {
	FSO_AUDIO_ABSTRACT_SESSION_POLICY_DUMMY_PROPERTY
};
void fso_audio_abstract_session_policy_handleConnectingStream (FsoAudioAbstractSessionPolicy* self, FreeSmartphoneAudioStream stream);
static void fso_audio_abstract_session_policy_real_handleConnectingStream (FsoAudioAbstractSessionPolicy* self, FreeSmartphoneAudioStream stream);
void fso_audio_abstract_session_policy_handleDisconnectingStream (FsoAudioAbstractSessionPolicy* self, FreeSmartphoneAudioStream stream);
static void fso_audio_abstract_session_policy_real_handleDisconnectingStream (FsoAudioAbstractSessionPolicy* self, FreeSmartphoneAudioStream stream);
void fso_audio_abstract_session_policy_provideStreamControl (FsoAudioAbstractSessionPolicy* self, FsoAudioAbstractStreamControl* stream_control);
static gchar* fso_audio_abstract_session_policy_real_repr (FsoFrameworkAbstractObject* base);
FsoAudioAbstractSessionPolicy* fso_audio_abstract_session_policy_construct (GType object_type);
static void fso_audio_abstract_session_policy_finalize (GObject* obj);
GType fso_audio_null_session_policy_get_type (void) G_GNUC_CONST;
enum  {
	FSO_AUDIO_NULL_SESSION_POLICY_DUMMY_PROPERTY
};
static void fso_audio_null_session_policy_real_handleConnectingStream (FsoAudioAbstractSessionPolicy* base, FreeSmartphoneAudioStream stream);
static void fso_audio_null_session_policy_real_handleDisconnectingStream (FsoAudioAbstractSessionPolicy* base, FreeSmartphoneAudioStream stream);
FsoAudioNullSessionPolicy* fso_audio_null_session_policy_new (void);
FsoAudioNullSessionPolicy* fso_audio_null_session_policy_construct (GType object_type);


static void fso_audio_abstract_session_policy_real_handleConnectingStream (FsoAudioAbstractSessionPolicy* self, FreeSmartphoneAudioStream stream) {
	g_critical ("Type `%s' does not implement abstract method `fso_audio_abstract_session_policy_handleConnectingStream'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void fso_audio_abstract_session_policy_handleConnectingStream (FsoAudioAbstractSessionPolicy* self, FreeSmartphoneAudioStream stream) {
	g_return_if_fail (self != NULL);
	FSO_AUDIO_ABSTRACT_SESSION_POLICY_GET_CLASS (self)->handleConnectingStream (self, stream);
}


static void fso_audio_abstract_session_policy_real_handleDisconnectingStream (FsoAudioAbstractSessionPolicy* self, FreeSmartphoneAudioStream stream) {
	g_critical ("Type `%s' does not implement abstract method `fso_audio_abstract_session_policy_handleDisconnectingStream'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void fso_audio_abstract_session_policy_handleDisconnectingStream (FsoAudioAbstractSessionPolicy* self, FreeSmartphoneAudioStream stream) {
	g_return_if_fail (self != NULL);
	FSO_AUDIO_ABSTRACT_SESSION_POLICY_GET_CLASS (self)->handleDisconnectingStream (self, stream);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void fso_audio_abstract_session_policy_provideStreamControl (FsoAudioAbstractSessionPolicy* self, FsoAudioAbstractStreamControl* stream_control) {
	FsoAudioAbstractStreamControl* _tmp0_;
	FsoAudioAbstractStreamControl* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (stream_control != NULL);
	_tmp0_ = stream_control;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->stream_control);
	self->stream_control = _tmp1_;
}


static gchar* fso_audio_abstract_session_policy_real_repr (FsoFrameworkAbstractObject* base) {
	FsoAudioAbstractSessionPolicy * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (FsoAudioAbstractSessionPolicy*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


FsoAudioAbstractSessionPolicy* fso_audio_abstract_session_policy_construct (GType object_type) {
	FsoAudioAbstractSessionPolicy * self = NULL;
	self = (FsoAudioAbstractSessionPolicy*) fso_framework_abstract_object_construct (object_type);
	return self;
}


static void fso_audio_abstract_session_policy_class_init (FsoAudioAbstractSessionPolicyClass * klass) {
	fso_audio_abstract_session_policy_parent_class = g_type_class_peek_parent (klass);
	FSO_AUDIO_ABSTRACT_SESSION_POLICY_CLASS (klass)->handleConnectingStream = fso_audio_abstract_session_policy_real_handleConnectingStream;
	FSO_AUDIO_ABSTRACT_SESSION_POLICY_CLASS (klass)->handleDisconnectingStream = fso_audio_abstract_session_policy_real_handleDisconnectingStream;
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = fso_audio_abstract_session_policy_real_repr;
	G_OBJECT_CLASS (klass)->finalize = fso_audio_abstract_session_policy_finalize;
}


static void fso_audio_abstract_session_policy_instance_init (FsoAudioAbstractSessionPolicy * self) {
}


static void fso_audio_abstract_session_policy_finalize (GObject* obj) {
	FsoAudioAbstractSessionPolicy * self;
	self = FSO_AUDIO_ABSTRACT_SESSION_POLICY (obj);
	_g_object_unref0 (self->stream_control);
	G_OBJECT_CLASS (fso_audio_abstract_session_policy_parent_class)->finalize (obj);
}


GType fso_audio_abstract_session_policy_get_type (void) {
	static volatile gsize fso_audio_abstract_session_policy_type_id__volatile = 0;
	if (g_once_init_enter (&fso_audio_abstract_session_policy_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoAudioAbstractSessionPolicyClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_audio_abstract_session_policy_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoAudioAbstractSessionPolicy), 0, (GInstanceInitFunc) fso_audio_abstract_session_policy_instance_init, NULL };
		GType fso_audio_abstract_session_policy_type_id;
		fso_audio_abstract_session_policy_type_id = g_type_register_static (FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "FsoAudioAbstractSessionPolicy", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&fso_audio_abstract_session_policy_type_id__volatile, fso_audio_abstract_session_policy_type_id);
	}
	return fso_audio_abstract_session_policy_type_id__volatile;
}


static void fso_audio_null_session_policy_real_handleConnectingStream (FsoAudioAbstractSessionPolicy* base, FreeSmartphoneAudioStream stream) {
	FsoAudioNullSessionPolicy * self;
	FsoFrameworkLogger* _tmp0_;
	self = (FsoAudioNullSessionPolicy*) base;
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_warning (_tmp0_, "NullSessionPolicy::handleConnectingStream(): This is maybe not what yo" \
"u want!");
}


static void fso_audio_null_session_policy_real_handleDisconnectingStream (FsoAudioAbstractSessionPolicy* base, FreeSmartphoneAudioStream stream) {
	FsoAudioNullSessionPolicy * self;
	FsoFrameworkLogger* _tmp0_;
	self = (FsoAudioNullSessionPolicy*) base;
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_warning (_tmp0_, "NullSessionPolicy::handleDisconnectingStream(): This is maybe not what" \
" you want!");
}


FsoAudioNullSessionPolicy* fso_audio_null_session_policy_construct (GType object_type) {
	FsoAudioNullSessionPolicy * self = NULL;
	self = (FsoAudioNullSessionPolicy*) fso_audio_abstract_session_policy_construct (object_type);
	return self;
}


FsoAudioNullSessionPolicy* fso_audio_null_session_policy_new (void) {
	return fso_audio_null_session_policy_construct (FSO_AUDIO_TYPE_NULL_SESSION_POLICY);
}


static void fso_audio_null_session_policy_class_init (FsoAudioNullSessionPolicyClass * klass) {
	fso_audio_null_session_policy_parent_class = g_type_class_peek_parent (klass);
	FSO_AUDIO_ABSTRACT_SESSION_POLICY_CLASS (klass)->handleConnectingStream = fso_audio_null_session_policy_real_handleConnectingStream;
	FSO_AUDIO_ABSTRACT_SESSION_POLICY_CLASS (klass)->handleDisconnectingStream = fso_audio_null_session_policy_real_handleDisconnectingStream;
}


static void fso_audio_null_session_policy_instance_init (FsoAudioNullSessionPolicy * self) {
}


GType fso_audio_null_session_policy_get_type (void) {
	static volatile gsize fso_audio_null_session_policy_type_id__volatile = 0;
	if (g_once_init_enter (&fso_audio_null_session_policy_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoAudioNullSessionPolicyClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_audio_null_session_policy_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoAudioNullSessionPolicy), 0, (GInstanceInitFunc) fso_audio_null_session_policy_instance_init, NULL };
		GType fso_audio_null_session_policy_type_id;
		fso_audio_null_session_policy_type_id = g_type_register_static (FSO_AUDIO_TYPE_ABSTRACT_SESSION_POLICY, "FsoAudioNullSessionPolicy", &g_define_type_info, 0);
		g_once_init_leave (&fso_audio_null_session_policy_type_id__volatile, fso_audio_null_session_policy_type_id);
	}
	return fso_audio_null_session_policy_type_id__volatile;
}



