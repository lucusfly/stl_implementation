#ifndef JIA_STRING_H
#define JIA_STRING_H
#include <iostream>

namespace jia {

    class String {
        typedef int size_type;

        private:
            size_type _len;
            char * _p;

        public:
            String();
            String(const char *);
            String(const String &);
            String& operator=(const String &);
            String& operator=(const char *);
            ~String();

            size_type length() const;
            char& operator[](size_type);
            //const char& operator[](size_type) const;
            char& at(size_type);
            //const char& at(size_type) const;
            void clear();
            bool empty() const;

            //param1 start index, param2 length
            String substr(size_type, size_type) const;
            String& operator+=(const String &);

            friend String operator+(const String&, const String&);
            friend bool operator==(const String&, const String&);
            friend std::ostream& operator<<(std::ostream&, const String&);
            friend std::istream& operator>>(std::istream&, String&);
    };

}

#endif
