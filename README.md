# HTC Endeavoru (aka One X)

## Building the ROM yourself

Download the latest LiquidSmooth Source
	
[https://github.com/LiquidSmooth](https://github.com/LiquidSmooth)

You will also need the extra tools from adrian-bl-hox-jb repos

In the root of the source folder do the following commands one by one -

	rm -rf system/core && git clone git://github.com/adrian-bl-hox-jb/android_system_core -b jb42 system/core

	git clone git://github.com/adrian-bl-hox-jb/android_hox_tools hox/tools

	git clone git://github.com/adrian-bl-hox-jb/android_vendor_htc_endeavoru -b jb vendor/htc/endeavoru

Now to download this device tree. Use this command -

	git clone git://github.com/mattmanwrx/android_device_htc_endeavoru_ls -b jb device/htc/endeavoru

Finally, we need to cherry pick a commit for the camera to work, so use these commands

	cd frameworks/native
	
	git fetch git://github.com/adrian-bl-hox-jb/android_frameworks_native
	
	git cherry-pick 9266b89

	cd ../..
	
That should be it for the tools needed, now lets build.

## Build:

	. build/envsetup.sh && lunch

Chose the number that "liquid_endeavoru-userdebug" is on

	mka liquid

This will create a flashable.zip in the out/product/target/endeavoru folder

## Links

* [Thread on XDA](http://forum.xda-developers.com/showthread.php?t=2102878)
* [mattmanwrx's site](http://www.mattman.org)

## Credits

* With thanks to the LiquidSmooth team
* Thanks to pabx from XDA (adrain-bl-hox-jb)
