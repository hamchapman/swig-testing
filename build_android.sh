ANDROID_API_LEVEL=28

if [[ "$OSTYPE" == msys* ]]; then
    ANDROID_HOST=windows-x86_64
else
    unamestr=`uname`
    if [[ "$unamestr" == Darwin ]]; then
        ANDROID_HOST=darwin-x86_64
    elif [[ "$unamestr" == Linux ]]; then
        ANDROID_HOST=linux-x86_64
    else
        echo "Unknow host platform"
        exit 1
    fi
fi

rm app/src/main/java/gg/hc/mydatabase/*.java || true
mkdir -p app/src/main/java/gg/hc/mydatabase
swig -java -package gg.hc.mydatabase -outdir app/src/main/java/gg/hc/mydatabase -o database_android.c database_swig.i

ANDROID_ARCHS=( aarch64 armv7 x86 x86_64 )
ANDROID_ARCH_TARGETS=( aarch64-linux-android armv7a-linux-androideabi i686-linux-android x86_64-linux-android )
for i in "${!ANDROID_ARCH_TARGETS[@]}"; do
    rm libdatabase.so
    rm database.lo database_android.lo

    ANDROID_TARGET="${ANDROID_ARCH_TARGETS[$i]}"
    ANDROID_ARCH="${ANDROID_ARCHS[$i]}"

    CC="$NDK_HOME/toolchains/llvm/prebuilt/${ANDROID_HOST}/bin/${ANDROID_TARGET}${ANDROID_API_LEVEL}-clang"

    $CC -c database.c
    $CC -fPIC -c database.c -o database.lo

    $CC -c database_android.c
    $CC -fPIC -c database_android.c -o database_android.lo

    $CC -pthread -shared -o libdatabase.so database.lo database_android.lo

    mkdir -p "app/src/main/libs/${ANDROID_ARCH}"
    cp "libdatabase.so" "app/src/main/libs/${ANDROID_ARCH}"
done
