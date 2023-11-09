`class ` [`Partitioning`](#class_partitioning) | 
`class ` [`USBStorage`](#class_u_s_b_storage) | [USBStorage](#class_u_s_b_storage) class provides an interface to access USB storage devices. It inherits from the [Arduino_UnifiedStorage](#class_arduino___unified_storage) class and implements its pure virtual functions.
`struct ` [`Partition`](#struct_partition) | 
`public static void ` [`debugPrint`](#class_arduino___unified_storage_1ab0b726c7f98ea3623679097224290a07)`(String message)` | 
`public static void ` [`testPrint`](#class_arduino___unified_storage_1a1fafe7a15fbd21c8705a9f86a92f6dd9)`(String message)` | 
### `public static void ` [`debugPrint`](#class_arduino___unified_storage_1ab0b726c7f98ea3623679097224290a07)`(String message)` <a id="class_arduino___unified_storage_1ab0b726c7f98ea3623679097224290a07" class="anchor"></a>

<hr />

### `public static void ` [`testPrint`](#class_arduino___unified_storage_1a1fafe7a15fbd21c8705a9f86a92f6dd9)`(String message)` <a id="class_arduino___unified_storage_1a1fafe7a15fbd21c8705a9f86a92f6dd9" class="anchor"></a>

<hr />

`public  ` [`Folder`](#class_folder_1a8af69fd19ba86816c60b4c2291311eb1)`()` | Creates an empty [Folder](#class_folder) object. Please note that any operation on this object will fail until a valid directory is assigned to it.
`public  ` [`Folder`](#class_folder_1aa2a4dc98e8c383c7b4fa503b45813fe3)`(const char * dirname)` | Creates a directory with the specified name. If the directory already exists, it returns a [Folder](#class_folder) object representing the existing directory. Otherwise, it tries to create a new directory with the specified name. If it fails the `path` property of the [Folder](#class_folder) object will be null.
`public  ` [`Folder`](#class_folder_1a6f445bfe0214a03ba00a1408e41726dd)`(String dirname)` | Creates a directory with the specified name. If the directory already exists, it returns a [Folder](#class_folder) object representing the existing directory. Otherwise, it tries to create a new directory with the specified name. If it fails the `path` property of the [Folder](#class_folder) object will be empty.
Creates an empty [Folder](#class_folder) object. Please note that any operation on this object will fail until a valid directory is assigned to it.
Creates a directory with the specified name. If the directory already exists, it returns a [Folder](#class_folder) object representing the existing directory. Otherwise, it tries to create a new directory with the specified name. If it fails the `path` property of the [Folder](#class_folder) object will be null.
Creates a directory with the specified name. If the directory already exists, it returns a [Folder](#class_folder) object representing the existing directory. Otherwise, it tries to create a new directory with the specified name. If it fails the `path` property of the [Folder](#class_folder) object will be empty.
```cpp
`public  ` [`InternalStorage`](#class_internal_storage_1ac45948ef554bc659efed81240140192e)`()` | Constructs an [InternalStorage](#class_internal_storage) object with default settings. If no partitions are available, it restores the default partitioning scheme (See [restoreDefaultPartitions()](#class_internal_storage_1ace77d2372832c2f9ef39d382cc443259) for more info). If partitions are available, it sets the partition number, file system type, and partition name based on the last partition available. When using the default partitioning scheme the last partition would be the user partition.
`public virtual bool ` [`format`](#class_internal_storage_1a9ee819a55de5d411e6b10bdc9942c601)`(FileSystems fs)` | Formats the internal storage with the selected file system.
`public BlockDeviceType * ` [`getBlockDevice`](#class_internal_storage_1a499c1975764c56ad3770ef9c582d7dda)`()` | Retrieves the block device associated with the internal storage.
`public static bool ` [`partition`](#class_internal_storage_1acd4f9617061b962f38b20a4c6ddb8d48)`(std::vector< ` [`Partition`](#struct_partition)` > partitions)` | Partitions the internal storage according to the partitioning scheme given in the `partitions` parameter erasing the existing partitions 
`public static bool ` [`partition`](#class_internal_storage_1aefb31c03b94006e75b18111f07c99331)`()` | Creates one partition spanning over the whole size of the internal storage drive erasing the existing partitions. 
`public static bool ` [`restoreDefaultPartitions`](#class_internal_storage_1ace77d2372832c2f9ef39d382cc443259)`()` | Restores the default partitioning scheme (1MB FAT32 for Certificates, 5MB FAT32 for OTA, 8MB user storage) to the internal storage drive erasing the existing partitions. 
`public static std::vector< ` [`Partition`](#struct_partition)` > ` [`readPartitions`](#class_internal_storage_1a7191c21a719e9fe8132dc3cfaed3f0ec)`()` | Reads the partitioning scheme from the MBR sector of the internal storage drive and returns a vector of structs of type [Partition](#struct_partition) that represents the partitioning scheme 
Constructs an [InternalStorage](#class_internal_storage) object with default settings. If no partitions are available, it restores the default partitioning scheme (See [restoreDefaultPartitions()](#class_internal_storage_1ace77d2372832c2f9ef39d382cc443259) for more info). If partitions are available, it sets the partition number, file system type, and partition name based on the last partition available. When using the default partitioning scheme the last partition would be the user partition.
### `public virtual bool ` [`format`](#class_internal_storage_1a9ee819a55de5d411e6b10bdc9942c601)`(FileSystems fs)` <a id="class_internal_storage_1a9ee819a55de5d411e6b10bdc9942c601" class="anchor"></a>
Formats the internal storage with the selected file system.
#### Returns
true if successful, false if failed.
### `public BlockDeviceType * ` [`getBlockDevice`](#class_internal_storage_1a499c1975764c56ad3770ef9c582d7dda)`()` <a id="class_internal_storage_1a499c1975764c56ad3770ef9c582d7dda" class="anchor"></a>

Retrieves the block device associated with the internal storage.
#### Returns
The block device as a BlockDevice object.
<hr />
### `public static bool ` [`partition`](#class_internal_storage_1acd4f9617061b962f38b20a4c6ddb8d48)`(std::vector< ` [`Partition`](#struct_partition)` > partitions)` <a id="class_internal_storage_1acd4f9617061b962f38b20a4c6ddb8d48" class="anchor"></a>

Partitions the internal storage according to the partitioning scheme given in the `partitions` parameter erasing the existing partitions 
* `partitions` - vector of structs of type [Partition](#struct_partition) that represents the partitioning scheme 

#### Returns
true if successful, false if failed.
### `public static bool ` [`partition`](#class_internal_storage_1aefb31c03b94006e75b18111f07c99331)`()` <a id="class_internal_storage_1aefb31c03b94006e75b18111f07c99331" class="anchor"></a>
Creates one partition spanning over the whole size of the internal storage drive erasing the existing partitions. 
#### Returns
true if successful, false if failed.
<hr />
### `public static bool ` [`restoreDefaultPartitions`](#class_internal_storage_1ace77d2372832c2f9ef39d382cc443259)`()` <a id="class_internal_storage_1ace77d2372832c2f9ef39d382cc443259" class="anchor"></a>

Restores the default partitioning scheme (1MB FAT32 for Certificates, 5MB FAT32 for OTA, 8MB user storage) to the internal storage drive erasing the existing partitions. 
### `public static std::vector< ` [`Partition`](#struct_partition)` > ` [`readPartitions`](#class_internal_storage_1a7191c21a719e9fe8132dc3cfaed3f0ec)`()` <a id="class_internal_storage_1a7191c21a719e9fe8132dc3cfaed3f0ec" class="anchor"></a>
Reads the partitioning scheme from the MBR sector of the internal storage drive and returns a vector of structs of type [Partition](#struct_partition) that represents the partitioning scheme 
#### Returns
vector of structs of type [Partition](#struct_partition)
<hr />

# class `Partitioning` <a id="class_partitioning" class="anchor"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public static bool ` [`eraseMBRSector`](#class_partitioning_1a662f276b27785e76cdf9f89c5356e784)`(BlockDeviceType * blockDevice)` | Erases the first block (4096 bytes) of the BlockDevice to delete any already existing MBR partition table 
`public static bool ` [`partitionDrive`](#class_partitioning_1a803b6e9a67304c6551d2a90ed5473985)`(BlockDeviceType * blockDevice, std::vector< ` [`Partition`](#struct_partition)` > partitions)` | Partitions the BlockDevice according to the partitioning schemme given by the vector of [Partition](#struct_partition) structs 
`public static std::vector< ` [`Partition`](#struct_partition)` > ` [`readPartitions`](#class_partitioning_1a44886fc5c7320a07cc42171ce9581fec)`(BlockDeviceType * blockDevice)` | Reads and unpacks the MBR partition information and returns a list of partitions it can find on the drive 

## Members

### `public static bool ` [`eraseMBRSector`](#class_partitioning_1a662f276b27785e76cdf9f89c5356e784)`(BlockDeviceType * blockDevice)` <a id="class_partitioning_1a662f276b27785e76cdf9f89c5356e784" class="anchor"></a>

Erases the first block (4096 bytes) of the BlockDevice to delete any already existing MBR partition table 
#### Parameters
* `The` BlockDevice on which the MBR sector is situated. 
True upon success, False on failure
<hr />

### `public static bool ` [`partitionDrive`](#class_partitioning_1a803b6e9a67304c6551d2a90ed5473985)`(BlockDeviceType * blockDevice, std::vector< ` [`Partition`](#struct_partition)` > partitions)` <a id="class_partitioning_1a803b6e9a67304c6551d2a90ed5473985" class="anchor"></a>

Partitions the BlockDevice according to the partitioning schemme given by the vector of [Partition](#struct_partition) structs 
#### Parameters
* `blockDevice` - the BlockDevice which we would like to partition. 

* `partitions` - a vector of [Partition](#struct_partition) structs that represents the partitioning scheme 

#### Returns
True upon success, False on failure
### `public static std::vector< ` [`Partition`](#struct_partition)` > ` [`readPartitions`](#class_partitioning_1a44886fc5c7320a07cc42171ce9581fec)`(BlockDeviceType * blockDevice)` <a id="class_partitioning_1a44886fc5c7320a07cc42171ce9581fec" class="anchor"></a>

Reads and unpacks the MBR partition information and returns a list of partitions it can find on the drive 
#### Parameters
* `blockDevice` on which the MBR sector is situated. 

#### Returns
std::vector of [Partition](#struct_partition) containing size and filesystem information about each partition
<hr />
```cpp
```cpp
[USBStorage](#class_u_s_b_storage) class provides an interface to access USB storage devices. It inherits from the [Arduino_UnifiedStorage](#class_arduino___unified_storage) class and implements its pure virtual functions.
`public bool ` [`isMounted`](#class_u_s_b_storage_1a2d3e3a732f2a43ab67e2fcd05e4ac058)`()` | Checks if the USB storage is mounted.
`public void ` [`onConnect`](#class_u_s_b_storage_1a1dfb2b9dde7fbdc26c0bf73be9babe25)`(void(*)() callbackFunction)` | Sets the callback function to be called when a USB connection is established.
`public void ` [`removeOnConnectCallback`](#class_u_s_b_storage_1afc58782a3f5207356d29392cb31730a0)`()` | Removes the callback function that is executed when the USB storage device is connected.
`public void ` [`onDisconnect`](#class_u_s_b_storage_1a10ac0c8965eee6041b384a4823bb9720)`(void(*)() callbackFunction)` | Sets a callback function to be called when the USB storage device is disconnected.
`public void ` [`removeOnDisconnectCallback`](#class_u_s_b_storage_1a2333fb1697b7ca72e5127cf60fc6680f)`()` | Removes the callback function that is called when the USB storage device is disconnected.
### `public bool ` [`isMounted`](#class_u_s_b_storage_1a2d3e3a732f2a43ab67e2fcd05e4ac058)`()` <a id="class_u_s_b_storage_1a2d3e3a732f2a43ab67e2fcd05e4ac058" class="anchor"></a>
Checks if the USB storage is mounted.
true if mounted, false otherwise.
<hr />

### `public void ` [`onConnect`](#class_u_s_b_storage_1a1dfb2b9dde7fbdc26c0bf73be9babe25)`(void(*)() callbackFunction)` <a id="class_u_s_b_storage_1a1dfb2b9dde7fbdc26c0bf73be9babe25" class="anchor"></a>

Sets the callback function to be called when a USB connection is established.

#### Parameters
* `callbackFunction` A pointer to the function to be called when a USB connection is established.
<hr />

### `public void ` [`removeOnConnectCallback`](#class_u_s_b_storage_1afc58782a3f5207356d29392cb31730a0)`()` <a id="class_u_s_b_storage_1afc58782a3f5207356d29392cb31730a0" class="anchor"></a>

Removes the callback function that is executed when the USB storage device is connected.

### `public void ` [`onDisconnect`](#class_u_s_b_storage_1a10ac0c8965eee6041b384a4823bb9720)`(void(*)() callbackFunction)` <a id="class_u_s_b_storage_1a10ac0c8965eee6041b384a4823bb9720" class="anchor"></a>

Sets a callback function to be called when the USB storage device is disconnected.

#### Parameters
* `callbackFunction` A pointer to the function to be called when the USB storage device is disconnected.
<hr />

### `public void ` [`removeOnDisconnectCallback`](#class_u_s_b_storage_1a2333fb1697b7ca72e5127cf60fc6680f)`()` <a id="class_u_s_b_storage_1a2333fb1697b7ca72e5127cf60fc6680f" class="anchor"></a>

Removes the callback function that is called when the USB storage device is disconnected.

<hr />

# struct `Partition` <a id="struct_partition" class="anchor"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int ` [`size`](#struct_partition_1a718bdba639f222d90d23480b58caa1f9) | 
`public FileSystems ` [`fileSystemType`](#struct_partition_1af5c05bc6faa14fb253c3a39e5e883529) | 

## Members

### `public int ` [`size`](#struct_partition_1a718bdba639f222d90d23480b58caa1f9) <a id="struct_partition_1a718bdba639f222d90d23480b58caa1f9" class="anchor"></a>

<hr />

### `public FileSystems ` [`fileSystemType`](#struct_partition_1af5c05bc6faa14fb253c3a39e5e883529) <a id="struct_partition_1af5c05bc6faa14fb253c3a39e5e883529" class="anchor"></a>

<hr />