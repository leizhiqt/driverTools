#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>

static const unsigned char qt_resource_tree[] = {
0,
0,0,0,0,2,0,0,0,1,0,0,0,1,0,0,0,
8,0,2,0,0,0,16,0,0,0,2,0,0,0,182,0,
0,0,0,0,1,0,0,0,0,0,0,1,200,0,0,0,
0,0,1,0,0,0,0,0,0,0,102,0,0,0,0,0,
1,0,0,0,0,0,0,1,162,0,0,0,0,0,1,0,
0,0,0,0,0,1,42,0,0,0,0,0,1,0,0,0,
0,0,0,2,170,0,0,0,0,0,1,0,0,0,0,0,
0,0,246,0,0,0,0,0,1,0,0,0,0,0,0,0,
20,0,0,0,0,0,1,0,0,0,0,0,0,0,160,0,
0,0,0,0,1,0,0,0,0,0,0,2,12,0,0,0,
0,0,1,0,0,0,0,0,0,2,138,0,0,0,0,0,
1,0,0,0,0,0,0,0,72,0,0,0,0,0,1,0,
0,0,0,0,0,1,104,0,0,0,0,0,1,0,0,0,
0,0,0,2,106,0,0,0,0,0,1,0,0,0,0,0,
0,2,40,0,0,0,0,0,1,0,0,0,0,0,0,2,
68,0,0,0,0,0,1,0,0,0,0};
static const unsigned char qt_resource_names[] = {
0,
1,0,0,0,47,0,47,0,3,0,0,120,60,0,113,0,
109,0,108,0,23,7,114,122,220,0,71,0,114,0,111,0,
117,0,112,0,66,0,111,0,120,0,95,0,82,0,83,0,
52,0,50,0,50,0,95,0,82,0,101,0,99,0,118,0,
46,0,113,0,109,0,108,0,12,10,108,231,92,0,80,0,
97,0,103,0,101,0,68,0,105,0,115,0,112,0,46,0,
113,0,109,0,108,0,26,4,249,3,188,0,71,0,114,0,
111,0,117,0,112,0,66,0,111,0,120,0,95,0,65,0,
82,0,73,0,78,0,67,0,52,0,50,0,57,0,95,0,
82,0,101,0,99,0,118,0,46,0,113,0,109,0,108,0,
8,8,1,90,92,0,109,0,97,0,105,0,110,0,46,0,
113,0,109,0,108,0,29,3,224,194,92,0,71,0,114,0,
111,0,117,0,112,0,66,0,111,0,120,0,95,0,82,0,
83,0,52,0,50,0,50,0,95,0,77,0,97,0,110,0,
99,0,104,0,101,0,115,0,116,0,101,0,114,0,46,0,
113,0,109,0,108,0,23,7,52,122,220,0,71,0,114,0,
111,0,117,0,112,0,66,0,111,0,120,0,95,0,82,0,
83,0,50,0,51,0,50,0,95,0,82,0,101,0,99,0,
118,0,46,0,113,0,109,0,108,0,28,6,160,124,220,0,
71,0,114,0,111,0,117,0,112,0,66,0,111,0,120,0,
95,0,82,0,83,0,50,0,51,0,50,0,95,0,82,0,
101,0,99,0,118,0,95,0,83,0,101,0,110,0,100,0,
46,0,113,0,109,0,108,0,26,10,178,78,60,0,71,0,
114,0,111,0,117,0,112,0,66,0,111,0,120,0,95,0,
68,0,73,0,79,0,95,0,82,0,101,0,99,0,118,0,
95,0,83,0,101,0,110,0,100,0,46,0,113,0,109,0,
108,0,16,5,132,15,156,0,80,0,97,0,103,0,101,0,
65,0,82,0,73,0,78,0,67,0,52,0,50,0,57,0,
46,0,113,0,109,0,108,0,31,4,216,215,252,0,71,0,
114,0,111,0,117,0,112,0,66,0,111,0,120,0,95,0,
65,0,82,0,73,0,78,0,67,0,52,0,50,0,57,0,
95,0,82,0,101,0,99,0,118,0,95,0,83,0,101,0,
110,0,100,0,46,0,113,0,109,0,108,0,11,8,142,175,
28,0,80,0,97,0,103,0,101,0,68,0,73,0,79,0,
46,0,113,0,109,0,108,0,11,12,108,175,124,0,72,0,
90,0,88,0,84,0,101,0,120,0,116,0,46,0,113,0,
109,0,108,0,16,15,223,18,60,0,72,0,90,0,88,0,
84,0,97,0,98,0,66,0,117,0,116,0,116,0,111,0,
110,0,46,0,113,0,109,0,108,0,13,11,174,27,188,0,
80,0,97,0,103,0,101,0,82,0,83,0,52,0,50,0,
50,0,46,0,113,0,109,0,108,0,13,9,158,27,188,0,
80,0,97,0,103,0,101,0,82,0,83,0,50,0,51,0,
50,0,46,0,113,0,109,0,108,0,28,6,169,60,220,0,
71,0,114,0,111,0,117,0,112,0,66,0,111,0,120,0,
95,0,82,0,83,0,52,0,50,0,50,0,95,0,82,0,
101,0,99,0,118,0,95,0,83,0,101,0,110,0,100,0,
46,0,113,0,109,0,108};
static const unsigned char qt_resource_empty_payout[] = { 0, 0, 0, 0, 0 };
QT_BEGIN_NAMESPACE
extern Q_CORE_EXPORT bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
QT_END_NAMESPACE
namespace QmlCacheGeneratedCode {
namespace _qml_GroupBox_RS422_Recv_Send_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_PageRS232_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_PageRS422_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_HZXTabButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_HZXText_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_PageDIO_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_GroupBox_ARINC429_Recv_Send_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_PageARINC429_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_GroupBox_DIO_Recv_Send_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_GroupBox_RS232_Recv_Send_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_GroupBox_RS232_Recv_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_GroupBox_RS422_Manchester_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_main_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_GroupBox_ARINC429_Recv_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_PageDisp_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_GroupBox_RS422_Recv_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/GroupBox_RS422_Recv_Send.qml"), &QmlCacheGeneratedCode::_qml_GroupBox_RS422_Recv_Send_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/PageRS232.qml"), &QmlCacheGeneratedCode::_qml_PageRS232_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/PageRS422.qml"), &QmlCacheGeneratedCode::_qml_PageRS422_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/HZXTabButton.qml"), &QmlCacheGeneratedCode::_qml_HZXTabButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/HZXText.qml"), &QmlCacheGeneratedCode::_qml_HZXText_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/PageDIO.qml"), &QmlCacheGeneratedCode::_qml_PageDIO_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/GroupBox_ARINC429_Recv_Send.qml"), &QmlCacheGeneratedCode::_qml_GroupBox_ARINC429_Recv_Send_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/PageARINC429.qml"), &QmlCacheGeneratedCode::_qml_PageARINC429_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/GroupBox_DIO_Recv_Send.qml"), &QmlCacheGeneratedCode::_qml_GroupBox_DIO_Recv_Send_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/GroupBox_RS232_Recv_Send.qml"), &QmlCacheGeneratedCode::_qml_GroupBox_RS232_Recv_Send_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/GroupBox_RS232_Recv.qml"), &QmlCacheGeneratedCode::_qml_GroupBox_RS232_Recv_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/GroupBox_RS422_Manchester.qml"), &QmlCacheGeneratedCode::_qml_GroupBox_RS422_Manchester_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/main.qml"), &QmlCacheGeneratedCode::_qml_main_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/GroupBox_ARINC429_Recv.qml"), &QmlCacheGeneratedCode::_qml_GroupBox_ARINC429_Recv_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/PageDisp.qml"), &QmlCacheGeneratedCode::_qml_PageDisp_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/GroupBox_RS422_Recv.qml"), &QmlCacheGeneratedCode::_qml_GroupBox_RS422_Recv_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.version = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
QT_PREPEND_NAMESPACE(qRegisterResourceData)(/*version*/0x01, qt_resource_tree, qt_resource_names, qt_resource_empty_payout);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qml)() {
    ::unitRegistry();
    Q_INIT_RESOURCE(qml_qmlcache);
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qml))
int QT_MANGLE_NAMESPACE(qCleanupResources_qml)() {
    Q_CLEANUP_RESOURCE(qml_qmlcache);
    return 1;
}
