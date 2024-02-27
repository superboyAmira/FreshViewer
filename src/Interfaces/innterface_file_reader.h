#ifndef SRC_INTERFACES_INTERFACE_FILE_READER_H_
#define SRC_INTERFACES_INTERFACE_FILE_READER_H_


namespace s21 {
    /*
    Интерфейс класса парсера .obj файла
    */
    class IReader {
        public:
            virtual ~IReader() = default;
            virtual void ReadFile() = 0;
            virtual void SaveData() = 0;
            virtual bool OpenFile() = 0;
            virtual void CloseFile() = 0;
    };


}

#endif  // SRC_INTERFACES_INTERFACE_FILE_READER_H_