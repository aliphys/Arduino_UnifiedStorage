#include <Arduino_UnifiedStorage.h>

#if !defined(ARDUINO_OPTA)
#define HAS_SD 
#endif
#define HAS_USB 
#define HAS_QSPI 

#if defined(HAS_USB)
USBStorage usb = USBStorage();
#endif

#if defined(HAS_SD)
SDStorage sd = SDStorage();
#endif

#if defined(HAS_QSPI)
InternalStorage internal = InternalStorage();
#endif


bool testFileCreationWithOpen(Folder root) {
  UFile file = UFile();
  String path = root.getPathAsString() + "/test_open.txt";
  printFormatted(path);
  if (file.open(path, FileMode::WRITE)) {
    printFormatted("\n--- Test creating file using file.open ---");
    printFormatted("Test creating file using file.open - Success");
    file.close();
    file.remove();
    return true;
  } else {
    printFormatted("Test creating file using file.open - Failed. Error: " + String(getErrno()));
    return false;
  }

}

bool testFileCreationWithCreate(Folder root) {
  printFormatted("\n--- Test creating file using root.createFile ---");
  UFile file = root.createFile("test_create.txt", FileMode::WRITE);
  if (file.exists()) {
    printFormatted("Test creating file using root.createFile - Success");
    file.close();
    file.remove();
    return true;
  } else {
    printFormatted("Test creating file using root.createFile - Failed. Error: " + String(getErrno()));
    return false;
  }
}

bool testWritingCharBuffer(Folder root) {
  UFile file = root.createFile("test_write.txt", FileMode::WRITE);
  if (file.exists()) {
    printFormatted("\n--- Test writing char * buffer ---");
    size_t bytesWritten = file.write(reinterpret_cast<const uint8_t*>("Hello, World!"), 13);
    printFormatted("Bytes written to file: " + String(bytesWritten));
    file.close();
    file.remove();
    return bytesWritten == 13;
  } else {
    printFormatted("Test writing char * buffer - Failed. Error: " + String(getErrno()));
    return false;
  }
}

bool testWritingWithString(Folder root) {
  UFile file = root.createFile("test_write_string.txt", FileMode::WRITE);
  if (file.exists()) {
    printFormatted("\n--- Test writing String ---");
    String data = " This is a test with String data.";
    size_t bytesWritten = file.write(data);
    printFormatted("Bytes written to file (with String): " + String(bytesWritten));
    file.close();
    file.remove();
    return true;

  } else {
    printFormatted("Test writing with String data type - Failed. Error: " + String(getErrno()));
    return false;
  }
  
}

bool testAppending(Folder root) {
  UFile file = root.createFile("test_append.txt", FileMode::WRITE);
  if (file.exists()) {
    printFormatted("\n--- Test appending ---");
    String data = " Appending some more data.";
    size_t bytesWritten = file.write(reinterpret_cast<const uint8_t*>(data.c_str()), data.length());
    printFormatted("Bytes written to file (appending): " + String(bytesWritten));
    file.close();
    file.remove();
    return true;
  } else {
    printFormatted("Test appending to the file - Failed. Error: " + String(getErrno()));
    return false;
  }
}

bool testReadingAll(Folder root) {
  UFile file = root.createFile("test_read.txt", FileMode::WRITE);
  if (file.exists()) {
    file.write(reinterpret_cast<const uint8_t*>("Hello, World!"), 13);
    file.close();

    if (file.open(root.getPathAsString() + "/test_read.txt", FileMode::READ)) {
      char buffer[file.available()];
      size_t bytesRead = file.read(reinterpret_cast<uint8_t*>(buffer), sizeof(buffer));
      buffer[bytesRead] = '\0'; // Null-terminate the string
      printFormatted("\n--- Test reading everything from the file ---");
      printFormatted("Read from file (test_read.txt): " + String(buffer));
      file.close();

      file.remove();

      return true;
    } else {
      printFormatted("Test reading everything from the file - Failed. Error: " + String(getErrno()));
      return false;
    }
  } else {
    printFormatted("Test reading everything from the file - Failed to create file. Error: " + String(getErrno()));
    return false;
  
  }

  return false;
}

bool testSeeking(Folder root) {

  UFile file = root.createFile("test_seek.txt", FileMode::WRITE);
  if (file.exists()) {
    file.write(reinterpret_cast<const uint8_t*>("Hello, World!"), 13);
    file.close();
 

    if (file.open(root.getPathAsString() + "/test_seek.txt", FileMode::READ)) {
      printFormatted("\n--- Test seeking file ---");
      file.seek(7);
      char buffer[20];
      size_t bytesRead = file.read(reinterpret_cast<uint8_t*>(buffer), sizeof(buffer));
      buffer[bytesRead] = '\0'; // Null-terminate the string
      printFormatted("Read after seeking: " + String(buffer));
      file.close();
      file.remove();
      return true;
    } else {
      printFormatted("Test seeking in the file - Failed. Error: " + String(getErrno()));
      return false;
    }
  } else {
    printFormatted("Test seeking in the file - Failed to create file. Error: " + String(getErrno()));
    return false;
  }
  
}

bool testAvailableData(Folder root) {
  UFile file = root.createFile("test_available.txt", FileMode::WRITE);
  if (file.exists()) {
    file.write(reinterpret_cast<const uint8_t*>("Hello, World!"), 13);
    file.close();

    if (file.open(root.getPathAsString() + "/test_available.txt", FileMode::READ)) {
      printFormatted("\n--- Test available data ---");
      int availableBytes = file.available();
      printFormatted("Available bytes in file (test_available.txt): " + String(availableBytes));
      file.close();
      file.remove();
      return true;
    } else {
      printFormatted("Test checking available data in the file - Failed. Error: " + String(getErrno()));
      return false;
    }
  } else {
    printFormatted("Test checking available data in the file - Failed to create file. Error: " + String(getErrno()));
    return false;
  }

  return false;
}

bool testCopyingFile(Folder root) {
    // Test copying a file
  UFile sourceFile = root.createFile("test_source_copy.txt", FileMode::WRITE);
  if (sourceFile.exists()) {
    sourceFile.write(reinterpret_cast<const uint8_t*>("Hello, World!"), 13);
    sourceFile.close();

    Folder destinationFolder = root.createSubfolder("test_folder_copy");

    if (destinationFolder.exists()) {
        printFormatted("\n--- Test copying a file ---");
        printFormatted("Source file name: " + String(sourceFile.getPathAsString()));
        
        if (sourceFile.copyTo(destinationFolder)) {
          printFormatted("File copied successfully!");
          sourceFile.close();
          sourceFile.remove();
          destinationFolder.remove();
          return true;
        } else {
          printFormatted("File copying failed. Error: " + String(getErrno()));
          return false;
        }
      } else {
        printFormatted("Test copying a file - Failed. Error: " + String(getErrno()));
        return false;
      }

    } else {
      printFormatted("Test copying a file - Failed to create destination folder. Error: " + String(getErrno()));
      return false;
    }
}

bool testMovingFile(Folder root) {
  UFile sourceFileMove = root.createFile("test_source_move.txt", FileMode::WRITE);
  if (sourceFileMove.exists()) {
    sourceFileMove.write(reinterpret_cast<const uint8_t*>("Hello, World!"), 13);
    sourceFileMove.close();

    Folder destinationFolder = root.createSubfolder("test_folder_move");
    if (destinationFolder.exists()) {
      UFile movedFile = sourceFileMove;
      if (movedFile.exists()) {
        printFormatted("\n--- Test moving a file ---");
        printFormatted("Source file name: " + String(sourceFileMove.getPathAsString()));
        printFormatted("Destination file name: " + String(destinationFolder.getPathAsString()) + "/test_source_move.txt");
        if (sourceFileMove.moveTo(destinationFolder)) {
          printFormatted("File moved successfully!");
          sourceFileMove.close();
          movedFile.close();
          movedFile.remove();
          destinationFolder.remove();
          sourceFileMove.remove();
          return true;
        } else {
          printFormatted("File moving failed. Error: " + String(getErrno()));
          return false;
        }
      } else {
        printFormatted("Test moving a file - Failed. Error: " + String(getErrno()));
        return false;
      }
    } else {
      printFormatted("Test moving a file - Failed to create destination folder. Error: " + String(getErrno()));
      return false;
    }
  } else {
    printFormatted("Test moving a file - Failed. Error: " + String(getErrno()));
    return false;
  }
}

void printFolderContents(Folder dir, int indentation = 0) {
  std::vector<Folder> directories = dir.getFolders();
  std::vector<UFile>files = dir.getFiles();

  // Print directories
  for (Folder subdir : directories) {
    for (int i = 0; i < indentation; i++) {
      printFormatted("  ");
    }
    printFormatted("[D] ");
    printFormatted(subdir.getPath());
    printFolderContents(subdir, indentation + 1);
  }

  // Print files
  for (UFile file : files) {
    for (int i = 0; i < indentation; i++) {
      printFormatted("  ");
    }
    printFormatted("[F] ");
    printFormatted(file.getPath());
  }
}

void runTests(Arduino_UnifiedStorage * storage, String storageType) {
    if (storage->begin()) {
        Folder root = storage->getRootFolder();
    
        printFormatted("\n=== Testing " + storageType + " ===");
        printFormatted("========= File Tests =========");

        testFileCreationWithOpen(root); 
        testFileCreationWithCreate(root);
        testWritingCharBuffer(root);
        testWritingWithString(root);
        testAppending(root);
        testReadingAll(root);
        testSeeking(root);
        testAvailableData(root);
        testCopyingFile(root);
        testMovingFile(root);

        printFormatted("\n========= FS Contents after File Tests =========");
        printFormatted("Should be empty if deletion was successful");

        printFolderContents(root);
        printFormatted("=============================\n");

        storage -> unmount();
    }
}

void setup(){
 
    #if defined(ARDUINO_PORTENTA_C33) || defined(ARDUINO_PORTENTA_H7_M7)
        Serial.begin(115200);
        while(!Serial);
    #elif defined(ARDUINO_OPTA)
        beginRS485(115200);
    #endif 

    
    #if defined(HAS_SD)
        sd.format(FS_FAT);
        runTests(&&sd, "SD");
    #endif 

    #if defined(HAS_USB)
        usb.format(FS_FAT);
        runTests(&usb, "USB");
    #endif 

    #if defined(HAS_QSPI)
        internal.format(FS_FAT);
        runTests(&internal, "QSPI");
    #endif 



}

void loop(){

}