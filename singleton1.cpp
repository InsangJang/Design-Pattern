// class FileSystem
// {
// public:
//     static FileSystem& instance() {
//         // 게으른 초기화
//         if(instance_ == nullptr)
//         {
//             instance_ = new FileSystem();
//         }

//         return *instance_;
//     }

// private:
//     FileSystem(){}
//     static FileSystem* instance_;
// };

// class FileSystem {
// public:
//     static FileSystem& instance() {
//         static FileSystem* instance = new FileSystem();
//         return *instance;
//     }

// private:
//     FileSystem(){}
// };

class FileSystem {
public:
    static FileSystem& instance() {
        #if PLATFORM == PLAYSTATION
        static FileSystem* instance = new PS3FileSystem();
        #elif PLATFORM == WII
        static FileSystem* instance = new WIIFileSystem();
        #endifreturn *instance;

    }

    virtual ~FileSystem(){}
    virtual char* readFile(char* path) = 0;
    virtual void writeFile(char* path, char* contents) = 0;

protected:
    FileSystem(){}
};

class PS3FileSystem:public FileSystem {
public:
    virtual char* readFile(char* path) {

    }

    virtual void writeFile(char* path, char* contents) {

    }
};

class WIIFileSystem : public FIleSystem {
public:
    virtual char* readFile(char* path) {

    }

    virtual void writeFile(char* path, char* contents) {

    }
};
