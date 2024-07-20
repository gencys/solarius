## SOLARIUS

Solarius is a custom kernel for the EZFlash Omega Definitive edition. It was forked from [Simple](https://github.com/Sterophonick/omega-de-kernel) by [Sterophonick](https://github.com/Sterophonick).

The goal of this custom kernel is three-fold:

   1. Document the EZFlash kernel as much as possible for posterity.
   2. Flashcart UIs don't need to be ugly, let's make a nice one (still ongoing).
   3. Make the cart available in more languages.

### How to use

> [!CAUTION]
> This is a kernel for the **Omega DE**, not for the first Omega cartridge.
>
> You **must** install the official kernel first **before** trying to install Solarius.

Much like the Simple kernel, there are two variants to Solarius, a dark mode and a light mode.

   1. Enable "Show hidden files" on your computer.
   2. Choose and download the file you need depdending on the mode you want:
      - `ezkernelnew_dark.zip` for the dark mode, or
      - `ezkernelnew_light.zip` for the light mode
   3. Extract your zip file somehwere on your computer.
   4. The file that you extracted should contain:
      - A folder named `BACKUP`
      - A folder named `LANG`
      - A file named `ezkernelnew.bin`
   5. Pop your Omega DE's SD card in your computer.
   6. On the SD card, you should have a folder named `SYSTEM`, rename it into `.config` (yes, the dot before config is intentional)
      - Your computer may warn you that you are about to create a hidden folder, that's the goal!
      - It may also warn you that you're modifying the folder's extension, that's okay, we know what we are doing, we are professionals.
   7. In the file you extracted earlier, move `LANG` and `BACKUP` into `.config` which you just created.
      - If you don't see `.config` remember to enable "Show hidden files" on your computer (google it, the procedure for that will depend on which operating system you use).
   8. Move `ezkernelnew.bin` next to `.config` (*next to it*, not *in* it).
   9. Safely remove your SD card from your computer and put it back in your Omega DE.
   10. Put your Omega DE in your console and boot the console **while holding the L trigger** until a screen showing an update progress shows up.
   11. You're done ! Congrats, you did it ! You can be proud of yourself ;)

> [!NOTE]
> An optional last step is to delete the `ezkernalnew.bin` file from your Omega DE's SD card, either by putting it into your computer, or by deleting is directly from your console by selecting it and pressing `L + Start`.

Now you can simply organize your games however you wish on your SD card :)

#### Updating the firmware

The only way to update the firmware is via the official kernel from EZflash. To do that first rename the `.config` file on your SD card to `SYSTEM` and follow the update instructions from EZFlash's kernel. Once that's done you can reinstall Solarius by following the steps above.

### Need support for a new language

I unfortuantely only speak English and French so these are the only two languages available right now, but I want more! The goal is to support as many languages as possible so that the Omega DE cartridge can be used by anyone.

So if you feel up for it, please take a look at the files in the `LANG` directory of this repository and translate one of the files in there. All of those files contain the same thing but in different languages so pick the one with which you feel most comfortable.

Once that's done you can submit a PR on this repo with your translation so that we can add it to Solarius!

### What's new?

#### v1.0

   - Removed the unecessary QR code for the online manual
   - Changed the font to a nicer one ([Cozette](https://github.com/slavfox/Cozette))
   - Added possibility to load more languages
   - Only show visible and useful folders

### Credits

This custom kernel is based on the Simple kernel made by [Sterophonick](https://github.com/Sterophonick), so full credit to him for the work he did on it!

This custom kernel uses the font [Cozette](https://github.com/slavfox/Cozette), massive thanks to [Slavfox](https://github.com/slavfox) for creating this awesome font.

Take a look at the [original README](./original_README.md).