/* plugin.c generated by valac 0.16.1, the Vala compiler
 * generated from plugin.vala, do not modify */

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
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_AUDIO_MANAGER (audio_manager_get_type ())
#define AUDIO_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_AUDIO_MANAGER, AudioManager))
#define IS_AUDIO_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_AUDIO_MANAGER))
#define AUDIO_MANAGER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TYPE_AUDIO_MANAGER, AudioManagerIface))

typedef struct _AudioManager AudioManager;
typedef struct _AudioManagerIface AudioManagerIface;

#define TYPE_AUDIO_MANAGER_PROXY (audio_manager_proxy_get_type ())
typedef GDBusProxy AudioManagerProxy;
typedef GDBusProxyClass AudioManagerProxyClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _AudioManagerIface {
	GTypeInterface parent_iface;
	gchar* (*register_session) (AudioManager* self, const gchar* name, GError** error);
	void (*release_session) (AudioManager* self, const gchar* token, GError** error);
};


extern AudioManager* manager;
AudioManager* manager = NULL;
extern gchar* active_token;
gchar* active_token = NULL;
extern gboolean registered;
gboolean registered = FALSE;

GType audio_manager_proxy_get_type (void) G_GNUC_CONST;
guint audio_manager_register_object (void* object, GDBusConnection* connection, const gchar* path, GError** error);
GType audio_manager_get_type (void) G_GNUC_CONST;
gchar* audio_manager_register_session (AudioManager* self, const gchar* name, GError** error);
void audio_manager_release_session (AudioManager* self, const gchar* token, GError** error);
static void audio_manager_proxy_g_signal (GDBusProxy* proxy, const gchar* sender_name, const gchar* signal_name, GVariant* parameters);
static gchar* audio_manager_proxy_register_session (AudioManager* self, const gchar* name, GError** error);
static void audio_manager_proxy_release_session (AudioManager* self, const gchar* token, GError** error);
static void audio_manager_proxy_audio_manager_interface_init (AudioManagerIface* iface);
static void _dbus_audio_manager_register_session (AudioManager* self, GVariant* parameters, GDBusMethodInvocation* invocation);
static void _dbus_audio_manager_release_session (AudioManager* self, GVariant* parameters, GDBusMethodInvocation* invocation);
static void audio_manager_dbus_interface_method_call (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* method_name, GVariant* parameters, GDBusMethodInvocation* invocation, gpointer user_data);
static GVariant* audio_manager_dbus_interface_get_property (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* property_name, GError** error, gpointer user_data);
static gboolean audio_manager_dbus_interface_set_property (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* property_name, GVariant* value, GError** error, gpointer user_data);
static void _audio_manager_unregister_object (gpointer user_data);
#define FSOAUDIO_BUSNAME "org.freesmartphone.oaudiod"
#define FSOAUDIO_PATH "/org/freesmartphone/Audio"
#define FSOAUDIO_MANAGER_IFNAME "org.freesmartphone.Audio.Manager"
#define timeout 10
gint fsoaudio_request_session (const gchar* pcmname);
gint fsoaudio_release_session (void);

static const GDBusArgInfo _audio_manager_dbus_arg_info_register_session_name = {-1, "name", "s"};
static const GDBusArgInfo _audio_manager_dbus_arg_info_register_session_result = {-1, "result", "s"};
static const GDBusArgInfo * const _audio_manager_dbus_arg_info_register_session_in[] = {&_audio_manager_dbus_arg_info_register_session_name, NULL};
static const GDBusArgInfo * const _audio_manager_dbus_arg_info_register_session_out[] = {&_audio_manager_dbus_arg_info_register_session_result, NULL};
static const GDBusMethodInfo _audio_manager_dbus_method_info_register_session = {-1, "RegisterSession", (GDBusArgInfo **) (&_audio_manager_dbus_arg_info_register_session_in), (GDBusArgInfo **) (&_audio_manager_dbus_arg_info_register_session_out)};
static const GDBusArgInfo _audio_manager_dbus_arg_info_release_session_token = {-1, "token", "s"};
static const GDBusArgInfo * const _audio_manager_dbus_arg_info_release_session_in[] = {&_audio_manager_dbus_arg_info_release_session_token, NULL};
static const GDBusArgInfo * const _audio_manager_dbus_arg_info_release_session_out[] = {NULL};
static const GDBusMethodInfo _audio_manager_dbus_method_info_release_session = {-1, "ReleaseSession", (GDBusArgInfo **) (&_audio_manager_dbus_arg_info_release_session_in), (GDBusArgInfo **) (&_audio_manager_dbus_arg_info_release_session_out)};
static const GDBusMethodInfo * const _audio_manager_dbus_method_info[] = {&_audio_manager_dbus_method_info_register_session, &_audio_manager_dbus_method_info_release_session, NULL};
static const GDBusSignalInfo * const _audio_manager_dbus_signal_info[] = {NULL};
static const GDBusPropertyInfo * const _audio_manager_dbus_property_info[] = {NULL};
static const GDBusInterfaceInfo _audio_manager_dbus_interface_info = {-1, "org.freesmartphone.Audio.Manager", (GDBusMethodInfo **) (&_audio_manager_dbus_method_info), (GDBusSignalInfo **) (&_audio_manager_dbus_signal_info), (GDBusPropertyInfo **) (&_audio_manager_dbus_property_info)};
static const GDBusInterfaceVTable _audio_manager_dbus_interface_vtable = {audio_manager_dbus_interface_method_call, audio_manager_dbus_interface_get_property, audio_manager_dbus_interface_set_property};

gchar* audio_manager_register_session (AudioManager* self, const gchar* name, GError** error) {
	g_return_val_if_fail (self != NULL, NULL);
	return AUDIO_MANAGER_GET_INTERFACE (self)->register_session (self, name, error);
}


void audio_manager_release_session (AudioManager* self, const gchar* token, GError** error) {
	g_return_if_fail (self != NULL);
	AUDIO_MANAGER_GET_INTERFACE (self)->release_session (self, token, error);
}


static void audio_manager_base_init (AudioManagerIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType audio_manager_get_type (void) {
	static volatile gsize audio_manager_type_id__volatile = 0;
	if (g_once_init_enter (&audio_manager_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (AudioManagerIface), (GBaseInitFunc) audio_manager_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType audio_manager_type_id;
		audio_manager_type_id = g_type_register_static (G_TYPE_INTERFACE, "AudioManager", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (audio_manager_type_id, G_TYPE_OBJECT);
		g_type_set_qdata (audio_manager_type_id, g_quark_from_static_string ("vala-dbus-proxy-type"), (void*) audio_manager_proxy_get_type);
		g_type_set_qdata (audio_manager_type_id, g_quark_from_static_string ("vala-dbus-interface-name"), "org.freesmartphone.Audio.Manager");
		g_type_set_qdata (audio_manager_type_id, g_quark_from_static_string ("vala-dbus-register-object"), (void*) audio_manager_register_object);
		g_once_init_leave (&audio_manager_type_id__volatile, audio_manager_type_id);
	}
	return audio_manager_type_id__volatile;
}


G_DEFINE_TYPE_EXTENDED (AudioManagerProxy, audio_manager_proxy, G_TYPE_DBUS_PROXY, 0, G_IMPLEMENT_INTERFACE (TYPE_AUDIO_MANAGER, audio_manager_proxy_audio_manager_interface_init) )
static void audio_manager_proxy_class_init (AudioManagerProxyClass* klass) {
	G_DBUS_PROXY_CLASS (klass)->g_signal = audio_manager_proxy_g_signal;
}


static void audio_manager_proxy_g_signal (GDBusProxy* proxy, const gchar* sender_name, const gchar* signal_name, GVariant* parameters) {
}


static void audio_manager_proxy_init (AudioManagerProxy* self) {
}


static gchar* audio_manager_proxy_register_session (AudioManager* self, const gchar* name, GError** error) {
	GDBusMessage *_message;
	GVariant *_arguments;
	GVariantBuilder _arguments_builder;
	GDBusMessage *_reply_message;
	GVariant *_reply;
	GVariantIter _reply_iter;
	gchar* _result;
	GVariant* _tmp0_;
	G_IO_ERROR;
	_message = g_dbus_message_new_method_call (g_dbus_proxy_get_name ((GDBusProxy *) self), g_dbus_proxy_get_object_path ((GDBusProxy *) self), "org.freesmartphone.Audio.Manager", "RegisterSession");
	g_variant_builder_init (&_arguments_builder, G_VARIANT_TYPE_TUPLE);
	g_variant_builder_add_value (&_arguments_builder, g_variant_new_string (name));
	_arguments = g_variant_builder_end (&_arguments_builder);
	g_dbus_message_set_body (_message, _arguments);
	_reply_message = g_dbus_connection_send_message_with_reply_sync (g_dbus_proxy_get_connection ((GDBusProxy *) self), _message, G_DBUS_SEND_MESSAGE_FLAGS_NONE, g_dbus_proxy_get_default_timeout ((GDBusProxy *) self), NULL, NULL, error);
	g_object_unref (_message);
	if (!_reply_message) {
		return NULL;
	}
	if (g_dbus_message_to_gerror (_reply_message, error)) {
		g_object_unref (_reply_message);
		return NULL;
	}
	_reply = g_dbus_message_get_body (_reply_message);
	g_variant_iter_init (&_reply_iter, _reply);
	_tmp0_ = g_variant_iter_next_value (&_reply_iter);
	_result = g_variant_dup_string (_tmp0_, NULL);
	g_variant_unref (_tmp0_);
	g_object_unref (_reply_message);
	return _result;
}


static void audio_manager_proxy_release_session (AudioManager* self, const gchar* token, GError** error) {
	GDBusMessage *_message;
	GVariant *_arguments;
	GVariantBuilder _arguments_builder;
	GDBusMessage *_reply_message;
	G_IO_ERROR;
	_message = g_dbus_message_new_method_call (g_dbus_proxy_get_name ((GDBusProxy *) self), g_dbus_proxy_get_object_path ((GDBusProxy *) self), "org.freesmartphone.Audio.Manager", "ReleaseSession");
	g_variant_builder_init (&_arguments_builder, G_VARIANT_TYPE_TUPLE);
	g_variant_builder_add_value (&_arguments_builder, g_variant_new_string (token));
	_arguments = g_variant_builder_end (&_arguments_builder);
	g_dbus_message_set_body (_message, _arguments);
	_reply_message = g_dbus_connection_send_message_with_reply_sync (g_dbus_proxy_get_connection ((GDBusProxy *) self), _message, G_DBUS_SEND_MESSAGE_FLAGS_NONE, g_dbus_proxy_get_default_timeout ((GDBusProxy *) self), NULL, NULL, error);
	g_object_unref (_message);
	if (!_reply_message) {
		return;
	}
	if (g_dbus_message_to_gerror (_reply_message, error)) {
		g_object_unref (_reply_message);
		return;
	}
	g_object_unref (_reply_message);
}


static void audio_manager_proxy_audio_manager_interface_init (AudioManagerIface* iface) {
	iface->register_session = audio_manager_proxy_register_session;
	iface->release_session = audio_manager_proxy_release_session;
}


static void _dbus_audio_manager_register_session (AudioManager* self, GVariant* parameters, GDBusMethodInvocation* invocation) {
	GError* error = NULL;
	GVariantIter _arguments_iter;
	gchar* name = NULL;
	GVariant* _tmp1_;
	GDBusMessage* _reply_message;
	GVariant* _reply;
	GVariantBuilder _reply_builder;
	gchar* result;
	g_variant_iter_init (&_arguments_iter, parameters);
	_tmp1_ = g_variant_iter_next_value (&_arguments_iter);
	name = g_variant_dup_string (_tmp1_, NULL);
	g_variant_unref (_tmp1_);
	result = audio_manager_register_session (self, name, &error);
	if (error) {
		g_dbus_method_invocation_return_gerror (invocation, error);
		return;
	}
	_reply_message = g_dbus_message_new_method_reply (g_dbus_method_invocation_get_message (invocation));
	g_variant_builder_init (&_reply_builder, G_VARIANT_TYPE_TUPLE);
	g_variant_builder_add_value (&_reply_builder, g_variant_new_string (result));
	_g_free0 (result);
	_reply = g_variant_builder_end (&_reply_builder);
	g_dbus_message_set_body (_reply_message, _reply);
	_g_free0 (name);
	g_dbus_connection_send_message (g_dbus_method_invocation_get_connection (invocation), _reply_message, G_DBUS_SEND_MESSAGE_FLAGS_NONE, NULL, NULL);
	g_object_unref (invocation);
	g_object_unref (_reply_message);
}


static void _dbus_audio_manager_release_session (AudioManager* self, GVariant* parameters, GDBusMethodInvocation* invocation) {
	GError* error = NULL;
	GVariantIter _arguments_iter;
	gchar* token = NULL;
	GVariant* _tmp2_;
	GDBusMessage* _reply_message;
	GVariant* _reply;
	GVariantBuilder _reply_builder;
	g_variant_iter_init (&_arguments_iter, parameters);
	_tmp2_ = g_variant_iter_next_value (&_arguments_iter);
	token = g_variant_dup_string (_tmp2_, NULL);
	g_variant_unref (_tmp2_);
	audio_manager_release_session (self, token, &error);
	if (error) {
		g_dbus_method_invocation_return_gerror (invocation, error);
		return;
	}
	_reply_message = g_dbus_message_new_method_reply (g_dbus_method_invocation_get_message (invocation));
	g_variant_builder_init (&_reply_builder, G_VARIANT_TYPE_TUPLE);
	_reply = g_variant_builder_end (&_reply_builder);
	g_dbus_message_set_body (_reply_message, _reply);
	_g_free0 (token);
	g_dbus_connection_send_message (g_dbus_method_invocation_get_connection (invocation), _reply_message, G_DBUS_SEND_MESSAGE_FLAGS_NONE, NULL, NULL);
	g_object_unref (invocation);
	g_object_unref (_reply_message);
}


static void audio_manager_dbus_interface_method_call (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* method_name, GVariant* parameters, GDBusMethodInvocation* invocation, gpointer user_data) {
	gpointer* data;
	gpointer object;
	data = user_data;
	object = data[0];
	if (strcmp (method_name, "RegisterSession") == 0) {
		_dbus_audio_manager_register_session (object, parameters, invocation);
	} else if (strcmp (method_name, "ReleaseSession") == 0) {
		_dbus_audio_manager_release_session (object, parameters, invocation);
	} else {
		g_object_unref (invocation);
	}
}


static GVariant* audio_manager_dbus_interface_get_property (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* property_name, GError** error, gpointer user_data) {
	gpointer* data;
	gpointer object;
	data = user_data;
	object = data[0];
	return NULL;
}


static gboolean audio_manager_dbus_interface_set_property (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* property_name, GVariant* value, GError** error, gpointer user_data) {
	gpointer* data;
	gpointer object;
	data = user_data;
	object = data[0];
	return FALSE;
}


guint audio_manager_register_object (gpointer object, GDBusConnection* connection, const gchar* path, GError** error) {
	guint result;
	gpointer *data;
	data = g_new (gpointer, 3);
	data[0] = g_object_ref (object);
	data[1] = g_object_ref (connection);
	data[2] = g_strdup (path);
	result = g_dbus_connection_register_object (connection, path, (GDBusInterfaceInfo *) (&_audio_manager_dbus_interface_info), &_audio_manager_dbus_interface_vtable, data, _audio_manager_unregister_object, error);
	if (!result) {
		return 0;
	}
	return result;
}


static void _audio_manager_unregister_object (gpointer user_data) {
	gpointer* data;
	data = user_data;
	g_object_unref (data[0]);
	g_object_unref (data[1]);
	g_free (data[2]);
	g_free (data);
}


gint fsoaudio_request_session (const gchar* pcmname) {
	gint result = 0;
	gchar* _tmp0_;
	gint _tmp7_ = 0;
	gboolean _tmp8_;
	gint _tmp9_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (pcmname != NULL, 0);
	registered = FALSE;
	_tmp0_ = g_strdup ("");
	_g_free0 (active_token);
	active_token = _tmp0_;
	{
		AudioManager* _tmp1_ = NULL;
		AudioManager* _tmp2_;
		AudioManager* _tmp3_;
		const gchar* _tmp4_;
		gchar* _tmp5_ = NULL;
		gchar* _tmp6_;
		_tmp1_ = g_initable_new (TYPE_AUDIO_MANAGER_PROXY, NULL, &_inner_error_, "g-flags", 0, "g-name", FSOAUDIO_BUSNAME, "g-bus-type", G_BUS_TYPE_SYSTEM, "g-object-path", FSOAUDIO_PATH, "g-interface-name", "org.freesmartphone.Audio.Manager", NULL);
		_tmp2_ = (AudioManager*) _tmp1_;
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
		_g_object_unref0 (manager);
		manager = _tmp2_;
		_tmp3_ = manager;
		_tmp4_ = pcmname;
		_tmp5_ = audio_manager_register_session (_tmp3_, _tmp4_, &_inner_error_);
		_tmp6_ = _tmp5_;
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
		_g_free0 (active_token);
		active_token = _tmp6_;
		registered = TRUE;
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* err = NULL;
		err = _inner_error_;
		_inner_error_ = NULL;
		_g_error_free0 (err);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	_tmp8_ = registered;
	if (_tmp8_) {
		_tmp7_ = 0;
	} else {
		_tmp7_ = -1;
	}
	_tmp9_ = _tmp7_;
	result = _tmp9_;
	return result;
}


gint fsoaudio_release_session (void) {
	gint result = 0;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_;
	gboolean _tmp4_;
	gboolean _tmp8_;
	GError * _inner_error_ = NULL;
	_tmp2_ = registered;
	if (_tmp2_) {
		AudioManager* _tmp3_;
		_tmp3_ = manager;
		_tmp1_ = _tmp3_ != NULL;
	} else {
		_tmp1_ = FALSE;
	}
	_tmp4_ = _tmp1_;
	if (_tmp4_) {
		const gchar* _tmp5_;
		gint _tmp6_;
		gint _tmp7_;
		_tmp5_ = active_token;
		_tmp6_ = strlen (_tmp5_);
		_tmp7_ = _tmp6_;
		_tmp0_ = _tmp7_ > 0;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp8_ = _tmp0_;
	if (_tmp8_) {
		{
			AudioManager* _tmp9_;
			const gchar* _tmp10_;
			_tmp9_ = manager;
			_tmp10_ = active_token;
			audio_manager_release_session (_tmp9_, _tmp10_, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch1_g_error;
			}
			registered = FALSE;
		}
		goto __finally1;
		__catch1_g_error:
		{
			GError* err = NULL;
			err = _inner_error_;
			_inner_error_ = NULL;
			_g_error_free0 (err);
		}
		__finally1:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return 0;
		}
	}
	result = 0;
	return result;
}



