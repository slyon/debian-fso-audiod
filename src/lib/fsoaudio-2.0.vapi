/* fsoaudio-2.0.vapi generated by valac 0.16.0, do not modify. */

namespace FsoAudio {
	[CCode (cheader_filename = "fsoaudio.h")]
	public abstract class AbstractRouter : FsoAudio.IRouter, FsoFramework.AbstractObject {
		protected FreeSmartphone.Audio.Device[] call_supported_devices;
		protected FreeSmartphone.Audio.Device current_device;
		protected FreeSmartphone.Audio.Mode current_mode;
		protected FreeSmartphone.Audio.Device[] normal_supported_devices;
		public AbstractRouter ();
		public virtual FreeSmartphone.Audio.Device[] get_available_devices (FreeSmartphone.Audio.Mode mode);
		public virtual void set_device (FreeSmartphone.Audio.Device device, bool expose = true);
		public virtual void set_mode (FreeSmartphone.Audio.Mode mode, bool force = false);
		public virtual void set_volume (FreeSmartphone.Audio.Control control, uint volume);
	}
	[CCode (cheader_filename = "fsoaudio.h")]
	public abstract class AbstractSessionPolicy : FsoFramework.AbstractObject {
		protected FsoAudio.AbstractStreamControl stream_control;
		public AbstractSessionPolicy ();
		public abstract void handleConnectingStream (FreeSmartphone.Audio.Stream stream);
		public abstract void handleDisconnectingStream (FreeSmartphone.Audio.Stream stream);
		public void provideStreamControl (FsoAudio.AbstractStreamControl stream_control);
		public override string repr ();
	}
	[CCode (cheader_filename = "fsoaudio.h")]
	public abstract class AbstractStreamControl : FsoFramework.AbstractObject {
		public AbstractStreamControl ();
		public abstract bool get_mute (FreeSmartphone.Audio.Stream stream);
		public abstract uint get_volume (FreeSmartphone.Audio.Stream stream);
		public override string repr ();
		public abstract void set_mute (FreeSmartphone.Audio.Stream stream, bool mute);
		public abstract void set_volume (FreeSmartphone.Audio.Stream stream, uint level);
		public abstract void setup ();
		public signal void mute_changed (FreeSmartphone.Audio.Stream stream, bool mute);
		public signal void volume_changed (FreeSmartphone.Audio.Stream stream, uint level);
	}
	[CCode (cheader_filename = "fsoaudio.h")]
	public class BunchOfMixerControls {
		public FsoAudio.MixerControl[] controls;
		public uint idxMicVolume;
		public uint idxSpeakerVolume;
		public BunchOfMixerControls (FsoAudio.MixerControl[] controls, uint idxSpeakerVolume = 0, uint idxMicVolume = 0);
		public string to_string ();
	}
	[CCode (cheader_filename = "fsoaudio.h")]
	public class MixerControl {
		public Alsa.ElemId eid;
		public Alsa.ElemInfo info;
		public Alsa.ElemValue value;
		public MixerControl (ref Alsa.ElemId eid, ref Alsa.ElemInfo info, ref Alsa.ElemValue value);
		public string to_string ();
		public uint volume { get; set; }
	}
	[CCode (cheader_filename = "fsoaudio.h")]
	public class NullRouter : FsoAudio.AbstractRouter {
		public NullRouter ();
		public override FreeSmartphone.Audio.Device[] get_available_devices (FreeSmartphone.Audio.Mode mode);
		public override string repr ();
	}
	[CCode (cheader_filename = "fsoaudio.h")]
	public class NullSessionPolicy : FsoAudio.AbstractSessionPolicy {
		public NullSessionPolicy ();
		public override void handleConnectingStream (FreeSmartphone.Audio.Stream stream);
		public override void handleDisconnectingStream (FreeSmartphone.Audio.Stream stream);
	}
	[CCode (cheader_filename = "fsoaudio.h")]
	public class NullStreamControl : FsoAudio.AbstractStreamControl {
		public NullStreamControl ();
		public override bool get_mute (FreeSmartphone.Audio.Stream stream);
		public override uint get_volume (FreeSmartphone.Audio.Stream stream);
		public override void set_mute (FreeSmartphone.Audio.Stream stream, bool mute);
		public override void set_volume (FreeSmartphone.Audio.Stream stream, uint level);
		public override void setup ();
	}
	[CCode (cheader_filename = "fsoaudio.h")]
	public class PcmDevice {
		public Alsa.PcmDevice device;
		public PcmDevice ();
		public void close ();
		public void open (string devicename = "default", Alsa.PcmStream mode = Alsa.PcmStream.PLAYBACK) throws FsoAudio.SoundError;
		public void prepare () throws FsoAudio.SoundError;
		public Alsa.PcmSignedFrames readi (uint8[] buf, Alsa.PcmUnsignedFrames size) throws FsoAudio.SoundError;
		public Alsa.PcmSignedFrames readn (uint8*[] buf, Alsa.PcmUnsignedFrames size) throws FsoAudio.SoundError;
		public int recover (int error, int silent);
		public void setFormat (Alsa.PcmAccess access, Alsa.PcmFormat format, int desiredrate = 44100, uint channels = 2) throws FsoAudio.SoundError;
		public Alsa.PcmSignedFrames writei (uint8[] buf, Alsa.PcmUnsignedFrames size) throws FsoAudio.SoundError;
		public Alsa.PcmSignedFrames writen (uint8*[] buf, Alsa.PcmUnsignedFrames size) throws FsoAudio.SoundError;
	}
	[CCode (cheader_filename = "fsoaudio.h")]
	public class SessionHandler : FsoFramework.AbstractObject {
		public SessionHandler (FsoAudio.AbstractSessionPolicy policy);
		public string register_session (FreeSmartphone.Audio.Stream stream) throws FreeSmartphone.Error;
		public void release_session (string token) throws FreeSmartphone.Error;
		public override string repr ();
		public FreeSmartphone.Audio.Stream streamTypeForToken (string token);
	}
	[CCode (cheader_filename = "fsoaudio.h")]
	public class SoundDevice : FsoFramework.AbstractObject {
		public string cardname;
		public string fullname;
		public string mixername;
		public string name;
		public FsoAudio.MixerControl[] allMixerControls () throws FsoAudio.SoundError;
		public FsoAudio.MixerControl controlForId (uint idx) throws FsoAudio.SoundError;
		public FsoAudio.MixerControl controlForString (string description) throws FsoAudio.SoundError;
		public static FsoAudio.SoundDevice create (string cardname = "default") throws FsoAudio.SoundError;
		public override string repr ();
		public void setAllMixerControls (FsoAudio.MixerControl[] controls) throws FsoAudio.SoundError;
		public void setControl (FsoAudio.MixerControl control) throws FsoAudio.SoundError;
		public void setVolumeForIndex (uint id, uint8 val);
		public uint8 volumeForIndex (uint id);
	}
	[CCode (cheader_filename = "fsoaudio.h")]
	public interface IRouter : FsoFramework.AbstractObject {
		public abstract FreeSmartphone.Audio.Device[] get_available_devices (FreeSmartphone.Audio.Mode mode);
		public abstract void set_device (FreeSmartphone.Audio.Device device, bool expose = true);
		public abstract void set_mode (FreeSmartphone.Audio.Mode mode, bool force = false);
		public abstract void set_volume (FreeSmartphone.Audio.Control control, uint volume);
	}
	[CCode (cheader_filename = "fsoaudio.h")]
	public errordomain SoundError {
		NO_DEVICE,
		DEVICE_ERROR,
		NOT_ENOUGH_CONTROLS,
		INVALID_DESCRIPTOR
	}
}
