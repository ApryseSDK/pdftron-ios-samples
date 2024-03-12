import React, { Component } from "react";
import {
  Platform,
  StyleSheet,
  Text,
  View,
  PermissionsAndroid,
  BackHandler,
  NativeModules,
  Alert,
} from "react-native";

import { DocumentView, RNPdftron } from "@pdftron/react-native-pdf";

type Props = {};
export default class App extends Component<Props> {
  // If you are using TypeScript, use `constructor(props: Props) {`
  // Otherwise, use:
  constructor(props) {
    super(props);

    // Uses the platform to determine if storage permisions have been automatically granted.
    // The result of this check is placed in the component's state.
    // this.state = {
    //   permissionGranted: Platform.OS === 'ios' ? true : false
    // };

    RNPdftron.initialize("Insert commercial license key here after purchase");
    RNPdftron.enableJavaScript(true);
  }

  // Uses the platform to determine if storage permissions need to be requested.
  // componentDidMount() {
  //   if (Platform.OS === 'android') {
  //     this.requestStoragePermission();
  //   }
  // }

  // Requests storage permissions for Android and updates the component's state using
  // the result.
  // async requestStoragePermission() {
  //   try {
  //     const granted = await PermissionsAndroid.request(
  //       PermissionsAndroid.PERMISSIONS.WRITE_EXTERNAL_STORAGE
  //     );
  //     if (granted === PermissionsAndroid.RESULTS.GRANTED) {
  //       this.setState({
  //         permissionGranted: true
  //       });
  //       console.log("Storage permission granted");
  //     } else {
  //       this.setState({
  //         permissionGranted: false
  //       });
  //       console.log("Storage permission denied");
  //     }
  //   } catch (err) {
  //     console.warn(err);
  //   }
  // }

  onLeadingNavButtonPressed = () => {
    console.log("leading nav button pressed");
    if (Platform.OS === "ios") {
      Alert.alert(
        "App",
        "onLeadingNavButtonPressed",
        [{ text: "OK", onPress: () => console.log("OK Pressed") }],
        { cancelable: true }
      );
    } else {
      BackHandler.exitApp();
    }
  };

  render() {
    // If the component's state indicates that storage permissions have not been granted,
    // a view is loaded prompting users to grant these permissions.
    // if (!this.state.permissionGranted) {
    //   return (
    //     <View style={styles.container}>
    //       <Text>
    //         Storage permission required.
    //       </Text>
    //     </View>
    //   )
    // }

    const path =
      "https://pdftron.s3.amazonaws.com/downloads/pl/PDFTRON_mobile_about.pdf";

    return (
      <DocumentView
        document={path}
        showLeadingNavButton={true}
        leadingNavButtonIcon={
          Platform.OS === "ios"
            ? "ic_close_black_24px.png"
            : "ic_arrow_back_white_24dp"
        }
        onLeadingNavButtonPressed={this.onLeadingNavButtonPressed}
      />
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: "center",
    alignItems: "center",
    backgroundColor: "#F5FCFF",
  },
});