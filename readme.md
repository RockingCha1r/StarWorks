# Starworks

I want to make a starfox-like game for the NumWorks calculator.

## Build the app

You'll need the embedded ARM toolchain and Node.js (works well with the v20.20.2).

<details>

    <summary>Downloading dependencies</summary>

    ### Fedora

    ```bash
    sudo dnf install arm-none-eabi-gcc-cs arm-none-eabi-binutils nodejs
    ```

    ### Debian / Ubuntu

    ```bash
    sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi nodejs npm
    ```

    ### Arch 

    ```bash
    sudo pacman -S arm-none-eabi-gcc arm-none-eabi-binutils nodejs npm
    ```

    ### macOS

    ```bash
    brew install numworks/tap/arm-none-eabi-gcc node
    ```
</details>

```bash
make clean
make build
```

and you will find the compiled file in `build/starworks.nwa`. You can install it with [this website](https://my.numworks.com/apps). You could also just find this file in the "Releases" section.